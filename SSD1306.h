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
/*
 * Chip Number : SSD1306
 * Description : Monochrome 0.96" 128x64 OLED graphic display
 * Manufacture : Adafruit
 * Web Site    : http://www.adafruit.com/products/326
 * Interfaces  : I2C or SPI
*/

#ifndef SSD1306_H
#define SSD1306_H

#include "ezCOMM.h"
#include <cytypes.h>
#include "TypeDefine.h"


/*=========================================================================
    SSD1306 Displays
    -----------------------------------------------------------------------
    The driver is used in multiple displays (128x64, 128x32, etc.).
    Select the appropriate display below to create an appropriately
    sized framebuffer, etc.

    SSD1306_128_64  128x64 pixel display

    SSD1306_128_32  128x32 pixel display

    You also need to set the LCDWIDTH and LCDHEIGHT defines to an
    appropriate size

    -----------------------------------------------------------------------*/
/*=========================================================================*/
//------------------------------------------------------------
// Defines ///////////////////////////////////////////////////
//------------------------------------------------------------

typedef enum{
    SSD1306_SA0_0, // SA0 = 0
    SSD1306_SA0_1  // SA0 = 1
} SSD1306_I2C_ADDRESS;

#define SSD1306_DEFAULT_I2C_ADDRESS             SSD1306_I2C_Address_2
// Address for 128x32 is 0x3C
// Address for 128x32 is 0x3D (default) or 0x3C (if SA0 is grounded)

typedef enum {
    SSD1306_LCD_128_64 = 0x64,
    SSD1306_LCD_128_32 = 0x32
} SSD1306_LCD_TYPE;

//Set tme interval between each scroll step in term of frame frequency
#define SSD1306_SCROLL_INTERVAL_2_FRAMES        0b111
#define SSD1306_SCROLL_INTERVAL_3_FRAMES        0b100
#define SSD1306_SCROLL_INTERVAL_4_FRAMES        0b101
#define SSD1306_SCROLL_INTERVAL_5_FRAMES        0b000
#define SSD1306_SCROLL_INTERVAL_25_FRAMES       0b110
#define SSD1306_SCROLL_INTERVAL_64_FRAMES       0b001
#define SSD1306_SCROLL_INTERVAL_128_FRAMES      0b010
#define SSD1306_SCROLL_INTERVAL_256_FRAMES      0b011

typedef struct SSD1306_CONFIG{
    union{
    SSD1306_I2C_ADDRESS     I2C;
    uint8_t                 SPI;
    } Address;
    SSD1306_LCD_TYPE        LCDType;

} SSD1306_CONFIG;

typedef SSD1306_CONFIG * PSSD1306_CONFIG;

//------------------------------------------------------------
// Public Data Structure /////////////////////////////////////
//------------------------------------------------------------
typedef struct EZOBJ_SSD1306 {
    void*           PrivateData;

    SSD1306_CONFIG  Config;

} EZOBJ_SSD1306;

typedef EZOBJ_SSD1306 * PEZOBJ_SSD1306;

//------------------------------------------------------------
// Public Functions //////////////////////////////////////////
//------------------------------------------------------------

PEZOBJ_SSD1306 SSD1306_Create();
void            SSD1306_Release(PEZOBJ_SSD1306 ssd1306);

//void            SSD1306_SetIoAddress(PEZOBJ_SSD1306 ssd1306, uint16 addr);

void            SSD1306_ConnectResetPin(PEZOBJ_SSD1306 ssd1306, PEZOBJ_IO rst);
void            SSD1306_ConnectDataCmdPin(PEZOBJ_SSD1306 ssd1306, PEZOBJ_IO dc);
void            SSD1306_ConnectI2C(PEZOBJ_SSD1306 ssd1306, PEZOBJ_I2C i2c);
void            SSD1306_ConnectSPI(PEZOBJ_SSD1306 ssd1306, PEZOBJ_SPI spi);
// void            SSD1306_SetLCDType(PEZOBJ_SSD1306 ssd1306, enum SSD1306_LCD_TYPE type);
void            SSD1306_SetLCDFont(PEZOBJ_SSD1306 ssd1306, uint8* font, uint8 fontWidth);

bool            SSD1306_Init (PEZOBJ_SSD1306 ssd1306);
void            SSD1306_Start(PEZOBJ_SSD1306 ssd1306);

void            SSD1306_ClearDisplay(PEZOBJ_SSD1306 ssd1306);
void            SSD1306_ClearBuffer(PEZOBJ_SSD1306 ssd1306);

void            SSD1306_FillDisplay(PEZOBJ_SSD1306 ssd1306);
//void            SSD1306_DisplayBuffer(PEZOBJ_SSD1306 ssd1306);
void            SSD1306_Display(PEZOBJ_SSD1306 ssd1306);

void            SSD1306_SetDisplayPower(PEZOBJ_SSD1306 ssd1306, bool sw);

void            SSD1306_SetScrollInterval(PEZOBJ_SSD1306 ssd1306, uint8 value);
void            SSD1306_StartScrollRight(PEZOBJ_SSD1306 ssd1306, uint8 start, uint8 stop);
void            SSD1306_StartScrollLeft(PEZOBJ_SSD1306 ssd1306, uint8 start, uint8 stop);

void            SSD1306_StartScrollDiagRight(PEZOBJ_SSD1306 ssd1306, uint8 start, uint8 stop);
void            SSD1306_StartScrollDiagLeft(PEZOBJ_SSD1306 ssd1306, uint8 start, uint8 stop);
void            SSD1306_StopScroll(PEZOBJ_SSD1306 ssd1306);

void            SSD1306_Position(PEZOBJ_SSD1306 ssd1306, uint8 row, uint8 col);
void            SSD1306_PrintChar(PEZOBJ_SSD1306 ssd1306, char ch);
void            SSD1306_PrintString(PEZOBJ_SSD1306 ssd1306, const char text[]);
void            SSD1306_PrintStringLn(PEZOBJ_SSD1306 ssd1306, const char text[]);
void            SSD1306_PrintBuffer(PEZOBJ_SSD1306 ssd1306, uint8 buf[], uint16 len);


#endif







//[] END OF FILE
//
