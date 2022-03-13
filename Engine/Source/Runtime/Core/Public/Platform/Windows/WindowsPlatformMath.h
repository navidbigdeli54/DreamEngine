#pragma once

#ifdef _MSC_VER
#include "Platform/Generic/GenericPlatformMath.h"

struct WindowsPlatformMath : public GenericPlatformMath
{
    
};

typedef WindowsPlatformMath PlatformMath;
#endif
