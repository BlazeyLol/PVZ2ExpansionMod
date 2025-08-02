#pragma once
#include "Color.h"
#include "RtObject.h"
#include "RtWeakPtr.h"
#include "BaseResource.h"

namespace Sexy
{
	class Matrix3 {
	public:
		float mat[3][3];
	};

	class Transform2D : public Matrix3 {
	public:
		Transform2D() {
			memset(mat, 0, sizeof(mat));
			mat[0][0] = 1.0;
			mat[1][1] = 1.0;
			mat[2][2] = 1.0;
		}
	};

	class PopAnim : public BaseResource {
	public:
		int unk3;
		int unk4;
		int m_drawScale;
		int m_imgScale;
		int m_animRate;
		Rect m_animRect;
		int m_lastPlayedFrameLabel;
		char pad0040[0x8];
		int unkStruct;
		int m_mainAnimDef;
		int m_blendTicksTotal;
		int m_blendTicksCur;
		int m_blendDelay;
		Transform2D m_transform;
		Color m_color;
		bool m_additive;
		bool unk5;
		bool m_animRunning;
		bool m_paused;
		bool m_colorizeType;
	};

	static_assert(sizeof(PopAnim) == 0x98);
	static_assert(offsetof(PopAnim, pad0040) == 0x40);
	static_assert(offsetof(PopAnim, m_transform) == 0x5C);

}