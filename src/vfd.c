/**
 * $Id: vfd.c 05:57 PM 2019-05-29 $
 *
 * This program is Futaba 202-MD-08GK VFD Glass GPIO Interface driver
 *
 * MIT License
 * 
 * Copyright (c) 2019 ssk.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
*/ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <string.h>     // memset
#include "vfd.h"
#include "font/international_5x7.h"
//#include "font/lcd_compatible_5x7.h"
//#include "font/hd44780u_6_5x7.h"


static void init_timer1(void);
static void _write(const uint8_t loc);
static void sck_le_pulseHL(void);
static void sck_anodeHL(void);

uint8_t _framebuffer[VFD_FRAMEBUFFER_SZ] = {0};  // display character is saved
uint8_t _chattribute[VFD_DISP_LENGTH]    = {0};  // display character property is saved(triangle mark)

// Volatile variables - will be changed by the ISR
volatile uint8_t ISR_CurrentGrid = 0;

coordinates _vfd_coord;

void vfd_init(void)
{
  VFD_CONTROL_DDR |=  (_BV(VFD_GCLK) | _BV(VFD_GSI) | _BV(VFD_ACLK) | _BV(VFD_BK));  // outputs.
  VFD_CONTROL     &= ~(_BV(VFD_GCLK) | _BV(VFD_GSI) | _BV(VFD_ACLK));                // initial value 'L'
/**
 * 4.6 Initialization
 *
 * When applying power to the VFD, the blanking should be disabled to ensure random data in the 
 * shift registers does not cause a bright flash or current surge. 
 * Depending on the control procedure, the display should only be illuminated once the correct data is 
 * in the shift registers and one latch pulse has occurred.
 * https://www.noritake-elec.com/technology/general-technical-information/cig-driver-vfd
 *
*/
  VFD_DISP_OFF();   
    
  VFD_DATA_DDR |=  (_BV(VFD_SIN0) | _BV(VFD_SIN1) | _BV(VFD_SIN2) | _BV(VFD_SIN3)); // outputs.
  VFD_DATA     &= ~(_BV(VFD_SIN0) | _BV(VFD_SIN1) | _BV(VFD_SIN2) | _BV(VFD_SIN3)); // initial value 'L'
 
  init_timer1();
  sei();
}

static void init_timer1(void)
{
  TCCR1B  = _BV(WGM12);       // CTC Mode 4
  TCCR1B |= _BV(CS10);        // CTC Mode, clkI/O/1 (No prescaling)
  OCR1A   =  VFD_GRID_TICKS;  // period for each grid scanning

  TIMSK1 = _BV(OCIE1A);       // Enable Timer/Counter1 interrupts.
}

ISR(TIMER1_COMPA_vect)
{
  VFD_DISP_OFF();
  
/**
 * TD62C950RF grid driver /STB(latch) pin is linked directly to the VCC.
 * /STB(latch) can be held High to allow the grid shift register data to be direct trnsferred to the grid
 * So what is needed is first mark 
 *
 * LCD or VFD works the same way, This is based on the same principle.
*/
  if(ISR_CurrentGrid == 0)    // first grid mark
  {
    VFD_CONTROL |=   _BV(VFD_GSI);
  }
  
  _write(ISR_CurrentGrid); 
  sck_le_pulseHL();
  
  VFD_CONTROL &=  ~_BV(VFD_GSI);
  
  if(ISR_CurrentGrid++ > VFD_GRID_MAX) 
  {
    ISR_CurrentGrid = 0;
  }

  VFD_DISP_ON();
}

/**
 * low level function to write nibble to 4 bit Anode driver
 *
 * @param loc output character location
 * @param attr character attribute (Triangle mark on/off)
 *
 * @note attr only applies to line 2
 *
*/
static void _write(const uint8_t loc)
{
  uint8_t ch   = _framebuffer[loc];
  uint8_t attr = (loc > VFD_DISP_LENGTH-1) ? (_chattribute[loc - VFD_DISP_LENGTH]) : 0;
  uint8_t data[FONT_FIXED_WIDTH] = {0};
 uint16_t index = (ch - FONT_FIRST_CHAR) * FONT_FIXED_WIDTH;
  
  if( ch >= FONT_FIRST_CHAR )     // valid character
  {
    memcpy_P(data, (international_5x7 + index), FONT_FIXED_WIDTH);
    //memcpy_P(data, (lcd_compatible_5x7 + index), FONT_FIXED_WIDTH);
    //memcpy_P(data, (hd44780u_6_5x7 + index), FONT_FIXED_WIDTH);
  }

  if(attr) 
  {
     data[0] |= attr;       // Triangle Mark On
  }
  else
  {
     data[0] |= 0;
  }
      

  // code that supports software 8 to 4 multiplexer(74HC157)
  // 0,2,4,6 even 4bit
  for(uint8_t i=0; i<5; i++)
  {
    if(data[i] &  _BV(0)) VFD_DATA |=  _BV(VFD_SIN0); else VFD_DATA &= ~_BV(VFD_SIN0);    
    if(data[i] &  _BV(2)) VFD_DATA |=  _BV(VFD_SIN1); else VFD_DATA &= ~_BV(VFD_SIN1);    
    if(data[i] &  _BV(4)) VFD_DATA |=  _BV(VFD_SIN2); else VFD_DATA &= ~_BV(VFD_SIN2);    
    if(data[i] &  _BV(6)) VFD_DATA |=  _BV(VFD_SIN3); else VFD_DATA &= ~_BV(VFD_SIN3);    
    
    sck_anodeHL();
  }

  // 1,3,5,7 odd 4bit
  for(uint8_t i=0; i<5; i++)
  {
    if(data[i] &  _BV(1)) VFD_DATA |=  _BV(VFD_SIN0); else VFD_DATA &= ~_BV(VFD_SIN0);    
    if(data[i] &  _BV(3)) VFD_DATA |=  _BV(VFD_SIN1); else VFD_DATA &= ~_BV(VFD_SIN1);    
    if(data[i] &  _BV(5)) VFD_DATA |=  _BV(VFD_SIN2); else VFD_DATA &= ~_BV(VFD_SIN2);    
    if(data[i] &  _BV(7)) VFD_DATA |=  _BV(VFD_SIN3); else VFD_DATA &= ~_BV(VFD_SIN3);    
    
    sck_anodeHL();
  }  
}
// clear screen
void vfd_clear(const uint8_t fillchar)
{
  memset(_framebuffer, fillchar, VFD_FRAMEBUFFER_SZ);
  vfd_gotoxy(0,0);
}

// clear line
void vgd_clear_line(const uint8_t y)
{
  uint8_t index;

  // line1:0 ~ 19, line2:20~39
  if(y == 1) index = VFD_DISP_LENGTH;

  memset( _framebuffer + index, ' ', VFD_DISP_LENGTH);
  vfd_gotoxy(y,0);
}

/**
 * output a character
 *
 * @param ch send data byte to framebuffer
 *
 * If the character will not fit on the current text line
 * inside the text area, the text position is wrapped to the next line.
 * the x,y position are used in a round robin fashion
 *
*/
void vfd_putc(const uint8_t ch)
{
  _framebuffer[(VFD_DISP_LENGTH * _vfd_coord.y) + _vfd_coord.x] = ch;
  
  if(_vfd_coord.x < VFD_DISP_LENGTH-1) 
  {
    vfd_gotoxy(_vfd_coord.x+1, _vfd_coord.y);
  }
  else
  {
    if(_vfd_coord.y == 0)
    {
      vfd_gotoxy(0, _vfd_coord.y+1);
    }
    else                      
    {
      vfd_gotoxy(0, 0);
    }
  }
}
/**
 * display string without auto linefeed
 *
 * @param *str string to be displayed
 *
*/
void vfd_puts(const unsigned char *str)
{
  uint8_t ch;

  while((ch = *str++))
  {
    vfd_putc(ch);
  }
}

/**
 * display string from program memory without auto linefeed
 *
 * @param PGM_P str string from program memory be be displayed
 *
*/
void vfd_puts_p(PGM_P str)
{
  uint8_t ch;

  while((ch = pgm_read_byte(str++)))
  {
    vfd_putc(ch);
  }
}

/**
 * go to at x,y to the given position
 *
 * @param x X coordinate, a value from 0 to VFD_DISP_LENGTH -1
 * @param y Y coordinate, a value from 0 to VFD_LINES -1
 *
 * Sets the current position at location the specified x,y
 * x and y are relative to the 0,0 origin of the display which
 * is the upper left corner.
 * Requests to set position outside the range of the display will be ignored.
 *
*/
void vfd_gotoxy(const uint8_t x, const uint8_t y)
{
  // exit if coordinates are not legal
  if( (x > VFD_DISP_LENGTH - 1) || (y > VFD_LINES - 1))  return;

  _vfd_coord.x = x;                // save new coordinates
  _vfd_coord.y = y;
}

/**
 * triangle mark On/Off at x1,x2 to the given position
 *
 * @param x1 start , a value from 0 to VFD_DISP_LENGTH -1
 * @param x2 end, a value from 0 to VFD_DISP_LENGTH -1
 * @param attr VFD_TMARK_ON, VFD_TMARK_OFF
 *
 * @note That only applies to line 2
 *
*/
void vfd_tmark(const uint8_t x1, const uint8_t x2, const uint8_t attr)
{
  // exit if coordinates are not legal
  if((x1 > VFD_DISP_LENGTH - 1) || (x2 > VFD_DISP_LENGTH - 1)) return;

  for(uint8_t i=x1; i<=x2; i++)
  {
    _chattribute[i] = attr;
  }
}

// serial clock(grid) & latch enable(anode)
static void sck_le_pulseHL(void)
{
  VFD_CONTROL |=   _BV(VFD_GCLK);
  VFD_CONTROL &=  ~_BV(VFD_GCLK);
}

// serial clock(anode)
static void sck_anodeHL(void)
{
  VFD_CONTROL |=   _BV(VFD_ACLK);
  VFD_CONTROL &=  ~_BV(VFD_ACLK);
}
/*
*EOF
*/
