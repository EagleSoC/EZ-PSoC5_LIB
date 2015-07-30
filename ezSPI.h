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
#ifndef EZCOMM_SPI_H
#define EZCOMM_SPI_H


#include <cytypes.h>
#include "TypeDefine.h"
#include "ezCOMM.h"



PEZOBJ_SPI          ezSPI_Create();
void                ezSPI_Release(PEZOBJ_SPI spi);

bool                ezSPI_Init(PEZOBJ_SPI spi);
void                ezSPI_Start(PEZOBJ_SPI spi);

void                ezSPI_ConnectSSDecoder(PEZOBJ_SPI spi, PEZOBJ_DECODER ssDecoder);
void                ezSPI_ConnectSSIOControl(PEZOBJ_SPI spi, PEZOBJ_IO ctrl);

bool                ezSPI_TxDone(PEZOBJ_SPI spi);

bool                ezSPI_ReadReg   (PEZOBJ_COMM comm, uint8  reg, uint8 *result);
bool                ezSPI_ReadRegs  (PEZOBJ_COMM comm, uint8  reg, uint8* buf, uint8 len);

bool                ezSPI_WriteReg  (PEZOBJ_COMM comm, uint8  reg, uint8  value);
bool                ezSPI_WriteRegs (PEZOBJ_COMM comm, uint8  reg, uint8 *buf, uint8 buflen);

bool                ezSPI_ReadData  (PEZOBJ_COMM comm, uint8 *value);
bool                ezSPI_WriteData (PEZOBJ_COMM comm, uint8 value);

bool                ezSPI_WriteArray(PEZOBJ_COMM comm, uint8 *buf, uint8 len);

bool                ezSPI_Open  (PEZOBJ_COMM comm);
void                ezSPI_Write (PEZOBJ_COMM comm, uint8_t *writebuf, int writelen);
int                 ezSPI_Read  (PEZOBJ_COMM comm, uint8_t *readbuf,  int readlen);
void                ezSPI_Close (PEZOBJ_COMM comm);


#endif
//[] END OF FILE
//
