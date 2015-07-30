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

#ifndef EZWINDOW_H
#define EZWINDOW_H

#include "ezCOMM.h"
#include "ezCOLOR.h"
#include <cytypes.h>
#include "TypeDefine.h"

//------------------------------------------------------------
// Defines ///////////////////////////////////////////////////
//------------------------------------------------------------
#ifndef swap
#define swap(a, b) { int16_t t = a; a = b; b = t; }
#endif


//------------------------------------------------------------
// Public Data Structure /////////////////////////////////////
//------------------------------------------------------------


typedef struct  ezWINDOW_FUNCTIONCALLLIST{
    int     DeviceID;
    void    (* ezWINDOW_DrawPixel)(void* ezObj, int16_t x, int16_t y, uint32_t color);
    void    (* ezWINDOW_DrawFastVLine)(void* ezObj, int16_t x, int16_t y, int16_t h, uint32_t color);
    void    (* ezWINDOW_DrawFastHLine)(void* ezObj, int16_t x, int16_t y, int16_t w, uint32_t color);
    void    (* ezWINDOW_FillScreen)(void* ezObj, uint32_t color);
    void    (* ezWINDOW_FillRect)(void* ezObj, int16_t x, int16_t y, int16_t w, int16_t h, uint32_t color);
    void    (* ezWINDOW_InvertDisplay)(void* ezObj, bool i);
    void    (* ezWINDOW_Display)(void* ezObj);
} ezWINDOW_FUNCTIONCALLLIST;

typedef ezWINDOW_FUNCTIONCALLLIST * PezWINDOW_FUNCTIONCALLLIST;


//------------------------------------------------------------
// Public Functions //////////////////////////////////////////
//------------------------------------------------------------
void            ezWINDOW_Create();
void            ezWINDOW_Release();

int             ezWINDOW_GetDeviceCount();
void            ezWINDOW_Register(PSinglelLink PNewRegLink);


// Virtual
void            ezWINDOW_ClearDisplay(int deviceID);
void            ezWINDOW_DrawPixel(int deviceID, int16_t x, int16_t y, uint32_t color);
void            ezWINDOW_DrawFastVLine(int deviceID, int16_t x, int16_t y, int16_t h, uint32_t color);
void            ezWINDOW_DrawFastHLine(int deviceID, int16_t x, int16_t y, int16_t w, uint32_t color);
void            ezWINDOW_FillScreen(int deviceID, uint32_t color);
void            ezWINDOW_FillRect(int deviceID, int16_t x, int16_t y, int16_t w, int16_t h, uint32_t color);
void            ezWINDOW_InvertDisplay(int deviceID, bool i);

// for ezWINDOW
void            ezWINDOW_DrawLine(int deviceID, int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint32_t color);

void            ezWINDOW_DrawCircle(int deviceID, int16_t x0, int16_t y0, int16_t r, uint32_t color);
void            ezWINDOW_DrawCircleHelper(int deviceID, int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint32_t color);

void            ezWINDOW_FillCircle(int deviceID, int16_t x0, int16_t y0, int16_t r, uint32_t color);
void            ezWINDOW_FillCircleHelper(int deviceID, int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint32_t color);

void            ezWINDOW_DrawTriangle(int deviceID, int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint32_t color);
void            ezWINDOW_FillTriangle(int deviceID, int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint32_t color);

void            ezWINDOW_DrawRoundRect(int deviceID, int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint32_t color);
void            ezWINDOW_FillRoundRect(int deviceID, int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint32_t color);

void            ezWINDOW_DrawBitmap(int deviceID, int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint32_t color);
void            ezWINDOW_DrawChar(int deviceID, int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint32_t color);

void            ezWINDOW_SetCursor(int deviceID);
void            ezWINDOW_SetTextColor(int deviceID);
void            ezWINDOW_SetTextColorAndBackground(int deviceID);
void            ezWINDOW_SetTextSize(int deviceID);
void            ezWINDOW_SetTextWrap(int deviceID);
void            ezWINDOW_SetRotation(int deviceID, uint8_t m);






#endif


/* [] END OF FILE */

