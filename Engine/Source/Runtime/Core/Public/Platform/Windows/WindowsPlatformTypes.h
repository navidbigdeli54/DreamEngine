#pragma once

#ifdef _MSC_VER

#include "Platform/Generic/GenericPlatformTypes.h"

struct FWindowsPlatformTypes : public FGenericPlatformTypes
{
    typedef unsigned __int8 UInt8;
    typedef unsigned __int16 UInt16;
    typedef unsigned __int32 UInt32;
    typedef unsigned __int64 UInt64;

    typedef signed __int8 Int8;
    typedef signed __int16 Int16;
    typedef signed __int32 Int32;
    typedef signed __int64 Int64;
};

typedef FWindowsPlatformTypes FPlatformTypes;

#endif
