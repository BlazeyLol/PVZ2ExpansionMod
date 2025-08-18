#pragma once
#include "BoardEntity.h"
#include "ZombiePropertySheet.h"
#include "EntityConditions.h"
#include "Plant.h"
#include "ZombieType.h"
#include "ZombieAnimRig.h"

#define ZOMBIE_VFUNC_COUNT 204

#define ZOMBIE_VFTABLE_ADDR 0x1CAE3B8

#define OFFSET_ZOMBIE_GETTYPE 0x89E20C

#define ZOMBIE_DTOR_ADDR 0x8A2D98
#define ZOMBIE_ISDEADORDYING_ADDR 0x0

#define ZOMBIE_CTOR_ADDR 0x8A2834

class Zombie : public BoardEntity
{
public:
	int m_helm;
	float m_helmHitpoints;
	char pad_006C[12];
	Sexy::RtWeakPtr<ZombieType> m_type;
	Sexy::RtWeakPtr<ZombieAnimRig> m_animRig;
	char pad_0088[88];
	double m_elapsedTimeInState;
	float m_stateMachineTimeScale;
	int32_t m_playingAnim;
	int32_t m_zombieFlags;
	int32_t m_facing;
	float m_hitpoints;
	float m_maxHitpoints;
	bool m_isTimeToKillActive;
	char pad_0101[3];
	float m_timeToKill;
	float m_speedScale;
	float m_dpsScale;
	float m_damageScale;
	float m_shrunkenDamageScale;
	float m_walkSpeed;
	float m_translationMultiplier;
	float m_maxHelmHitpoints;
	int32_t m_spawnedFromWave;
	float m_nextChewSoundTime;
	float m_mowedStartTime;
	float m_flickedStartTime;
	struct SexyVector3 m_flickOffStartPosition;
	struct SexyVector3 m_flickOffTarget;
	float m_flickOffTimeToTarget;
	float m_flickOffFinalRotation;
	float m_rotation;
	float m_scale;
	int32_t m_zombieRenderLayerOffset;
	Sexy::RtWeakPtr<Plant> m_ownerPlant;
	Sexy::RtWeakPtr<Sexy::RtWeakPtr<Sexy::RtObject>> m_forcedTarget;
	char pad_0170[24];
	struct SexyVector2 m_stormTargetLocation;
	int32_t m_stormType;
	std::vector<Sexy::RtWeakPtr<void>> m_armor;
	ZombieConditionTracker m_conditionTracker;
	int trackerPad[21];
	char pad_0210[190];
	std::vector<int> m_familyResistances;
	std::vector<Sexy::RtWeakPtr<Sexy::RtObject>> m_targetHistory;
	int32_t m_loot;
	Sexy::Color m_highlightColor;
	bool m_isBeingDestroyed;
	bool m_wasMowedDown;
	Sexy::RtWeakPtr<ZombiePropertySheet> m_propertySheet;

	~Zombie() {
		typedef Zombie* (*zombieDtor)(Zombie*);
		((zombieDtor)getActualOffset(ZOMBIE_DTOR_ADDR))(this);
	}

	bool IsDeadOrDying() {
		typedef bool (*isDeadOrDying)(Zombie*);
		return ((isDeadOrDying)getActualOffset(ZOMBIE_ISDEADORDYING_ADDR))(this);
	}

	DEFINE_RT_CLASS_GET_CLASS_WRAPPER(OFFSET_ZOMBIE_GETTYPE);

	virtual FPoint GetShadowScaling() {}
	virtual void Function51() {}
	virtual void Function52() {}
	virtual int UpdateHelmDegrades() {}
	virtual int GetTotalHitpoints() {}
	virtual void Function55() {}
	virtual void Function56() {}
	virtual void SpawnFromGround() {}
	virtual void Function58() {}
	virtual void RiseFromPod() {}
	virtual void SetFlagType() {} // for flag zombies
	virtual void EnterIdle() {}
	virtual void EnterWalk() {}
	virtual void EnterGrabbed() {}
	virtual void ActivateJam() {}
	virtual void DeactivateJam() {}
	virtual void Function66() {}
	virtual void Function67() {}
	virtual int ApplyStun(float duration, PlantFramework* instigator) {}
	virtual int ApplyStunWithoutInstigator(float duration) {}
	virtual bool IsStunned() {}
	virtual void Function71() {}
	virtual void Function72() {}
	virtual void Function73() {}
	virtual void Die(int unk) {}
	virtual void ThreatAlert() {} // runs when zombie is close to house
	virtual void Function76() {}
	virtual void Function77() {}
	virtual void Function78() {}
	virtual void Function79() {}
	virtual void Function80() {}
	virtual bool HasArmDrop() {}
	virtual void Function82() {}
	virtual void Function83() {}
	virtual void Function84() {}
	virtual void Function85() {}
	virtual void Function86() {}
	virtual void Function87(Sexy::Graphics* g) {}
	virtual void Function88() {}
	virtual void Function89() {}
	virtual void Function90() {}
	virtual void Function91() {}
	virtual void Function92() {}
	virtual void Function93() {}
	virtual void Function94() {}
	virtual void Function95() {}
	virtual void Function96() {}
	virtual void Function97() {}
	virtual void Function98() {}
	virtual void Function99() {}
	virtual void Function100() {}
	virtual void Function101() {}
	virtual void Function102() {}
	virtual void Function103() {}
	virtual void Function104() {}
	virtual void Function105() {}
	virtual void Function106() {}
	virtual int GetTideEffect() {}
	virtual void* FindAttackTarget() {}
	virtual void Function109() {}
	virtual void Function110() {}
	virtual void Function111() {}
	virtual void Function112() {}
	virtual void Function113() {}
	virtual void Function114() {}
	virtual void Function115() {}
	virtual void Function116() {}
	virtual void Function117() {}
	virtual float GetWalkSpeed() {}
	virtual void Function119() {}
	virtual void IdleOnEnter(int unk) {} // weird argument
	virtual void IdleOnLoop() {}
	virtual void IdleOnExit() {}
	virtual void WalkOnEnter() {}
	virtual void WalkOnLoop() {}
	virtual void WalkOnExit() {}
	virtual void EatOnEnter() {}
	virtual void EatOnLoop() {}
	virtual void EatOnExit() {}
	virtual void BleedingOutOnEnter() {}
	virtual void BleedingOutOnLoop() {}
	virtual void BleedingOutOnExit() {}
	virtual void DieOnEnter() {}
	virtual void DieOnLoop() {}
	virtual void DieOnExit() {}
	virtual void ElectrocuteOnEnter() {}
	virtual void ElectrocuteOnLoop() {}
	virtual void ElectrocuteOnExit() {}
	virtual void AshOnEnter() {}
	virtual void AshOnLoop() {}
	virtual void AshOnExit() {}
	virtual void MowedDownOnEnter() {}
	virtual void MowedDownOnLoop() {}
	virtual void MowedDownOnExit() {}
	virtual void FlickedOffOnEnter() {}
	virtual void FlickedOffOnLoop() {}
	virtual void FlickedOffOnExit() {}
	virtual void WinningOnEnter() {}
	virtual void WinningOnLoop() {}
	virtual void WinningOnExit() {}
	virtual void PlantifyOnEnter() {}
	virtual void PlantifyOnLoop() {}
	virtual void PlantifyOnExit() {}
	virtual void GrabbedOnEnter() {}
	virtual void GrabbedOnLoop() {}
	virtual void GrabbedOnExit() {}
	virtual void RiseFromGroundOnEnter() {}
	virtual void RiseFromGroundOnLoop() {}
	virtual void RiseFromGroundOnExit() {}
	virtual void RiseFromStormOnEnter() {}
	virtual void RiseFromStormOnLoop() {}
	virtual void RiseFromStormOnExit() {}
	virtual void StormEntranceOnEnter() {}
	virtual void StormEntranceOnLoop() {}
	virtual void StormEntranceOnExit() {}
	virtual void RiseFromPodOnEnter() {}
	virtual void RiseFromPodOnLoop() {}
	virtual void RiseFromPodOnExit() {}
	virtual void Function168() {}
	virtual void Function169() {}
	virtual void OnActionCommand(SexyString* currentAnim, int unk1, SexyString* actionName, int unk2) {}
	virtual void Function171() {}
	virtual void Electrocute() {}
	virtual void Ash() {}
	virtual void Function174() {}
	virtual void Function175() {}
	virtual void Function176() {}
	virtual void Function177() {}
	virtual void Function178() {}
	virtual void Function179() {}
	virtual void KillWithFatalDamage() {}
	virtual void Function181() {}
	virtual void Function182() {}
	virtual void Function183() {}
	virtual void Function184() {}
	virtual void Function185() {}
	virtual void Function186() {}
	virtual void Function187() {}
	virtual void Function188() {}
	virtual SexyString GetElectrocuteEffectName() {}
	virtual SexyString GetAshEffectName() {}
	virtual void Function191() {}
	virtual void Function192() {}
	virtual void Function193() {}
	virtual float GetArmDropFraction() {}
	virtual void Function195() {}
	virtual DamageInfo GetAttackDamage() {}
	virtual void OnDeath() {}
	virtual SexyVector3 Function198() {} // get some offset of the zombie's position
	virtual void Function199() {}
	virtual void Function200() {}
	virtual void PlaySoundOnWalk() {}
	virtual void PlaySoundOnIdle() {}
	virtual void PlaySoundOnEat() {}
};

static_assert(offsetof(Zombie, m_conditionTracker) == 0x1A0);
static_assert(offsetof(Zombie, pad_0210) == 0x210);