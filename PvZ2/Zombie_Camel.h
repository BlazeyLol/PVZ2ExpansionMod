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

	ZombieCamelSegmentType m_camelType;

	// unsure of the order
	bool m_isACamel;
	bool m_tooCloseToPrev;
	bool m_tooFarFromNext;
	int m_signDamageIndex;
	bool m_spawnDeathAnim;
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

static_assert(offsetof(ZombieCamelProps, CamelSegmentOffset) == 0x198);
static_assert(offsetof(ZombieCamelProps, SpawnManyCamelSegmentAtPosition) == 0x1A8);
static_assert(offsetof(ZombieCamelProps, SurprisedTime) == 0x1B0);
static_assert(offsetof(ZombieCamelProps, SegmentType) == 0x1B8);

//class ZombieCamelTouchProps : public ZombieCamelProps
//{
//public:
//	float PostMatchStunChance;
//	float PostMatchStunDuration;
//};
//
//static_assert(offsetof(ZombieCamelTouchProps, PostMatchStunChance) == 0x1D0);
//static_assert(offsetof(ZombieCamelTouchProps, PostMatchStunDuration) == 0x1D4);