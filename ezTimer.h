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
#ifndef COMM_EZTIMER_H
#define COMM_EZTIMER_H

#include "ezCOMM.h"
#include <cytypes.h>
#include "TypeDefine.h"
#include "ezI2C.h"
//------------------------------------------------------------
// Defines ///////////////////////////////////////////////////
//------------------------------------------------------------
#define CONNECT_TIMER(X,Y)  X->Timer_Start                = Y##_Start; \
                            X->Timer_Stop                 = Y##_Stop; \
                            X->Timer_SetInterruptMode     = Y##_SetInterruptMode; \
                            X->Timer_ReadStatusRegister   = Y##_ReadStatusRegister; \
                            X->Timer_ReadControlRegister  = Y##_ReadControlRegister; \
                            X->Timer_WriteControlRegister = Y##_WriteControlRegister; \
                            X->Timer_WriteCounter         = Y##_WriteCounter; \
                            X->Timer_ReadCounter          = Y##_ReadCounter; \
                            X->Timer_WritePeriod          = Y##_WritePeriod; \
                            X->Timer_ReadPeriod           = Y##_ReadPeriod; \
                            X->Timer_ReadCapture          = Y##_ReadCapture; \
                            X->Timer_SetCaptureMode       = Y##_SetCaptureMode; \
                            X->Timer_SetCaptureCount      = Y##_SetCaptureCount; \
                            X->Timer_ReadCaptureCount     = Y##_ReadCaptureCount; \
                            X->Timer_SoftwareCapture      = Y##_SoftwareCapture; \
                            X->Timer_SetTriggerMode       = Y##_SetTriggerMode; \
                            X->Timer_EnableTrigger        = Y##_EnableTrigger; \
                            X->Timer_DisableTrigger       = Y##_DisableTrigger; \
                            X->Timer_SetInterruptCount    = Y##_SetInterruptCount; \
                            X->Timer_ClearFIFO            = Y##_ClearFIFO; \
                            X->Timer_Sleep                = Y##_Sleep; \
                            X->Timer_Wakeup               = Y##_Wakeup; \
                            X->Timer_Init                 = Y##_Init; \
                            X->Timer_Enable               = Y##_Enable; \
                            X->Timer_SaveConfig           = Y##_SaveConfig; \
                            X->Timer_RestoreConfig        = Y##_RestoreConfig;















//------------------------------------------------------------
// Public Data Structure /////////////////////////////////////
//------------------------------------------------------------
typedef struct EZOBJ_TIMER {
    void*       PrivateData;

} EZOBJ_TIMER;

typedef EZOBJ_TIMER * PEZOBJ_TIMER;


//------------------------------------------------------------
// Public Functions //////////////////////////////////////////
//------------------------------------------------------------
PEZOBJ_TIMER       ezTIMER_Create();
void                ezTIMER_Release(PEZOBJ_TIMER timer);

bool                ezTIMER_Init (PEZOBJ_TIMER timer);
void                ezTIMER_Start(PEZOBJ_TIMER timer);








#endif

/* [] END OF FILE */

