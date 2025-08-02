#pragma once
#include "PopAnimRig.h"
#include "PropertySheetBase.h"

#define PLANTANIMRIG_DTOR_ADDR 0x2681CC

class PlantAnimRigPropertySheet : public PropertySheetBase
{
public:
	std::vector<SexyString> AttackAnimations;
};

class PlantCustomLayers {
	SexyString m_baseName;
};

class PlantAnimRig : public PopAnimRig
{
public:
	int m_stateAnimsCompleted;
	char unk1[24];
	int m_plantFoodPlayCount;
	int m_currentDamageStateIndex;
	int unk2;
	Sexy::DelegateBase m_plantFoodCallback;
	Sexy::DelegateBase m_firingCallback;
	Sexy::RtReflectionDelegateBase m_onPlantFoodMainStarted;
	Sexy::RtReflectionDelegateBase m_onPlantFoodMainLooped;
	Sexy::RtReflectionDelegateBase m_onPlantFoodMainEnded;
	std::vector<PlantCustomLayers> m_customizableLayers;
	int unk3;
	Sexy::RtWeakPtr<PlantAnimRigPropertySheet> m_props;
	int m_tier;
	int unk4;

	/*
	~PlantAnimRig() {
		typedef void (*unk1Destroy)(char*);
		((unk1Destroy)getActualOffset(0x276ED4))(unk1);

		typedef void (*unk2Destroy)(PlantAnimRig*);
		((unk2Destroy)getActualOffset(0x276FF8))(this);
	}
	*/ // I'm not the owner of these objects, so I don't worry about maintaining them

	virtual void Function32();
	virtual void Function33();
	virtual void PlayAttackBasedOnTier();
	virtual void PlayPlantFoodWithNoCallbacks();
	virtual void Function36();
	virtual void Function37();
	virtual void PlayHelpedOn();
	virtual void PlayHelped();
	virtual void PlayHelpedOff();
	virtual void PlayReload();
	virtual void PlayReloadLoop();
	virtual void PlayReloadEnd();
	virtual void PlayCharging();
	virtual void PlayCycling();
	virtual void Function46();
	virtual void Function47();
	virtual void Function48();
	virtual void Function49();
	virtual void Function50();
	virtual void Function51();
	virtual void PlayPlantFoodOn();
	virtual void PlayPlantFood();
	virtual void PlayPlantFoodOff();
	virtual void GetAttack();
	virtual void GetDamage();
	virtual void GetPlantFoodOn();
	virtual void GetPlantFood();
	virtual void GetPlantFoodOff();
	virtual void GetHelpedOn();
	virtual void GetHelped();
	virtual void GetHelpedOff();
	virtual void GetReload();
	virtual void GetReloadLoop();
	virtual void GetReloadEnd();
	virtual void GetCharging();
	virtual void GetCycling();
};

static_assert(sizeof(PlantAnimRig) == 0x278);
static_assert(offsetof(PlantAnimRig, m_plantFoodCallback) == 0x198);

