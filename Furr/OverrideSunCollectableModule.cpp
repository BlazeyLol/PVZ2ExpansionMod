#include "OverrideSunCollectableModule.h"
#include <PvZ2/Board.h>

DEFINE_STATIC_RT_CLASS_MEMBERS(Furr::OverrideSunCollectableModule);
DEFINE_STATIC_RT_CLASS_MEMBERS(Furr::OverrideSunCollectableModuleProps);

void* Furr::OverrideSunCollectableModule::Destroy(OverrideSunCollectableModule* self) {
	typedef void* (*levelModuleDtor)(LevelModule*);
	return ((levelModuleDtor)getActualOffset(LEVELMODULE_DTOR_ADDR))(self);
}

void* Furr::OverrideSunCollectableModuleProps::Destroy(OverrideSunCollectableModuleProps* self) {
	typedef void* (*levelModulePropsDtor)(LevelModuleProperties*);
	return ((levelModulePropsDtor)getActualOffset(LEVELMODULEPROPS_DTOR_ADDR))(self);
}

void Furr::OverrideSunCollectableModule::registerDelegates(OverrideSunCollectableModule* self)
{
	auto* props = reinterpret_cast<OverrideSunCollectableModuleProps*>(self->m_propertySheetPtr.Get());
	SexyString collectableType = props->CollectableType;

	getBoard()->m_collectableID_SunFromSky = collectableType;
}

void* Furr::OverrideSunCollectableModuleProps::getModuleType() {
	return getRtClass();
}

void Furr::OverrideSunCollectableModule::modInit()
{
	LOGI("OverrideSunCollectableModule mod init");

	vftable = copyVFTable(getActualOffset(LEVELMODULE_VTBL), LEVELMODULE_VTBL_NFUNC);
	patchVFTable(vftable, (void*)getRtClass(), RTOBJECT_GETTYPE_INDEX);
	patchVFTable(vftable, (void*)Destroy, 2);
	patchVFTable(vftable, (void*)DestroyAndDealloc, RTOBJECT_DESTRUCT_INDEX);
	patchVFTable(vftable, (void*)registerDelegates, 7);

	getRtClass();

	LOGI("OverrideSunCollectableModule finish init");
}

void Furr::OverrideSunCollectableModuleProps::modInit()
{
	LOGI("OverrideSunCollectableModuleProps mod init");

	vftable = copyVFTable(getActualOffset(LEVELMODULEPROPS_VTBL), LEVELMODULEPROPS_VTBL_NFUNC);
	patchVFTable(vftable, (void*)getRtClass(), RTOBJECT_GETTYPE_INDEX);
	patchVFTable(vftable, (void*)Destroy, 2);
	patchVFTable(vftable, (void*)DestroyAndDealloc, RTOBJECT_DESTRUCT_INDEX);
	patchVFTable(vftable, (void*)getModuleType, LEVELMODULEPROPS_GETMODULETYPE_INDEX);

	getRtClass();

	LOGI("OverrideSunCollectableModuleProps finish init");
}