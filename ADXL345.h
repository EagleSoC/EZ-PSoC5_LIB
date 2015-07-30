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
// SPI Settings for ADXL-345
// +--------------------+-----------------
// | Processor Setting  | Description
// +--------------------+-----------------
//   Master               ADXL345 operates as slave 
//   SPI Mode             Clock polarity (CPOL) = 1
//                        Clock phase (CPHA) = 1
//   Bit Sequence         MSB first mode
//



#ifndef ADXL345_H
#define ADXL345_H


#include <cytypes.h>
#include "TypeDefine.h"
#include "ezCOMM.h"

//------------------------------------------------------------
// Defines ///////////////////////////////////////////////////
//------------------------------------------------------------
/*
    typedef enum {
    ADXL345_INT_ACT_HI = 0,
    ADXL345_INT_ACT_LOW
} ADXL345_CONF_INT;
*/
    
typedef enum {
    ADXL345_ACC_2G = 0,
    ADXL345_ACC_4G,
    ADXL345_ACC_8G,
    ADXL345_ACC_16G
} ADXL345_CONF_RANGE_SETTING;

typedef enum {
    ADXL345_ACC_ODR_0_10_HZ = 0,    // Output Data Rate = 0.10 Hz (BW = 0.05 Hz)
    ADXL345_ACC_ODR_0_20_HZ,        // Output Data Rate = 0.20 Hz (BW = 0.10 Hz)
    ADXL345_ACC_ODR_0_39_HZ,        // Output Data Rate = 0.39 Hz (BW = 0.20 Hz)
    ADXL345_ACC_ODR_0_78_HZ,        // Output Data Rate = 0.78 Hz (BW = 0.39 Hz)
    ADXL345_ACC_ODR_1_56_HZ,        // Output Data Rate = 1.56 Hz (BW = 0.78 Hz)
    ADXL345_ACC_ODR_3_13_HZ,        // Output Data Rate = 3.13 Hz (BW = 1.56 Hz)
    ADXL345_ACC_ODR_6_25_HZ,        // Output Data Rate = 6.25 Hz (BW = 3.13 Hz)
    ADXL345_ACC_ODR_12_5_HZ,        // Output Data Rate = 12.5 Hz (BW = 6.25 Hz)
    ADXL345_ACC_ODR_25_HZ,          // Output Data Rate = 25 Hz   (BW = 12.5 Hz)
    ADXL345_ACC_ODR_50_HZ,          // Output Data Rate = 50 Hz   (BW = 25 Hz)
    ADXL345_ACC_ODR_100_HZ,         // Output Data Rate = 100 Hz  (BW = 50 Hz)
    ADXL345_ACC_ODR_200_HZ,         // Output Data Rate = 200 Hz  (BW = 100 Hz)
    ADXL345_ACC_ODR_400_HZ,         // Output Data Rate = 400 Hz  (BW = 200 Hz)
    ADXL345_ACC_ODR_800_HZ,         // Output Data Rate = 800 Hz  (BW = 400 Hz)
    ADXL345_ACC_ODR_1600_HZ,        // Output Data Rate = 1600 Hz (BW = 800 Hz)
    ADXL345_ACC_ODR_3200_HZ         // Output Data Rate = 3200 Hz (BW = 1600 Hz)
} ADXL345_CONF_ODR;

typedef enum{
    ADXL345_AL_ADDRESS_LOW,
    ADXL345_AL_ADDRESS_HIGH
    
} ADXL345_CONF_ALT_ADDRESS;

typedef enum {
    ADXL345_SPI_4_WIRE = 0,
    ADXL345_SPI_3_WIRE
} ADXL345_CONF_SPI_MODE;
//------------------------------------------------------------
// Public Data Structure /////////////////////////////////////
//------------------------------------------------------------
typedef struct ADXL345_CONFIG{
    ADXL345_CONF_RANGE_SETTING      AccFullScale;
    ADXL345_CONF_ODR                AccOutputDataRate;
    ADXL345_CONF_SPI_MODE           SpiMode;
    ADXL345_CONF_ALT_ADDRESS        AltAddress;
}ADXL345_CONFIG;
    
    
typedef struct EZOBJ_ADXL345 {
    void*           PrivateData;
    VECTOR3Df       a;      // Unit: mg
//    VECTOR3D        a;
    int8_t          ErrorCode;
    ADXL345_CONFIG  Config;

} EZOBJ_ADXL345;

typedef EZOBJ_ADXL345 * PEZOBJ_ADXL345;


//------------------------------------------------------------
// Public Functions //////////////////////////////////////////
//------------------------------------------------------------
PEZOBJ_ADXL345      ADXL345_Create();
void                ADXL345_Release(PEZOBJ_ADXL345 adxl);

void                ADXL345_ConnectI2C(PEZOBJ_ADXL345 adxl, PEZOBJ_I2C i2c);
void                ADXL345_ConnectSPI(PEZOBJ_ADXL345 adxl, PEZOBJ_SPI spi);

void                ADXL345_ConnectISR_to_INT1(PEZOBJ_ADXL345 adxl, PEZOBJ_ISR isr);
void                ADXL345_ConnectISR_to_INT2(PEZOBJ_ADXL345 adxl, PEZOBJ_ISR isr);

bool                ADXL345_Init (PEZOBJ_ADXL345 adxl);
void                ADXL345_Start(PEZOBJ_ADXL345 adxl);

bool                ADXL345_ReadAcc(PEZOBJ_ADXL345 adxl);


#endif
    


   
/* [] END OF FILE */
