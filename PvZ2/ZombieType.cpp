#include "ZombieType.h"

void ZombieType::GetFromName(Sexy::RtWeakPtr<ZombieType>* res, SexyString zombieName) {
	typedef int (*zombieTypeDirectoryGet)();
	int zombieTypeDirectoryInstance = ((zombieTypeDirectoryGet)getActualOffset(ZOMBIETYPEDIRECTORY_GET))();

	typedef void (*getAliasedType)(Sexy::RtWeakPtr<ZombieType>*, int, SexyString*);
	((getAliasedType)getActualOffset(ZOMBIETYPEDIRECTORY_GETTYPE))(res, zombieTypeDirectoryInstance, &zombieName);
}