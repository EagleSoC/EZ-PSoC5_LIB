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

#ifndef EZSOCKET_H
#define EZSOCKET_H

#include "ezCOMM.h"
#include <cytypes.h>
#include "TypeDefine.h"

//------------------------------------------------------------
// Defines ///////////////////////////////////////////////////
//------------------------------------------------------------

typedef int                 SOCKET;
typedef uint32_t            socketlen_t;
typedef unsigned short      sa_family_t;
typedef uint32_t            in_addr_t;
typedef uint16_t            in_port_t;
typedef int32_t             socklen_t;

//------------------------------------------------------------
// Public Data Structure /////////////////////////////////////
//------------------------------------------------------------

typedef enum {
    AF_INET     = 2,    // Internet family for IPv4 only (internetwork: UDP, TCP, etc.)
    AF_INET6            // Internet family for IPv6 and IPv4
} ezSOCKET_ADDRESS_FAMILY;

typedef enum {
    SOCKET_STREAM,    // Provides sequenced, reliable, two-way, connection-based byte streams.  An out-of-band data transmission                        mechanism may be supported.
    SOCKET_DGRAM,     // Supports datagrams (connectionless, unreliable messages of a fixed maximum length).
    SOCKET_RAW        // Provides raw network protocol access.
}ezSOCKET_TYPE;

typedef enum {
    SOCKET_NONBLOCK = 0x01,
} ezSOCKET_PROTOCOL;

typedef enum {
    MSG_DONTOUT,
    MSG_DONTWAIT,
    MSG_OOB,
    MSG_PEEK,
    MSG_WAITALL
} ezSOCKET_MSG_FLAG;


typedef struct in_addr{
    in_addr_t               s_addr;
} in_addr;

typedef struct in6_addr{
    uint8_t                 s6_addr[16];    // IPv6 Address
} in6_addr;

typedef struct sockaddr{
    sa_family_t             sa_family;
    uint8_t                 sa_data[14];
} sockaddr;

#pragma pack(push)  // push current alignment to stack
#pragma pack (1)    // Set alignment to 1 byte boundary
typedef struct socketaddr_in{
    sa_family_t             sin_family;     // AF_INET
    in_port_t               sin_port;       // TCP & UDP Port, 16-bit
    in_addr                 sin_addr;       // 32-bit IPv4 Address
    char                    sin_zero[8];    // 保留
} socketaddr_in;

typedef struct socketaddr_in6{
    sa_family_t             sin6_family;    // AF_INET6
    in_port_t               sin6_port;      // TCP & UDP Port, 16-bit
    uint32_t                sin6_flowinfo;  // Priority abd Flow label
    in6_addr                sin6_addr;      // IPv6 Address
} socketaddr_in6;

typedef struct hostent{
    char                   *h_name;         // hostname: "www.google.com"
    char                  **h_aliases;      // Aliases
    int                     h_addresstype;  // AF_INET or AF_INET6
    int                     h_length;       // The length of h_addr_list
    char                  **h_addr_list;
} hostent;


#pragma pack(pop)   // Restore original alignment from stack


//------------------------------------------------------------
// Public Functions //////////////////////////////////////////
//------------------------------------------------------------
void                ezSOCKET_Create();
void                ezSOCKET_Release();

SOCKET              ezSOCKET_Socket  (ezSOCKET_ADDRESS_FAMILY af, ezSOCKET_TYPE type, int protocol);
int                 ezSOCKET_Bind    (SOCKET socketfd, const sockaddr* address, socklen_t addrlen);
int                 ezSOCKET_Listen  (SOCKET socketfd, int backlog);
int                 ezSOCKET_Accept  (SOCKET socketfd, sockaddr* cliaddr, socklen_t addrlen);
int                 ezSOCKET_Connect (SOCKET socketfd, sockaddr *address, socklen_t addrlen);
int                 ezSOCKET_Read    (SOCKET socketfd, char *buf, int len); // Connected Socket
int                 ezSOCKET_Write   (SOCKET socketfd, char *buf, int len); // Connected Socket
int                 ezSOCKET_Recv    (SOCKET socketfd, void *buf, size_t nbytes, int flag);
int                 ezSOCKET_Send    (SOCKET socketfd, void *buf, size_t nbytes, int flag);
int                 ezSOCKET_RecvFrom(SOCKET socketfd, void *buf, size_t nbytes, int flag, sockaddr *from, socketlen_t addrlen);// Unconnected Socket
int                 ezSOCKET_SendTo  (SOCKET socketfd, void *buf, size_t nbytes, int flag, sockaddr *to, socketlen_t addrlen);  // Unconnected Socket

int                 ezSOCKET_Close   (SOCKET socketfd);

int                 ezSOCKET_GetSocketName();
int                 ezSOCKET_GetSockeTop();

unsigned long       inet_addr(const char* str);
unsigned long  int  htonl(unsigned long  int hostlong);
unsigned short int  htons(unsigned short int hostshort);
unsigned long  int  ntol (unsigned long  int netlong);
unsigned short int  ntohs(unsigned short int netshort);

hostent*            gethostbyname(const char *name);
hostent*            gethostbyaddr(const char *addr, size_t len, int family);





#endif
/* [] END OF FILE */

