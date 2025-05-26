#pragma once

#ifdef __GNUC__
#include "Platform/Generic/GenericPlatformMath.h"

struct FLinuxPlatformMath : public GenericPlatformMath
{
    
};

typedef FLinuxPlatformMath PlatformMath;
#endif