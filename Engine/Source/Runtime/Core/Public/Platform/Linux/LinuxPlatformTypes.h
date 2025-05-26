#pragma once

#include "Platform/Generic/GenericPlatformTypes.h"

#ifdef __GNUC__
struct FLinuxPlatformTypes : public FGenericPlatformTypes
{
    typedef unsigned char UInt8;
    typedef unsigned short int UInt16;
    typedef unsigned int UInt32;
    typedef unsigned long int UInt64;

    typedef signed char Int8;
    typedef signed short int Int16;
    typedef signed int Int32;
    typedef signed long int Int64;
};

typedef FLinuxPlatformTypes FPlatformTypes;

#endif