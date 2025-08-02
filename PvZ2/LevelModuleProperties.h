#pragma once
#include "PropertySheetBase.h"

#define LEVELMODULEPROPS_GETCLASS_ADDR 0xDF1860
#define LEVELMODULEPROPS_CTOR_ADDR 0x28DAF0
#define LEVELMODULEPROPS_DTOR_ADDR 0x294E7C
#define LEVELMODULEPROPS_VTBL 0x1CF0770
#define LEVELMODULEPROPS_VTBL_NFUNC 18

#define LEVELMODULEPROPS_GETMODULETYPE_INDEX 14

class LevelModuleProperties : public PropertySheetBase
{
public:
	std::vector<SexyString> ResourceGroupNames;
	Sexy::RtWeakPtr<void> DifficultyProps;
	SexyString IconImage;
	SexyString IconText;
};

static_assert(sizeof(LevelModuleProperties) == 0x48); // 0x50 is the true size
