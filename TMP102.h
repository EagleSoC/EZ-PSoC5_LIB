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
 * Chip Number : TMP102
 * Description : Low Power Digital Temperature Sensor
 * Manufacture : Texas Instruments
 * Web Site    : http://www.ti.com/
 * Interfaces  : I2C
*/

#ifndef TMP102_H
#define TMP102_H

#include "ezCOMM.h"
#include <cytypes.h>
#include "TypeDefine.h"

//------------------------------------------------------------
// Defines ///////////////////////////////////////////////////
//------------------------------------------------------------


typedef enum {
    TMP102_ADR0_TO_GND   = 0,
    TMP102_ADR0_TO_VCC,
    TMP102_ADR0_TO_SDA,
    TMP102_ADR0_TO_SCL

} TMP102_ADR0_CONNECTION;

typedef enum {
    TMP102_EM_NORMAL_12BIT_MODE,
    TMP102_EM_EXTENDED_13BIT_MODE
} TMP102_EXTENDED_MODE;

typedef enum {
    TMP102_CR_CONVERSION_RATE_DEFAULT = 2,
    TMP102_CR_CONVERSION_RATE_0_25HZ  = 0,
    TMP102_CR_CONVERSION_RATE_1HZ     = 1,
    TMP102_CR_CONVERSION_RATE_4HZ     = 2,
    TMP102_CR_CONVERSION_RATE_8HZ     = 3
} TMP102_CONVERSION_RATE;

//typedef enum {
//    TMP102_SD_CONTINUE_CONVERT        = 0,
//    TMP102_SD_SHUTDOWN_AFTER_CONVERT  = 1
//} TMP102_SHUTDOWN_MODE;

typedef enum {
    TMP102_ALERT_PIN_ACT_LOW,
    TMP102_ALERT_PIN_ACT_HIGH
} TMP102_ALERT_PIN_POLARITY;

typedef enum {
    TMP102_ALERT_PIN_AS_IO,
    TMP102_ALERT_PIN_AS_INTERRUPT
} TMP102_ALERT_PIN_MODE;


typedef enum {
    TMP102_FQ_CONSECUTIVE_FAULTS_1 = 0,
    TMP102_FQ_CONSECUTIVE_FAULTS_2 = 1,
    TMP102_FQ_CONSECUTIVE_FAULTS_4 = 2,
    TMP102_FQ_CONSECUTIVE_FAULTS_6 = 3,
} TMP102_FAULT_QUEUE;

/*
typedef enum {
    TMP102__
    TMP102__
} TMP102_;

typedef enum {
    TMP102__
    TMP102__
} TMP102_;

typedef enum {
    TMP102__
    TMP102__
} TMP102_;
*/

//------------------------------------------------------------
// Public Data Structure /////////////////////////////////////
//------------------------------------------------------------

typedef struct TMP102_CONFIG{
    TMP102_ADR0_CONNECTION      Adr0;
    TMP102_EXTENDED_MODE        ExtendedMode;
    TMP102_CONVERSION_RATE      Conversionrate;
    TMP102_ALERT_PIN_MODE       AlertPinMode;
    TMP102_ALERT_PIN_POLARITY   AlertPinPolarity;



}TMP102_CONFIG;



typedef struct EZOBJ_TMP102 {
    void*           PrivateData;

    TMP102_CONFIG   Config;
    float           TemperatureC;
    float           TemperatureF;


} EZOBJ_TMP102;

typedef EZOBJ_TMP102 * PEZOBJ_TMP102;


//------------------------------------------------------------
// Public Functions //////////////////////////////////////////
//------------------------------------------------------------
PEZOBJ_TMP102      TMP102_Create();
void                TMP102_Release(PEZOBJ_TMP102 tmp);

void                TMP102_ConnectI2C(PEZOBJ_TMP102 tmp, PEZOBJ_I2C i2c);

bool                TMP102_Init (PEZOBJ_TMP102 tmp);
void                TMP102_Start(PEZOBJ_TMP102 tmp);

bool                TMP102_Read(PEZOBJ_TMP102 tmp);

bool                TMP102_SetHighTemperatureAlert(PEZOBJ_TMP102 tmp, float tempHi);
bool                TMP102_SetLowTemperatureAlert(PEZOBJ_TMP102 tmp, float tempLo);






#endif


/* [] END OF FILE */

