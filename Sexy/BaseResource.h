#pragma once
#include "RtObject.h"
#include "RtWeakPtr.h"

namespace Sexy
{
	class BaseResource : public RtObject
	{
	public:
		int unk;
		RtWeakPtr<void> m_rtID;
		RtWeakPtr<void> unkPtr2;
	};
}