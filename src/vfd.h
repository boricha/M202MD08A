#ifndef _VFD_H_
#define _VFD_H_
/**
 * $Id: vfd.h 05:57 PM 2019-05-29 $
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
 
/**
 * Abbreviations
 *
 * GCLK,    (Grid) shift register clock(TD62C950RFG)
 * GSI,     (Grid) serial data Input.
 * ACLK,    (Anode) shift register clock(SN755700A x 2)
 * SINx     (Anode) serial data Input. (4Bits)
 * BK,      (Anode) output blanking Control input 
 *
 * TMARK    Triangle Mark, That only applies to line 2
 *   |      □ □ □ □ □ □ . . . □ □ □ □ □ □
 *   |      □ □ □ □ □ □ . . . □ □ □ □ □ □
 *   +--->  ▼ ▼ ▼ ▼ ▼ ▼ . . . ▼ ▼ ▼ ▼ ▼ ▼
*/ 

#define VFD_CONTROL_DDR      DDRC
#define VFD_CONTROL          PORTC
#define VFD_GCLK             1    // U1(3), Grid serial data clock (Anode data latch enable are linked to this pin)
#define VFD_GSI              2    // U1(2) 
#define VFD_BK               3    // U1(1) 
#define VFD_ACLK             4    // U8(11) 

#define VFD_DATA_DDR         DDRD
#define VFD_DATA             PORTD
#define VFD_SIN0             4    // U1(37) -> U4(A1~A10)
#define VFD_SIN1             5    // U1(36) -> U4(A11~A20)
#define VFD_SIN2             6    // U1(35) -> U3(A21~A30)
#define VFD_SIN3             7    // U1(34) -> U3(A31~A36)
                                  
// Used to disable output circuitry while data is being latched.
// an inter-digit blanking time should be added between grid pulse timings
#define VFD_DISP_OFF()      (VFD_CONTROL |=   _BV(VFD_BK))   // output disable
#define VFD_DISP_ON()       (VFD_CONTROL &=  ~_BV(VFD_BK))   // output enable 

/**
 *  Definitions for VFD software characteristics
 *  Change these definitions to adapt setting to your display
 */
#define VFD_LINES            2    // Number of visible lines of the display
#define VFD_DISP_LENGTH      20   // Visibles characters per line of the display

#define VFD_FRAMEBUFFER_SZ  (VFD_LINES * VFD_DISP_LENGTH)

// visibles characters whole of the display,  The GRID is the same as the DIGIT
#define VFD_GRID_MAX        (VFD_LINES * VFD_DISP_LENGTH)  

#define VFD_GSF              100   // Grid Scanning Frequency (80Hz above)
#define VFD_GRID_TICKS      (F_CPU / (VFD_GRID_MAX * VFD_GSF))

#define VFD_TMARK_ON         0x80  // Triangle Mark on
#define VFD_TMARK_OFF        0x00  // Triangle Mark of


#ifndef __ASSEMBLER__
/**
 *  Definitions for VFD physical characteristics 
 *  Change these definitions to adapt setting to your display
 */
#ifndef VFD_ITYPES
#define VFD_ITYPES
typedef struct coordinates
{
  uint8_t x;
  uint8_t y;
} coordinates;
#endif

//extern coordinates  _vfd_coord;
extern void vfd_init(void);
extern void vfd_clear(const uint8_t fillchar);
extern void vfd_clear_line(const uint8_t y);
extern void vfd_gotoxy(const uint8_t x, const uint8_t y);
extern void vfd_putc(const uint8_t c);
extern void vfd_puts(const unsigned char *str);
extern void vfd_puts_p(PGM_P str);
extern void vfd_tmark(const uint8_t x1, const uint8_t x2, const uint8_t attr);
#define vfd_puts_P(__s) vfd_puts_p(PSTR(__s));
#endif
#endif
/*
*EOF
*/
