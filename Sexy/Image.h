#pragma once
#include "RtObject.h"
#include "BaseResource.h"

namespace Sexy
{
	class Image : public BaseResource
	{
	public:
		char pad018[12];
		SexyString m_filePath;
		int m_width;
		int m_height;
		int m_numRows;
		int m_numCols;
		RtWeakPtr<Image> m_atlasImage;
		int m_atlastStartX;
		int m_atlastStartY;
		int m_atlastEndX;
		int m_atlastEndY;
	};

	static_assert(sizeof(Image) == 0x58);
	static_assert(offsetof(Image, m_filePath) == 0x24);
	static_assert(offsetof(Image, m_atlastStartY) == 0x4C);
}