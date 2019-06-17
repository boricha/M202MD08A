/**
 * $Id: main.c 05:57 PM 2019-05-29 $
 *
 * This program is Main of Futaba M202MD08A(2x20) VFD GPIO Interface Demo
 * 
 * Application : Character Display 
 * Features 20x2 Digits, 5x7 Dots + Triangle Mark
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
 * copies or substantial portions of the Software.
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
#include <util/delay.h>
#include <string.h>     // memset
#include "vfd.h"

static void setup(void);
static void setup(void);
static void demo_welcome(void);
static void demo_ascii(void);
static void demo_tmark(void);
static void demo_end(void);

int main(void)
{
  _delay_ms(100);

  setup();

  while(1)
  {
   _delay_ms(1000);
    demo_welcome();
    demo_ascii();
    demo_tmark();
    demo_end();
  }
}
static void setup(void)
{
  vfd_init();
}

static void demo_welcome(void)
{
  vfd_clear(' ');
  // \xab,\xbb : special character
  vfd_puts_P("\xab FUTABA M202MD08A \xbb");
  vfd_gotoxy(3,1);
  vfd_puts_P("GPIO Interface");
  _delay_ms(2000);
}

static void demo_ascii(void)
{
  vfd_clear(' ');
  vfd_puts_P("5x7 + Triangle Mark");
  vfd_gotoxy(1,1);
  vfd_puts_P("International Font");
  _delay_ms(2000);
  
  vfd_gotoxy(0,1);
  for(uint8_t i=32;i<255;i++)
  {
    vfd_putc(i);
    _delay_ms(100);
  }
  _delay_ms(1000);
  
  vfd_gotoxy(0,0);
  for(uint8_t i=0;i<VFD_GRID_MAX;i++)
  {
    vfd_putc(0xbe);
  }
  _delay_ms(2000);

}
static void demo_end(void)
{
  vfd_clear(' ');
  vfd_gotoxy(4,0);
  vfd_puts_P("Thank you for");
  vfd_gotoxy(6,1);
  vfd_puts_P("Watching!.");
  _delay_ms(4000);

  vfd_clear(' ');
  _delay_ms(4000);
}  
static void demo_tmark(void)
{
  demo_welcome();

  vfd_tmark(0,19, VFD_TMARK_ON);        // TMark all On
  _delay_ms(1000);

  vfd_tmark(0,19, VFD_TMARK_OFF);       // TMark all Off
  _delay_ms(1000);

  for(uint8_t i=0; i<VFD_DISP_LENGTH;i++)
  {
    vfd_tmark(i,i, VFD_TMARK_ON);
   _delay_ms(100);
   vfd_tmark(i,i, VFD_TMARK_OFF);
  }
  _delay_ms(1000);

  for(uint8_t i=VFD_DISP_LENGTH-1; i--;)
  {
    vfd_tmark(i,i, VFD_TMARK_ON);
   _delay_ms(100);
   vfd_tmark(i,i, VFD_TMARK_OFF);
  }

  vfd_tmark(0,19, VFD_TMARK_ON);        // TMark all On
  _delay_ms(1000);

  vfd_tmark(0,19, VFD_TMARK_OFF);       // TMark all Off
  _delay_ms(2000);
}
/*
*EOF
*/
