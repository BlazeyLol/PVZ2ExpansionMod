#pragma once
#include <PvZ2/LevelModule.h>
#include <PvZ2/LevelModuleProperties.h>

namespace Furr
{
	class OverrideSunCollectableModule : public LevelModule
	{
		DECLARE_STATIC_RT_CLASS_MEMBERS(OverrideSunCollectableModule);

		DEFINE_RT_CLASS_CONSTRUCT_FUNCTION(OverrideSunCollectableModule, LEVELMODULE_CTOR_ADDR);

		DEFINE_RT_CLASS_BUILD_SYMBOLS_WITHOUT_CLASS_PROPERTIES(OverrideSunCollectableModule, LevelModule);

		DEFINE_RT_CLASS_REGISTER_CLASS_FUNCTION(OverrideSunCollectableModule);

		//DEFINE_RT_CLASS_GET_CLASS_FUNCTION(OverrideSunCollectableModule, LEVELMODULE_GETCLASS_ADDR);
		
		DEFINE_RT_CLASS_GET_CLASS_FUNCTION(OverrideSunCollectableModule, LEVELMODULE_GETCLASS_ADDR);

		DECLARE_RTOBJECT_DTORS(OverrideSunCollectableModule);

		static void registerDelegates(OverrideSunCollectableModule* self);
	};

	class OverrideSunCollectableModuleProps : public LevelModuleProperties
	{
		DECLARE_STATIC_RT_CLASS_MEMBERS(OverrideSunCollectableModuleProps);

		SexyString CollectableType = "sun";

		DEFINE_RT_CLASS_CONSTRUCT_FUNCTION(OverrideSunCollectableModuleProps, LEVELMODULEPROPS_CTOR_ADDR);

		RT_CLASS_BUILD_SYMBOLS_BEGIN(OverrideSunCollectableModuleProps, LevelModuleProperties);
			REGISTER_STRING_PROPERTY(builder, rclass, OverrideSunCollectableModuleProps, CollectableType);
		RT_CLASS_BUILD_SYMBOLS_END();

		DEFINE_RT_CLASS_REGISTER_CLASS_FUNCTION(OverrideSunCollectableModuleProps);

		DEFINE_RT_CLASS_GET_CLASS_FUNCTION(OverrideSunCollectableModuleProps, LEVELMODULEPROPS_GETCLASS_ADDR);

		DECLARE_RTOBJECT_DTORS(OverrideSunCollectableModuleProps);

		static void* getModuleType();
	};
}