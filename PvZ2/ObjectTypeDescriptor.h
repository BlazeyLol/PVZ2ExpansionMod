#pragma once
#include <Sexy/RtObject.h>

class ObjectTypeDescriptor : public Sexy::RtObject
{
public:
	SexyString TypeName;
};

static_assert(offsetof(ObjectTypeDescriptor, TypeName) == 0x4);