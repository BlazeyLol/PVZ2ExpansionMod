#pragma once
#include "ZombiePropertySheet.h"

class ZombieWithActionsProps : public ZombiePropertySheet
{
public:
	std::vector<Sexy::RtWeakPtr<Sexy::RtObject>> Actions;
};