# M202MD08A
Futaba M202MD08A(2x20) VFD GPIO Interface Demo

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

## Abbreviations
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

## tada
![alt text](https://github.com/boricha/M202MD08A/blob/master/src/tada.jpg)
## Pinout
![alt text](https://github.com/boricha/M202MD08A/blob/master/src/pinout.jpg)        
## Schematic
![alt text](https://github.com/boricha/M202MD08A/blob/schematic/schematic.jpg)
## Remove Parts(Optional)
![alt text](https://github.com/boricha/M202MD08A/blob/master/src/RemoveParts.jpg)
