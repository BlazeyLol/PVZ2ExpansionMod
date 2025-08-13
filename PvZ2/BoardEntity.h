#pragma once
#include "ModularRealObject.h"
#include "Components.h"

#define OFFSET_BOARDENTITY_DIE 0x53F498

class BoardEntity : public ModularRealObject
{
public:
	int m_level;
	int m_unk0x3C;
	Rect m_collisionRect;
	int m_boardEntityFlags;
	int m_unk0x54;
	Sexy::RtWeakPtr<ComponentRunner> m_componentRunner;
	float m_createdTime;

	void Die() {
		typedef void (*DieFunc)(BoardEntity*);
		((DieFunc)getActualOffset(OFFSET_BOARDENTITY_DIE))(this);
	}

	void GetGridCoords(int* res) {
		res[0] = (this->m_position.x - 200.0) / 64.0;
		res[1] = (this->m_position.y - 160.0) / 76.0;
	}

	virtual void Function35() {};
	virtual void Function36() {};
	virtual void Function37() {};
	virtual void Function38() {};
	virtual void Function39() {};
	virtual void Function40() {};
	virtual void Function41() {};
	virtual void Function42() {};
	virtual void Function43() {};
	virtual void Function44() {};
	virtual void Function45() {};
	virtual void Function46() {};
	virtual void Function47() {};
	virtual SexyString* GetTypeName() {};
	virtual void OnSpawn() {};
};

class BoardEntityStat
{
public:
	int Type;
	int Value;
};