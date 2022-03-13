#pragma once

#ifdef __GNUC__
#include "Platform/Generic/GenericPlatformMath.h"

struct LinuxPlatformMath : public GenericPlatformMath
{
    
};

typedef LinuxPlatformMath PlatformMath;
#endif