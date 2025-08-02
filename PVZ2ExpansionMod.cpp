#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unistd.h>

#include "PVZ2ExpansionMod.h"

#include <Sexy/SexyApp.h>

#include "PvZ2/Board.h"
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
std::vector<PlantType*> g_modPlantTypenames;
std::vector<ZombieType*> g_modZombieTypenames;

#define REGISTER_PLANT_TYPENAME(typename) \
    g_modPlantTypenames.push_back(typename); \

#define REGISTER_ZOMBIE_TYPENAME(typename) \
    g_modZombieTypenames.push_back(typename); \

typedef void* (*plantTypeCtor)(PlantType*);
plantTypeCtor oPlantTypeCtor = NULL;

void* hkPlantTypeCtor(PlantType* self)
{
    REGISTER_PLANT_TYPENAME(self);
    return oPlantTypeCtor(self);
}

typedef PlantNameMapper* (*PlantNameMapperCtor)(PlantNameMapper*);
PlantNameMapperCtor oPlantNameMapperCtor = NULL;

void* hkCreatePlantNameMapper(PlantNameMapper* self)
{
    PlantNameMapper* obj = oPlantNameMapperCtor(self);
    obj->m_aliasToId.clear();

    for (size_t iter = 0; iter < g_modPlantTypenames.size(); iter++)
    {
        PlantType* type = g_modPlantTypenames[iter];
        obj->m_aliasToId[type->TypeName] = type->IntegerID;
    }

    return obj;
}

typedef void* (*zombieTypeCtor)(ZombieType*);
zombieTypeCtor oZombieTypeCtor = NULL;

void* hkZombieTypeCtor(ZombieType* self)
{
    REGISTER_ZOMBIE_TYPENAME(self);
    return oZombieTypeCtor(self);
}

typedef ZombieAlmanac* (*ZombieAlmanacCtor)(ZombieAlmanac*);
ZombieAlmanacCtor oZombieAlmanacCtor = NULL;

void* hkCreateZombieTypenameMap(ZombieAlmanac* self)
{
    ZombieAlmanac* obj = oZombieAlmanacCtor(self);
    obj->m_aliasToId.clear();

    for (size_t iter = 0; iter < g_modZombieTypenames.size(); iter++)
    {
        auto* type = g_modZombieTypenames[iter];
        obj->m_aliasToId[type->TypeName] = type->IntegerID;
    }

    return obj;
}

#pragma endregion

#pragma region Mummy Memory Fix

typedef void(*camelMinigameModuleFunc)(int, int, int);
camelMinigameModuleFunc cmmFunc = (camelMinigameModuleFunc)getActualOffset(0x78CFA0);

void hkCamelZombieFunc(int a1, int a2, int a3)
{
    // Redirect call to some function in CamelMinigameModule
    // This fixes the crash when camels are rising from the ground
    cmmFunc(a1, a2, a3);
}

#pragma endregion

#pragma region Vertical World Map Scrolling

void hkWorldMapDoMovement(WorldMap* self, float fX, float fY, bool disableBoundaryChecks)
{
    if (!disableBoundaryChecks)
    {
        if (fX <= self->m_boundaryX) {
            fX = self->m_boundaryX;
        }

        if (fX >= self->m_boundaryX + self->m_boundaryWidth) {
            fX = self->m_boundaryX + self->m_boundaryWidth;
        }

        if (fY <= self->m_boundaryY) {
            fY = self->m_boundaryY;
        }

        if (fY >= self->m_boundaryY + self->m_boundaryHeight) {
            fY = self->m_boundaryY + self->m_boundaryHeight;
        }
    }

    self->m_posX = fX;
    self->m_posY = fY;
}

#pragma endregion

#pragma region Piano Zombie List

typedef bool (*initZombiePianoList)(int, int);
initZombiePianoList oInitZombiePianoList = NULL;

std::vector<SexyString>* g_pianoList = NULL;
bool g_pianoListInitialized = false;

bool hkInitZombiePianoList(int a1, int a2)
{
    // This function is called every frame when a piano zombie is on screen
    // So this global bool is needed to prevent wasting a massive amount of cpu time
    if (!g_pianoListInitialized)
    {
        bool orig = oInitZombiePianoList(a1, a2);

        uint ptrAddr = getActualOffset(0x1D890F4); // address of piano zombie's list in memory
        g_pianoList = reinterpret_cast<std::vector<SexyString>*>(ptrAddr);

        // @todo: add this to piano zombie's props instead?
        g_pianoList->clear();
        g_pianoList->push_back("cowboy");
        g_pianoList->push_back("cowboy_armor1");
        g_pianoList->push_back("cowboy_armor2");
        g_pianoList->push_back("cowboy_armor4");

        g_pianoListInitialized = true;
    }
    return oInitZombiePianoList(a1, a2);
}

#pragma endregion

typedef int(*boardCtor)(Board*, int*);
boardCtor oBoardDraw = NULL;

int hkBoardDraw(Board* self, int* a2)
{

    oBoardDraw(self, a2);
    return 1;
}

typedef int (*mGetBoard)();
mGetBoard oGetBoard = NULL;

Board* hkGetBoard() {
    // just making this available for own use
    return (Board*)oGetBoard();
}

Board* getBoard() {
    return hkGetBoard();
}

#pragma region Build Symbol Funcs

Reflection::CRefManualSymbolBuilder::BuildSymbolsFunc PlantType::oPlantTypeBuildSymbols = NULL;
Reflection::CRefManualSymbolBuilder::BuildSymbolsFunc ZombieType::oZombieTypeBuildSymbols = NULL;

#pragma endregion

// hardcoded bull codename: 75667C

__attribute__((constructor))
// This is automatically executed when the lib is loaded
// Run your initialization code here
void libPVZ2ExpansionMod_main()
{
	LOGI("Initializing %s", LIB_TAG);

    // Function hooks
    FluffyHookFunction(0x8D3150, (void*)hkPlantTypeCtor, (void**)&oPlantTypeCtor);
    FluffyHookFunction(0xDA5C58, (void*)hkCreatePlantNameMapper, (void**)&oPlantNameMapperCtor);
    FluffyHookFunction(0xCA5768, (void*)hkZombieTypeCtor, (void**)&oZombieTypeCtor);
    FluffyHookFunction(0x10643E0, (void*)hkCreateZombieTypenameMap, (void**)&oZombieAlmanacCtor);
    FluffyHookFunction(0x8D1FE8, (void*)PlantType::buildSymbols, (void**)&PlantType::oPlantTypeBuildSymbols);
    FluffyHookFunction(0xCA5894, (void*)ZombieType::buildSymbols, (void**)&ZombieType::oZombieTypeBuildSymbols);

    FluffyHookFunction(0x789DC8, (void*)hkCamelZombieFunc, nullptr);
    //FluffyHookFunction(0x440E4C, (void*)hkWorldMapDoMovement, nullptr);
    //FluffyHookFunction(0x9EC540, (void*)hkWorldDataCtor, (void**)&oWorldDataCtor);
    FluffyHookFunction(0x885F80, (void*)hkInitZombiePianoList, (void**)&oInitZombiePianoList);

    //FluffyHookFunction(0x72C56C, (void*)hkBoardDraw, (void**)&oBoardDraw);
    //FluffyHookFunction(0x949EFC, (void*)hkGetBoard, (void**)&oGetBoard);

    //Furr::OverrideSunCollectableModule::modInit();
    //Furr::OverrideSunCollectableModuleProps::modInit();

    PlantPowerLily::modInit();

    //ZombieCamel::modInit();
    //ZombieEightiesArcadeProps::modInit();

    LOGI("Finished initializing");
}