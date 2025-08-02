#pragma once
#include <Sexy/RtWeakPtr.h>
#include "ProjectilePropertySheet.h"

class PlantAction
{
public:
	int Type;
	Sexy::RtWeakPtr<ProjectilePropertySheet> Projectile;
	int ExplodeType;
	float ExplodeRadius;
	int TriggerType;
	bool DieAfterExplode;
	bool Burns;
	bool SecondaryAction;
	float InitialMinCooldownTime;
	float CooldownTimeMin;
	float CooldownTimeMax;
	int Damage;
	int SplashDamage;
	float XVelocityOverride;
	int PushbackAmount;
	float ChillDuration;
	float FreezeDuration;
	float StunDuration;
	SexyString ProjectileLaunchSound;
	Rect RectTriggerRange;
	SexyVector2 SpawnOffset;
};