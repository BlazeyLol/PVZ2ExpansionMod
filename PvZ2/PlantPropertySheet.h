#pragma once
#include <map>
#include <vector>

#include "BoardEntity.h"
#include "Plant.h"
#include "PropertySheetBase.h"

#define PLANTPROPS_VFTABLE_FUNC_COUNT 14

#define PLANTPROPS_VFTABLE 0x1C5F700
#define PLANTPROPS_GETTYPE 0x2AFF48
#define PLANTPROPS_CTOR 0x2B17D4

class PlantBoost
{
public:
	Sexy::RtWeakPtr<void> PlantBoostProps;
	int Value;
	int CooldownDurationSeconds;
};

class PowerSet
{
public:
	std::vector<int> List;
};

class PlantPropertySheet : public PropertySheetBase
{
public:
	DEFINE_RT_CLASS_GET_CLASS_WRAPPER(PLANTPROPS_GETTYPE);

	SexyString TypeName;
	int Cost;
	int BeghouledCost;
	float Hitpoints;
	float PacketCooldown;
	float StartingCooldown;
	float PlantFoodDurationSeconds;
	int PlantFoodPlayCount;
	float PlantFoodShineTime = 0.75f;
	SexyString PlantfoodActivationSound;
	SexyString HelpedActivationSound;
	int PlantGridType;
	int MultiPlantLayer = 1;
	std::vector<PlantAction> Actions;
	PowerSet Powers;
	int GridWidth = 1;
	int GridHeight = 1;
	int GridItemDamage;
	float PlantingOffsetY;
	SexyVector2 CursorPreviewOffset;
	SexyVector2 ArtCenter;
	SexyVector2 ZenGardenOffset;
	float ZenGardenSmallScale = 0.6f;
	float ZenGardenLargeScale = 1.2f;
	Rect HitRectAdjust;
	int Height = 2;
	int DangerRoomWeight = 100;
	bool IsZenGardenTreasurePlant;
	bool IsZenGardenWaterPlant;
	int ZenGardenSproutWeight;
	int ZenGardenBoostCost;
	int ZenGardenDurationOverrideSeconds = -1;
	std::vector<PlantBoost> Boosts;
	Rect RestrictPlantingToGridArea;
	std::vector<BoardEntityStat> PlantStats;
	std::vector<SexyString> ValidStages;
	std::vector<SexyString> SuggestionAlts;
	bool CanReciveFirstAid;
	bool IsConsumable;
	bool IsInstant;
	bool CanLiveOnWaves;
	bool CanPlantAgainToUpgrade;
	std::map<SexyString, int> IdleAnimationWeights;
	Sexy::RtWeakPtr<void> AnimRigProps;
	bool HidePlantingEffects;
	float MasteryBoostChance;
	float MasteryResistancePiercing;
};

static_assert(sizeof(PlantPropertySheet) == 0x140);
static_assert(offsetof(PlantPropertySheet, PlantGridType) == 0x60);
static_assert(offsetof(PlantPropertySheet, ArtCenter) == 0x98);
static_assert(offsetof(PlantPropertySheet, IdleAnimationWeights) == 0x120);