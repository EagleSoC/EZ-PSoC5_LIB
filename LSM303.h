/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
// Driver for ST LSM303DLHC MEMS Accelerometer / Magnetimeter connected via SPI / I2C

#if !defined(LSM303_H)
#define LSM303_H

#include "ezCOMM.h"
#include <cytypes.h>
#include "TypeDefine.h"

//------------------------------------------------------------
// Defines ///////////////////////////////////////////////////
//------------------------------------------------------------
//------------------------------------------------------------
// device types
typedef enum {
    LSM303DLH_DEVICE                = 0,
    LSM303DLM_DEVICE                = 1,
    LSM303DLHC_DEVICE               = 2,
    LSM303_DEVICE_AUTO              = 3
} LSM303_CONF_DEVICE_TYPE;
//------------------------------------------------------------
// SA0_A states
typedef enum LSM303_SA0_STATUS{
    LSM303_SA0_A_LOW                = 0,
    LSM303_SA0_A_HIGH               = 1,
    LSM303_SA0_A_AUTO               = 2
} LSM303_CONF_SA0_STATUS;
//------------------------------------------------------------
typedef enum {
    LSM303_NORMAL_MODE              = 0x00,
    LSM303_LOWPOWER_MODE            = 0x08
} LSM303_CONF_POWERMODE;
//------------------------------------------------------------
typedef enum {
    LSM303_ACC_ODR_1_HZ             = 0x10,     // Output Data Rate = 1 Hz
    LSM303_ACC_ODR_10_HZ            = 0x20,     // Output Data Rate = 10 Hz
    LSM303_ACC_ODR_25_HZ            = 0x30,     // Output Data Rate = 25 Hz
    LSM303_ACC_ODR_50_HZ            = 0x40,     // Output Data Rate = 50 Hz
    LSM303_ACC_ODR_100_HZ           = 0x50,     // Output Data Rate = 100 Hz
    LSM303_ACC_ODR_200_HZ           = 0x60,     // Output Data Rate = 200 Hz
    LSM303_ACC_ODR_400_HZ           = 0x70,     // Output Data Rate = 400 Hz
    LSM303_ACC_ODR_1620_HZ_LP       = 0x80,     // Output Data Rate = 1620 Hz only in Low Power Mode
    LSM303_ACC_ODR_1344_HZ          = 0x90,     // Output Data Rate = 1344 Hz in Normal mode
    LSM303_ACC_ODR_5376_HZ_LP       = 0x90      // Output Data Rate = 5376 Hz in Low Power Mode
} LSM303_CONF_ACC_ODR;
//------------------------------------------------------------
typedef enum {
    LSM303_X_ENABLE                 = 0x01,
    LSM303_Y_ENABLE                 = 0x02,
    LSM303_Z_ENABLE                 = 0x04,
    LSM303_XYZ_ENABLE               = 0x07,
    LSM303_XYZ_DISABLE              = 0x00
} LSM303_CONF_AXES_ENABLE;
//------------------------------------------------------------
typedef enum {
    LSM303_HR_ENABLE                = 0x08,
    LSM303_HR_DISABLE               = 0x00
} LSM303_CONF_ACC_HIGH_RESOLUTION;
//------------------------------------------------------------
typedef enum {
    LSM303_ACC_FULLSCALE_2G         = 0x00,
    LSM303_ACC_FULLSCALE_4G         = 0x10,
    LSM303_ACC_FULLSCALE_8G         = 0x20,
    LSM303DLHM_ACC_FULLSCALE_8G     = 0x30,     // DLH/DLM
    LSM303_ACC_FULLSCALE_16G        = 0x30
} LSM303_CONF_ACC_FULLSCALE;
//------------------------------------------------------------
typedef enum {
    LSM303_ACC_BLKUPDATE_CONTINOUS  = 0x00, // Continue Update
    LSM303_ACC_BLKUPDATE_SINGLE     = 0x80  // Single Update: output registers not update until MSB and LSB reading
} LSM303_CONF_ACC_BLOCK_DATA_UPDATE;
//------------------------------------------------------------
typedef enum {
    LSM303_BLE_LSB                  = 0x00, // Little Endian: data LSB @ lower address
    LSM303_BLE_MSB                  = 0x40  // Big Endian: data MSB @ lower address
} LSM303_CONF_ENDIAN_DATA;
//------------------------------------------------------------
typedef enum {
    LSM303_ACC_BOOT_NORMALMODE      = 0x00,
    LSM303_ACC_BOOT_REBOOTMEMORY    = 0x80
} LSM303_CONF_ACC_BOOT_MODE;
//------------------------------------------------------------
typedef enum {
    LSM303_ACC_HPF_NORMAL_MODE_RES  = 0x00,
    LSM303_ACC_HPF_REF_SIGNAL       = 0x40,
    LSM303_ACC_HPF_NORMAL_MODE      = 0x80,
    LSM303_ACC_HPF_AUTORESET_INT    = 0xC0
} LSM303_CONF_ACC_HPF_MODE;
//------------------------------------------------------------
typedef enum {
    LSM303_ACC_HPFCF_8              = 0x00,
    LSM303_ACC_HPFCF_16             = 0x10,
    LSM303_ACC_HPFCF_32             = 0x20,
    LSM303_ACC_HPFCF_64             = 0x30
} LSM303_CONF_ACC_HP_CUTOFF_FREQ;
//------------------------------------------------------------
typedef enum {
    LSM303_ACC_HPF_DISABLE          = 0x00,
    LSM303_ACC_HPF_ENABLE           = 0x08
} LSM303_CONF_ACC_HPF_STATUS;
//------------------------------------------------------------
typedef enum {
    LSM303_ACC_HPF_CLICK_DISABLE    = 0x00,
    LSM303_ACC_HPF_CLICK_ENABLE     = 0x04
} LSM303_CONF_ACC_HPF_CLICK;
//------------------------------------------------------------
typedef enum {
    LSM303_ACC_HPF_AOI1_DISABLE     = 0x00,
    LSM303_ACC_HPF_AOI1_ENABLE      = 0x01
} LSM303_CONF_ACC_HPF_AOI1;
//------------------------------------------------------------
typedef enum {
    LSM303_ACC_HPF_AOI2_DISABLE     = 0x00,
    LSM303_ACC_HPF_AOI2_ENABLE      = 0x02
} LSM303_CONF_ACC_HPF_AOI2;
//------------------------------------------------------------
typedef enum {
    LSM303_ACC_INT1_CLICK           = 0x80,
    LSM303_ACC_INT1_AOI1            = 0x40,
    LSM303_ACC_INT1_AOI2            = 0x20,
    LSM303_ACC_INT1_DRY1            = 0x10,
    LSM303_ACC_INT1_DRY2            = 0x08,
    LSM303_ACC_INT1_WTM             = 0x04,
    LSM303_ACC_INT1_OVERRUN         = 0x02
} LSM303_CONF_ACC_INT1_CONF;
//------------------------------------------------------------
typedef enum {
    LSM303_ACC_INT2_CLICK           = 0x80,
    LSM303_ACC_INT2_INT1            = 0x40,
    LSM303_ACC_INT2_INT2            = 0x20,
    LSM303_ACC_INT2_BOOT            = 0x10,
    LSM303_ACC_INT2_ACT             = 0x08,
    LSM303_ACC_INT2_HLACTIVE        = 0x02
} LSM303_CONF_ACC_INT2_CONF;
//------------------------------------------------------------
typedef enum {
    LSM303_ACC_OR_COMBINATION       = 0x00,     // OR combination of enabled IRQs
    LSM303_ACC_AND_COMBINATION      = 0x80,     // AND combination of enabled IRQs
    LSM303_ACC_MOV_COMBINATION      = 0x40,     // 6D movement recongnition
    LSM303_ACC_POS_COMBINATION      = 0xC0      // 6D position recongnition
} LSM303_CONF_ACC_INT_COMB;
//------------------------------------------------------------
typedef enum {
    LSM303_ACC_Z_HIGH               = 0x20,     // Z High enabled IRQs
    LSM303_ACC_Z_LOW                = 0x10,     // Z Low  enabled IRQs
    LSM303_ACC_Y_HIGH               = 0x08,     // Y High enabled IRQs
    LSM303_ACC_Y_LOW                = 0x04,     // Y Low  enabled IRQs
    LSM303_ACC_X_HIGH               = 0x02,     // X High enabled IRQs
    LSM303_ACC_X_LOW                = 0x01      // X Low  enabled IRQs
} LSM303_CONF_ACC_INT_AXES;
//------------------------------------------------------------
typedef enum {
    LSM303_ACC_Z_DOUBLE_CLICK       = 0x20,     // Z double click IRQs
    LSM303_ACC_Z_SINGLE_CLICK       = 0x10,     // Z signal click IRQs
    LSM303_ACC_Y_DOUBLE_CLICK       = 0x08,     // Y double click IRQs
    LSM303_ACC_Y_SINGLE_CLICK       = 0x04,     // Y signal click IRQs
    LSM303_ACC_X_DOUBLE_CLICK       = 0x02,     // X double click IRQs
    LSM303_ACC_X_SINGLE_CLICK       = 0x01,     // X signal click IRQs
} LSM303_CONF_ACC_INT_CLICK;
//------------------------------------------------------------
typedef enum {
    LSM303_ACC_INT_DISABLE          = 0x00,
    LSM303_ACC_INT_ENABLEE          = 0x80
} LSM303_CONF_ACC_INT1_STATUS;
//------------------------------------------------------------
typedef enum {
    LSM303_ACC_INT1_LOW_EDGE        = 0x20,
    LSM303_ACC_INT1_HIGH_EDGE       = 0x00
} LSM303_CONF_ACC_INT1_EDGE;
//------------------------------------------------------------
typedef enum {
    LSM303_MAG_ODR_0_75_HZ          = 0x00,     // Output Data Rate = 0.75 Hz
    LSM303_MAG_ODR_1_5_HZ           = 0x04,     // Output Data Rate = 1.5 Hz
    LSM303_MAG_ODR_3_0_HZ           = 0x08,     // Output Data Rate = 3 Hz
    LSM303_MAG_ODR_7_5_HZ           = 0x0C,     // Output Data Rate = 7.5 Hz
    LSM303_MAG_ODR_15_HZ            = 0x10,     // Output Data Rate = 15 Hz
    LSM303_MAG_ODR_30_HZ            = 0x14,     // Output Data Rate = 30 Hz
    LSM303_MAG_ODR_75_HZ            = 0x18,     // Output Data Rate = 75 Hz
    LSM303_MAG_ODR_220_HZ           = 0x1C      // Output Data Rate = 220 Hz
} LSM303_CONF_MAG_ODR;
//------------------------------------------------------------
typedef enum {
    LSM303_MAG_FS_1_3_GA            = 0x20,     // Full scale = 1.3 Gauss
    LSM303_MAG_FS_1_9_GA            = 0x40,     // Full scale = 1.9 Gauss
    LSM303_MAG_FS_2_5_GA            = 0x60,     // Full scale = 2.5 Gauss
    LSM303_MAG_FS_4_0_GA            = 0x80,     // Full scale = 4.0 Gauss
    LSM303_MAG_FS_4_7_GA            = 0xA0,     // Full scale = 4.7 Gauss
    LSM303_MAG_FS_5_6_GA            = 0xC0,     // Full scale = 5.6 Gauss
    LSM303_MAG_FS_8_1_GA            = 0xE0      // Full scale = 8.1 Gauss
} LSM303_CONF_MAG_FULLSCALE;
//------------------------------------------------------------
typedef enum {
    LSM303_MAG_CONTINOUS            = 0x00,     // Continuous-Conversion Mode
    LSM303_MAG_SINGLE               = 0x01,     // Single-Conversion Node
    LSM303_MAG_SLEEP                = 0x02      // Sleep Mode
} LSM303_CONF_MAG_WORKING_MODE;
//------------------------------------------------------------
typedef enum {
    LSM303_MAG_TEMPSENSOR_ENABLE    = 0x80,     // Temp Sensor Enable
    LSM303_MAG_TEMPSENSOR_DISABLE   = 0x00      // Temp Sensor Disable
} LSM303_CONF_MAG_TEMP_SENSOR;

//------------------------------------------------------------
typedef enum {
    LSM303_FORWARD_RIGHT_DOWN       = 0x01,     // X->Forward, Y->Right, Z->Down
    LSM303_FORWARD_LEFT_UP          = 0x02      // X->Forward, Y->Left,  Z->Up
} LSM303_CONF_AXES_ORIENT;

//------------------------------------------------------------
// Config
//------------------------------------------------------------
typedef struct LSM303_CONFIG{
    LSM303_CONF_DEVICE_TYPE         Device;     // Chip Type (4200D or D20)
    LSM303_CONF_SA0_STATUS          SA0;        // SA0: LOW, HIGH, or AUTO
    LSM303_CONF_POWERMODE           PowerMode;
    LSM303_CONF_AXES_ENABLE         AxesEnable;
    LSM303_CONF_ENDIAN_DATA         Endianess;

    LSM303_CONF_ACC_FULLSCALE       AccFullScale;
    LSM303_CONF_ACC_ODR             AccOutputDataRate;
    LSM303_CONF_ACC_BLOCK_DATA_UPDATE AccBlockDataUpdate;
    LSM303_CONF_ACC_HIGH_RESOLUTION   AccHighResolution;

    LSM303_CONF_MAG_FULLSCALE       MagFullScale;
    LSM303_CONF_MAG_ODR             MagOutputDataRate;
    LSM303_CONF_MAG_WORKING_MODE    MagWorkingMode;

    LSM303_CONF_MAG_TEMP_SENSOR     TempSensor;

    LSM303_CONF_AXES_ORIENT         AxesOrientation;
} LSM303_CONFIG;

//------------------------------------------------------------
// Public Data Structure /////////////////////////////////////
//------------------------------------------------------------
typedef struct EZOBJ_LSM303 {
    void*       PrivateData;

    VECTOR3Df       a;  // accelerometer reading
    VECTOR3Df       m;  // magnetometer reading
    float           tempF;   //Temperature;

    LSM303_CONFIG   Config;

} EZOBJ_LSM303;

typedef EZOBJ_LSM303 * PEZOBJ_LSM303;

//------------------------------------------------------------
// Public Functions //////////////////////////////////////////
//------------------------------------------------------------

PEZOBJ_LSM303   LSM303_Create();
void            LSM303_Release(PEZOBJ_LSM303 lsm303);

void            LSM303_ConnectI2C(PEZOBJ_LSM303 lsm303, PEZOBJ_I2C i2c);

bool            LSM303_Init (PEZOBJ_LSM303 lsm303);
void            LSM303_Start(PEZOBJ_LSM303 lsm303);

void            LSM303_SetAccRawOffset(PEZOBJ_LSM303 lsm303);
bool            LSM303_MeasureAccRawOffset(PEZOBJ_LSM303 lsm303, int loopTimes);
bool            LSM303_MeasureMagCalibration(PEZOBJ_LSM303 lsm303, int loopTimes);
void            LSM303_ReadMagMax(PEZOBJ_LSM303 lsm303);
void            LSM303_ReadMagMin(PEZOBJ_LSM303 lsm303);

void            LSM303_SetMagMax(PEZOBJ_LSM303 lsm303);
void            LSM303_SetMagMin(PEZOBJ_LSM303 lsm303);

// Reads all 6 channels of the LSM303 and stores them in the object variables
void            LSM303_Read(PEZOBJ_LSM303 lsm303);

bool            LSM303_ReadAcc(PEZOBJ_LSM303 lsm303);
bool            LSM303_ReadMag(PEZOBJ_LSM303 lsm303);

bool            LSM303_ReadTemp(PEZOBJ_LSM303 lsm303);

// Interface
void            LSM303_GetAccIntf(PEZOBJ_LSM303 lsm303, PEZOBJ_INTERFACE intf);
void            LSM303_GetMagIntf(PEZOBJ_LSM303 lsm303, PEZOBJ_INTERFACE intf);

bool            LSM303_GetAccStatus(PEZOBJ_LSM303 lsm303, uint8* status);
bool            LSM303_GetMagStatus(PEZOBJ_LSM303 lsm303, uint8* status);


//------------------------------------------------------------
// Sample Code and Parameters ////////////////////////////////
//------------------------------------------------------------
/*
    lsm303 = LSM303_Create();
    LSM303_ConnectI2C(lsm303, i2c);

    lsm303->a.x =  -39.0f;
    lsm303->a.y =  18.0f;
    lsm303->a.z =  -16.0f;
    LSM303_SetAccOffset(lsm303);

    lsm303->m.x =  258.0f;
    lsm303->m.y =  192.0f;
    lsm303->m.z =  220.0f;
    LSM303_SetMagMax(lsm303);

    lsm303->m.x = -512.0f;
    lsm303->m.y = -376.0f;
    lsm303->m.z = -258.0f;
    LSM303_SetMagMin(lsm303);

    LSM303_Init(lsm303);
    LSM303_Start(lsm303);
    //LSM303_MeasureAccOffset(lsm303);
*/

#endif // LSM303DLHC_H
//[] END OF FILE
