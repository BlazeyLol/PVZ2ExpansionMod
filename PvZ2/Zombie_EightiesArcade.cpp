#include "Zombie_EightiesArcade.h"
#include "Zombie.h"
#include "Board.h"
#include "GridItem.h"

typedef void(*arcadeZombiePushGridItem)(Zombie*, int);
arcadeZombiePushGridItem oArcadeZombiePushGridItem = nullptr;

// the type should be ZombieEightiesArcade*
void hkArcadeZombiePushGridItem(Zombie* self, int a2)
{
    auto* props = reinterpret_cast<ZombieEightiesArcadeProps*>(self->m_propertySheet.Get());

    if (props->GridItemType == "eightiesarcadecabinet")
    {
        oArcadeZombiePushGridItem(self, a2);
    }
    else
    {
        // calculates the grid position
        // it assumes the zombie has never moved
        int spawnPosY = (540 - self->m_position.y) / 76 * -1 + 5;
        auto* gridItem = GridItem::SpawnGridItemAt(props->GridItemType, 10, spawnPosY);
    }
}

Reflection::CRefManualSymbolBuilder::BuildSymbolsFunc ZombieEightiesArcadeProps::oZombieEightiesArcadePropsBuildSymbols = nullptr;

void ZombieEightiesArcadeProps::modInit()
{
    LOGI("Initializing ZombieEightiesArcadeProps");

    PVZ2HookFunction(0x79898C, (void*)hkArcadeZombiePushGridItem, (void**)&oArcadeZombiePushGridItem);
    PVZ2HookFunction(0x798BF8, (void*)construct, nullptr);
    PVZ2HookFunction(0x798D84, (void*)buildSymbols, (void**)&oZombieEightiesArcadePropsBuildSymbols);
}