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
#ifndef EZCOMM_UART_H
#define EZCOMM_UART_H

#include "ezCOMM.h"


enum INT_FORMAT{
    DEC     = 1,
    DEC8,
    DEC16,
    DEC32,
    HEX8,
    HEX16,
    HEX32,
    BIN8,
    BIN16,
    BIN32
};





PEZOBJ_UART        ezUART_Create();
void                ezUART_Release(PEZOBJ_UART uart);

bool                ezUART_Init(PEZOBJ_UART uart);
void                ezUART_Start(PEZOBJ_UART uart);

void                ezUART_SetRxInterrupt(PEZOBJ_UART uart, PEZOBJ_ISR isr);
void                ezUART_SetTxInterrupt(PEZOBJ_UART uart, PEZOBJ_ISR isr);

void                ezUART_ClearTxRxBuffer(PEZOBJ_UART uart);

void                ezUART_Print(PEZOBJ_UART uart, char str[]);
void                ezUART_PrintLn(PEZOBJ_UART uart, char str[]);

uint8               ezUART_RxAvaliable(PEZOBJ_UART uart);
uint8               ezUART_ReadLine(PEZOBJ_UART uart, char* buf, const int bufLength);
bool                ezUART_ReadChar(PEZOBJ_UART uart, char* ch);




#endif
//[] END OF FILE

