#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unistd.h>

#include "PVZ2ExpansionMod.h"

#include <Sexy/SexyApp.h>

#include "PvZ2/Board.h"
#include "PvZ2/BoardPropertySheet.h"
#include "PvZ2/PlantType.h"
#include "PvZ2/WorldMap.h"
#include "PvZ2/ZombieType.h"

#include "PvZ2/Plant_PowerLily.h"
#include "PvZ2/Zombie_EightiesArcade.h"
#include "PvZ2/Zombie_Camel.h"

#include <Furr/OverrideSunCollectableModule.h>


#pragma region Alias to ID

class ZombieAlmanac
{
public:
    void* vftable;
    std::map<SexyString, int> m_aliasToId;
};

class PlantNameMapper
{
public:
    void* vftable;
    std::map<SexyString, int> m_aliasToId;
};

// used for the custom id system
// can be used for typename list for restriction sets
std::vector<PlantType*> g_modPlantTypenames;
std::vector<ZombieType*> g_modZombieTypenames;

#define REGISTER_PLANT_TYPENAME(typename) \
    g_modPlantTypenames.push_back(typename); \

#define REGISTER_ZOMBIE_TYPENAME(typename) \
    g_modZombieTypenames.push_back(typename); \

typedef void* (*plantTypeCtor)(PlantType*);
plantTypeCtor oPlantTypeCtor = nullptr;

void* hkPlantTypeCtor(PlantType* self)
{
    REGISTER_PLANT_TYPENAME(self);
    return oPlantTypeCtor(self);
}

typedef PlantNameMapper* (*PlantNameMapperCtor)(PlantNameMapper*);
PlantNameMapperCtor oPlantNameMapperCtor = nullptr;

void* hkCreatePlantNameMapper(PlantNameMapper* self)
{
    oPlantNameMapperCtor(self);
    self->m_aliasToId.clear();

    for (size_t iter = 0; iter < g_modPlantTypenames.size(); iter++)
    {
        PlantType* type = g_modPlantTypenames[iter];
        self->m_aliasToId[type->TypeName] = type->IntegerID;
        //LOGI("Registered plant typename %s with ID %d", type->TypeName.c_str(), type->IntegerID);
    }

    return self;
}

typedef void* (*zombieTypeCtor)(ZombieType*);
zombieTypeCtor oZombieTypeCtor = nullptr;

void* hkZombieTypeCtor(ZombieType* self)
{
    REGISTER_ZOMBIE_TYPENAME(self);
    return oZombieTypeCtor(self);
}

typedef ZombieAlmanac* (*ZombieAlmanacCtor)(ZombieAlmanac*);
ZombieAlmanacCtor oZombieAlmanacCtor = nullptr;

void* hkCreateZombieTypenameMap(ZombieAlmanac* self)
{
    oZombieAlmanacCtor(self);
    self->m_aliasToId.clear();

    for (size_t iter = 0; iter < g_modZombieTypenames.size(); iter++)
    {
        auto* type = g_modZombieTypenames[iter];
        self->m_aliasToId[type->TypeName] = type->IntegerID;
        //LOGI("Registered zombie typename %s with ID %d", type->TypeName.c_str(), type->IntegerID);
    }

    return self;
}

#pragma endregion

#pragma region Mummy Memory Fix

#ifdef A32
#define CAMEL_MINIGAME_MODULE_FUNC 0x78CFA0
#else
#define CAMEL_MINIGAME_MODULE_FUNC 0xB1BE04
#endif

typedef void(*camelMinigameModuleFunc)(int, int, int);
camelMinigameModuleFunc cmmFunc = (camelMinigameModuleFunc)getActualOffset(CAMEL_MINIGAME_MODULE_FUNC);

void hkCamelZombieFunc(int a1, int a2, int a3)
{
    // Redirect call to some function in CamelMinigameModule
    // This fixes the crash when camels are rising from the ground
    cmmFunc(a1, a2, a3);
}

#pragma endregion

#pragma region Vertical World Map Scrolling

// this is inlined in A64
// the proper function is WorldMap::Init that sets up the X axis boundaries
// I think it should be called every time a world map is entered
void hkWorldMapDoMovement(WorldMap* self, float fX, float fY, bool disableBoundaryChecks)
{
    if (!disableBoundaryChecks)
    {
        if (fX <= self->m_boundingRect.mX) {
            fX = self->m_boundingRect.mX;
        }

        if (fX >= self->m_boundingRect.mX + self->m_boundingRect.mWidth) {
            fX = self->m_boundingRect.mX + self->m_boundingRect.mWidth;
        }

        if (fY <= self->m_boundingRect.mY) {
            fY = self->m_boundingRect.mY;
        }

        if (fY >= self->m_boundingRect.mY + self->m_boundingRect.mHeight) {
            fY = self->m_boundingRect.mY + self->m_boundingRect.mHeight;
        }
    }

    self->m_posX = fX;
    self->m_posY = fY;
}

#pragma endregion

#pragma region Board Zoom + GetBoard

// todo: find 2 functions that calculate board zoom
// maybe its in LawnApp vftable

typedef int64_t (*mGetBoard)();
mGetBoard oGetBoard = NULL;

Board* hkGetBoard() {
    // just making this available for own use
    return (Board*)oGetBoard();
}

Board* getBoard() {
    return hkGetBoard();
}

#pragma endregion

#pragma region Build Symbol Funcs

Reflection::CRefManualSymbolBuilder::BuildSymbolsFunc PlantType::oPlantTypeBuildSymbols = nullptr;
Reflection::CRefManualSymbolBuilder::BuildSymbolsFunc ZombieType::oZombieTypeBuildSymbols = nullptr;

#pragma endregion

// hardcoded bull codename: 75667C

// just a placeholder func
typedef int(*mapp)(int);
mapp oMap = NULL;

int map(int a1)
{
    LOGI("now");
    return oMap(a1);
}

__attribute__((constructor))
// This is automatically executed when the lib is loaded
// Run your initialization code here
void libPVZ2ExpansionMod_main()
{
	LOGI("Initializing %s", LIB_TAG);

    // Function hooks
    
#ifdef A32
    // IntegerID backport
    PVZ2HookFunction(0x8D3150, (void*)hkPlantTypeCtor, (void**)&oPlantTypeCtor);
    PVZ2HookFunction(0xDA5C58, (void*)hkCreatePlantNameMapper, (void**)&oPlantNameMapperCtor);
    PVZ2HookFunction(0xCA5768, (void*)hkZombieTypeCtor, (void**)&oZombieTypeCtor);
    PVZ2HookFunction(0x10643E0, (void*)hkCreateZombieTypenameMap, (void**)&oZombieAlmanacCtor);
    PVZ2HookFunction(0x8D1FE8, (void*)PlantType::buildSymbols, (void**)&PlantType::oPlantTypeBuildSymbols);
    PVZ2HookFunction(0xCA5894, (void*)ZombieType::buildSymbols, (void**)&ZombieType::oZombieTypeBuildSymbols);

    // Some general fixes
    PVZ2HookFunction(0x789DC8, (void*)hkCamelZombieFunc, nullptr);
    PVZ2HookFunction(0x949EFC, (void*)hkGetBoard, (void**)&oGetBoard);
#else
    PVZ2HookFunction(0xC6D080, (void*)hkPlantTypeCtor, (void**)&oPlantTypeCtor);
    PVZ2HookFunction(0x11797B4, (void*)hkCreatePlantNameMapper, (void**)&oPlantNameMapperCtor);
    PVZ2HookFunction(0x10680BC, (void*)hkZombieTypeCtor, (void**)&oZombieTypeCtor);
    PVZ2HookFunction(0x14665C4, (void*)hkCreateZombieTypenameMap, (void**)&oZombieAlmanacCtor);
    PVZ2HookFunction(0xC6BF48, (void*)PlantType::buildSymbols, (void**)&PlantType::oPlantTypeBuildSymbols);
    PVZ2HookFunction(0x106828C, (void*)ZombieType::buildSymbols, (void**)&ZombieType::oZombieTypeBuildSymbols);

    PVZ2HookFunction(0xB18DC4, (void*)hkCamelZombieFunc, nullptr);
    PVZ2HookFunction(0xCE4D8C, (void*)hkGetBoard, (void**)&oGetBoard);
#endif

    //PVZ2HookFunction(0x440E4C, (void*)hkWorldMapDoMovement, nullptr);
    //PVZ2HookFunction(0x9EC540, (void*)hkWorldDataCtor, (void**)&oWorldDataCtor);
    //PVZ2HookFunction(0x102C138, (void*)map, (void**)&oMap);

    //PVZ2HookFunction(0x72C56C, (void*)hkBoardDraw, (void**)&oBoardDraw);

    //Furr::OverrideSunCollectableModule::modInit();
    //Furr::OverrideSunCollectableModuleProps::modInit();

    // feature inits
    PowerLilyProps::modInit();
    BoardPropertySheet::modInit();

    //ZombieCamel::modInit();
    //ZombieEightiesArcadeProps::modInit();

    LOGI("Finished initializing");
}