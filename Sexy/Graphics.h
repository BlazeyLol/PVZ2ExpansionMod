#pragma once
#include "Color.h"

#define UNK_GRAPHICSFUNC 0x1124614
#define UNK_GRAPHICSFUNC2 0x1124784

namespace Sexy
{
	class Graphics
	{
	public:
		int unk1;
		int unk2;
		float m_transX;
		float m_transY;
		float m_scaleX;
		float m_scaleY;
		float m_scaleOrigX;
		float m_scaleOrigY;
		Rect m_clipRect;
		Color m_color;
		int m_font; // Sexy::Font type
		int m_drawMode;
		bool m_colorizeImages;
		bool m_fastStretch;
		bool m_writeColoredString;
		bool m_linearBlend;
		bool m_is3D;
		int m_renderDevice; // AndroidRenderDevice*
		int m_renderContext;
		int m_graphics3D;
		// there are still at least 4 more unknown fields

		void UnkFunc() {
			typedef void (*unkFunc)(Graphics*);
			((unkFunc)getActualOffset(UNK_GRAPHICSFUNC))(this);
		}

		void UnkFunc2() {
			typedef void (*unkFunc)(Graphics*);
			((unkFunc)getActualOffset(UNK_GRAPHICSFUNC2))(this);
		}
	};
}