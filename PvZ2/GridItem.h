#pragma once
#include "BoardEntity.h"
#include "GridItemPropertySheet.h"
#include "EntityConditions.h"
#include "AttachedEffectManager.h"
#include "ObjectTypeDescriptor.h"

// the reflected fields are not checked!
// todo: fix the field order
class GridItemType : public ObjectTypeDescriptor
{
public:
	SexyString GridItemClass;
	std::vector<SexyString> ResourceGroups;
	std::vector<SexyString> AudioGroups;
	Sexy::RtWeakPtr<GridItemPropertySheet> Properties;
};

class GridItem : public BoardEntity
{
public:
	// AttachedEffectManager m_attachedEffects
	int unk;
	GridItemConditionTracker m_conditionTracker;
	char unk2[76];
	Sexy::RtWeakPtr<GridItemType> m_type;
	float m_health;
	float m_healthMax;
	Point m_gridLocation;
	Sexy::RtWeakPtr<GridItemPropertySheet> m_props;

	static GridItem* getByName(const SexyString& gridItemName)
	{
		typedef GridItem* (*func716690)(Board*, SexyString, int, int);
		func716690 func_716690 = (func716690)getActualOffset(0x716690);
		return func_716690(getBoard(), gridItemName, 0, 0);
	}
};

static_assert(sizeof(GridItem) == 0xF0);
static_assert(offsetof(GridItem, unk2) == 0x84);
static_assert(offsetof(GridItem, m_conditionTracker) == 0x68);