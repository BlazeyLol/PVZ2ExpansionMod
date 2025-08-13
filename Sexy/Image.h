#pragma once
#include "RtObject.h"
#include "BaseResource.h"

namespace Sexy
{
	class Image : public BaseResource
	{
	public:
		char pad018[12];
		SexyString mFilePath;
		int mWidth;
		int mHeight;
		int mNumRows;
		int mNumCols;
		RtWeakPtr<Image> mAtlasImage;
		int mAtlastStartX;
		int mAtlastStartY;
		int mAtlastEndX;
		int mAtlastEndY;
	};

#ifdef A32
	static_assert(sizeof(Image) == 0x58);
	static_assert(offsetof(Image, mFilePath) == 0x24);
	static_assert(offsetof(Image, mAtlastStartY) == 0x4C);
#else
#endif
}