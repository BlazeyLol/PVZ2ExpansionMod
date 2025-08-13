#include "BoardPropertySheet.h"

BoardPropertySheet* g_boardPropertySheet = nullptr;

typedef void* (*boardPropertySheetCtor)(BoardPropertySheet*);
boardPropertySheetCtor oBoardPropertySheetCtor = nullptr;

void* hkBoardPropertySheetCtor(BoardPropertySheet* self)
{
    LOGI("Board propsheet ctor");
    oBoardPropertySheetCtor(self);

    self->ZombiePianoList.clear();
    self->ZombiePianoList.shrink_to_fit();

    if (!g_boardPropertySheet)
    {
        LOGI("g_boardPropertySheet is null!");
        g_boardPropertySheet = self;
    }

    return self;
}

typedef bool (*initZombiePianoList)(int, int);
initZombiePianoList oInitZombiePianoList = nullptr;

std::vector<SexyString>* g_pianoList = nullptr;
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

        g_pianoList->clear();
        for (size_t iter = 0; iter < g_boardPropertySheet->ZombiePianoList.size(); iter++)
        {
            SexyString zombieTypename = g_boardPropertySheet->ZombiePianoList[iter];
            g_pianoList->push_back(zombieTypename);
            LOGI("ZombiePianoList typename: %s", zombieTypename.c_str());
        }

        g_pianoListInitialized = true;
    }
    return oInitZombiePianoList(a1, a2);
}

Reflection::CRefManualSymbolBuilder::BuildSymbolsFunc BoardPropertySheet::oBoardPropertySheetBuildSymbols = nullptr;

void BoardPropertySheet::modInit()
{
    LOGI("Initializing BoardPropertySheet");

    PVZ2HookFunction(0xD98368, (void*)BoardPropertySheet::buildSymbols, (void**)&oBoardPropertySheetBuildSymbols);
    PVZ2HookFunction(0xD982A8, (void*)hkBoardPropertySheetCtor, (void**)&oBoardPropertySheetCtor);

    PVZ2HookFunction(0x885F80, (void*)hkInitZombiePianoList, (void**)&oInitZombiePianoList);
}