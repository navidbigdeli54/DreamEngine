#pragma once

struct GenericPlatformTypes
{
	typedef unsigned char UInt8;
	typedef unsigned short int UInt16;
	typedef unsigned int UInt32;
	typedef unsigned long int UInt64;

	typedef signed char Int8;
	typedef signed short int Int16;
	typedef signed int Int32;
	typedef signed long int Int64;

	typedef char ANSIChar;
	typedef char16_t UTF16Char;
	typedef char32_t UTF32Char;
	typedef wchar_t WChar;

	typedef unsigned long USizeT;

	typedef signed long SizeT;
};
