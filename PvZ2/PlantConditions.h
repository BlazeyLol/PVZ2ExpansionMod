#pragma once
#include <vector>
#include "EntityConditions.h"
#include <Sexy/RtWeakPtr.h>

enum PlantConditions
{
	plant_rapidfire = 0,
	plant_squdiifed = 1,
	plant_sheeped = 2,
	plant_damageflash = 3,
	plant_plantfoodflash = 4,
	plant_highlighted = 5,
	plant_icecubed = 6,
	plant_froststage1 = 7,
	plant_froststage2 = 8,
	plant_notfiring = 9,
	plant_stunnedbyzombielove = 10,
	plant_shadowboosted = 11,
	plant_supershadowboosted = 12,
	plant_swapping = 13,
	plant_liftedoff = 14,
	plant_net = 15,
	plant_sauced = 16,
	plant_pvineboosted1 = 17,
	plant_pvineboosted2 = 18,
	plant_pvineboosted3 = 19,
	plantgroup_icecubed = 20,
	plantgroup_squidified = 21,
	plantgroup_sheeped = 22,
	plantgroup_net = 23,
	plantgroup_sauced = 24,
	plant_unk6 = 25,
};

class PlantConditionTracker
{
public:
	std::vector<uint8_t> m_conditionFlags;
	std::vector<EntityCondition> m_conditions;
	char unk[32];
	int m_shaderOverrideColorRed;
	int m_shaderOverrideColorBlue;
	int m_shaderOverrideColorGreen;
	int m_shaderOverrideColorAlpha;
	int m_unkColorTrackerRed;
	int m_unkColorTrackerBlue;
	int m_unkColorTrackerGreen;
	int m_unkColorTrackerAlpha;
	int unk2;
	Sexy::RtWeakPtr<void> unkPtr;

	bool HasCondition(PlantConditions condition) {
		return m_conditionFlags[condition] > 0;
	}

	virtual void Function0() {};
	virtual void Function1() {};
	virtual void Function2() {};
	virtual void Function3() {};
};

static_assert(sizeof(PlantConditionTracker) == 0x68);
