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

#ifndef EZDHCP_H
#define EZDHCP_H

#include "ezCOMM.h"
#include <cytypes.h>
#include "TypeDefine.h"
#include "ezNETWORK.h"

//------------------------------------------------------------
// Defines ///////////////////////////////////////////////////
//------------------------------------------------------------


//------------------------------------------------------------
// Public Data Structure /////////////////////////////////////
//------------------------------------------------------------
/*
typedef struct EZOBJ_DHCP{
    void*       PrivateData;
    

} EZOBJ_DHCP;
typedef EZOBJ_DHCP *    PEZOBJ_DHCP;
*/
        


//------------------------------------------------------------
// Public Functions //////////////////////////////////////////
//------------------------------------------------------------
void                ezDHCP_Create();
void                ezDHCP_Release();

//bool                ezDHCP_Init ();
void                ezDHCP_Start();

bool                ezDHCP_ReleaseIP(PEZOBJ_INTERFACE_NIC nic);
bool                ezDHCP_RenewIP(PEZOBJ_INTERFACE_NIC nic);

uint8_t             ezDHCP_Run();


#endif
/* [] END OF FILE */

