#pragma once
#include "DelegateBase.h"
#include "RtWeakPtr.h"

namespace Sexy
{
	class RtReflectionDelegateBase
	{
		Sexy::RtWeakPtr<int> m_ownerPtr;
		SexyString m_eventName;
		DelegateBase m_delegate;
		int m_isDelegateSetup;
	};
}