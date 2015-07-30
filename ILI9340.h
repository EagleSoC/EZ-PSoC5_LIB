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

#ifndef ILI9340_H
#define ILI9340_H

#include "ezCOMM.h"
#include <cytypes.h>
#include "TypeDefine.h"
#include "ezWINDOW.h"
#include "ezCOLOR.h"


//------------------------------------------------------------
// Defines ///////////////////////////////////////////////////
//------------------------------------------------------------
// Color Definition
/*
#define ILI9340_BLACK       0x0000
#define ILI9340_BLUE        0x001F
#define ILI9340_RED         0xF800
#define ILI9340_GREEN       0x07E0
#define ILI9340_CYAN        0x07FF
#define ILI9340_MAGENTA     0xF81F
#define ILI9340_YELLOW      0xFFE0
#define ILI9340_WHITE       0xFFFF
*/






//------------------------------------------------------------
// Public Data Structure /////////////////////////////////////
//------------------------------------------------------------

typedef struct EZOBJ_ILI9340 {
    void*       PrivateData;


} EZOBJ_ILI9340;

typedef EZOBJ_ILI9340 * PEZOBJ_ILI9340;


//------------------------------------------------------------
// Public Functions //////////////////////////////////////////
//------------------------------------------------------------
PEZOBJ_ILI9340      ILI9340_Create();
void                ILI9340_Release(PEZOBJ_ILI9340 ili9340);

void                ILI9340_ConnectResetPin(PEZOBJ_ILI9340 ili9340, PEZOBJ_IO rst);
void                ILI9340_ConnectDataCmdPin(PEZOBJ_ILI9340 ili9340, PEZOBJ_IO dc);
void                ILI9340_ConnectSPI(PEZOBJ_ILI9340 ili9340, PEZOBJ_SPI isp);
void                ILI9340_SetLCDFont(PEZOBJ_ILI9340 ili9340, uint8* font, uint8 fontWidth);

bool                ILI9340_Init (PEZOBJ_ILI9340 ili9340);
void                ILI9340_Start(PEZOBJ_ILI9340 ili9340);

int                 ILI9340_GetDeviceID(PEZOBJ_ILI9340 ili9340);










#endif

/* [] END OF FILE */

