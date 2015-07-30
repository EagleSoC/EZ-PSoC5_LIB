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

#ifndef MY9221_H
#define MY9221_H

#include "ezCOMM.h"
#include <cytypes.h>
#include "TypeDefine.h"

//------------------------------------------------------------
// Defines ///////////////////////////////////////////////////
//------------------------------------------------------------


//------------------------------------------------------------
// Public Data Structure /////////////////////////////////////
//------------------------------------------------------------
#define MY9221_CFG_ONE_SHOT_MODE        0b0000000000000001
#define MY9221_CFG_COUNTER_RESET_MODE   0b0000000000000010
#define MY9221_CFG_OUTPUT_PWM_APDM      0b0000000000000100
#define MY9221_CFG_EXT_OSC              0b0000000000001000
#define MY9221_CFG_APDM_OUTPUT          0b0000000000010000

#define MY9221_CFG_CLK_ORG              0b0000000000000000
#define MY9221_CFG_CLK_ORG_DIV_2        0b0000000000100000
#define MY9221_CFG_CLK_ORG_DIV_4        0b0000000001000000
#define MY9221_CFG_CLK_ORG_DIV_8        0b0000000001100000
#define MY9221_CFG_CLK_ORG_DIV_16       0b0000000010000000
#define MY9221_CFG_CLK_ORG_DIV_64       0b0000000010100000
#define MY9221_CFG_CLK_ORG_DIV_128      0b0000000011000000
#define MY9221_CFG_CLK_ORG_DIV_256      0b0000000011100000

#define MY9221_CFG_8BIT_GRAY            0b0000000000000000
#define MY9221_CFG_12BIT_GRAY           0b0000000100000000
#define MY9221_CFG_14BIT_GRAY           0b0000001000000000
#define MY9221_CFG_16BIT_GRAY           0b0000001100000000

#define MY9221_CFG_IOUT_FAST            0b0000010000000000

typedef struct MY9221_CONFIG{
    uint16_t    CommandData;
} MY9221_CONFIG;
typedef MY9221_CONFIG * PMY9221_CONFIG;
    
typedef struct EZOBJ_MY9221 {
    void*           PrivateData;
    MY9221_CONFIG   Config;
    uint16_t*       PLED;
    
} EZOBJ_MY9221;

typedef EZOBJ_MY9221 * PEZOBJ_MY9221;


//------------------------------------------------------------
// Public Functions //////////////////////////////////////////
//------------------------------------------------------------
PEZOBJ_MY9221       MY9221_Create();
void                MY9221_Release(PEZOBJ_MY9221 my);

void                MY9221_ConnectDCLKPin(PEZOBJ_MY9221 my, PEZOBJ_IO dclk);
void                MY9221_ConnectDIPin(PEZOBJ_MY9221 my, PEZOBJ_IO di);

bool                MY9221_SetLeds(PEZOBJ_MY9221 my, uint8_t leds);

bool                MY9221_Init (PEZOBJ_MY9221 my);
void                MY9221_Start(PEZOBJ_MY9221 my);

void                MY9221_CircularLEDWrite(PEZOBJ_MY9221 my);
void                MY9221_ClearDisplay(PEZOBJ_MY9221 my);


#endif
/* [] END OF FILE */

