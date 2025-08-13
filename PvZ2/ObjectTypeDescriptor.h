#pragma once
#include <Sexy/RtObject.h>

class ObjectTypeDescriptor : public Sexy::RtObject
{
public:
	SexyString TypeName;
};

#ifdef A32
static_assert(offsetof(ObjectTypeDescriptor, TypeName) == 0x4);
#else
static_assert(offsetof(ObjectTypeDescriptor, TypeName) == 0x8);
#endif