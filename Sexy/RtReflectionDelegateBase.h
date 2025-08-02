#pragma once
#include "DelegateBase.h"
#include "RtWeakPtr.h"

namespace Sexy
{
	class RtReflectionDelegateBase
	{
		Sexy::RtWeakPtr<int> ownerPtr;
		SexyString eventName;
		DelegateBase delegate;
		int isDelegateSetup;
	};
}