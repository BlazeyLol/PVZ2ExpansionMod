#pragma once
#include <vector>
#include "PropertySheetBase.h"
#include "BoardEntity.h"

#define ZOMBIEPROPS_VFTABLE_FUNC_COUNT 14

#define ZOMBIEPROPS_VFTABLE 0x1CB89D0
#define ZOMBIEPROPS_GETTYPE 0xA01550
#define ZOMBIEPROPS_CTOR 0x87AEF8

class ZombiePropertySheet : public PropertySheetBase
{
public:
	DEFINE_RT_CLASS_GET_CLASS_WRAPPER(ZOMBIEPROPS_GETTYPE);

	enum ZombieSize {
		normal,
		large,
		chicken,
		imp
	};

	enum HelmType {
		none,
		cone,
		bucket,
		sarcophagus,
		camelsign,
		poncho,
		metalplate,
		cowboyhat,
		gravestone,
		crown,
		surfboard,
		iceblock,
		shovel,
		brick
	};

	char pad_1C[12];
	float Speed;
	float SpeedVariance;
	float Hitpoints;
	float TimeToKillInSeconds;
	float EatDPS;
	float PowerUpDamageModifier;
	float FireDamageMultiplier;
	float FoeEatDamageReflectPct;
	float AlmanacScale;
	SexyVector2 AlmanacOffset;
	int Ammo;
	ZombieSize Size;
	bool CanSpawnPlantFood;
	bool CanTriggerZombieWin;
	bool CanSurrender;
	bool ExplodesWhenMowed;
	bool NormalDeathWhenMowed;
	bool IsValidPinchTarget;
	bool NormalDeathOnExplosion;
	bool ChillInsteadOfFreeze;
	bool CanBePlantTossedStrong;
	bool CanBePlantTossedWeak;
	bool SkipHeadDropState;
	float ArmDropFraction;
	HelmType Helm;
	float HelmHitpoints;
	int HelmDamageLayerIndices;
	bool HelmAbsorbsOverflowDamage;
	bool MetallicBodyParts;
	int GridHeight;
	Rect HitRect;
	Rect AttackRect;
	int Cost;
	int WavePointCost;
	int Weight;
	float ScoreOverride;
	SexyVector2 StreetSize;
	SexyVector2 StreetCriticalSize;
	SexyVector2 StreetOffset;
	float ArtScale;
	SexyVector2 ArtCenter;
	SexyVector3 ShadowOffset;
	SexyVector2 ShadowScaling;
	SexyString GroundTrackName;
	SexyVector2 ArtCenterBurnEffectOffset;
	Point GridExtents;
	SexyVector2 HypnoshroomEffectOffset;
	std::vector<int> ZombieStats;
	std::vector<Sexy::RtWeakPtr<void>> ZombieArmorProps;
	std::vector<int> ConditionImmunities;
	bool IgnoreWaterLine;
	float MaxTideLoweredPercent;
	SexyString SoundOnDeath;
	SexyString SoundOnTakeDamage;
	SexyString SoundOnWalk;
	SexyString SoundOnEat;
	SexyString SoundOnIdle;
	SexyString SoundOnAsh;
	SexyString SoundOnElectrocute;
	bool CanBeFlicked;
	bool CanBeFlickedOff;
	bool FlickIsLaneRestricted;
	bool IsSpawnedFlying;
	float ShrunkenScale;
	float unk;
};

static_assert(sizeof(ZombiePropertySheet) == 0x198);
static_assert(offsetof(ZombiePropertySheet, Speed) == 0x28);
static_assert(offsetof(ZombiePropertySheet, SpeedVariance) == 0x2C);
static_assert(offsetof(ZombiePropertySheet, AlmanacOffset) == 0x4C);
static_assert(offsetof(ZombiePropertySheet, ArmDropFraction) == 0x68);
static_assert(offsetof(ZombiePropertySheet, HelmHitpoints) == 0x70);
static_assert(offsetof(ZombiePropertySheet, HitRect) == 0x80);
static_assert(offsetof(ZombiePropertySheet, ScoreOverride) == 0xAC);
static_assert(offsetof(ZombiePropertySheet, ShadowScaling) == 0xE0);
static_assert(offsetof(ZombiePropertySheet, GroundTrackName) == 0xE8);
static_assert(offsetof(ZombiePropertySheet, ArtCenterBurnEffectOffset) == 0xF4);
static_assert(offsetof(ZombiePropertySheet, GridExtents) == 0xFC);
static_assert(offsetof(ZombiePropertySheet, HypnoshroomEffectOffset) == 0x104);
static_assert(offsetof(ZombiePropertySheet, MaxTideLoweredPercent) == 0x134);
static_assert(offsetof(ZombiePropertySheet, ShrunkenScale) == 0x190);