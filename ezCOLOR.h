/* ========================================
 *
 * Copyright AirSupplyLab.com, 2013
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF AirSupplyLab.com.
 *
 * Airs Lin
 * ========================================
*/

//------------------------------------------------------------
// *.h ///////////////////////////////////////////////////////
//------------------------------------------------------------

#ifndef EZCOLOR_H
#define EZCOLOR_H

#include <cytypes.h>
#include "TypeDefine.h"

//------------------------------------------------------------
// Defines ///////////////////////////////////////////////////
//------------------------------------------------------------

#define     ezCOLOR_RGB_BLACK 	            0x000000 	// RGB(0,0,0)
#define     ezCOLOR_RGB_WHITE 	            0xFFFFFF 	// RGB(255,255,255)
#define     ezCOLOR_RGB_RED 	            0xFF0000 	// RGB(255,0,0)
#define     ezCOLOR_RGB_LIME 	            0x00FF00 	// RGB(0,255,0)
#define     ezCOLOR_RGB_BLUE 	            0x0000FF 	// RGB(0,0,255)
#define     ezCOLOR_RGB_YELLOW 	            0xFFFF00 	// RGB(255,255,0)
#define     ezCOLOR_RGB_CYAN 	            0x00FFFF 	// RGB(0,255,255)
#define     ezCOLOR_RGB_MAGENTA 	        0xFF00FF 	// RGB(255,0,255)
#define     ezCOLOR_RGB_SILVER 	            0xC0C0C0 	// RGB(192,192,192)
#define     ezCOLOR_RGB_GRAY 	            0x808080 	// RGB(128,128,128)
#define     ezCOLOR_RGB_MAROON 	            0x800000 	// RGB(128,0,0)
#define     ezCOLOR_RGB_OLIVE 	            0x808000 	// RGB(128,128,0)
#define     ezCOLOR_RGB_GREEN 	            0x008000 	// RGB(0,128,0)
#define     ezCOLOR_RGB_PURPLE 	            0x800080 	// RGB(128,0,128)
#define     ezCOLOR_RGB_TEAL 	            0x008080 	// RGB(0,128,128)
#define     ezCOLOR_RGB_NAVY 	            0x000080 	// RGB(0,0,128)


#define     ezCOLOR_RGB_MAROON 	            0x800000 	// RGB(128,0,0)
#define     ezCOLOR_RGB_DARK_RED 	        0x8B0000 	// RGB(139,0,0)
#define     ezCOLOR_RGB_BROWN 	            0xA52A2A 	// RGB(165,42,42)
#define     ezCOLOR_RGB_FIREBRICK 	        0xB22222 	// RGB(178,34,34)
#define     ezCOLOR_RGB_CRIMSON 	        0xDC143C 	// RGB(220,20,60)
#define     ezCOLOR_RGB_RED 	            0xFF0000 	// RGB(255,0,0)
#define     ezCOLOR_RGB_TOMATO 	            0xFF6347 	// RGB(255,99,71)
#define     ezCOLOR_RGB_CORAL 	            0xFF7F50 	// RGB(255,127,80)
#define     ezCOLOR_RGB_INDIAN_RED 	        0xCD5C5C 	// RGB(205,92,92)


#define     ezCOLOR_RGB_LIGHT_CORAL 	    0xF08080 	// RGB(240,128,128)
#define     ezCOLOR_RGB_DARK_SALMON 	    0xE9967A 	// RGB(233,150,122)
#define     ezCOLOR_RGB_SALMON 	            0xFA8072 	// RGB(250,128,114)
#define     ezCOLOR_RGB_LIGHT_SALMON 	    0xFFA07A 	// RGB(255,160,122)
#define     ezCOLOR_RGB_ORANGE_RED 	        0xFF4500 	// RGB(255,69,0)
#define     ezCOLOR_RGB_DARK_ORANGE 	    0xFF8C00 	// RGB(255,140,0)
#define     ezCOLOR_RGB_ORANGE 	            0xFFA500 	// RGB(255,165,0)
#define     ezCOLOR_RGB_GOLD 	            0xFFD700 	// RGB(255,215,0)
#define     ezCOLOR_RGB_DARK_GOLDEN_ROD 	0xB8860B 	// RGB(184,134,11)
#define     ezCOLOR_RGB_GOLDEN_ROD 	        0xDAA520 	// RGB(218,165,32)
#define     ezCOLOR_RGB_PALE_GOLDEN_ROD 	0xEEE8AA 	// RGB(238,232,170)
#define     ezCOLOR_RGB_DARK_KHAKI 	        0xBDB76B 	// RGB(189,183,107)
#define     ezCOLOR_RGB_KHAKI 	            0xF0E68C 	// RGB(240,230,140)
#define     ezCOLOR_RGB_OLIVE 	            0x808000 	// RGB(128,128,0)
//#define     ezCOLOR_RGB_YELLOW 	            0xFFFF00 	// RGB(255,255,0)
#define     ezCOLOR_RGB_YELLOW_GREEN 	    0x9ACD32 	// RGB(154,205,50)
#define     ezCOLOR_RGB_DARK_OLIVE_GREEN 	0x556B2F 	// RGB(85,107,47)
#define     ezCOLOR_RGB_OLIVE_DRAB 	        0x6B8E23 	// RGB(107,142,35)
#define     ezCOLOR_RGB_LAWN_GREEN 	        0x7CFC00 	// RGB(124,252,0)
#define     ezCOLOR_RGB_CHART_REUSE 	    0x7FFF00 	// RGB(127,255,0)
#define     ezCOLOR_RGB_GREEN_YELLOW 	    0xADFF2F 	// RGB(173,255,47)
#define     ezCOLOR_RGB_DARK_GREEN 	        0x006400 	// RGB(0,100,0)
#define     ezCOLOR_RGB_GREEN 	            0x008000 	// RGB(0,128,0)
#define     ezCOLOR_RGB_FOREST_GREEN 	    0x228B22 	// RGB(34,139,34)
#define     ezCOLOR_RGB_LIME 	            0x00FF00 	// RGB(0,255,0)
#define     ezCOLOR_RGB_LIME_GREEN 	        0x32CD32 	// RGB(50,205,50)
#define     ezCOLOR_RGB_LIGHT_GREEN 	    0x90EE90 	// RGB(144,238,144)
#define     ezCOLOR_RGB_PALE_GREEN 	        0x98FB98 	// RGB(152,251,152)
#define     ezCOLOR_RGB_DARK_SEA_GREEN 	    0x8FBC8F 	// RGB(143,188,143)
#define     ezCOLOR_RGB_MEDIUM_SPRING_GREEN 0x00FA9A 	// RGB(0,250,154)
#define     ezCOLOR_RGB_SPRING_GREEN 	    0x00FF7F 	// RGB(0,255,127)
#define     ezCOLOR_RGB_SEA_GREEN 	        0x2E8B57 	// RGB(46,139,87)
#define     ezCOLOR_RGB_MEDIUM_AQUA_MARINE 	0x66CDAA 	// RGB(102,205,170)
#define     ezCOLOR_RGB_MEDIUM_SEA_GREEN 	0x3CB371 	// RGB(60,179,113)
#define     ezCOLOR_RGB_LIGHT_SEA_GREEN 	0x20B2AA 	// RGB(32,178,170)
#define     ezCOLOR_RGB_DARK_SLATE_GRAY 	0x2F4F4F 	// RGB(47,79,79)
#define     ezCOLOR_RGB_TEAL 	            0x008080 	// RGB(0,128,128)
#define     ezCOLOR_RGB_DARK_CYAN 	        0x008B8B 	// RGB(0,139,139)
#define     ezCOLOR_RGB_AQUA 	            0x00FFFF 	// RGB(0,255,255)
#define     ezCOLOR_RGB_CYAN 	            0x00FFFF 	// RGB(0,255,255)
#define     ezCOLOR_RGB_LIGHT_CYAN 	        0xE0FFFF 	// RGB(224,255,255)
#define     ezCOLOR_RGB_DARK_TURQUOISE 	    0x00CED1 	// RGB(0,206,209)
#define     ezCOLOR_RGB_TURQUOISE 	        0x40E0D0 	// RGB(64,224,208)
#define     ezCOLOR_RGB_MEDIUM_TURQUOISE 	0x48D1CC 	// RGB(72,209,204)
#define     ezCOLOR_RGB_PALE_TURQUOISE 	    0xAFEEEE 	// RGB(175,238,238)
#define     ezCOLOR_RGB_AQUA_MARINE 	    0x7FFFD4 	// RGB(127,255,212)
#define     ezCOLOR_RGB_POWDER_BLUE 	    0xB0E0E6 	// RGB(176,224,230)
#define     ezCOLOR_RGB_CADET_BLUE 	        0x5F9EA0 	// RGB(95,158,160)
#define     ezCOLOR_RGB_STEEL_BLUE 	        0x4682B4 	// RGB(70,130,180)
#define     ezCOLOR_RGB_CORN_FLOWER BLUE 	0x6495ED 	// RGB(100,149,237)
#define     ezCOLOR_RGB_DEEP_SKY_BLUE 	    0x00BFFF 	// RGB(0,191,255)
#define     ezCOLOR_RGB_DODGER_BLUE 	    0x1E90FF 	// RGB(30,144,255)
#define     ezCOLOR_RGB_LIGHT_BLUE 	        0xADD8E6 	// RGB(173,216,230)
#define     ezCOLOR_RGB_SKY_BLUE 	        0x87CEEB 	// RGB(135,206,235)
#define     ezCOLOR_RGB_LIGHT_SKY_BLUE 	    0x87CEFA 	// RGB(135,206,250)
#define     ezCOLOR_RGB_MIDNIGHT_BLUE 	    0x191970 	// RGB(25,25,112)
#define     ezCOLOR_RGB_NAVY 	            0x000080 	// RGB(0,0,128)
#define     ezCOLOR_RGB_DARK_BLUE 	        0x00008B 	// RGB(0,0,139)
#define     ezCOLOR_RGB_MEDIUM_BLUE 	    0x0000CD 	// RGB(0,0,205)
#define     ezCOLOR_RGB_BLUE 	            0x0000FF 	// RGB(0,0,255)
#define     ezCOLOR_RGB_ROYAL_BLUE 	        0x4169E1 	// RGB(65,105,225)
#define     ezCOLOR_RGB_BLUE_VIOLET 	    0x8A2BE2 	// RGB(138,43,226)
#define     ezCOLOR_RGB_INDIGO 	            0x4B0082 	// RGB(75,0,130)
#define     ezCOLOR_RGB_DARK_SLATE_BLUE 	0x483D8B 	// RGB(72,61,139)
#define     ezCOLOR_RGB_SLATE_BLUE 	        0x6A5ACD 	// RGB(106,90,205)
#define     ezCOLOR_RGB_MEDIUM_SLATE_BLUE 	0x7B68EE 	// RGB(123,104,238)
#define     ezCOLOR_RGB_MEDIUM_PURPLE 	    0x9370DB 	// RGB(147,112,219)
#define     ezCOLOR_RGB_DARK_MAGENTA 	    0x8B008B 	// RGB(139,0,139)
#define     ezCOLOR_RGB_DARK_VIOLET 	    0x9400D3 	// RGB(148,0,211)
#define     ezCOLOR_RGB_DARK_ORCHID 	    0x9932CC 	// RGB(153,50,204)
#define     ezCOLOR_RGB_MEDIUM_ORCHID 	    0xBA55D3 	// RGB(186,85,211)
#define     ezCOLOR_RGB_PURPLE 	            0x800080 	// RGB(128,0,128)
#define     ezCOLOR_RGB_THISTLE 	        0xD8BFD8 	// RGB(216,191,216)
#define     ezCOLOR_RGB_PLUM 	            0xDDA0DD 	// RGB(221,160,221)
#define     ezCOLOR_RGB_VIOLET 	            0xEE82EE 	// RGB(238,130,238)
#define     ezCOLOR_RGB_MAGENTA	            0xFF00FF 	// RGB(255,0,255)
#define     ezCOLOR_RGB_ORCHID 	            0xDA70D6 	// RGB(218,112,214)
#define     ezCOLOR_RGB_MEDIUM_VIOLET_RED 	0xC71585 	// RGB(199,21,133)
#define     ezCOLOR_RGB_PALE_VIOLET_RED 	0xDB7093 	// RGB(219,112,147)
#define     ezCOLOR_RGB_DEEP_PINK 	        0xFF1493 	// RGB(255,20,147)
#define     ezCOLOR_RGB_HOT_PINK 	        0xFF69B4 	// RGB(255,105,180)
#define     ezCOLOR_RGB_LIGHT_PINK 	        0xFFB6C1 	// RGB(255,182,193)
#define     ezCOLOR_RGB_PINK 	            0xFFC0CB 	// RGB(255,192,203)
#define     ezCOLOR_RGB_ANTIQUE_WHITE 	    0xFAEBD7 	// RGB(250,235,215)
#define     ezCOLOR_RGB_BEIGE 	            0xF5F5DC 	// RGB(245,245,220)
#define     ezCOLOR_RGB_BISQUE 	            0xFFE4C4 	// RGB(255,228,196)
#define     ezCOLOR_RGB_BLANCHED_ALMOND 	0xFFEBCD 	// RGB(255,235,205)
#define     ezCOLOR_RGB_WHEAT 	            0xF5DEB3 	// RGB(245,222,179)
#define     ezCOLOR_RGB_CORN_SILK 	        0xFFF8DC 	// RGB(255,248,220)
#define     ezCOLOR_RGB_LEMON_CHIFFON 	    0xFFFACD 	// RGB(255,250,205)
#define     ezCOLOR_RGB_LIGHT_GOLDEN_ROD    0xFAFAD2 	// RGB(250,250,210)
#define     ezCOLOR_RGB_LIGHT_YELLOW 	    0xFFFFE0 	// RGB(255,255,224)
#define     ezCOLOR_RGB_SADDLE_BROWN 	    0x8B4513 	// RGB(139,69,19)
#define     ezCOLOR_RGB_SIENNA 	            0xA0522D 	// RGB(160,82,45)
#define     ezCOLOR_RGB_CHOCOLATE 	        0xD2691E 	// RGB(210,105,30)
#define     ezCOLOR_RGB_PERU                0xCD853F 	// RGB(205,133,63)
#define     ezCOLOR_RGB_SANDY_BROWN 	    0xF4A460 	// RGB(244,164,96)
#define     ezCOLOR_RGB_BURLY_WOOD 	        0xDEB887 	// RGB(222,184,135)
#define     ezCOLOR_RGB_TAN 	            0xD2B48C 	// RGB(210,180,140)
#define     ezCOLOR_RGB_ROSY_BROWN 	        0xBC8F8F 	// RGB(188,143,143)
#define     ezCOLOR_RGB_MOCCASIN 	        0xFFE4B5 	// RGB(255,228,181)
#define     ezCOLOR_RGB_NAVAJO_WHITE 	    0xFFDEAD 	// RGB(255,222,173)
#define     ezCOLOR_RGB_PEACH_PUFF 	        0xFFDAB9 	// RGB(255,218,185)
#define     ezCOLOR_RGB_MISTY_ROSE 	        0xFFE4E1 	// RGB(255,228,225)
#define     ezCOLOR_RGB_LAVENDER_BLUSH 	    0xFFF0F5 	// RGB(255,240,245)
#define     ezCOLOR_RGB_LINEN 	            0xFAF0E6 	// RGB(250,240,230)
#define     ezCOLOR_RGB_OLD_LACE 	        0xFDF5E6 	// RGB(253,245,230)
#define     ezCOLOR_RGB_PAPAYA_WHIP 	    0xFFEFD5 	// RGB(255,239,213)
#define     ezCOLOR_RGB_SEA_SHELL 	        0xFFF5EE 	// RGB(255,245,238)
#define     ezCOLOR_RGB_MINT_CREAM 	        0xF5FFFA 	// RGB(245,255,250)
#define     ezCOLOR_RGB_SLATE_GRAY 	        0x708090 	// RGB(112,128,144)
#define     ezCOLOR_RGB_LIGHT_SLATE GRAY 	0x778899 	// RGB(119,136,153)
#define     ezCOLOR_RGB_LIGHT_STEEL BLUE 	0xB0C4DE 	// RGB(176,196,222)
#define     ezCOLOR_RGB_LAVENDER 	        0xE6E6FA 	// RGB(230,230,250)
#define     ezCOLOR_RGB_FLORAL_WHITE 	    0xFFFAF0 	// RGB(255,250,240)
#define     ezCOLOR_RGB_ALICE_BLUE 	        0xF0F8FF 	// RGB(240,248,255)
#define     ezCOLOR_RGB_GHOST_WHITE 	    0xF8F8FF 	// RGB(248,248,255)
#define     ezCOLOR_RGB_HONEYDEW 	        0xF0FFF0 	// RGB(240,255,240)
#define     ezCOLOR_RGB_IVORY 	            0xFFFFF0 	// RGB(255,255,240)
#define     ezCOLOR_RGB_AZURE 	            0xF0FFFF 	// RGB(240,255,255)
#define     ezCOLOR_RGB_SNOW 	            0xFFFAFA 	// RGB(255,250,250)
#define     ezCOLOR_RGB_BLACK 	            0x000000 	// RGB(0,0,0)
#define     ezCOLOR_RGB_DIM_GRAY            0x696969 	// RGB(105,105,105)
#define     ezCOLOR_RGB_GRAY 	            0x808080 	// RGB(128,128,128)
#define     ezCOLOR_RGB_DARK_GRAY 	        0xA9A9A9 	// RGB(169,169,169)
#define     ezCOLOR_RGB_SILVER 	            0xC0C0C0 	// RGB(192,192,192)
#define     ezCOLOR_RGB_LIGHT_GRAY 	        0xD3D3D3 	// RGB(211,211,211)
#define     ezCOLOR_RGB_GAINSBORO 	        0xDCDCDC 	// RGB(220,220,220)
#define     ezCOLOR_RGB_WHITE_SMOKE 	    0xF5F5F5 	// RGB(245,245,245)
#define     ezCOLOR_RGB_WHITE 	            0xFFFFFF    // RGB(255,255,255)
#define     ezCOLOR_RGB_INVERSE             0x10000000

//------------------------------------------------------------
// Public Data Structure /////////////////////////////////////
//------------------------------------------------------------

//------------------------------------------------------------
// Public Functions //////////////////////////////////////////
//------------------------------------------------------------
uint16_t    ezCOLOR_rgb_RGB565(uint8_t r, uint8_t g, uint8_t b);
uint16_t    ezCOLOR_RGB888_RGB565(uint32_t rgb);


#endif
/* [] END OF FILE */
