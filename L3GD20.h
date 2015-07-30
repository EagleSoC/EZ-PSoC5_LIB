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

// Driver for the ST L3GD20 MEMS gyroscope connected via SPI or I2C

#if !defined(L3GD20_H)
#define L3GD20_H

#include "ezCOMM.h"
#include <cytypes.h>
#include "TypeDefine.h"
#include "ezI2C.h"

//------------------------------------------------------------
// Defines ///////////////////////////////////////////////////
//------------------------------------------------------------
// device types
typedef enum {
    L3G_DEVICE_AUTO = 0,
    L3G4200D_DEVICE = 1,
    L3GD20_DEVICE   = 2,
    L3GD20H_DEVICE  = 3
} L3G_CONF_DEVICE_TYPE;

typedef enum {
    L3G_SA0_LOW  = 0,
    L3G_SA0_HIGH = 1,
    L3G_SA0_AUTO = 2
} L3G_CONF_SA0_STATUS;

typedef enum {
    L3G_MODE_POWNDOWN       = 0x00,
    L3G_MODE_ACTIVE         = 0x08
} L3G_CONF_POWERMODE;
/*
typedef enum {
    L3G_ODR_95HZ            = 0x00,
    L3G_ODR_190HZ           = 0x40,
    L3G_ODR_380HZ           = 0x80,
    L3G_ODR_760HZ           = 0xC0
} L3G_CONF_OUTPUTDATARATE;
*/
/*
typedef enum {
    L3G_BANDWIDTH_0         = 0x00,
    L3G_BANDWIDTH_1         = 0x10,
    L3G_BANDWIDTH_2         = 0x20,
    L3G_BANDWIDTH_3         = 0x30,
} L3G_CONF_BANDWIDTH;
*/
#define L3G_REG1_RATE_LP_MASK 0xF0 /* Mask to guard partial register update */
/* keep lowpass low to avoid noise issues */
typedef enum {
    L3G_RATE_NA_LP_NA           = 0xFFFF,
    L3GD20_RATE_95HZ_LP_12_5HZ  = ((0<<7) | (0<<6) | (0<<5) | (0<<4)),
    L3GD20_RATE_95HZ_LP_25HZ    = ((0<<7) | (0<<6) | (0<<5) | (1<<4)),
    L3GD20_RATE_190HZ_LP_12_5HZ = ((0<<7) | (1<<6) | (0<<5) | (0<<4)),
    L3GD20_RATE_190HZ_LP_25HZ   = ((0<<7) | (1<<6) | (0<<5) | (1<<4)),
    L3GD20_RATE_190HZ_LP_50HZ   = ((0<<7) | (1<<6) | (1<<5) | (0<<4)),
    L3GD20_RATE_190HZ_LP_70HZ   = ((0<<7) | (1<<6) | (1<<5) | (1<<4)),
    L3GD20_RATE_380HZ_LP_20HZ   = ((1<<7) | (0<<6) | (0<<5) | (0<<4)),
    L3GD20_RATE_380HZ_LP_25HZ   = ((1<<7) | (0<<6) | (0<<5) | (1<<4)),
    L3GD20_RATE_380HZ_LP_50HZ   = ((1<<7) | (0<<6) | (1<<5) | (0<<4)),
    L3GD20_RATE_380HZ_LP_100HZ  = ((1<<7) | (0<<6) | (1<<5) | (1<<4)),
    L3GD20_RATE_760HZ_LP_30HZ   = ((1<<7) | (1<<6) | (0<<5) | (0<<4)),
    L3GD20_RATE_760HZ_LP_35HZ   = ((1<<7) | (1<<6) | (0<<5) | (1<<4)),
    L3GD20_RATE_760HZ_LP_50HZ   = ((1<<7) | (1<<6) | (1<<5) | (0<<4)),
    L3GD20_RATE_760HZ_LP_100HZ  = ((1<<7) | (1<<6) | (1<<5) | (1<<4)),

    L3GD20H_RATE_12_5HZ_LP_NA   = ((0<<7) | (0<<6) | (0<<5) | (0<<4) | (1)),
    L3GD20H_RATE_25HZ_LP_NA     = ((0<<7) | (1<<6) | (0<<5) | (0<<4) | (1)),
    L3GD20H_RATE_50HZ_LP_NA     = ((1<<7) | (0<<6) | (0<<5) | (0<<4) | (1)),
    L3GD20H_RATE_100HZ_LP_12_5HZ= ((0<<7) | (0<<6) | (0<<5) | (0<<4) | (0)),
    L3GD20H_RATE_100HZ_LP_25HZ  = ((0<<7) | (0<<6) | (0<<5) | (1<<4) | (0)),
    L3GD20H_RATE_200HZ_LP_12_5HZ= ((0<<7) | (1<<6) | (0<<5) | (0<<4) | (0)),
    L3GD20H_RATE_200HZ_LP_70HZ  = ((0<<7) | (1<<6) | (1<<5) | (1<<4) | (0)),
    L3GD20H_RATE_400HZ_LP_20HZ  = ((1<<7) | (0<<6) | (0<<5) | (0<<4) | (0)),
    L3GD20H_RATE_400HZ_LP_25HZ  = ((1<<7) | (0<<6) | (0<<5) | (1<<4) | (0)),
    L3GD20H_RATE_400HZ_LP_50HZ  = ((1<<7) | (0<<6) | (1<<5) | (0<<4) | (0)),
    L3GD20H_RATE_400HZ_LP_110HZ = ((1<<7) | (0<<6) | (1<<5) | (1<<4) | (0)),
    L3GD20H_RATE_800HZ_LP_30HZ  = ((1<<7) | (1<<6) | (0<<5) | (0<<4) | (0)),
    L3GD20H_RATE_800HZ_LP_35HZ  = ((1<<7) | (1<<6) | (0<<5) | (1<<4) | (0)),
    L3GD20H_RATE_800HZ_LP_100HZ = ((1<<7) | (1<<6) | (1<<5) | (1<<4) | (0))
} L3G_CONF_ODR_RATE_LP;

typedef enum {
    L3G_X_ENABLE            = 0x02,
    L3G_Y_ENABLE            = 0x01,
    L3G_Z_ENABLE            = 0x04,
    L3G_XYZ_ENABLE          = 0x07,
    L3G_XYZ_DISABLE         = 0x00
} L3G_CONF_AXES_ENABLE;

typedef enum {
    L3G_FULLSCALE_250dps    = 0x00,
    L3G_FULLSCALE_500dps    = 0x10,
    L3G_FULLSCALE_2000dps   = 0x20,

    L3GD20H_FULLSCALE_245dps    = 0x00,
    L3GD20H_FULLSCALE_500dps    = 0x10,
    L3GD20H_FULLSCALE_2000dps   = 0x20
} L3G_CONF_FULLSCALE;


typedef enum {
    L3G_BLKDATAUPDATE_CONTINOUS = 0x00,
    L3G_BLKDATAUPDATE_SINGLE    = 0x80
} L3G_CONF_BLOCK_DATA_UPDATE;

typedef enum {
    L3G_BLE_LSB             = 0x00,
    L3G_BLE_MSB             = 0x40,
} L3G_CONF_ENDIAN_DATA;

typedef enum {
    L3G_INT1_DISABLE        = 0x00,
    L3G_INT1_ENABLE         = 0x80,
} L3G_CONF_INT1_STATUS;

typedef enum {
    L3G_INT2_DISABLE        = 0x00,
    L3G_INT2_ENABLE         = 0x08,
} L3G_CONF_INT2_STATUS;

typedef enum {
    L3G_INT1_LOW_EDGE       = 0x20,
    L3G_INT1_HIGH_EDGE      = 0x00,
} L3G_CONF_INT1_EDGE;

typedef enum {
    L3G_BOOT_NORMALMODE     = 0x00,
    L3G_BOOT_REBOOTMEMORY   = 0x80
} L3G_CONF_BOOT_MODE;

typedef enum {
    L3G_INT1_SEL_LPF1       = 0x00,
    L3G_INT1_SEL_HPF        = 0x04,
    L3G_INT1_SEL_LPF2       = 0x08
} L3G_CONF_INT1_SEL;

typedef enum {
    L3G_OUT_SEL_LPF1       = 0x00,
    L3G_OUT_SEL_HPF        = 0x01,
    L3G_OUT_SEL_LPF2       = 0x02
} L3G_CONF_OUT_SEL;

typedef enum{ // HPen
    L3G_HPFILTER_DISABLE    = 0x00,
    L3G_HPFILTER_ENABLE     = 0x10
} L3G_CONF_HP_FILTER_ENABLE;

typedef enum {
    L3G_HPFM_NORMAL_MODE_RES = 0x00,
    L3G_HPFM_REF_SIGNAL     = 0x10,
    L3G_HPFM_NORMAL_MODE    = 0x20,
    L3G_HPFM_AUTORESET_INT  = 0x30
} L3G_CONF_HPFILTER_MODE;

typedef enum {
    L3GD20_HPCF_0           = 0x00,
    L3GD20_HPCF_1           = 0x01,
    L3GD20_HPCF_2           = 0x02,
    L3GD20_HPCF_3           = 0x03,
    L3GD20_HPCF_4           = 0x04,
    L3GD20_HPCF_5           = 0x05,
    L3GD20_HPCF_6           = 0x06,
    L3GD20_HPCF_7           = 0x07,
    L3GD20_HPCF_8           = 0x08,
    L3GD20_HPCF_9           = 0x09
} L3G_CONF_HPF_CUTOFF_FREQ;

typedef enum {
    L3G_FORWARD_RIGHT_DOWN  = 0x01,     // X->Forward, Y->Right, Z->Down
    L3G_FORWARD_LEFT_UP     = 0x02      // X->Forward, Y->Left,  Z->Up
} L3G_CONF_AXES_ORIENT;

typedef enum {
    L3G_DISABLE_SOFTWARE_LPF = 0,
    L3G_ENABLE_SOFTWARE_LPF  = 1
} L3G_CONF_SOFTWARE_LPF;


typedef struct L3G_CONFIG{
    L3G_CONF_DEVICE_TYPE        Device;
    L3G_CONF_SA0_STATUS         SA0;
    L3G_CONF_FULLSCALE          FullScale;

    L3G_CONF_POWERMODE          PowerMode;
    L3G_CONF_ODR_RATE_LP        OutDataRate_CutOffFreq;
    L3G_CONF_AXES_ENABLE        AxesEnable;
    L3G_CONF_BLOCK_DATA_UPDATE  BlockDataUpdate;
    L3G_CONF_ENDIAN_DATA        Endianess;

    L3G_CONF_HP_FILTER_ENABLE   HPF_Enable;
    L3G_CONF_HPFILTER_MODE      HPF_Mode;
    L3G_CONF_HPF_CUTOFF_FREQ    HPF_CutoffFreq;
    L3G_CONF_INT1_SEL           INT1_Selection;
    L3G_CONF_OUT_SEL            Out_Selection;

    L3G_CONF_SOFTWARE_LPF       SoftwareLowpassFilter;
    L3G_CONF_AXES_ORIENT        AxesOrientation;

} L3G_CONFIG;


//------------------------------------------------------------
// Public Data Struct ////////////////////////////////////////
//------------------------------------------------------------
typedef struct EZOBJ_L3G {
    void*           PrivateData;
    VECTOR3Df       g;          // Gyro Angular Velocity Readings (deg/sec)

    int8            tempC;      // Temperature

    L3G_CONFIG      Config;
} EZOBJ_L3G;

typedef EZOBJ_L3G * PEZOBJ_L3G;
//------------------------------------------------------------
// Public Functions //////////////////////////////////////////
//------------------------------------------------------------

PEZOBJ_L3G      L3G_Create();
void            L3G_Release(PEZOBJ_L3G l3g);

void            L3G_SetIoAddress(PEZOBJ_L3G l3g, uint16 addr);
void            L3G_ConnectI2C(PEZOBJ_L3G l3g, PEZOBJ_I2C i2c);
//void            L3G_ConnectISR(PEZOBJ_L3G l3g, PEZOBJ_ISR isr);

bool            L3G_Init(PEZOBJ_L3G l3g);
void            L3G_Start(PEZOBJ_L3G l3g);

void            L3G_SetGyroRawOffset(PEZOBJ_L3G l3g);
//void            L3G_ReadGyroRawNoiseLevel(PEZOBJ_L3G l3g);
bool            L3G_MeasureGyroRawOffset(PEZOBJ_L3G l3g, int loopTimes); // Calculate initial DC offset and noise level of gyro

bool            L3G_ReadGyro(PEZOBJ_L3G l3g);
bool            L3G_ReadGyroInDeg(PEZOBJ_L3G l3g);
bool            L3G_ReadGyroInRad(PEZOBJ_L3G l3g);
bool            L3G_ReadTemp(PEZOBJ_L3G l3g);
bool            L3G_Status(PEZOBJ_L3G l3g, uint8* status);

// Interface
void            L3G_GetGyroIntf(PEZOBJ_L3G l3g, PEZOBJ_INTERFACE intf);


//------------------------------------------------------------
// Sample Code and Parameters ////////////////////////////////
//------------------------------------------------------------
/*

    l3g = L3G_Create();
    L3G_ConnectI2C(l3g, i2c);
    l3g->g.x = -15.0f;
    l3g->g.y = 13.0f;
    l3g->g.z = 6.0f;
    L3G_SetGyroOffset(l3g);

    L3G_Init(l3g);
    L3G_Start(l3g);
    //L3G_MeasureOffcet(l3g);

*/

#endif
//[] END OF FILE
