#include "SexyUtils.h"
#include "PvZ2/Board.h"
#include <Sexy/SexyApp.h>
#include <Sexy/RtWeakPtr.h>

inline uint getLawnApp() {
	return *(uint*)getActualOffset(0x1D92A94);
}

uint getSexyApp() {
	return *(uint*)getActualOffset(SEXYAPP_ADDR);
}

int getWeakPtr(int addr) {
	Sexy::RtWeakPtr<int> a = Sexy::RtWeakPtr<int>();
	a.FromOther((Sexy::RtWeakPtr<int>*)addr);
	return (int)a.Get();
}

void loadResGroup(const SexyString& groupName)
{
	typedef void(*loadResGroup)(int, SexyString);
	auto loadResourceGroup = (loadResGroup)getActualOffset(0x5DAE84);
	loadResourceGroup(getLawnApp(), groupName);
}

void playWiseEvent(const SexyString& eventName)
{
	typedef int (*func26AA10)();
	auto func_26AA10 = (func26AA10)getActualOffset(0x26AA10);

	typedef void(*playWiseEvent)(int, SexyString, int);
	auto playAudioEvent = (playWiseEvent)getActualOffset(0x6B3068);
	playAudioEvent(func_26AA10(), eventName, 0);
}

void spawnCollectable(const SexyString& collectableName, SexyVector2 position)
{
	typedef void(*spawnCollectable)(Board*, SexyString, SexyVector2*);
	auto spawnCollectableFunc = (spawnCollectable)getActualOffset(0x718158);
	spawnCollectableFunc(getBoard(), collectableName, &position);
}