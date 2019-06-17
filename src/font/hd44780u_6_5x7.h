#ifndef _HD44780U_6_5X7_
#define _HD44780U_6_5X7_

/**
 * THIS IS COLUMN MAJOR FONT
 * application : SAMSUNG KS0108, NOVATEK NT7502, EPSON SED1520 (Small LCD Panel 128x64,100x32 etc.)
 *
 * created with TDF(The Dot Factory) v.0.1.4
 * MSB First, Fixed Width, Fixed Height
 * written by ssk.
 *
 * Original Font Information : Font data for HD44780U A02 6pts
 * https://www.dafontfree.net/freefonts-5x8-lcd-hd44780u-a02-f91293.htm
 *
 * File Name           : hd44780u_6_5x7.h
 * Date                : 12:01 AM 2019-06-03
 *
*/
#include <avr/pgmspace.h>

#define FONT_FIXED_WIDTH	      5   // pixel
#define FONT_HEIGHT		   	      7   // pixel
#define FONT_FIRST_CHAR		      32          
#define FONT_END_CHAR 		      126 

const uint8_t hd44780u_6_5x7[] PROGMEM =
{
/**
 *  0,         // 0, font size high byte  (do not use  hear)
 *  0,         // 1, font size low  byte  (do not use  hear)
 *  5,         // 2, Character width  (pixel)
 *  7,         // 3, Character height (pixel)
 *  32,        // 4, First character  (' ')
 *  126,       // 5, End character    ( ~ )
*/    
	/* @0 ' ' (5 pixels wide) */
	//      
	//      
	//      
	//      
	//      
	//      
	//      
	//      
	0x00, 0x00, 0x00, 0x00, 0x00, 

	/* @5 '!' (5 pixels wide) */
	//   #  
	//   #  
	//   #  
	//   #  
	//   #  
	//      
	//   #  
	//      
	0x00, 0x00, 0x5F, 0x00, 0x00, 

	/* @10 '"' (5 pixels wide) */
	//  # # 
	//  # # 
	//  # # 
	//      
	//      
	//      
	//      
	//      
	0x00, 0x07, 0x00, 0x07, 0x00, 

	/* @15 '#' (5 pixels wide) */
	//  # # 
	//  # # 
	// #####
	//  # # 
	// #####
	//  # # 
	//  # # 
	//      
	0x14, 0x7F, 0x14, 0x7F, 0x14, 

	/* @20 '$' (5 pixels wide) */
	//   #  
	//  ####
	// # #  
	//  ### 
	//   # #
	// #### 
	//   #  
	//      
	0x24, 0x2A, 0x7F, 0x2A, 0x12, 

	/* @25 '%' (5 pixels wide) */
	// ##   
	// ##  #
	//    # 
	//   #  
	//  #   
	// #  ##
	//    ##
	//      
	0x23, 0x13, 0x08, 0x64, 0x62, 

	/* @30 '&' (5 pixels wide) */
	//  ##  
	// #  # 
	// # #  
	//  #   
	// # # #
	// #  # 
	//  ## #
	//      
	0x36, 0x49, 0x55, 0x22, 0x50, 

	/* @35 ''' (5 pixels wide) */
	//   #  
	//   #  
	//      
	//      
	//      
	//      
	//      
	//      
	0x00, 0x00, 0x03, 0x00, 0x00, 

	/* @40 '(' (5 pixels wide) */
	//    # 
	//   #  
	//  #   
	//  #   
	//  #   
	//   #  
	//    # 
	//      
	0x00, 0x1C, 0x22, 0x41, 0x00, 

	/* @45 ')' (5 pixels wide) */
	//  #   
	//   #  
	//    # 
	//    # 
	//    # 
	//   #  
	//  #   
	//      
	0x00, 0x41, 0x22, 0x1C, 0x00, 

	/* @50 '*' (5 pixels wide) */
	//      
	//   #  
	// # # #
	//  ### 
	// # # #
	//   #  
	//      
	//      
	0x14, 0x08, 0x3E, 0x08, 0x14, 

	/* @55 '+' (5 pixels wide) */
	//      
	//   #  
	//   #  
	// #####
	//   #  
	//   #  
	//      
	//      
	0x08, 0x08, 0x3E, 0x08, 0x08, 

	/* @60 ',' (5 pixels wide) */
	//      
	//      
	//      
	//      
	//  ##  
	//   #  
	//  #   
	//      
	0x00, 0x50, 0x30, 0x00, 0x00, 

	/* @65 '-' (5 pixels wide) */
	//      
	//      
	//      
	// #####
	//      
	//      
	//      
	//      
	0x08, 0x08, 0x08, 0x08, 0x08, 

	/* @70 '.' (5 pixels wide) */
	//      
	//      
	//      
	//      
	//      
	//  ##  
	//  ##  
	//      
	0x00, 0x60, 0x60, 0x00, 0x00, 

	/* @75 '/' (5 pixels wide) */
	//      
	//     #
	//    # 
	//   #  
	//  #   
	// #    
	//      
	//      
	0x20, 0x10, 0x08, 0x04, 0x02, 

	/* @80 '0' (5 pixels wide) */
	//  ### 
	// #   #
	// #  ##
	// # # #
	// ##  #
	// #   #
	//  ### 
	//      
	0x3E, 0x51, 0x49, 0x45, 0x3E, 

	/* @85 '1' (5 pixels wide) */
	//   #  
	//  ##  
	//   #  
	//   #  
	//   #  
	//   #  
	//  ### 
	//      
	0x00, 0x42, 0x7F, 0x40, 0x00, 

	/* @90 '2' (5 pixels wide) */
	//  ### 
	// #   #
	//     #
	//    # 
	//   #  
	//  #   
	// #####
	//      
	0x42, 0x61, 0x51, 0x49, 0x46, 

	/* @95 '3' (5 pixels wide) */
	// #####
	//    # 
	//   #  
	//    # 
	//     #
	// #   #
	//  ### 
	//      
	0x21, 0x41, 0x45, 0x4B, 0x31, 

	/* @100 '4' (5 pixels wide) */
	//    # 
	//   ## 
	//  # # 
	// #  # 
	// #####
	//    # 
	//    # 
	//      
	0x18, 0x14, 0x12, 0x7F, 0x10, 

	/* @105 '5' (5 pixels wide) */
	// #####
	// #    
	// #### 
	//     #
	//     #
	// #   #
	//  ### 
	//      
	0x27, 0x45, 0x45, 0x45, 0x39, 

	/* @110 '6' (5 pixels wide) */
	//   ## 
	//  #   
	// #    
	// #### 
	// #   #
	// #   #
	//  ### 
	//      
	0x3C, 0x4A, 0x49, 0x49, 0x30, 

	/* @115 '7' (5 pixels wide) */
	// #####
	// #   #
	//    # 
	//   #  
	//  #   
	//  #   
	//  #   
	//      
	0x03, 0x71, 0x09, 0x05, 0x03, 

	/* @120 '8' (5 pixels wide) */
	//  ### 
	// #   #
	// #   #
	//  ### 
	// #   #
	// #   #
	//  ### 
	//      
	0x36, 0x49, 0x49, 0x49, 0x36, 

	/* @125 '9' (5 pixels wide) */
	//  ### 
	// #   #
	// #   #
	//  ####
	//     #
	//    # 
	//  ##  
	//      
	0x06, 0x49, 0x49, 0x29, 0x1E, 

	/* @130 ':' (5 pixels wide) */
	//      
	//  ##  
	//  ##  
	//      
	//  ##  
	//  ##  
	//      
	//      
	0x00, 0x36, 0x36, 0x00, 0x00, 

	/* @135 ';' (5 pixels wide) */
	//      
	//  ##  
	//  ##  
	//      
	//  ##  
	//   #  
	//  #   
	//      
	0x00, 0x56, 0x36, 0x00, 0x00, 

	/* @140 '<' (5 pixels wide) */
	//    # 
	//   #  
	//  #   
	// #    
	//  #   
	//   #  
	//    # 
	//      
	0x08, 0x14, 0x22, 0x41, 0x00, 

	/* @145 '=' (5 pixels wide) */
	//      
	//      
	// #####
	//      
	// #####
	//      
	//      
	//      
	0x14, 0x14, 0x14, 0x14, 0x14, 

	/* @150 '>' (5 pixels wide) */
	//  #   
	//   #  
	//    # 
	//     #
	//    # 
	//   #  
	//  #   
	//      
	0x00, 0x41, 0x22, 0x14, 0x08, 

	/* @155 '?' (5 pixels wide) */
	//  ### 
	// #   #
	//     #
	//    # 
	//   #  
	//      
	//   #  
	//      
	0x02, 0x01, 0x51, 0x09, 0x06, 

	/* @160 '@' (5 pixels wide) */
	//  ### 
	// #   #
	//     #
	//  ## #
	// # # #
	// # # #
	//  ### 
	//      
	0x32, 0x49, 0x79, 0x41, 0x3E, 

	/* @165 'A' (5 pixels wide) */
	//  ### 
	// #   #
	// #   #
	// #   #
	// #####
	// #   #
	// #   #
	//      
	0x7E, 0x11, 0x11, 0x11, 0x7E, 

	/* @170 'B' (5 pixels wide) */
	// #### 
	// #   #
	// #   #
	// #### 
	// #   #
	// #   #
	// #### 
	//      
	0x7F, 0x49, 0x49, 0x49, 0x36, 

	/* @175 'C' (5 pixels wide) */
	//  ### 
	// #   #
	// #    
	// #    
	// #    
	// #   #
	//  ### 
	//      
	0x3E, 0x41, 0x41, 0x41, 0x22, 

	/* @180 'D' (5 pixels wide) */
	// #### 
	// #   #
	// #   #
	// #   #
	// #   #
	// #   #
	// #### 
	//      
	0x7F, 0x41, 0x41, 0x41, 0x3E, 

	/* @185 'E' (5 pixels wide) */
	// #####
	// #    
	// #    
	// #### 
	// #    
	// #    
	// #####
	//      
	0x7F, 0x49, 0x49, 0x49, 0x41, 

	/* @190 'F' (5 pixels wide) */
	// #####
	// #    
	// #    
	// #### 
	// #    
	// #    
	// #    
	//      
	0x7F, 0x09, 0x09, 0x09, 0x01, 

	/* @195 'G' (5 pixels wide) */
	//  ### 
	// #   #
	// #    
	// #  ##
	// #   #
	// #   #
	//  ####
	//      
	0x3E, 0x41, 0x41, 0x49, 0x7A, 

	/* @200 'H' (5 pixels wide) */
	// #   #
	// #   #
	// #   #
	// #####
	// #   #
	// #   #
	// #   #
	//      
	0x7F, 0x08, 0x08, 0x08, 0x7F, 

	/* @205 'I' (5 pixels wide) */
	//  ### 
	//   #  
	//   #  
	//   #  
	//   #  
	//   #  
	//  ### 
	//      
	0x00, 0x41, 0x7F, 0x41, 0x00, 

	/* @210 'J' (5 pixels wide) */
	//   ###
	//    # 
	//    # 
	//    # 
	//    # 
	// #  # 
	//  ##  
	//      
	0x20, 0x40, 0x41, 0x3F, 0x01, 

	/* @215 'K' (5 pixels wide) */
	// #   #
	// #  # 
	// # #  
	// ##   
	// # #  
	// #  # 
	// #   #
	//      
	0x7F, 0x08, 0x14, 0x22, 0x41, 

	/* @220 'L' (5 pixels wide) */
	// #    
	// #    
	// #    
	// #    
	// #    
	// #    
	// #####
	//      
	0x7F, 0x40, 0x40, 0x40, 0x40, 

	/* @225 'M' (5 pixels wide) */
	// #   #
	// ## ##
	// # # #
	// # # #
	// #   #
	// #   #
	// #   #
	//      
	0x7F, 0x02, 0x0C, 0x02, 0x7F, 

	/* @230 'N' (5 pixels wide) */
	// #   #
	// #   #
	// ##  #
	// # # #
	// #  ##
	// #   #
	// #   #
	//      
	0x7F, 0x04, 0x08, 0x10, 0x7F, 

	/* @235 'O' (5 pixels wide) */
	//  ### 
	// #   #
	// #   #
	// #   #
	// #   #
	// #   #
	//  ### 
	//      
	0x3E, 0x41, 0x41, 0x41, 0x3E, 

	/* @240 'P' (5 pixels wide) */
	// #### 
	// #   #
	// #   #
	// #### 
	// #    
	// #    
	// #    
	//      
	0x7F, 0x09, 0x09, 0x09, 0x06, 

	/* @245 'Q' (5 pixels wide) */
	//  ### 
	// #   #
	// #   #
	// #   #
	// # # #
	// #  # 
	//  ## #
	//      
	0x3E, 0x41, 0x51, 0x21, 0x5E, 

	/* @250 'R' (5 pixels wide) */
	// #### 
	// #   #
	// #   #
	// #### 
	// # #  
	// #  # 
	// #   #
	//      
	0x7F, 0x09, 0x19, 0x29, 0x46, 

	/* @255 'S' (5 pixels wide) */
	//  ### 
	// #   #
	// #    
	//  ### 
	//     #
	// #   #
	//  ### 
	//      
	0x26, 0x49, 0x49, 0x49, 0x32, 

	/* @260 'T' (5 pixels wide) */
	// #####
	//   #  
	//   #  
	//   #  
	//   #  
	//   #  
	//   #  
	//      
	0x01, 0x01, 0x7F, 0x01, 0x01, 

	/* @265 'U' (5 pixels wide) */
	// #   #
	// #   #
	// #   #
	// #   #
	// #   #
	// #   #
	//  ### 
	//      
	0x3F, 0x40, 0x40, 0x40, 0x3F, 

	/* @270 'V' (5 pixels wide) */
	// #   #
	// #   #
	// #   #
	// #   #
	// #   #
	//  # # 
	//   #  
	//      
	0x1F, 0x20, 0x40, 0x20, 0x1F, 

	/* @275 'W' (5 pixels wide) */
	// #   #
	// #   #
	// #   #
	// # # #
	// # # #
	// # # #
	//  # # 
	//      
	0x3F, 0x40, 0x38, 0x40, 0x3F, 

	/* @280 'X' (5 pixels wide) */
	// #   #
	// #   #
	//  # # 
	//   #  
	//  # # 
	// #   #
	// #   #
	//      
	0x63, 0x14, 0x08, 0x14, 0x63, 

	/* @285 'Y' (5 pixels wide) */
	// #   #
	// #   #
	// #   #
	//  # # 
	//   #  
	//   #  
	//   #  
	//      
	0x07, 0x08, 0x70, 0x08, 0x07, 

	/* @290 'Z' (5 pixels wide) */
	// #####
	//     #
	//    # 
	//   #  
	//  #   
	// #    
	// #####
	//      
	0x61, 0x51, 0x49, 0x45, 0x43, 

	/* @295 '[' (5 pixels wide) */
	//  ### 
	//  #   
	//  #   
	//  #   
	//  #   
	//  #   
	//  ### 
	//      
	0x00, 0x7F, 0x41, 0x41, 0x00, 

	/* @300 '\' (5 pixels wide) */
	//      
	// #    
	//  #   
	//   #  
	//    # 
	//     #
	//      
	//      
	0x02, 0x04, 0x08, 0x10, 0x20, 

	/* @305 ']' (5 pixels wide) */
	//  ### 
	//    # 
	//    # 
	//    # 
	//    # 
	//    # 
	//  ### 
	//      
	0x00, 0x41, 0x41, 0x7F, 0x00, 

	/* @310 '^' (5 pixels wide) */
	//   #  
	//  # # 
	// #   #
	//      
	//      
	//      
	//      
	//      
	0x04, 0x02, 0x01, 0x02, 0x04, 

	/* @315 '_' (5 pixels wide) */
	//      
	//      
	//      
	//      
	//      
	//      
	// #####
	//      
	0x40, 0x40, 0x40, 0x40, 0x40, 

	/* @320 '`' (5 pixels wide) */
	//  #   
	//   #  
	//    # 
	//      
	//      
	//      
	//      
	//      
	0x00, 0x01, 0x02, 0x04, 0x00, 

	/* @325 'a' (5 pixels wide) */
	//      
	//      
	//  ### 
	//     #
	//  ####
	// #   #
	//  ####
	//      
	0x20, 0x54, 0x54, 0x54, 0x78, 

	/* @330 'b' (5 pixels wide) */
	// #    
	// #    
	// # ## 
	// ##  #
	// #   #
	// #   #
	// #### 
	//      
	0x7F, 0x48, 0x44, 0x44, 0x38, 

	/* @335 'c' (5 pixels wide) */
	//      
	//      
	//  ### 
	// #    
	// #    
	// #   #
	//  ### 
	//      
	0x38, 0x44, 0x44, 0x44, 0x20, 

	/* @340 'd' (5 pixels wide) */
	//     #
	//     #
	//  ## #
	// #  ##
	// #   #
	// #   #
	//  ####
	//      
	0x38, 0x44, 0x44, 0x48, 0x7F, 

	/* @345 'e' (5 pixels wide) */
	//      
	//      
	//  ### 
	// #   #
	// #####
	// #    
	//  ### 
	//      
	0x38, 0x54, 0x54, 0x54, 0x18, 

	/* @350 'f' (5 pixels wide) */
	//   ## 
	//  #  #
	//  #   
	// ###  
	//  #   
	//  #   
	//  #   
	//      
	0x08, 0x7E, 0x09, 0x01, 0x02, 

	/* @355 'g' (5 pixels wide) */
	//      
	//      
	//  ####
	// #   #
	//  ####
	//     #
	//  ### 
	//      
	0x08, 0x54, 0x54, 0x54, 0x3C, 

	/* @360 'h' (5 pixels wide) */
	// #    
	// #    
	// # ## 
	// ##  #
	// #   #
	// #   #
	// #   #
	//      
	0x7F, 0x08, 0x04, 0x04, 0x78, 

	/* @365 'i' (5 pixels wide) */
	//   #  
	//      
	//   #  
	//  ##  
	//   #  
	//   #  
	//  ### 
	//      
	0x00, 0x48, 0x7D, 0x40, 0x00, 

	/* @370 'j' (5 pixels wide) */
	//    # 
	//      
	//   ## 
	//    # 
	//    # 
	// #  # 
	//  ##  
	//      
	0x20, 0x40, 0x44, 0x3D, 0x00, 

	/* @375 'k' (5 pixels wide) */
	// #    
	// #    
	// #  # 
	// # #  
	// ##   
	// # #  
	// #  # 
	//      
	0x7F, 0x10, 0x28, 0x44, 0x00, 

	/* @380 'l' (5 pixels wide) */
	//  ##  
	//   #  
	//   #  
	//   #  
	//   #  
	//   #  
	//  ### 
	//      
	0x00, 0x41, 0x7F, 0x40, 0x00, 

	/* @385 'm' (5 pixels wide) */
	//      
	//      
	// ## # 
	// # # #
	// # # #
	// # # #
	// # # #
	//      
	0x7C, 0x04, 0x78, 0x04, 0x78, 

	/* @390 'n' (5 pixels wide) */
	//      
	//      
	// # ## 
	// ##  #
	// #   #
	// #   #
	// #   #
	//      
	0x7C, 0x08, 0x04, 0x04, 0x78, 

	/* @395 'o' (5 pixels wide) */
	//      
	//      
	//  ### 
	// #   #
	// #   #
	// #   #
	//  ### 
	//      
	0x38, 0x44, 0x44, 0x44, 0x38, 

	/* @400 'p' (5 pixels wide) */
	//      
	//      
	// #### 
	// #   #
	// #### 
	// #    
	// #    
	//      
	0x7C, 0x14, 0x14, 0x14, 0x08, 

	/* @405 'q' (5 pixels wide) */
	//      
	//      
	//  ## #
	// #  ##
	//  ####
	//     #
	//     #
	//      
	0x08, 0x14, 0x14, 0x18, 0x7C, 

	/* @410 'r' (5 pixels wide) */
	//      
	//      
	// # ## 
	// ##  #
	// #    
	// #    
	// #    
	//     #
	0x7C, 0x08, 0x04, 0x04, 0x88, 

	/* @415 's' (5 pixels wide) */
	//      
	//      
	//  ### 
	// #    
	//  ### 
	//     #
	// #### 
	//      
	0x48, 0x54, 0x54, 0x54, 0x20, 

	/* @420 't' (5 pixels wide) */
	//  #   
	//  #   
	// ###  
	//  #   
	//  #   
	//  #  #
	//   ## 
	//      
	0x04, 0x3F, 0x44, 0x40, 0x20, 

	/* @425 'u' (5 pixels wide) */
	//      
	//      
	// #   #
	// #   #
	// #   #
	// #  ##
	//  ## #
	//      
	0x3C, 0x40, 0x40, 0x20, 0x7C, 

	/* @430 'v' (5 pixels wide) */
	//      
	//      
	// #   #
	// #   #
	// #   #
	//  # # 
	//   #  
	//      
	0x1C, 0x20, 0x40, 0x20, 0x1C, 

	/* @435 'w' (5 pixels wide) */
	//      
	//      
	// #   #
	// #   #
	// # # #
	// # # #
	//  # # 
	//      
	0x3C, 0x40, 0x30, 0x40, 0x3C, 

	/* @440 'x' (5 pixels wide) */
	//      
	//      
	// #   #
	//  # # 
	//   #  
	//  # # 
	// #   #
	//      
	0x44, 0x28, 0x10, 0x28, 0x44, 

	/* @445 'y' (5 pixels wide) */
	//      
	//      
	// #   #
	// #   #
	//  ####
	//     #
	//  ### 
	//      
	0x0C, 0x50, 0x50, 0x50, 0x3C, 

	/* @450 'z' (5 pixels wide) */
	//      
	//      
	// #####
	//    # 
	//   #  
	//  #   
	// #####
	//      
	0x44, 0x64, 0x54, 0x4C, 0x44, 

	/* @455 '{' (5 pixels wide) */
	//    # 
	//   #  
	//   #  
	//  #   
	//   #  
	//   #  
	//    # 
	//      
	0x00, 0x08, 0x36, 0x41, 0x00, 

	/* @460 '|' (5 pixels wide) */
	//   #  
	//   #  
	//   #  
	//   #  
	//   #  
	//   #  
	//   #  
	//      
	0x00, 0x00, 0x7F, 0x00, 0x00, 

	/* @465 '}' (5 pixels wide) */
	//  #   
	//   #  
	//   #  
	//    # 
	//   #  
	//   #  
	//  #   
	//      
	0x00, 0x41, 0x36, 0x08, 0x00, 

	/* @470 '~' (5 pixels wide) */
	//      
	//      
	//      
	//  ## #
	// #  # 
	//      
	//      
	//      
	0x10, 0x08, 0x08, 0x10, 0x08,     
};
#endif