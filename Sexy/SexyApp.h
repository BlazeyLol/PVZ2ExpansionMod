#pragma once

#ifdef A32
#define SEXYAPP_ADDR 0x1D9CA24
#else
#define SEXYAPP_ADDR 0x25A4618
#endif

namespace Sexy
{
	// derives from SexyAppBase
	class SexyApp
	{
	public:
		inline float Scale(float a1) {
			return *(float*)((uint64_t)this + 0x698) * a1;
		}

		inline float Unscale(float a1) {
			return a1 / *(float*)((uint64_t)this + 0x698);
		}

		inline float Scale(int a1) {
			return Scale((float)a1);
		}

		inline static SexyApp* Get() {
			return *(SexyApp**)getActualOffset(SEXYAPP_ADDR);
		}
	};
}

uint64_t getSexyApp();