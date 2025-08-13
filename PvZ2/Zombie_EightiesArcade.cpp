#include "Zombie_EightiesArcade.h"
#include "Zombie.h"
#include "Board.h"
#include "GridItem.h"

typedef void(*arcadeZombiePushGridItem)(Zombie*, int);
arcadeZombiePushGridItem oArcadeZombiePushGridItem = NULL;

// the type should be ZombieEightiesArcade*
void hkArcadeZombiePushGridItem(Zombie* self, int a2)
{
    auto* props = reinterpret_cast<ZombieEightiesArcadeProps*>(self->m_propertySheet.Get());
    LOGI("JamStyle: %s", props->JamStyle.c_str());
    LOGI("PushedGridItemType: %s", props->PushedGridItemType.c_str());

    //Rect rect;

    //typedef float (*funcCEB82C)(Rect, Zombie*);
    //auto func_CEB82C = (funcCEB82C)getActualOffset(0xCEB82C);
    //func_CEB82C(rect, self);
    //LOGI("passed step 1");

    //SexyString gridItemType = "eightiesarcadecabinet";
    //auto* gridItem = GridItem::getByName(gridItemType);

    //LOGI("passed step 2");

    //if (gridItem)
    //{
    //    LOGI("spawning %s", gridItemType.c_str());
    //    typedef int(*gridItemSpawn)(GridItem*, SexyString, bool);
    //    auto gridItemSpawnFunc = (gridItemSpawn)getActualOffset(0x498F04);
    //    gridItemSpawnFunc(gridItem, gridItemType, true);

    //    if (true)
    //    {
    //        
    //    }
    //}

    //oArcadeZombiePushGridItem(self, a2);
}

Reflection::CRefManualSymbolBuilder::BuildSymbolsFunc ZombieEightiesArcadeProps::oZombieEightiesArcadePropsBuildSymbols = NULL;

void ZombieEightiesArcadeProps::modInit()
{
    LOGI("EightiesArcade mod init");

    PVZ2HookFunction(0x79898C, (void*)hkArcadeZombiePushGridItem, (void**)&oArcadeZombiePushGridItem);
    PVZ2HookFunction(0x79898C, (void*)ZombieEightiesArcadeProps::buildSymbols, (void**)&ZombieEightiesArcadeProps::oZombieEightiesArcadePropsBuildSymbols);

    LOGI("EightiesArcade finish init");
}