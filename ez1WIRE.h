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
#ifndef EZONEWIRE_H
#define EZONEWIRE_H

#include <cytypes.h>
#include "TypeDefine.h"
#include "ezCOMM.h"

//------------------------------------------------------------
// Defines ///////////////////////////////////////////////////
//------------------------------------------------------------
// 1-Wire ROM Commands
#define WIRE1_DS_CMD_SEARCH             0xF0
#define WIRE1_DS_CMD_READ               0x33
#define WIRE1_DS_CMD_MATCH              0x55
#define WIRE1_DS_CMD_SKIP               0xCC
#define WIRE1_DS_CMD_ALARM_SEARCH       0xEC


//------------------------------------------------------------
// Public Data Structure /////////////////////////////////////
//------------------------------------------------------------


typedef enum ONEWIRE_MODE
{
    ONEWIRE_MODE_MAXDETECT = 0, // RHT03
    ONEWIRE_MODE_DALLAS     // DS2432
} ONEWIRE_MODE;


typedef struct EZOBJ_1WIRE
{
    void*           PrivateData;

    PEZOBJ_IO      io;

} EZOBJ_1WIRE;

typedef EZOBJ_1WIRE* PEZOBJ_1WIRE;

//------------------------------------------------------------
// Public Functions //////////////////////////////////////////
//------------------------------------------------------------

PEZOBJ_1WIRE    ez1WIRE_Create();
void            ez1WIRE_Release(PEZOBJ_1WIRE onewire);

bool            ez1WIRE_Init(PEZOBJ_1WIRE onewire);
void            ez1WIRE_Start(PEZOBJ_1WIRE onewire);

void            ez1WIRE_Mode(PEZOBJ_1WIRE onewire, ONEWIRE_MODE mode);

void            ez1WIRE_ConnectIO(PEZOBJ_1WIRE onewire, PEZOBJ_IO io);
void            ez1WIRE_IncreaseDeviceCount(PEZOBJ_1WIRE onewire);
int             ez1WIRE_GetDeviceCount(PEZOBJ_1WIRE onewire);
void            ez1WIRE_Register(PEZOBJ_1WIRE onewire, PSinglelLink PNewRegLink);

bool            ez1WIRE_Reset(PEZOBJ_1WIRE onewire);
bool            ez1WIRE_Read(PEZOBJ_1WIRE onewire, void* buf, const int databytes);
bool            ez1WIRE_Write(PEZOBJ_1WIRE onewire, void* buf, const int databytes);

bool            ez1WIRE_DS_DeviceIsConnected(PEZOBJ_1WIRE onewire, uint8_t rom[8]);

bool            ez1WIRE_DS_DeviceSearchFirst(PEZOBJ_1WIRE onewire, uint8_t newrom[8]);
void            ez1WIRE_DS_DeviceSearchFamilySkip(PEZOBJ_1WIRE onewire);
bool            ez1WIRE_DS_DeviceSearchNext(PEZOBJ_1WIRE onewire, uint8_t newrom[8]);

bool            ez1WIRE_DS_DeviceSearchTarget(PEZOBJ_1WIRE onewire, uint8_t familyCode,  uint8_t newrom[8]);
bool            ez1WIRE_DS_DeviceSearchTargetNext(PEZOBJ_1WIRE onewire, uint8_t newrom[8]);

bool            ez1WIRE_DS_CheckAddrInUsed(PEZOBJ_1WIRE onewire, uint8_t addr[8]);

uint8_t         ez1WIRE_CRC8(const uint8_t *addr, uint8_t len);
uint16_t        ez1WIRE_CRC16(const uint8_t *input, uint16_t len, uint16_t crc);


#endif
/* [] END OF FILE */
