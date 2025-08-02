#pragma once
#include "LevelModuleProperties.h"
#include <Sexy/RtWeakPtr.h>

#define LEVELMODULE_GETCLASS_ADDR 0xCF3960
#define LEVELMODULE_VTBL 0x1CE7414
#define LEVELMODULE_VTBL_NFUNC 19
#define LEVELMODULE_CTOR_ADDR 0x28E534
#define LEVELMODULE_DTOR_ADDR 0x2DF3B8

class LevelModule : public GameObject
{
public:
	Sexy::RtWeakPtr<LevelModuleProperties> m_propertySheetPtr;
};