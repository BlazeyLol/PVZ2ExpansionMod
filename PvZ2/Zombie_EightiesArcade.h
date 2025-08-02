#pragma once
#include "ZombieWithActionsProps.h"

class ZombieEightiesArcadeProps : public ZombieWithActionsProps
{
public:
	static void modInit();

	SexyString JamStyle;

	// new softcoded property
	SexyString PushedGridItemType = "eightiesarcadecabinet";

	static Reflection::CRefManualSymbolBuilder::BuildSymbolsFunc oZombieEightiesArcadePropsBuildSymbols;

	static void buildSymbols(Reflection::CRefManualSymbolBuilder* builder, Reflection::RClass* rclass)
	{
		oZombieEightiesArcadePropsBuildSymbols(builder, rclass);
		REGISTER_STRING_PROPERTY(builder, rclass, ZombieEightiesArcadeProps, PushedGridItemType);
	};
};