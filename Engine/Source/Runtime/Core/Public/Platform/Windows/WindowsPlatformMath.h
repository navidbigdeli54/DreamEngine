#pragma once

#ifdef _MSC_VER
#include "../Generic/GenericPlatformMath.h"

struct WindowsPlatformMath : public GenericPlatformMath
{
    
};

typedef WindowsPlatformMath PlatformMath;
#endif
