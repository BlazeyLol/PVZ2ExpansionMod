#include "Plant_PowerLily.h"
#include "Board.h"

// the type should be PlantPowerLily*
void hkPlantPowerLilySpawnCollectable(PlantFramework* self, int64_t a2)
{
    auto* props = self->m_plant->GetProps<PowerLilyProps>();

    //SexyVector2 spawnPos(self->m_plant->m_position.x, self->m_plant->m_position.y);
    //LOGI("Pos x: %f", spawnPos.x);
    //LOGI("Pos y: %f", spawnPos.y);
    //spawnCollectable("plantfood", spawnPos);

    SexyVector2 spawnPos(self->m_plant->m_position.x, self->m_plant->m_position.y + props->CollectableOffsetY);
    for (int iter = 0; iter < props->CollectableCount; iter++)
    {
        spawnCollectable(props->CollectableType, spawnPos);
    }
}

Reflection::CRefManualSymbolBuilder::BuildSymbolsFunc PowerLilyProps::oPowerLilyPropsBuildSymbols = NULL;

void PowerLilyProps::modInit()
{
    LOGI("Initializing PowerLilyProps");

    PVZ2HookFunction(0xB234A8, (void*)hkPlantPowerLilySpawnCollectable, nullptr);
    PVZ2HookFunction(0x2BBD5C, (void*)construct, nullptr);
    PVZ2HookFunction(0x2BBEA8, (void*)buildSymbols, (void**)&oPowerLilyPropsBuildSymbols);
}