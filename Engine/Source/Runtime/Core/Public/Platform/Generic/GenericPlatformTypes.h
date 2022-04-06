#pragma once

#include <stdint.h>
#include <cstddef>

struct GenericPlatformTypes
{
	typedef uint8_t UInt8;
	typedef uint16_t UInt16;
	typedef uint32_t UInt32;
	typedef uint64_t UInt64;

	typedef int8_t Int8;
	typedef int16_t Int16;
	typedef int32_t Int32;
	typedef int64_t Int64;

	typedef char ANSIChar;
	typedef char16_t UTF16Char;
	typedef char32_t UTF32Char;
};
