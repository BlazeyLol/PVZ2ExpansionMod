#pragma once

class WorldMap
{
public:
	char pad_0000[304];
	float m_posX;
	float m_posY;
	Rect m_boundingRect;
};

static_assert(offsetof(WorldMap, m_posX) == 0x130);
static_assert(offsetof(WorldMap, m_posY) == 0x134);
static_assert(offsetof(WorldMap, m_boundingRect) == 0x138);