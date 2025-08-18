#pragma once
#include "Plant.h"
#include "PlantPropertySheet.h"

class PowerLilyProps : public PlantPropertySheet
{
public:
	SexyString CollectableType = "plantfood";
	int CollectableCount = 1;
	float CollectableOffsetY = -60.0f;

	static Reflection::CRefManualSymbolBuilder::BuildSymbolsFunc oPowerLilyPropsBuildSymbols;
	static void modInit();

	static void* construct()
	{
		auto* props = new PowerLilyProps();

		typedef void* (*ctorWithThisPtr)(void*);
		ctorWithThisPtr baseCtor = (ctorWithThisPtr)getActualOffset(0x2B17D4);
		baseCtor(props);

		*reinterpret_cast<int*>(uintptr_t(props)) = getActualOffset(0x1C5FC58);
		return props;
	}

	static void buildSymbols(Reflection::CRefManualSymbolBuilder* builder, Reflection::RClass* rclass)
	{
		oPowerLilyPropsBuildSymbols(builder, rclass);
		REGISTER_STRING_PROPERTY(builder, rclass, PowerLilyProps, CollectableType);
		REGISTER_STANDARD_PROPERTY(builder, rclass, PowerLilyProps, CollectableCount);
		REGISTER_STANDARD_PROPERTY(builder, rclass, PowerLilyProps, CollectableOffsetY);
	};
};