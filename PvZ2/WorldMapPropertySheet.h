#pragma once
#include "PropertySheetBase.h"

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