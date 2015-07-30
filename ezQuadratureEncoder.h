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

//------------------------------------------------------------
// *.h ///////////////////////////////////////////////////////
//------------------------------------------------------------

#ifndef EZQUARDRATUREENCODER_H
#define EZQUARDRATUREENCODER_H

#include "ezCOMM.h"
#include <cytypes.h>
#include "TypeDefine.h"

//------------------------------------------------------------
// Defines ///////////////////////////////////////////////////
//------------------------------------------------------------
typedef enum EZROUTEDIRECTION{
    EZROUTATION_CW = 1,
    EZROUTATION_CCW    
} EZROUTEDIRECTION;

//------------------------------------------------------------
// Public Data Structure /////////////////////////////////////

typedef struct EZOBJ_QUADENCODER {
    void*       PrivateData;
    void        (*OnEvent)(EZROUTEDIRECTION dir);

} EZOBJ_QUADENCODER;

typedef EZOBJ_QUADENCODER * PEZOBJ_QUADENCODER;


//------------------------------------------------------------
// Public Functions //////////////////////////////////////////
//------------------------------------------------------------
PEZOBJ_QUADENCODER  ezQUADENCODER_Create();
void                ezQUADENCODER_Release(PEZOBJ_QUADENCODER qencoder);

void                ezQUADENCODER_ConnectSigAPin(PEZOBJ_QUADENCODER qencoder, PEZOBJ_IO sigA);
void                ezQUADENCODER_ConnectSigBPin(PEZOBJ_QUADENCODER qencoder, PEZOBJ_IO sigB);
void                ezQUADENCODER_ConnectISR(PEZOBJ_QUADENCODER qencoder, PEZOBJ_ISR isr);

bool                ezQUADENCODER_Init (PEZOBJ_QUADENCODER qencoder);
void                ezQUADENCODER_Start(PEZOBJ_QUADENCODER qencoder);


#endif
/* [] END OF FILE */
