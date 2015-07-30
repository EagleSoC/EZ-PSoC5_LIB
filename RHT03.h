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
 * Chip Number : RHT103
 * Description : Digital relative humidity & temperature sensor
 * Manufacture : Maxdetect
 * Web Site    : http://www.humiditycn.com/
 * Interfaces  : Max 1-Wire
*/

//------------------------------------------------------------
// *.h ///////////////////////////////////////////////////////
//------------------------------------------------------------

#ifndef RHT03_H
#define RHT03_H

#include "ezCOMM.h"
#include "ez1WIRE.h"
#include <cytypes.h>
#include "TypeDefine.h"

//------------------------------------------------------------
// Defines ///////////////////////////////////////////////////
//------------------------------------------------------------


//------------------------------------------------------------
// Public Data Structure /////////////////////////////////////
//------------------------------------------------------------

typedef struct EZOBJ_RHT03 {
    void*       PrivateData;

    float       TemperatureC;
    float       TemperatureF;
    float       HumidityRate;

} EZOBJ_RHT03;

typedef EZOBJ_RHT03 * PEZOBJ_RHT03;


//------------------------------------------------------------
// Public Functions //////////////////////////////////////////
//------------------------------------------------------------
PEZOBJ_RHT03        RHT03_Create();
void                RHT03_Release(PEZOBJ_RHT03 rht03);

void                RHT03_Connect1Wire(PEZOBJ_RHT03 rht03, PEZOBJ_1WIRE onewire);

bool                RHT03_Init (PEZOBJ_RHT03 rht03);
void                RHT03_Start(PEZOBJ_RHT03 rht03);

bool                RHT03_Read(PEZOBJ_RHT03 rht03);

#endif


/* [] END OF FILE */

