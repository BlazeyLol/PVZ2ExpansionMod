#pragma once
#include "PropertySheetBase.h"

enum ToggleCategory
{
	dev,
	live,
	camp
};

class Toggle
{
	SexyString Key;
	bool Enabled;
	SexyString DisplayName;
	ToggleCategory Category;
};

class PVZLiveConfig : public PropertySheetBase
{
public:
	int CDNRefreshMinutes;
	int LODEventTime;
	int LoadingTextCycleTime;
	float CDNDownloadTimeoutSeconds;
	float CDNForceDownloadTimeoutSeconds;
	float CDNCacheExpirationMinutes;
	float DraperLocalNotesPollFrequency;
	SexyString SeasonalCostumeLayers;
	SexyString TestIdSeedKey;
	SexyString TitleBackground;
	bool TitleShowLogo;
	std::vector<Toggle> Toggles;
};