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


#ifndef EZNETWORK_H
#define EZNETWORK_H

#include "ezCOMM.h"
#include <cytypes.h>
#include "TypeDefine.h"    


// Big-endian numbers are stored with the most significant byte in the lowest memory location ("big-end first"), whereas little-endian systems reverse this.
//
// A number of the UNIX system operate on CPUs that represent in big-endian
// Most Intel CPUs is little-endian
// Network byte order is big-endian
// x = 0x76543210
// -> little-endian: [76][54][32][10]
// -> big-endian: [10][32][54][76]
    
// htonl(): function 將 unsigned integer hostlong 從 host byte order 轉為 network byte order.
// htons(): function 將 unsigned short integer hostshort 從 host byte order 轉為 network byte order.
// htohl(): function 將 unsigned integer netlong 從 network byte order 轉為 host byte order.
// ntohs(): function 將 unsigned short integer netshort 從 network byte order 轉為 host byte order.    

    
#define htonl(x) ( ((x)<<24 & 0xFF000000UL) | \
                   ((x)<< 8 & 0x00FF0000UL) | \
                   ((x)>> 8 & 0x0000FF00UL) | \
                   ((x)>>24 & 0x000000FFUL) )
#define htons(x) ( ((x)<<8) | (((x)>>8)&0xFF) )
#define ntohl(x) htonl(x)    
#define ntohs(x) htons(x)
    
// IP Protocol
#define EZIP_PROTOCOL_IP        0       // Dummy for IP
#define EZIP_PROTOCOL_ICMP      1       // Control Message Protocol
#define EZIP_PROTOCOL_IGMP      2       // Internet Group Management Protocol
#define EZIP_PROTOCOL_GGP       3       // Gateway^2 (deprecated)
#define EZIP_PROTOCOL_TCP       6       // TCP
#define EZIP_PROTOCOL_PUP       12      // PUP
#define EZIP_PROTOCOL_UDP       17      // UDP
#define EZIP_PROTOCOL_IDP       22      // XNS idp
#define EZIP_PROTOCOL_ND        77      // Unofficial net disk protocol
#define EZIP_PROTOCOL_RAW       255     // Raw IP packet

typedef struct EZNETWORK_IPV4ADDR
{
    union {
        uint32_t    Ip_32b;
        struct {
            uint8_t Ip0, Ip1, Ip2, Ip3;
        }Ip_8b;
    }IP;
        
    union {
        uint32_t    Sub_32b;
        struct {
            uint8_t Sub0, Sub1, Sub2, Sub3;
        }Sub_8b;
    }SUBNET;
    union {
        uint32_t    Gtw_32b;
        struct {
            uint8_t Gtw0, Gtw1, Gtw2, Gtw3;
        }Gtw_8b;
    }GATEWAY;
} EZNETWORK_IPV4ADDR;

typedef EZNETWORK_IPV4ADDR * PEZNETWORK_IPV4ADDR;

typedef struct EZNETWIRK_MACADDR{
    uint8_t v[6];
} EZNETWIRK_MACADDR;

typedef EZNETWIRK_MACADDR * PEZNETWIRK_MACADDR;
   


typedef enum {
    CLOSED = 0,
    TCP    = 1,
    UDP    = 2
} EZNETWORK_PROTOCOL;

typedef struct EZOBJ_INTERFACE_NIC{
    void*               Obj;
    bool                Initialed;
    char*               Hostname;

    bool                Enabled;
    

    EZNETWORK_IPV4ADDR  IPv4;
    EZNETWIRK_MACADDR   MacAddr;
    bool                bUserMACAddr;
    
    
    
    struct {
        bool            Enabled;
        uint64_t        leasetime;
    } dhcp;

    void                (* EZNIC_SetIPv4)       (void* obj, ...);
    void                (* EZNIC_GetIPv4)       (void* obj, ...);
    void                (* EZNIC_SetIPv6)       (void* obj, ...);
    void                (* EZNIC_GetIPv6)       (void* obj, ...);
    void                (* EZNIC_SetMac)        (void* obj, ...);
    void                (* EZNIC_GetMac)        (void* obj, ...);
    
    uint8_t             (* EZNIC_Open)          (void* obj, ...);
    void                (* EZNIC_Close)         (void* obj, ...);
    void                (* EZNIC_Listen)        (void* obj, ...);
    void                (* EZNIC_Connect)       (void* obj, ...);
    bool                (* EZNIC_IsConnected)   (void* obj, ...);
    void                (* EZNIC_Disconnect)    (void* obj, ...);
    uint16_t            (* EZNIC_Send)          (void* obj, ...);
    uint16_t            (* EZNIC_Receive)       (void* obj, ...);
    uint16_t            (* EZNIC_Print)         (void* obj, ...);
} EZOBJ_INTERFACE_NIC;

typedef EZOBJ_INTERFACE_NIC * PEZOBJ_INTERFACE_NIC;


void                    ezNETWORK_InterfacePlugIn(PEZOBJ_INTERFACE_NIC nic);
uint8_t                 ezNETWORK_NumberOfInterface();
PEZOBJ_INTERFACE_NIC    ezNETWORK_FirstInterface();
PEZOBJ_INTERFACE_NIC    ezNETWORK_NextInterface();


uint32_t                ezNETWORK_IP2U32(uint8_t a, uint8_t b, uint8_t c, uint8_t d);
void                    ezNETWORK_U32_IP(uint32_t ip, uint8_t *a, uint8_t *b, uint8_t *c, uint8_t *d);



//*****************************************************************************
//
//!  UINT32_TO_STREAM_f
//!
//!  \param  p       pointer to the new stream
//!  \param  u32     pointer to the 32 bit
//!
//!  \return               pointer to the new stream
//!
//!  \brief                This function is used for copying 32 bit to stream
//!						   while converting to little endian format.
//
//*****************************************************************************

extern uint8_t* UINT32_TO_STREAM_f ( uint8_t *p, uint32_t u32);

//*****************************************************************************
//
//!  UINT16_TO_STREAM_f
//!
//!  \param  p       pointer to the new stream
//!  \param  u32     pointer to the 16 bit
//!
//!  \return               pointer to the new stream
//!
//!  \brief               This function is used for copying 16 bit to stream 
//!                       while converting to little endian format.
//
//*****************************************************************************

extern uint8_t* UINT16_TO_STREAM_f ( uint8_t *p, uint16_t u16);

//*****************************************************************************
//
//!  STREAM_TO_UINT16_f
//!
//!  \param  p          pointer to the stream
//!  \param  offset     offset in the stream
//!
//!  \return               pointer to the new 16 bit
//!
//!  \brief               This function is used for copying received stream to 
//!                       16 bit in little endian format.
//
//*****************************************************************************

extern uint16_t STREAM_TO_UINT16_f(char* p, uint16_t offset);

//*****************************************************************************
//
//!  STREAM_TO_UINT32_f
//!
//!  \param  p          pointer to the stream
//!  \param  offset     offset in the stream
//!
//!  \return               pointer to the new 32 bit
//!
//!  \brief               This function is used for copying received stream to
//!                       32 bit in little endian format.
//
//*****************************************************************************

extern uint32_t STREAM_TO_UINT32_f(char* p, uint16_t offset);


// Adafruit CC3k Host Driver Difference
// cc3k_int_poll function is used to try to make missed interrupts less common.
// Noted 12-12-2014 by tdicola

//*****************************************************************************
//
//!  cc3k_int_poll
//!
//!  \brief               checks if the interrupt pin is low
//!                       just in case the hardware missed a falling edge
//!                       function is in ccspi.cpp
//
//*****************************************************************************

//*****************************************************************************
//                    COMMON MACROs
//*****************************************************************************


//This macro is used for copying 8 bit to stream while converting to little endian format.
#define UINT8_TO_STREAM(_p, _val)	{*(_p)++ = (_val);}
//This macro is used for copying 16 bit to stream while converting to little endian format.
#define UINT16_TO_STREAM(_p, _u16)	(UINT16_TO_STREAM_f(_p, _u16))
//This macro is used for copying 32 bit to stream while converting to little endian format.
#define UINT32_TO_STREAM(_p, _u32)	(UINT32_TO_STREAM_f(_p, _u32))
//This macro is used for copying a specified value length bits (l) to stream while converting to little endian format.
// Adafruit CC3k Host Driver Difference
// Switch loop index to unsigned type to stop compiler warnings.
// Noted 04-08-2015 by tdicola
#define ARRAY_TO_STREAM(p, a, l) 	{register uint16_t _i; for (_i = 0; _i < l; _i++) *(p)++ = ((uint8_t *) a)[_i];}
//This macro is used for copying received stream to 8 bit in little endian format.
#define STREAM_TO_UINT8(_p, _offset, _u8)	{_u8 = (uint8_t)(*(_p + _offset));}
//This macro is used for copying received stream to 16 bit in little endian format.
#define STREAM_TO_UINT16(_p, _offset, _u16)	{_u16 = STREAM_TO_UINT16_f(_p, _offset);}
//This macro is used for copying received stream to 32 bit in little endian format.
#define STREAM_TO_UINT32(_p, _offset, _u32)	{_u32 = STREAM_TO_UINT32_f(_p, _offset);}
// Adafruit CC3k Host Driver Difference
// Switch loop index to unsigned type to stop compiler warnings.
// Noted 04-08-2015 by tdicola
#define STREAM_TO_STREAM(p, a, l) 	{register uint16_t _i; for (_i = 0; _i < l; _i++) *(a)++= ((uint8_t *) p)[_i];}
 




//*****************************************************************************
//                    COMMON MACROs
//*****************************************************************************


//This macro is used for copying 8 bit to stream while converting to little endian format.
#define UINT8_TO_STREAM(_p, _val)	{*(_p)++ = (_val);}
//This macro is used for copying 16 bit to stream while converting to little endian format.
#define UINT16_TO_STREAM(_p, _u16)	(UINT16_TO_STREAM_f(_p, _u16))
//This macro is used for copying 32 bit to stream while converting to little endian format.
#define UINT32_TO_STREAM(_p, _u32)	(UINT32_TO_STREAM_f(_p, _u32))
//This macro is used for copying a specified value length bits (l) to stream while converting to little endian format.
// Adafruit CC3k Host Driver Difference
// Switch loop index to unsigned type to stop compiler warnings.
// Noted 04-08-2015 by tdicola
#define ARRAY_TO_STREAM(p, a, l) 	{register uint16_t _i; for (_i = 0; _i < l; _i++) *(p)++ = ((uint8_t *) a)[_i];}
//This macro is used for copying received stream to 8 bit in little endian format.
#define STREAM_TO_UINT8(_p, _offset, _u8)	{_u8 = (uint8_t)(*(_p + _offset));}
//This macro is used for copying received stream to 16 bit in little endian format.
#define STREAM_TO_UINT16(_p, _offset, _u16)	{_u16 = STREAM_TO_UINT16_f(_p, _offset);}
//This macro is used for copying received stream to 32 bit in little endian format.
#define STREAM_TO_UINT32(_p, _offset, _u32)	{_u32 = STREAM_TO_UINT32_f(_p, _offset);}
// Adafruit CC3k Host Driver Difference
// Switch loop index to unsigned type to stop compiler warnings.
// Noted 04-08-2015 by tdicola
#define STREAM_TO_STREAM(p, a, l) 	{register uint16_t _i; for (_i = 0; _i < l; _i++) *(a)++= ((uint8_t *) p)[_i];}


















#endif
/* [] END OF FILE */

