#include "Plant_PowerLily.h"
#include "Board.h"

int hkPlantPowerLilySpawnCollectable(PlantPowerLily* self, int a2)
{
    auto* props = reinterpret_cast<PowerLilyProps*>(self->m_plant->m_propertySheet.Get());

    SexyVector2 spawnPos(self->m_plant->m_position.x, self->m_plant->m_position.y + props->CollectableOffsetY);
    for (int iter = 0; iter < props->CollectableCount; iter++)
    {
        spawnCollectable(props->CollectableType, spawnPos);
    }

    return 1;
}

Reflection::CRefManualSymbolBuilder::BuildSymbolsFunc PowerLilyProps::oPowerLilyPropsBuildSymbols = NULL;

void PlantPowerLily::modInit()
{
    LOGI("PowerLily mod init");

    FluffyHookFunction(0xB234A8, (void*)hkPlantPowerLilySpawnCollectable, nullptr);
    FluffyHookFunction(0x2BBEA8, (void*)PowerLilyProps::buildSymbols, (void**)&PowerLilyProps::oPowerLilyPropsBuildSymbols);

    LOGI("PowerLily finish init");
}