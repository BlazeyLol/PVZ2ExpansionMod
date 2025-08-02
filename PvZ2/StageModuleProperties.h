#pragma once
#include "LevelModuleProperties.h"

#define STAGEMODULEPROPS_GETCLASS_ADDR 0x4AF920
#define STAGEMODULEPROPS_VTBL 0x1C71840
#define STAGEMODULEPROPS_VFUNCS 18
#define STAGEMODULEPROPS_CONSTRUCT_ADDR 0x31DCB8

class StageModuleProperties : public LevelModuleProperties
{
public:
	char pad0048[4];
	SexyString BackgroundResourceGroup;
	SexyString BackgroundImagePrefix;
	SexyString StagePrefix;
	SexyString BasicZombieTypeName;
	SexyString FlagZombieTypeName;
	std::vector<SexyString> FlagVeteranZombieTypenames;
	SexyString Armor1ZombieTypeName;
	SexyString Armor2ZombieTypeName;
	SexyString Armor4ZombieTypeName;
	SexyString MusicSuffix;
	SexyString MusicSuffixMinigame;
	SexyString AmbientAudioSuffix;
	SexyString RailcartDefaultTypeName;
	SexyString GravestoneDefaultTypeName;
	SexyString DirtSpawnEffectName;
	SexyString ZombieEventAudio;
	SexyString LevelPowerupSet;
	std::vector<Point> DisabledStreetCells;
	SexyString ProgressFlagAsset;
	SexyString StarChallengeUnlockLevel;
};

static_assert(sizeof(StageModuleProperties) == 0x13C);
static_assert(offsetof(StageModuleProperties, RailcartDefaultTypeName) == 0xDC);