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

#ifndef EZLPF2P_H
#define EZLPF2P_H
#include <cytypes.h>
#include "TypeDefine.h"

//------------------------------------------------------------
// Defines ///////////////////////////////////////////////////
//------------------------------------------------------------


//------------------------------------------------------------
// Public Data Structure /////////////////////////////////////
//------------------------------------------------------------
typedef struct EZOBJ_LPF2P {
    void*       PrivateData;

} EZOBJ_LPF2P;

typedef EZOBJ_LPF2P * PEZOBJ_LPF2P;


//------------------------------------------------------------
// Public Functions //////////////////////////////////////////
//------------------------------------------------------------
PEZOBJ_LPF2P       ezLPF2P_Create();
void                ezLPF2P_Release(PEZOBJ_LPF2P lpf);

void                ezLPF2P_SetFreqCutoff (PEZOBJ_LPF2P lpf, float sample_freq, float cutoff_freq);
float               ezLPF2P_Apply(PEZOBJ_LPF2P lpf, float sample);
float               ezLPF2P_GetCutofffreq(PEZOBJ_LPF2P lpf);


#endif
/* [] END OF FILE */