#pragma once
#include "PropertySheetBase.h"
#include "CollisionTypeFlags.h"
#include "DamageTypeFlags.h"
#include "ZombieConditions.h"

#include <Sexy/Color.h>

#define PROJECTILEPROPS_VFTABLE_FUNC_COUNT 14

#define PROJECTILEPROPS_GETTYPE 0x317058
#define PROJECTILEPROPS_CTOR 0x29D4A4
#define PROJECTILEPROPS_VFTABLE 0x1C62EB0

class ZombieConditionEntry {
	ZombieConditions Condition;
	ValueRange Duration;
};

class ProjectilePropertySheet : public PropertySheetBase
{
public:
	DEFINE_RT_CLASS_GET_CLASS_WRAPPER(PROJECTILEPROPS_GETTYPE);

	SexyString ClassName = "Projectile";
	float BaseDamage;
	float HealAmount;
	char pad0030[0x10];
	float SplashDamage;
	float StunDuration;
	float SplashRadius;
	float SplashRadiusBaseDamageCutoff;
	bool ShakeBoardOnSplash;
	bool DiesOnImpact = true;
	bool HasShadow = true;
	bool ImpactShowsAtZombieFeet;
	bool RotateToMatchVelocity;
	bool ImpactSoundForce;
	bool FollowsGround;
	ZombieConditions OverrideStunCondition = zombie_condition_none;
	std::vector<ValueRange> InitialVelocity;
	std::vector<ValueRange> InitialAcceleration;
	std::vector<ValueRange> InitialVelocityScale;
	ValueRange InitialHeight;
	ValueRange InitialRotation;
	ValueRange InitialAngularVelocity;
	ValueRange InitialScale = ValueRange(1.0f, 1.0f);
	SexyString AttachedPAM;
	SexyString AttachedPAMAnimRigClass;
	SexyVector2 AttachedPAMOffset;
	std::vector<SexyString> AttachedPAMAnimationToPlay;
	SexyString ShadowImage = "IMAGE_PEA_SHADOWS";
	SexyString RenderImage;
	Sexy::Color RenderColor;
	FRect CollisionRect;
	SexyString ImpactSoundEvent;
	float ImpactSoundThrottleTimer;
	SexyString ImpactPAM;
	std::vector<SexyString> ImpactPAMAnimationToPlay;
	std::vector<ValueRange> ImpactOffset;
	SexyString SpawnPAM;
	std::vector<SexyString> SpawnPAMAnimationToPlay;
	std::vector<ValueRange> SpawnPAMOffset;
	std::vector<ZombieConditionEntry> Conditions;
	SexyVector2 AttachedPAMEffectOffset;
	std::vector<CollisionTypeFlags> CollisionFlags;
	std::vector<DamageTypeFlags> DamageFlags;
};

static_assert(sizeof(ProjectilePropertySheet) == 0x188);
static_assert(offsetof(ProjectilePropertySheet, ImpactPAM) == 0x114);
static_assert(offsetof(ProjectilePropertySheet, InitialScale) == 0x98);
static_assert(offsetof(ProjectilePropertySheet, OverrideStunCondition) == 0x58);