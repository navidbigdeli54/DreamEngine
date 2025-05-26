#pragma once

#ifdef _MSC_VER
#include "Platform/Generic/GenericPlatformMath.h"

struct FWindowsPlatformMath : public FGenericPlatformMath
{
    
};

typedef FWindowsPlatformMath FPlatformMath;
#endif
