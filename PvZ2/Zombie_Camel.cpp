#include "Zombie_Camel.h"

typedef int(*zombieCamelAssignArmor)(ZombieCamel*);
zombieCamelAssignArmor oZombieCamelAssignArmor = NULL;

int hkZombieCamelAssignArmor(ZombieCamel* self)
{
	auto* props = reinterpret_cast<ZombieCamelProps*>(self->m_propertySheet.Get());
	if (self->m_type.Get()->TypeName == "camel_onehump")
	{
		LOGI("SegmentType: %s", props->SegmentType.c_str());
		LOGI("SegmentZombieType: %s", props->SegmentZombieType.c_str());
		LOGI("SegmentCount: %d", props->SegmentCount);
	}

	return oZombieCamelAssignArmor(self);
}

Reflection::CRefManualSymbolBuilder::BuildSymbolsFunc ZombieCamelProps::oZombieCamelPropsBuildSymbols = NULL;

void ZombieCamel::modInit()
{
	LOGI("ZombieCamel mod init");

	FluffyHookFunction(0x7873E4, (void*)hkZombieCamelAssignArmor, (void**)&oZombieCamelAssignArmor);
	FluffyHookFunction(0xA07C70, (void*)ZombieCamelProps::buildSymbols, (void**)&ZombieCamelProps::oZombieCamelPropsBuildSymbols);

	LOGI("ZombieCamel finish init");
}