#pragma once
#include "Plant.h"
#include "PlantPropertySheet.h"

class PlantPowerLily : public PlantFramework
{
public:
	static void modInit();
};

class PowerLilyProps : public PlantPropertySheet
{
public:
	SexyString CollectableType = "plantfood";
	int CollectableCount = 1;
	char pad[16];
	float CollectableOffsetY;

	static Reflection::CRefManualSymbolBuilder::BuildSymbolsFunc oPowerLilyPropsBuildSymbols;

	// only buildSymbols is needed for class extensions
	static void buildSymbols(Reflection::CRefManualSymbolBuilder* builder, Reflection::RClass* rclass)
	{
		oPowerLilyPropsBuildSymbols(builder, rclass);
		REGISTER_STRING_PROPERTY(builder, rclass, PowerLilyProps, CollectableType);
		REGISTER_STANDARD_PROPERTY(builder, rclass, PowerLilyProps, CollectableCount);
		REGISTER_STANDARD_PROPERTY(builder, rclass, PowerLilyProps, CollectableOffsetY);
	};
};