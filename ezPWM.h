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

#ifndef COMM_EZPWM_H
#define COMM_EZPWM_H

#include "ezCOMM.h"
#include "TypeDefine.h"

#define CONNECT_PWM(X,Y)    X->PWM_Init                 = Y##_Init; \
                            X->PWM_Enable               = Y##_Enable; \
                            X->PWM_Start                = Y##_Start; \
                            X->PWM_Stop                 = Y##_Stop; \
                            X->PWM_ReadStatusRegister   = Y##_ReadStatusRegister; \
                            X->PWM_SetInterruptMode     = Y##_SetInterruptMode; \
                            X->PWM_ReadCounter          = Y##_ReadCounter; \
                            X->PWM_ReadCapture          = Y##_ReadCapture; \
                            X->PWM_WritePeriod          = Y##_WritePeriod; \
                            X->PWM_ReadPeriod           = Y##_ReadPeriod; \
                            X->PWM_WriteCompare         = Y##_WriteCompare; \
                            X->PWM_ReadCompare          = Y##_ReadCompare; \
                            X->ReadStatusRegister       = Y##_ReadStatusRegister; \
                            X->PWM_Resolution           = Y##_Resolution;

#define CONNECT_PWM2PORT(X,Y)  X->PWM_Init                 = Y##_Init; \
                            X->PWM_Enable               = Y##_Enable; \
                            X->PWM_Start                = Y##_Start; \
                            X->PWM_Stop                 = Y##_Stop; \
                            X->PWM_ReadStatusRegister   = Y##_ReadStatusRegister; \
                            X->PWM_ReadCounter          = Y##_ReadCounter; \
                            X->PWM_ReadCapture          = Y##_ReadCapture; \
                            X->PWM_WritePeriod          = Y##_WritePeriod; \
                            X->PWM_ReadPeriod           = Y##_ReadPeriod; \
                            X->PWM_WriteCompare1        = Y##_WriteCompare1; \
                            X->PWM_ReadCompare1         = Y##_ReadCompare1; \
                            X->PWM_WriteCompare2        = Y##_WriteCompare2; \
                            X->PWM_ReadCompare2         = Y##_ReadCompare2; \
                            X->PWM_Resolution           = Y##_Resolution;

typedef struct EZOBJ_PWM {
    void*   PrivateData;

    void    (* PWM_Init)(void);
    void    (* PWM_Enable)(void);

    void    (* PWM_Start)(void);
    void    (* PWM_Stop)(void);
    uint8   (* PWM_ReadStatusRegister)(void);

    void    (* PWM_SetCompareMode) (uint8);
    void    (* PWM_SetCompareMode1)(uint8);
    void    (* PWM_SetCompareMode2)(uint8);
    void    (* PWM_SetInterruptMode)(uint8);
    uint16  (* PWM_ReadCounter)(void);
    uint16  (* PWM_ReadCapture)(void);
    void    (* PWM_WritePeriod)(uint16);
    uint16  (* PWM_ReadPeriod)(void);
    void    (* PWM_WriteCompare)(uint16);
    uint16  (* PWM_ReadCompare)(void);
    void    (* PWM_WriteCompare1)(uint16);
    uint16  (* PWM_ReadCompare1)(void);
    void    (* PWM_WriteCompare2)(uint16);
    uint16  (* PWM_ReadCompare2)(void);


    int     PWM_Resolution;

} EZOBJ_PWM;

typedef EZOBJ_PWM*  PEZOBJ_PWM;

//typedef enum FREQ_UNIT{
//    HZ  =   0,
//    KHZ =   3,
//    MHZ =   6,
//    GHZ =   9
//} FREQ_UNIT;



PEZOBJ_PWM     ezPWM_Create();
void            ezPWM_Release(PEZOBJ_PWM pwm);

void            ezPWM_SetPWMClockIn  (PEZOBJ_PWM pwm, long clk);
void            ezPWM_SetPWMFrequency(PEZOBJ_PWM pwm, long freq);

void            ezPWM_ConnectISR(PEZOBJ_PWM pwm, PEZOBJ_ISR isr);


bool            ezPWM_Init(PEZOBJ_PWM pwm);
void            ezPWM_Start(PEZOBJ_PWM pwm);

void            ezPWM_SetDutyPercent(PEZOBJ_PWM pwm, uint16 duty);
void            ezPWM_SetDutyInMs(PEZOBJ_PWM pwm, float ms);
void            ezPWM_SetDutyInUs(PEZOBJ_PWM pwm, uint32_t us);

void            ezPWM_SetDutyPercentPort2(PEZOBJ_PWM pwm, uint16 duty);
void            ezPWM_SetDutyInMsPort2(PEZOBJ_PWM pwm, float ms);
void            ezPWM_SetDutyInUsPort2(PEZOBJ_PWM pwm, uint32_t us);



// Interface
bool            ezPWM_IsUsedInterrupt(PEZOBJ_PWM pwm);
void            ezPWM_Register(PEZOBJ_PWM pwm, PSinglelLink PNewRegLink);
void            ezPWM_Unregister(PEZOBJ_PWM pwm, PSinglelLink PUnRegLink);


#endif
/* [] END OF FILE */
