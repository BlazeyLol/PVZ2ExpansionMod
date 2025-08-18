#pragma once
#include "ZombieWithActionsProps.h"

class ZombieEightiesArcadeProps : public ZombieWithActionsProps
{
public:
	SexyString JamStyle = "jam_8bit";
	SexyString GridItemType = "eightiesarcadecabinet";

	static Reflection::CRefManualSymbolBuilder::BuildSymbolsFunc oZombieEightiesArcadePropsBuildSymbols;
	static void modInit();

	static void* construct()
	{
		auto* props = new ZombieEightiesArcadeProps();

		typedef void* (*ctorWithThisPtr)(void*);
		ctorWithThisPtr baseCtor = (ctorWithThisPtr)getActualOffset(0x87B2A4);
		baseCtor(props);

		*reinterpret_cast<int*>(uintptr_t(props)) = getActualOffset(0x1C95AE4);
		return props;
	}

	static void buildSymbols(Reflection::CRefManualSymbolBuilder* builder, Reflection::RClass* rclass)
	{
		oZombieEightiesArcadePropsBuildSymbols(builder, rclass);
		REGISTER_STRING_PROPERTY(builder, rclass, ZombieEightiesArcadeProps, GridItemType);
	};
};