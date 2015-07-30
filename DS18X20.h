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
 * Chip Number : DS18B20 / DS1820 / DS18S20 / DS1822 / DS1825M
 * Description : Programmable Resolution 1-Wire Digital Thermometer
 * Manufacture : Maxim Integrated
 * Web Site    : http://www.maxim-ic.com
 * Interfaces  : Dallas 1-Wire
*/

#ifndef DS18X20_H
#define DS18X20_H

#include "ezCOMM.h"
#include <cytypes.h>
#include "TypeDefine.h"
#include "ez1WIRE.h"

//------------------------------------------------------------
// Defines ///////////////////////////////////////////////////
//------------------------------------------------------------
// Model ID
typedef enum DS18X20_THERMOMETER {
    DS_THERMOMETER_DS18_AUTO = 0,
    DS_THERMOMETER_DS1820    = 0x20,
    DS_THERMOMETER_DS18S20   = 0x20,
    DS_THERMOMETER_DS18B20   = 0x28,
    DS_THERMOMETER_DS1822    = 0x22,
    DS_THERMOMETER_DS1825M   = 0x3B
} DS18X20_TEMPERATURE_SENSORS;

typedef enum DS18X20_TEMP_RESOLUTION {
    DS18X20_TEMP_RES_DEFAULT = -1,
    DS18X20_TEMP_RES_9_BIT   = 0,       //  9 bit
    DS18X20_TEMP_RES_10_BIT,            // 10 bit
    DS18X20_TEMP_RES_11_BIT,            // 11 bit
    DS18X20_TEMP_RES_12_BIT             // 12 bit
}DS18X20_TEMP_RESOLUTION;


//------------------------------------------------------------
// Public Data Structure /////////////////////////////////////
//------------------------------------------------------------
typedef struct EZOBJ_DS18X20 {
    void*       PrivateData;

    union{
        uint8_t                         addr[8];
        DS18X20_TEMPERATURE_SENSORS     familyCode;
    }ROMCode;

//  DS18X20_TEMPERATURE_RESOLUTION      bitResolution;
    float       TemperatureC;
    float       TemperatureF;

} EZOBJ_DS18X20;

typedef EZOBJ_DS18X20 * PEZOBJ_DS18X20;


//------------------------------------------------------------
// Public Functions //////////////////////////////////////////
//------------------------------------------------------------
PEZOBJ_DS18X20      DS18X20_Create();
void                DS18X20_Release(PEZOBJ_DS18X20 ds);

void                DS18X20_Connect1Wire(PEZOBJ_DS18X20 ds, PEZOBJ_1WIRE onewire);

bool                DS18X20_Init (PEZOBJ_DS18X20 ds);
void                DS18X20_Start(PEZOBJ_DS18X20 ds);
void                DS18X20_SetResolution(PEZOBJ_DS18X20 ds, DS18X20_TEMP_RESOLUTION newResolution);
DS18X20_TEMP_RESOLUTION DS18X20_GetResolution(PEZOBJ_DS18X20 ds);

bool                DS18X20_Read(PEZOBJ_DS18X20 ds);

#endif

/* [] END OF FILE */

