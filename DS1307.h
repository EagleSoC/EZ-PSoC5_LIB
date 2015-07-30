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
/*
 * Chip Number : DS1307
 * Description : 64 x 8 Serial Real-Time Clock
 * Manufacture : Dallas Semiconductor
 * Web Site    : http://www.maxim-ic.com
 * Interfaces  : I2C
*/


#ifndef DS1307_H
#define DS1307_H

#include "ezCOMM.H"
#include <cytypes.h>
#include "TypeDefine.h"

//------------------------------------------------------------
// Defines ///////////////////////////////////////////////////
//------------------------------------------------------------
#define DS1307_ADDRESS 0x68

#define DS1307_SQW_RATE_1       0x00
#define DS1307_SQW_RATE_4096    0x01
#define DS1307_SQW_RATE_8192    0x02
#define DS1307_SQW_RATE_32768   0x03


#pragma pack(push)  // push current alignment to stack
#pragma pack (1)    // Set alignment to 1 byte boundary
typedef struct EZDATETIME
{
    uint8   second;
    uint8   minute;
    uint8   hour24;
    uint8   dayOfWeek;
    uint8   day;
    uint8   month;
    uint16  year;
} EZDATETIME;
#pragma pack(pop)   // Restore original alignment from stack

typedef EZDATETIME * PEZDATETIME;

typedef struct EZOBJ_DS1307
{
    void*           PrivateData;
} EZOBJ_DS1307;

typedef EZOBJ_DS1307 * PEZOBJ_DS1307;


PEZOBJ_DS1307       DS1307_Create();
void                DS1307_Release(PEZOBJ_DS1307 ds);

void                DS1307_ConnectI2C(PEZOBJ_DS1307 ds, PEZOBJ_I2C i2c);

bool                DS1307_Init (PEZOBJ_DS1307 ds);
void                DS1307_Start(PEZOBJ_DS1307 ds);

bool                DS1307_Now(PEZOBJ_DS1307 ds, PEZDATETIME datetime);

bool                DS1307_SetDateTime(PEZOBJ_DS1307 ds, PEZDATETIME datetime);
bool                DS1307_SetDate(PEZOBJ_DS1307 ds, uint16 year, uint8 month, uint8 day, uint8 dayOfWeek);
bool                DS1307_SetTime(PEZOBJ_DS1307 ds, uint8 hour24, uint8 minute, uint8 second);

bool                DS1307_ReadMem(PEZOBJ_DS1307 ds, uint8 addr, uint8* result);
bool                DS1307_WriteMem(PEZOBJ_DS1307 ds, uint8 addr, uint8 value);

void                DS1307_SetClockRunning(PEZOBJ_DS1307 ds, bool running);
bool                DS1307_IsClockRunning(PEZOBJ_DS1307 ds);

void                DS1307_SetFixedOutputLevel(PEZOBJ_DS1307 ds, bool level);
bool                DS1307_GetFixedOutputLevel(PEZOBJ_DS1307 ds);

void                DS1307_SetSquareWaveEnabled(PEZOBJ_DS1307 ds, bool sqwe);
bool                DS1307_IsSquareWaveEnabled(PEZOBJ_DS1307 ds);
void                DS1307_SetSquareWaveRate(PEZOBJ_DS1307 ds, uint8 rate);
uint8               DS1307_GetSquareWaveRate(PEZOBJ_DS1307 ds);



#endif
//[] END OF FILE
