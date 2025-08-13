#pragma once
#include "Zombie.h"
#include "ZombiePropertySheet.h"

class ZombieCamel : public Zombie
{
public:
	static void modInit();

	enum ZombieCamelSegmentType {
		none,
		head,
		body,
		tail
	};

	// there are more fields
	// but they are useless
	ZombieCamelSegmentType m_camelType;
};

class ZombieCamelProps : public ZombiePropertySheet
{
public:
	int CamelSegmentOffset;
	int CamelSegmentTooCloseBuffer;
	int CamelSegmentTooFarBuffer;
	int WalkCycleOffset;
	int SpawnManyCamelSegmentAtPosition;
	bool PropagateSignDestruction;
	bool OnlyHeadZombieEats;
	float SurprisedTime;
	bool DropArmOnSignDrop;
	bool SwitchToHeadCamelSign;

	// it doesnt work :sob:
	SexyString SegmentType;
	char pad[16];
	SexyString SegmentZombieType;
	char pad2[4];
	int SegmentCount;

	static Reflection::CRefManualSymbolBuilder::BuildSymbolsFunc oZombieCamelPropsBuildSymbols;

	static void buildSymbols(Reflection::CRefManualSymbolBuilder* builder, Reflection::RClass* rclass)
	{
		oZombieCamelPropsBuildSymbols(builder, rclass);
		REGISTER_STRING_PROPERTY(builder, rclass, ZombieCamelProps, SegmentType);
		REGISTER_STRING_PROPERTY(builder, rclass, ZombieCamelProps, SegmentZombieType);
		REGISTER_STANDARD_PROPERTY(builder, rclass, ZombieCamelProps, SegmentCount);
	}
};

#ifdef A32
static_assert(offsetof(ZombieCamelProps, CamelSegmentOffset) == 0x198);
static_assert(offsetof(ZombieCamelProps, SpawnManyCamelSegmentAtPosition) == 0x1A8);
static_assert(offsetof(ZombieCamelProps, SurprisedTime) == 0x1B0);
static_assert(offsetof(ZombieCamelProps, SegmentType) == 0x1B8);
#else
#endif

//class ZombieCamelTouchProps : public ZombieCamelProps
//{
//public:
//	float PostMatchStunChance;
//	float PostMatchStunDuration;
//};
//
//static_assert(offsetof(ZombieCamelTouchProps, PostMatchStunChance) == 0x1D0);
//static_assert(offsetof(ZombieCamelTouchProps, PostMatchStunDuration) == 0x1D4);