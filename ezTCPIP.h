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

#ifndef EZTCPIP_H
#define EZTCPIP_H

#include "ezCOMM.h"
#include <cytypes.h>
#include "TypeDefine.h"
#include "ezNETWORK.h"

    
//------------------------------------------------------------
// Public Data Structure /////////////////////////////////////
//------------------------------------------------------------
typedef struct EZOBJ_TCPIP {
    void*       PrivateData;
    
   
    
} EZOBJ_TCPIP;

typedef EZOBJ_TCPIP * PEZOBJ_TCPIP;

//------------------------------------------------------------
// Public Functions //////////////////////////////////////////
//------------------------------------------------------------

PEZOBJ_TCPIP        ezTCPIP_Create();
void                ezTCPIP_Release(EZOBJ_TCPIP tcpip);

    
    



#endif
/* [] END OF FILE */
