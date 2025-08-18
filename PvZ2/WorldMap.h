#pragma once
#include "PropertySheetBase.h"

class WorldMap
{
public:
	char pad_0000[304];
	float m_posX;
	float m_posY;
	int m_boundaryX;
	int m_boundaryY;
	int m_boundaryWidth;
	int m_boundaryHeight;
};

class WorldMapPropertySheet : public PropertySheetBase
{
public:
	float ParallaxSpeedLayerForeground4;
	float ParallaxSpeedLayerForeground3;
	float ParallaxSpeedLayerForeground2;
	float ParallaxSpeedLayerForeground1;
	float ParallaxSpeedLayer1;
	float ParallaxSpeedLayer2;
	float ParallaxSpeedLayer3;
	float ParallaxSpeedLayer4;
	float ParallaxSpeedLayer5;
	float ParallaxSpeedLayer6;
	float ParallaxSpeedLayer7;
	float ParallaxSpeedLayer8;
	float ParallaxSpeedLayer9;
	float ParallaxSpeedLayer10;
	float PathUnlockSpeed;
	SexyVector2 SnapGrid;
	float EditorSafeZoneYStart;
	float EditorSafeZoneYEnd;

	std::vector<SexyString> EnableVerticalScrollingInWorlds;
};

static_assert(offsetof(WorldMap, m_posX) == 0x130);
static_assert(offsetof(WorldMap, m_posY) == 0x134);
static_assert(offsetof(WorldMap, m_boundaryX) == 0x138);