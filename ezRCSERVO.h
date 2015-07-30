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
#ifndef EZRCSERVO_H
#define EZRCSERVO_H

#include "ezCOMM.h"
#include "ezPWM.h"
#include "TypeDefine.h"

typedef struct EZOBJ_RCSERVO{
    void*   PrivateData;

    float   MaxPulseDurationInUs;
    float   CentrePulseDurationInUs;
    float   MinPulseDurationInUs;

    float   MaxServoDegree;
    float   MinServoDegree;

    float   Kp, Ki, Kd;
    bool    EnablePIDControl;

} EZOBJ_RCSERVO;

typedef EZOBJ_RCSERVO* PEZOBJ_RCSERVO;

PEZOBJ_RCSERVO  ezRCSERVO_Create();
void            ezRCSERVO_Release(PEZOBJ_RCSERVO servo);
bool            ezRCSERVO_Init(PEZOBJ_RCSERVO servo);
void            ezRCSERVO_Start(PEZOBJ_RCSERVO servo);


void            ezRCSERVO_ConnectPWM(PEZOBJ_RCSERVO servo, PEZOBJ_PWM pwm);
void            ezRCSERVO_ConnectPWMPort1(PEZOBJ_RCSERVO servo, PEZOBJ_PWM pwm);
void            ezRCSERVO_ConnectPWMPort2(PEZOBJ_RCSERVO servo, PEZOBJ_PWM pwm);

void            ezRCSERVO_SetServoDegree(PEZOBJ_RCSERVO servo, float degree);
void            ezRCSERVO_SetServoDutyUs(PEZOBJ_RCSERVO servo, uint16_t dutyUs);


#endif
/* [] END OF FILE */

