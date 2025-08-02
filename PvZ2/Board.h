#pragma once
#include "LevelDefinition.h"
#include "LevelModuleManager.h"
#include "Zombie.h"

#include <Sexy/RtWeakPtr.h>
#include <Sexy/RtObject.h>

#define GRID_TILE_WIDTH 64.0f
#define GRID_TILE_HEIGHT 76.0f
#define GRID_TILE_TOP 160.0
#define GRID_TILE_LEFT 200.0

#define BOARD_START_POS 232.0f
#define BOARD_END_POS 776.0f

class PresentRecord {
	SexyString presentTableName;
	uint seed;
	uint timeAwarded;
	uint timeOpened;
};

class RowPickingItem {
	int row;
	float weight;
	float lastPicked;
	float secondLastPicked;
};

class LootRollStats {
	int LootTotalCount;
	int SilverCount;
	int GoldCount;
	int DiamondCount;
	int PowerupCount;
	int NoKeyCount;
	int KeyCount;
};

// m_reasonPlayEnded
// m_destinationAfterBoard
// std::vector<Sexy::RtWeakPtr<void>> m_pushedAnimationMgr
// SexyString m_boardHolidayEventName
// m_watchedAdForPowerup
// m_track ThymedEventTrack
// m_eventsEndOfLevelFlag
// BoardLayerEffect m_layerEffectFastForward

// hypermodern?
// m_thymedEventID
// int64_t m_startLevelEpochTime

class Board
{
public:
	char pad_0000[148];
	int m_gridSizeX;
	int m_gridSizeY;
	int m_boardState;
	SexyString m_level;
	SexyString m_previousLevel;
	int m_levelNumber;
	int m_levelRandomIndex;
	pvztime_t m_levelStartTime;
	std::vector<SexyString> m_gameplayResources;
	int m_plantfoodCount;
	std::vector<PresentRecord> m_pendingPresentRewards;
	std::vector<Sexy::RtWeakPtr<void>> m_boardRegions;
	SexyVector3 m_finalDestroyedZombiePosition;
	int m_sunCurrency;
	int m_chooseRowUnk[5];
	float m_timeRowGotLawnMowered[5];
	RowPickingItem rowPickingArray[5];
	int m_cellType[9][5];
	bool m_cellLocked[9][5];
	uint m_plantfoodCountMax;
	LootRollStats m_lootRollStats;
	int m_activeStarIndex;
	bool m_levelPreviouslyCompleted;
	bool m_sunSpawningSuppressed;
	bool m_plantGrowthAndDecayPaused;
	bool m_plantsCanAttack;
	bool m_manualPlantsActive;
	bool m_pauseGameplayObjects;
	bool m_onlyDrawFade;
	bool unk2;
	bool m_gridItemsEnabled;
	char pad285[11];
	Sexy::RtWeakPtr<void> m_animationMgr;
	char pad298[56];
	int m_mowerLaunchesLeft;
	char pad2D4[32];
	SexyString m_collectableID_SunFromSky;
	Sexy::RtWeakPtr<LevelDefinition> m_levelDefinition;
	LevelModuleManager* m_levelModuleManager;
	char pad30C[4];
	std::vector<void*> m_cursors;
	char pad31C[16];
	std::u32string m_levelNameOverride;
	char pad338[8];
	Rect m_gridRect;
	char pad350[8];
	int m_levelNameTextWidgetPtr;
	char pad35C[64];
	std::vector<Zombie*> m_destroyedZombiesVec;
	std::vector<Zombie*> m_addedZombies;
	int m_fastForwardState;
	char pad3B8[8];
	int m_replayCost;
	char pad3C4[4];
	int m_bloverBlowAwayZombieCount;
	int m_tangleKelpedCount;
	int m_thawedIceblockCount;
	bool m_jestersSpawnedInLevel;
	bool m_jestersJuggled;
	bool m_wizardsSpawnedInLevel;
	bool m_wizardsSheepedPlant;
	bool m_zombieKilledByNonBanana;
	bool m_zombieKilledByBanana;
	bool m_plantedPhatBeet;
	bool m_plantedNonPhatBeet;
	bool m_fishermanSpawnedInLevel;
	bool m_fishermanHookedAPlant;
	bool m_weaselTouchedASliderTile;
	bool m_weaselSpawnedInLevel;
	int m_troglobitePushMinGridX;
	bool m_troglobitePushedABlock;
	bool m_excavatorSpawnedInLevel;
	bool m_excavatorShoveledAPlant;
	bool m_newspaperBurned;
	int m_goldLeafsPlantedCount;
	int m_tentSpawnCount;
	int m_thymewarpPlantedCount;
	bool m_boomboxSpawnedInLevel;
	bool m_boomboxBoomed;
	bool m_dinoSpawnedInLevel;
	bool m_dinoAffectedAZombie;
	bool m_allStarSpawned;
	bool m_allStarDestroyedPlant;
	bool pad3FA[2];
	int m_tRexKillCount;
	char pad400[0x190];
};

static_assert(sizeof(Board) == 0x590);
static_assert(offsetof(Board, m_boardRegions) == 0xE0);
static_assert(offsetof(Board, m_cellLocked) == 0x228);
static_assert(offsetof(Board, m_plantfoodCountMax) == 0x258);
static_assert(offsetof(Board, m_plantsCanAttack) == 0x27F);
static_assert(offsetof(Board, m_gridItemsEnabled) == 0x284);
static_assert(offsetof(Board, m_animationMgr) == 0x290);
static_assert(offsetof(Board, pad298) == 0x298);
static_assert(offsetof(Board, m_mowerLaunchesLeft) == 0x2D0);
static_assert(offsetof(Board, pad2D4) == 0x2D4);
static_assert(offsetof(Board, m_gridRect) == 0x340);
static_assert(offsetof(Board, pad3C4) == 0x3C4);
static_assert(offsetof(Board, m_levelNameTextWidgetPtr) == 0x358);
static_assert(offsetof(Board, m_troglobitePushMinGridX) == 0x3E0);
static_assert(offsetof(Board, m_allStarDestroyedPlant) == 0x3F9);
static_assert(offsetof(Board, m_addedZombies) == 0x3A8);

Board* getBoard();
uint getLawnApp();