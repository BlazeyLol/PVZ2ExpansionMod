#pragma once
#include "PropertySheetBase.h"

using Reflection::RCustomType::TStdVectorManipulator;

class BoardPropertySheet : public PropertySheetBase
{
public:
	float PlantTargetingXThreshold;
	uint16_t MaxSunCurrency;
	float ZombieThreatLowAlert_TriggerPositionX;
	float ZombieThreatHighAlert_TriggerPositionX;
	float ZombieThreatLowAlert_StarChallengeOffsetX;
	float ZombieThreatHighAlert_StarChallengeOffsetX;
	float ZombieThreatLowAlert_ProtectPlantOffsetX;
	float ZombieThreatHighAlert_ProtectPlantOffsetX;
	int CoinAlert_LowBalanceThreshold;
	std::vector<SexyString> RequiredSubsystems;
	float ZombieTideMaxHeightPct;
	float DefaultTideMaxHeightPct;
	float MaxTideDropoffDistance;
	std::vector<float> DynamicDifficultyMowerImmunity;
	std::vector<float> DynamicDifficultyMowerCooldown;
	float DangerRoomMowerImmunity;
	float DangerRoomMowerCooldown;
	std::vector<SexyString> LastStandPlantExcludelist;
	std::vector<SexyString> PlantFrostExcludelist;
	std::vector<SexyString> ProtectThePlantAdditionalPlantingExcludelist;
	std::vector<SexyString> PlantSmashAttackExcludelist;

	// new stuff
	std::vector<SexyString> ZombiePianoList;

	static void modInit();
	static Reflection::CRefManualSymbolBuilder::BuildSymbolsFunc oBoardPropertySheetBuildSymbols;

	static void buildSymbols(Reflection::CRefManualSymbolBuilder* builder, Reflection::RClass* rclass)
	{
		oBoardPropertySheetBuildSymbols(builder, rclass);
		LOGI("Building symbols for BoardPropertySheet");
		REGISTER_STRING_VECTOR_PROPERTY(builder, rclass, BoardPropertySheet, ZombiePianoList);
	}
};