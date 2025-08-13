#include "BoardPropertySheet.h"

typedef void* (*boardPropertySheetCtor)(BoardPropertySheet*);
boardPropertySheetCtor oBoardPropertySheetCtor = NULL;

BoardPropertySheet* g_boardProperties = NULL;

void* hkBoardPropertySheetCtor(BoardPropertySheet* self)
{
    oBoardPropertySheetCtor(self);
    return self;
}

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

        //g_pianoList->clear();
        //g_pianoList = &g_boardProperties->ZombiePianoList;
        for (size_t iter = 0; iter < g_boardProperties->ZombiePianoList.size(); iter++)
        {
            //g_pianoList->push_back(str);
            SexyString zombieTypename = g_boardProperties->ZombiePianoList[iter];
            LOGI("ZombiePianoList typename: %s", zombieTypename.c_str());
        }

        //LOGI("ZombiePianoList size: %d", g_boardProperties->ZombiePianoList.size());

        g_pianoList->clear();
        g_pianoList->push_back("cowboy");
        g_pianoList->push_back("cowboy_armor1");
        g_pianoList->push_back("cowboy_armor2");
        g_pianoList->push_back("cowboy_armor4");
        g_pianoList->push_back("feastivus");

        g_pianoListInitialized = true;
    }
    return oInitZombiePianoList(a1, a2);
}

Reflection::CRefManualSymbolBuilder::BuildSymbolsFunc BoardPropertySheet::oBoardPropertySheetBuildSymbols = NULL;

void BoardPropertySheet::modInit()
{
    LOGI("BoardPropertySheet mod init");

    PVZ2HookFunction(0xD98368, (void*)BoardPropertySheet::buildSymbols, (void**)&oBoardPropertySheetBuildSymbols);
    PVZ2HookFunction(0xD982A8, (void*)hkBoardPropertySheetCtor, (void**)&oBoardPropertySheetCtor);

    PVZ2HookFunction(0x885F80, (void*)hkInitZombiePianoList, (void**)&oInitZombiePianoList);

    LOGI("BoardPropertySheet finish init");
}