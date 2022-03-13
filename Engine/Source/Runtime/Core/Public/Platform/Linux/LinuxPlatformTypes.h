#pragma once

#include "../Generic/GenericPlatformTypes.h"

#ifdef __GNUC__
struct LinuxPlatformTypes : public GenericPlatformTypes
{
    typedef unsigned char UInt8;
    typedef unsigned short int UInt16;
    typedef unsigned long int UInt32;
    typedef unsigned long long int UInt64;

    typedef signed char Int8;
    typedef signed short int Int16;
    typedef signed long int Int32;
    typedef signed long long int Int64;
};

typedef LinuxPlatformTypes PlatformTypes;

#endif