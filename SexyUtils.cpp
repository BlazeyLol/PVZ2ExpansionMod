#include "SexyUtils.h"
#include "PvZ2/Board.h"
#include <Sexy/SexyApp.h>
#include <Sexy/RtWeakPtr.h>

#ifdef A32
#define LAWNAPP_ADDR 0x1D92A94
#else
#define LAWNAPP_ADDR 0x2593760
#endif

inline uint64_t getLawnApp() {
	return *(uint64_t*)getActualOffset(LAWNAPP_ADDR);
}

uint64_t getSexyApp() {
	return *(uint64_t*)getActualOffset(SEXYAPP_ADDR);
}

int64_t getWeakPtr(int64_t addr) {
	Sexy::RtWeakPtr<int64_t> a = Sexy::RtWeakPtr<int64_t>();
	a.FromOther((Sexy::RtWeakPtr<int64_t>*)addr);
	return (int64_t)a.Get();
}

#if A32

void loadResGroup(const SexyString& groupName)
{
	typedef void(*loadResGroup)(int, SexyString);
	auto loadResourceGroup = (loadResGroup)getActualOffset(0x5DAE84);
	loadResourceGroup(getLawnApp(), groupName);
}

void playWiseEvent(const SexyString& eventName)
{
	typedef int64_t(*func26AA10)();
	auto func_26AA10 = (func26AA10)getActualOffset(0x26AA10);

	typedef void(*playWiseEvent)(int64_t, SexyString, int64_t);
	auto playAudioEvent = (playWiseEvent)getActualOffset(0x6B3068);
	playAudioEvent(func_26AA10(), eventName, 0);
}

void spawnCollectable(const SexyString& collectableName, SexyVector2 position)
{
	typedef void(*spawnCollectable)(Board*, SexyString, SexyVector2*);
	auto spawnCollectableFunc = (spawnCollectable)getActualOffset(0x718158);
	spawnCollectableFunc(getBoard(), collectableName, &position);
}

#else

void loadResGroup(const SexyString& groupName)
{
	typedef void(*loadResGroup)(int, SexyString);
	auto loadResourceGroup = (loadResGroup)getActualOffset(0x5DAE84);
	loadResourceGroup(getLawnApp(), groupName);
}

void playWiseEvent(const SexyString& eventName)
{
	typedef int64_t(*func26AA10)();
	auto func_26AA10 = (func26AA10)getActualOffset(0x26AA10);

	typedef void(*playWiseEvent)(int64_t, SexyString, int64_t);
	auto playAudioEvent = (playWiseEvent)getActualOffset(0x6B3068);
	playAudioEvent(func_26AA10(), eventName, 0);
}

void spawnCollectable(const SexyString& collectableName, SexyVector2 position)
{
	typedef void(*spawnCollectable)(Board*, SexyString, SexyVector2*);
	auto spawnCollectableFunc = (spawnCollectable)getActualOffset(0xAA4180);
	spawnCollectableFunc(getBoard(), collectableName, &position);
}

#endif