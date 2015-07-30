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

//#include "String.h";

#if !defined(EZCOMM_I2C_H)
#define EZCOMM_I2C_H

//
#include <cytypes.h>
#include "TypeDefine.h"
#include "ezCOMM.h"



PEZOBJ_I2C      ezI2C_Create();
void            ezI2C_Release(PEZOBJ_I2C i2c);

bool            ezI2C_Init (EZOBJ_I2C *I2C);
void            ezI2C_Start(EZOBJ_I2C *I2C);

void            ezI2C_DisableInt(EZOBJ_I2C *I2C);
void            ezI2C_EnableInt (EZOBJ_I2C *I2C);

bool            ezI2C_ReadReg  (PEZOBJ_COMM comm, uint8  reg, uint8* result);
bool            ezI2C_ReadRegs (PEZOBJ_COMM comm, uint8  reg, uint8* buf, uint8 len);

bool            ezI2C_WriteReg (PEZOBJ_COMM comm, uint8  reg, uint8  value);
bool            ezI2C_WriteRegs(PEZOBJ_COMM comm, uint8  reg, uint8* buf, uint8 buflen);





#endif

//[] END OF FILE
