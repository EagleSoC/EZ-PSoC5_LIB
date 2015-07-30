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
#ifndef EZCOMM_H
#define EZCOMM_H

#include <cytypes.h>
#include "TypeDefine.h"
#include <cypins.h>
#include <stdio.h>

typedef enum {
    COMM_NONE = 0,
    COMM_I2CM = 0x80,  // I2C Master
    COMM_ISPM,         // ISP Master
    COMM_UART

} COMM_TYPES;



//------------------------------------------------------------
// Data Link /////////////////////////////////////////////////
//------------------------------------------------------------
typedef struct DoubleLink
{
    void *          Obj;
    void            (* Callback)(void*, ...);
    void *          prev;
    void *          next;
    void *          FuncionCallLists;
} DoubleLink;
typedef DoubleLink* PDoubleLink;

typedef struct SinglelLink
{
    void *          Obj;
    void            (* Callback)(void*, ...);
    void *          next;
//    void *          FuncionCallLists;
} SinglelLink;
typedef SinglelLink* PSinglelLink;




//------------------------------------------------------------
// Interrupt (ISR) ///////////////////////////////////////////
//------------------------------------------------------------
typedef struct EZOBJ_ISR
{
    void*           PrivateData;

    void            * PISR_Vector;
    void            * Obj;
    void            (* EZISR_Callback)(void *);

    void            (* EZISR_Start)(void);
    void            (* EZISR_StartEx)(cyisraddress address);
    void            (* EZISR_Stop)(void);
    void            (* EZISR_SetVector)(cyisraddress address);
    cyisraddress    (* EZISR_GetVector)(void);
    void            (* EZISR_SetPriority)(uint8 priority);
    uint8           (* EZISR_GetPriority)(void);
    void            (* EZISR_Enable)(void);
    uint8           (* EZISR_GetState)(void);
    void            (* EZISR_Disable)(void);
    void            (* EZISR_SetPending)(void);
    void            (* EZISR_ClearPending)(void);

    void            (* EZISR_Interrupt)(void);

} EZOBJ_ISR;

typedef EZOBJ_ISR * PEZOBJ_ISR;
//------------------------------------------------------------
//ISR_VECTOR(X,Y) - X: PEZOBJ_ISR, Y: PSoC Creater ISR object

#define ISR_VECTOR(X,Y)    CY_ISR_PROTO(Y##_ezISR_LOC); \
CY_ISR(Y##_ezISR_LOC) \
{                                   \
    if (X->EZISR_Callback != NULL)    \
        X->EZISR_Callback(X->Obj);    \
}
//------------------------------------------------------------
#define CONNECT_ISR(X,Y)    X->PISR_Vector              = Y##_ezISR_LOC; \
                            X->EZISR_Start              = Y##_Start; \
                            X->EZISR_StartEx            = Y##_StartEx; \
                            X->EZISR_Stop               = Y##_Stop; \
                            X->EZISR_SetVector          = Y##_SetVector; \
                            X->EZISR_GetVector          = Y##_GetVector; \
                            X->EZISR_SetPriority        = Y##_SetPriority; \
                            X->EZISR_GetPriority        = Y##_GetPriority; \
                            X->EZISR_Enable             = Y##_Enable; \
                            X->EZISR_GetState           = Y##_GetState; \
                            X->EZISR_Disable            = Y##_Disable; \
                            X->EZISR_SetPending         = Y##_SetPending; \
                            X->EZISR_ClearPending       = Y##_ClearPending; \
                            X->EZISR_Interrupt          = Y##_Interrupt;

//------------------------------------------------------------

PEZOBJ_ISR          ezISR_Create();
void                ezISR_Release(PEZOBJ_ISR isr);
bool                ezISR_Init(PEZOBJ_ISR isr);
void                ezISR_Start(PEZOBJ_ISR isr);
void                ezISR_Stop (PEZOBJ_ISR isr);

//------------------------------------------------------------
// SYSTEM TIMER //////////////////////////////////////////////
//------------------------------------------------------------

void                ezSYSTICK_Create();
void                ezSYSTICK_Start();
uint64_t            ezSYSTICK_GetTimeTick();
uint32_t            ezSYSTICK_CalculateTimeUs(const uint64_t startTick, const uint64_t endTick);
bool                ezSYSTICK_IsSysTickRunning();

CY_ISR_PROTO(ezSYSTICK_SysTickISR);

//------------------------------------------------------------
// GLOBAL TIMER //////////////////////////////////////////////
//------------------------------------------------------------
/*
#define TIMER_MAX_PERIOD_8b     0xFF        // 255
#define TIMER_MAX_PERIOD_16b    0xFFFF      // 65535
#define TIMER_MAX_PERIOD_24b    0xFFFFFF    // 16777215
#define TIMER_MAX_PERIOD_32b    0xFFFFFFFF  // 4294967295

CY_ISR_PROTO(ezGlobalTimer_ISR);

typedef enum {
    GLOBALTIMER_RESOLUTION_8BIT   =   0,
    GLOBALTIMER_RESOLUTION_16BIT  ,
    GLOBALTIMER_RESOLUTION_24BIT  ,
    GLOBALTIMER_RESOLUTION_32BIT
} GLOBALTIMER_RESOLUTIONS;



typedef struct EZOBJ_GLOBALTIMER{
    uint32_t        Period;
    uint32_t        TimerFreq_Hz;
    GLOBALTIMER_RESOLUTIONS    Resolution;

    void            (* EZTIMER_Start)(void);
    void            (* EZTIMER_Stop)(void);
    void            (* EZTIMER_Enable)(void);
    void            (* EZTIMER_WriteCounter16)(uint16 counter);
    void            (* EZTIMER_WriteCounter)(uint32 counter);
    uint16          (* EZTIMER_ReadCounter16)(void);
    uint32          (* EZTIMER_ReadCounter)(void);
    void            (* EZTIMER_WritePeriod16)(uint16 period);
    void            (* EZTIMER_WritePeriod)(uint32 period);
    uint16          (* EZTIMER_ReadPeriod16)(void);
    uint32          (* EZTIMER_ReadPeriod)(void);
    uint8           (* EZTIMER_ReadStatusRegister)(void);

    uint8           (* EZTIMER_Reg_CONTROL);
    void            (* EZISR_StartEx)(cyisraddress address);

} EZOBJ_GLOBALTIMER;

typedef EZOBJ_GLOBALTIMER * PEZOBJ_GLOBALTIMER;


#define CONNECT_GLOBALTIMER16(Y)  { \
        PEZOBJ_GLOBALTIMER gtimer1234 = ezGLOBALTIMER_GetGlobalTimerData(); \
        gtimer1234->EZTIMER_Start                = Y##_Start; \
        gtimer1234->EZTIMER_Stop                 = Y##_Stop; \
        gtimer1234->EZTIMER_Enable               = Y##_Enable; \
        gtimer1234->EZTIMER_WriteCounter16       = Y##_WriteCounter; \
        gtimer1234->EZTIMER_ReadCounter16        = Y##_ReadCounter; \
        gtimer1234->EZTIMER_WritePeriod16        = Y##_WritePeriod; \
        gtimer1234->EZTIMER_ReadPeriod16         = Y##_ReadPeriod;  \
        gtimer1234->EZTIMER_ReadStatusRegister   = Y##_ReadStatusRegister;  \
        gtimer1234->Period                     = TIMER_MAX_PERIOD_16b; \
        gtimer1234->Resolution                 = GLOBALTIMER_RESOLUTION_16BIT; \
}

#define CONNECT_GLOBALTIMER(Y)  { \
        PEZOBJ_GLOBALTIMER gtimer1234 = ezGLOBALTIMER_GetGlobalTimerData(); \
        gtimer1234->EZTIMER_Start                = Y##_Start; \
        gtimer1234->EZTIMER_Stop                 = Y##_Stop; \
        gtimer1234->EZTIMER_Enable               = Y##_Enable; \
        gtimer1234->EZTIMER_WriteCounter         = Y##_WriteCounter; \
        gtimer1234->EZTIMER_ReadCounter          = Y##_ReadCounter; \
        gtimer1234->EZTIMER_WritePeriod          = Y##_WritePeriod; \
        gtimer1234->EZTIMER_ReadPeriod           = Y##_ReadPeriod;  \
        gtimer1234->EZTIMER_ReadStatusRegister   = Y##_ReadStatusRegister;  \
        gtimer1234->Period                     = TIMER_MAX_PERIOD_32b; \
        gtimer1234->Resolution                 = GLOBALTIMER_RESOLUTION_32BIT;  \
}

#define CONNECT_GLOBALTIMERISR(Y) { \
        PEZOBJ_GLOBALTIMER gtimer1234 = ezGLOBALTIMER_GetGlobalTimerData(); \
        gtimer1234->Period = (gtimer1234->Resolution == GLOBALTIMER_RESOLUTION_16BIT )? TIMER_MAX_PERIOD_32b : gtimer1234->Period;  \
        gtimer1234->EZISR_StartEx           = Y##_StartEx;  \
}

void                ezGLOBALTIMER_Create();
PEZOBJ_GLOBALTIMER ezGLOBALTIMER_GetGlobalTimerData();
void                ezGLOABLTIMER_SetTimerFreq_Hz(uint32 freq);
bool                ezGLOBALTIMER_Start();
bool                ezGLOBALTIMER_IsTimerRunning();
uint32              ezGLOBALTIMER_GetTimeTick();
uint32              ezGLOBALTIMER_CalculateTimeUs(uint32 start, uint32 end);

*/


/*
#define CONNECT_TIMER8b(X,Y)    X->EZTIMER_Start                = Y##_Start; \
                                X->EZTIMER_Stop                 = Y##_Stop; \
                                X->EZTIMER_WriteCounter8        = Y##_WriteCounter; \
                                X->EZTIMER_ReadCounter8         = Y##_ReadCounter; \
                                X->EZTIMER_WritePeriod8         = Y##_WritePeriod; \
                                X->EZTIMER_ReadPeriod8          = Y##_ReadPeriod;

#define CONNECT_TIMER16b(X,Y)   X->EZTIMER_Start                = Y##_Start; \
                                X->EZTIMER_Stop                 = Y##_Stop; \
                                X->EZTIMER_WriteCounter16       = Y##_WriteCounter; \
                                X->EZTIMER_ReadCounter16        = Y##_ReadCounter; \
                                X->EZTIMER_WritePeriod16        = Y##_WritePeriod; \
                                X->EZTIMER_ReadPeriod16         = Y##_ReadPeriod;

#define CONNECT_TIMER32b(X,Y)   X->EZTIMER_Start                = Y##_Start; \
                                X->EZTIMER_Stop                 = Y##_Stop; \
                                X->EZTIMER_WriteCounter         = Y##_WriteCounter; \
                                X->EZTIMER_ReadCounter          = Y##_ReadCounter; \
                                X->EZTIMER_WritePeriod          = Y##_WritePeriod; \
                                X->EZTIMER_ReadPeriod           = Y##_ReadPeriod;

#define CONNECT_TIMER24b(X,Y)   CONNECT_TIMER32b(X,Y)
#define CONNECT_TIMER(X,Y)      CONNECT_TIMER32b(X,Y)

void                GLOBALTIMER_Release(PEZOBJ_GLOBALTIMER gtime);
void                GLOBALTIMER_Resolution(TIMER_RESOLUTION resolution);
void                GLOBALTIMER_TimerClockKHz(uint32 freqKHz);

*/
//------------------------------------------------------------
// COMM //////////////////////////////////////////////////////
//------------------------------------------------------------
typedef struct EZOBJ_COMM
{
    COMM_TYPES          CommType;
    uint16              IoAddress;    // I2C Address or SPI CS Address

    void *              CommObj;    // Point to real I2C or SPI Object

    bool                (* COMM_ReadReg)  (struct EZOBJ_COMM* comm, uint8  reg, uint8* result);
    bool                (* COMM_ReadRegs) (struct EZOBJ_COMM* comm, uint8  reg, uint8* buf, uint8 len);

    bool                (* COMM_WriteReg) (struct EZOBJ_COMM* comm, uint8  reg, uint8  value);
    bool                (* COMM_WriteRegs)(struct EZOBJ_COMM* comm, uint8  reg, uint8* buf, uint8 buflen);

    bool                (* COMM_ReadData) (struct EZOBJ_COMM* comm, uint8 *value);
    bool                (* COMM_WriteData)(struct EZOBJ_COMM* comm, uint8 value);

    bool                (* COMM_WriteArray)(struct EZOBJ_COMM* comm, uint8 *bug, uint8 len);

} EZOBJ_COMM;

typedef EZOBJ_COMM * PEZOBJ_COMM;

//------------------------------------------------------------
// Obj Interface /////////////////////////////////////////////
//------------------------------------------------------------

typedef struct EZOBJ_INTERFACE {
    char                IFName[3];
    void *              Obj;
    bool                (* FUNCALL)(void* obj, ...);
} EZOBJ_INTERFACE;

typedef EZOBJ_INTERFACE * PEZOBJ_INTERFACE;

PEZOBJ_INTERFACE        INTERFACE_Create();
void                    INTERFACE_Release(PEZOBJ_INTERFACE intfc);
bool                    INTERFACE_Call(PEZOBJ_INTERFACE intfc, ...);


//------------------------------------------------------------
// Network Devices ///////////////////////////////////////////
//------------------------------------------------------------
typedef struct EZOBJ_NETWORKDEVICE {
    int                 DeviceID;
    void                (* dd)();
    bool                (* FUNCALL)(void* obj, ...);
} EZOBJ_NETWORKDEVICE;

typedef EZOBJ_NETWORKDEVICE * PEZOBJ_NETWORKDEVICE;


typedef struct DeviceLink
{
    void *                  Obj;
    void *                  next;
    void *                  device;
} DeviceLink;
typedef DeviceLink* PDeviceLink;



//------------------------------------------------------------
// I2C Master ////////////////////////////////////////////////
//------------------------------------------------------------
#define CONNECT_I2C(X,Y)    X->EZI2C_Init                 = Y##_Init; \
                            X->EZI2C_Enable               = Y##_Enable; \
                            X->EZI2C_Start                = Y##_Start; \
                            X->EZI2C_Stop                 = Y##_Stop; \
                            X->EZI2C_ISR_NUMBER           = Y##_ISR_NUMBER; \
                            X->EZI2C_MasterClearStatus    = Y##_MasterClearStatus; \
                            X->EZI2C_MasterStatus         = Y##_MasterStatus; \
                            X->EZI2C_MasterWriteBuf       = Y##_MasterWriteBuf; \
                            X->EZI2C_MasterSendStart      = Y##_MasterSendStart; \
                            X->EZI2C_MasterSendRestart    = Y##_MasterSendRestart; \
                            X->EZI2C_MasterSendStop       = Y##_MasterSendStop; \
                            X->EZI2C_MasterWriteByte      = Y##_MasterWriteByte; \
                            X->EZI2C_MasterReadByte       = Y##_MasterReadByte;

typedef struct EZOBJ_I2C {
    void*   PrivateData;

    void    (* EZI2C_Init)(void);
    void    (* EZI2C_Enable)(void);

    void    (* EZI2C_Start)(void);
    void    (* EZI2C_Stop)(void);

    int     EZI2C_ISR_NUMBER;

    void    (* EZI2C_EnableInt)(void);
    void    (* EZI2C_DisableInt)(void);

    uint8   (* EZI2C_MasterStatus)(void);
    uint8   (* EZI2C_MasterClearStatus)(void);

    uint8   (* EZI2C_MasterWriteBuf)(uint8, uint8*, uint8, uint8);

    uint8   (* EZI2C_MasterReadBuf)(uint8, uint8*, uint8, uint8);

    uint8   (* EZI2C_MasterGetReadBufSize)(void);
    uint8   (* EZI2C_MasterGetWriteBufSize)(void);
    void    (* EZI2C_MasterClearReadBuf)(void);
    void    (* EZI2C_MasterClearWriteBuf)(void);


    uint8   (* EZI2C_MasterSendStart)(uint8, uint8);

    uint8   (* EZI2C_MasterSendRestart)(uint8, uint8);

    uint8   (* EZI2C_MasterSendStop)(void);
    uint8   (* EZI2C_MasterWriteByte)(uint8);
    uint8   (* EZI2C_MasterReadByte)(uint8);
} EZOBJ_I2C;

typedef EZOBJ_I2C * PEZOBJ_I2C;

//------------------------------------------------------------
// SPI ///////////////////////////////////////////////////////
//------------------------------------------------------------
#define CONNECT_SPI(X,Y)    X->EZSPI_Start                = Y##_Start; \
                            X->EZSPI_Init                 = Y##_Init; \
                            X->EZSPI_Enable               = Y##_Enable; \
                            X->EZSPI_ClearRxBuffer        = Y##_ClearRxBuffer; \
                            X->EZSPI_ClearTxBuffer        = Y##_ClearTxBuffer; \
                            X->EZSPI_ReadRxStatus         = Y##_ReadRxStatus; \
                            X->EZSPI_ReadTxStatus         = Y##_ReadTxStatus; \
                            X->EZSPI_GetRxBufferSize      = Y##_GetRxBufferSize; \
                            X->EZSPI_GetTxBufferSize      = Y##_GetTxBufferSize; \
                            X->EZSPI_ReadRxData           = Y##_ReadRxData; \
                            X->EZSPI_WriteTxData          = Y##_WriteTxData; \
                            X->EZSPI_ClearFIFO            = Y##_ClearFIFO; \
                            X->EZSPI_PutArray             = Y##_PutArray;

typedef struct EZOBJ_SPI
{
    void*   PrivateData;

    void    (* EZSPI_Start)(void);
    void    (* EZSPI_Init)(void);
    void    (* EZSPI_Enable)(void);

    void    (* EZSPI_ClearRxBuffer)(void);
    void    (* EZSPI_ClearTxBuffer)(void);

    uint8   (* EZSPI_ReadRxStatus)(void);
    uint8   (* EZSPI_ReadTxStatus)(void);

    uint8   (* EZSPI_GetRxBufferSize)(void);
    uint8   (* EZSPI_GetTxBufferSize)(void);

    uint8   (* EZSPI_ReadRxData) (void);
    void    (* EZSPI_WriteTxData) (uint8);

    void    (* EZSPI_ClearFIFO)(void);
    void    (* EZSPI_PutArray) (const uint8*, uint8);
} EZOBJ_SPI;

typedef EZOBJ_SPI * PEZOBJ_SPI;

//------------------------------------------------------------
// UART //////////////////////////////////////////////////////
//------------------------------------------------------------
#define CONNECT_UART(X,Y)   X->EZUART_Start               = Y##_Start; \
                            X->EZUART_Stop                = Y##_Start; \
                            X->EZUART_SetRxInterruptMode  = Y##_SetRxInterruptMode; \
                            X->EZUART_SetTxInterruptMode  = Y##_SetTxInterruptMode; \
                            X->EZUART_ClearRxBuffer       = Y##_ClearRxBuffer; \
                            X->EZUART_ClearTxBuffer       = Y##_ClearTxBuffer; \
                            X->EZUART_GetChar             = Y##_GetChar; \
                            X->EZUART_GetByte             = Y##_GetByte; \
                            X->EZUART_PutChar             = Y##_PutChar; \
                            X->EZUART_PutString           = Y##_PutString; \
                            X->EZUART_PutArray            = Y##_PutArray; \
                            X->EZUART_RxAvaliable         = Y##_RxAvaliable; \
                            X->EZUART_ReadLine            = Y##_ReadLine; \
                            X->EZUART_ReadChar            = Y##_ReadChar;

typedef struct EZOBJ_UART
{
    void*   PrivateData;

    void    (* EZUART_Start)(void);
    void    (* EZUART_Stop)(void);

    uint8   (* EZUART_ReadControlRegister)(void);
    void    (* EZUART_WriteControlRegister)(uint8);

    void    (* EZUART_EnableRxInt)(void);
    void    (* EZUART_DisableRxInt)(void);
    void    (* EZUART_SetRxInterruptMode)(uint8);
    uint8   (* EZUART_ReadRxData)(void);
    uint8   (* EZUART_ReadRxStatus)(void);
    uint8   (* EZUART_GetChar)(void);
    uint16  (* EZUART_GetByte)(void);
    uint16  (* EZUART_GetRxBufferSize)(void);
    void    (* EZUART_ClearRxBuffer)(void);

    void    (* EZUART_SetRxAddressMode)(uint8);

    void    (* EZUART_SetRxAddress1)(uint8);
    void    (* EZUART_SetRxAddress2)(uint8);

    void    (* EZUART_EnableTxInt)(void);
    void    (* EZUART_DisableTxInt)(void);
    void    (* EZUART_SetTxInterruptMode)(uint8);
    void    (* EZUART_WriteTxData)(uint8);
    uint8   (* EZUART_ReadTxStatus)(void);
    void    (* EZUART_PutChar)(uint8);
    void    (* EZUART_PutString)(const char8 *);
    void    (* EZUART_PutArray)(const uint8 *, uint8);
    void    (* EZUART_PutArray16)(const uint8 *, uint16);
    void    (* EZUART_PutCRLF)(uint8);
    uint8   (* EZUART_GetTxBufferSize)(void);
    uint16  (* EZUART_GetTxBufferSize16)(void);
    void    (* EZUART_ClearTxBuffer)(void);
    void    (* EZUART_SendBreak)(uint8);

    void    (* EZUART_LoadRxConfig)(void);
    void    (* EZUART_LoadTxConfig)(void);
    void    (* EZUART_SaveConfig)(void);
    void    (* EZUART_RestoreConfig)(void);

    void    (* UART_Init)(void);
    void    (* UART_Enable)(void);


} EZOBJ_UART;

typedef EZOBJ_UART * PEZOBJ_UART;

//------------------------------------------------------------
// Decoder ///////////////////////////////////////////////////
//------------------------------------------------------------
#define CONNECT_DECODER(X,Y)    X->ControlReg_Write     = Y##_Write; \
                                X->ControlReg_Read      = Y##_Read;

typedef struct EZOBJ_DECODER
{
    void    (* ControlReg_Write) (uint8);
    uint8   (* ControlReg_Read) (void);

} EZOBJ_DECODER;

typedef EZOBJ_DECODER * PEZOBJ_DECODER;

PEZOBJ_DECODER  ezDECODER_Create();
void            ezDECODER_Release(PEZOBJ_DECODER decoder);


//------------------------------------------------------------
// Control Register //////////////////////////////////////////
//------------------------------------------------------------
#define CONNECT_CTRLREGISTER(X,Y)   X->ControlReg_Write     = Y##_Write; \
                                    X->ControlReg_Read      = Y##_Read;

typedef struct EZOBJ_CTRLREGISTER
{
    void    (* ControlReg_Write) (uint8);
    uint8   (* ControlReg_Read) (void);

} EZOBJ_CTRLREGISTER;

typedef EZOBJ_CTRLREGISTER * PEZOBJ_CTRLREGISTER;

PEZOBJ_CTRLREGISTER     ezCTRLRTEGISTER_Create();
void                    ezCTRLRTEGISTER_Release(PEZOBJ_CTRLREGISTER ctrl);


//------------------------------------------------------------
// I/O Output ////////////////////////////////////////////////
//------------------------------------------------------------
//#define WIRE1_DM_ALG_HIZ         PIN_DM_ALG_HIZ   // High Impedance Analog
//#define WIRE1_DM_DIG_HIZ         PIN_DM_DIG_HIZ   // High Impedance Digital
//#define WIRE1_DM_RES_UP          PIN_DM_RES_UP    // Resistive Pull Up
//#define WIRE1_DM_RES_DWN         PIN_DM_RES_DWN   // Resistive Pull Down
//#define WIRE1_DM_OD_LO           PIN_DM_OD_LO     // Open Drain, Drives Low
//#define WIRE1_DM_OD_HI           PIN_DM_OD_HI     // Open Drain, Drives High
//#define WIRE1_DM_STRONG          PIN_DM_STRONG    // Strong Drive
//#define WIRE1_DM_RES_UPDWN       PIN_DM_RES_UPDWN // Resistive Pull Up/Down





#define CONNECT_IO(X,Y)     X->PIN_Read                 = Y##_Read; \
                            X->PIN_Write                = Y##_Write; \
                            X->PIN_ReadDataReg          = Y##_ReadDataReg; \
                            X->PIN_SetDriveMode         = Y##_SetDriveMode;
                          //X->PIN_ClearInterrupt       = Y##_ClearInterrupt;

typedef struct EZOBJ_IO
{
    uint8   (* PIN_Read)(void);
    void    (* PIN_Write)(uint8);
    uint8   (* PIN_ReadDataReg)(void);
    void    (* PIN_SetDriveMode)(uint8);
//    uint8   (* PIN_ClearInterrupt)(void);
} EZOBJ_IO;

typedef EZOBJ_IO * PEZOBJ_IO;

PEZOBJ_IO       ezIO_Create();
void            ezIO_Release(PEZOBJ_IO io);

//------------------------------------------------------------
//////////////////////////////////////////////////////////////
//------------------------------------------------------------
void            ezRANDOM_Create(const unsigned int seed);
unsigned short  ezRANDOM_Number(const unsigned long num);
//------------------------------------------------------------
//////////////////////////////////////////////////////////////
//------------------------------------------------------------

//------------------------------------------------------------
//////////////////////////////////////////////////////////////
//------------------------------------------------------------
float Constrain(float x, float a, float b);


//------------------------------------------------------------
//////////////////////////////////////////////////////////////
//------------------------------------------------------------
void            ezCOMM_ConnectI2C(PEZOBJ_COMM comm, PEZOBJ_I2C i2c);
void            ezCOMM_ConnectSPI(PEZOBJ_COMM comm, PEZOBJ_SPI spi);

#endif
//[] END OF FILE




