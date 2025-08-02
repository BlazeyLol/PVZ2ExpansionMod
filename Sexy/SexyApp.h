#pragma once

#define SEXYAPP_ADDR 0x1D9CA24

namespace Sexy
{
	class SexyApp
	{
	public:
		inline float Scale(float a1) {
			return *(float*)((uint)this + 0x698) * a1;
		}

		inline float Unscale(float a1) {
			return a1 / *(float*)((uint)this + 0x698);
		}

		inline float Scale(int a1) {
			return Scale((float)a1);
		}

		inline static SexyApp* Get() {
			return *(SexyApp**)getActualOffset(SEXYAPP_ADDR);
		}
	};
}

uint getSexyApp();