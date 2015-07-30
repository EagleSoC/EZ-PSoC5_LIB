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

#ifndef TYPEDEFINE_H
#define TYPEDEFINE_H

#include "cytypes.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

#ifndef BOOL
typedef unsigned int BOOL;
#endif

#ifndef bool
typedef unsigned int bool;
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

#ifndef byte
typedef unsigned char byte;
#endif

#ifndef HIGH
#define HIGH 1
#endif

#ifndef LOW
#define LOW 0
#endif

/*
#ifndef uint8
#define uint8 unsigned char
//typedef unsigned char uint8;
#endif

#ifndef uint16
#define uint16 unsigned int
//typedef unsigned int uint16;
#endif

#ifndef uint32
#define uint32 unsigned int
//typedef unsigned int uint32;
#endif

#ifndef int8
#define int8  int
//typedef int int8;
#endif

#ifndef int16
#define int16 int
//typedef int int16;
#endif

#ifndef int32
#define int32 int
//typedef int int32;
#endif
*/

#ifndef ToDeg
#define ToDeg(x) ((x)*57.2957795131)  // *180/pi
#endif

#ifndef ToRad
#define ToRad(x) ((x)*0.01745329252)  // *pi/180
#endif


#ifndef VECTOR_3D
#define VECTOR_3D
typedef struct VECTOR3Df
{
    float   x, y, z;
} VECTOR3Df;

typedef VECTOR3Df * PVECTOR3Df;


typedef struct VECTOR3D
{
    int32   x, y, z;
} VECTOR3D;

typedef VECTOR3D * PVECTOR3D;


#endif


#endif  // TYPEDEF_H
//[] END OF FILE


