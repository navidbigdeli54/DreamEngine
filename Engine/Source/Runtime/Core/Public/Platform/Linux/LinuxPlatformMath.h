#pragma once

#ifdef __GNUC__
#include "../Generic/GenericPlatformMath.h"

struct LinuxPlatformMath : public GenericPlatformMath
{
    
};

typedef LinuxPlatformMath PlatformMath;
#endif