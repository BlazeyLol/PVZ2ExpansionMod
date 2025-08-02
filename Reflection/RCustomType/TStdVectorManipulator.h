#pragma once
#include <Reflection/RType.h>
#include <Sexy/RtWeakPtr.h>

#define OFFSET_REFLECTION_RCUSTOMTYPE_TSTDVECTORMANIPULATOR_FUNC1 0x254210
#define OFFSET_REFLECTION_RCUSTOMTYPE_TSTDVECTORMANIPULATOR_FUNC2 0x254104
#define OFFSET_REFLECTION_RCUSTOMTYPE_TSTDVECTORMANIPULATOR_FUNC3 0x10E5340

namespace Reflection
{
	namespace RCustomType
	{
		struct UnkStruct
		{
		public:
			int unk1;
			int unk2;
			int unk3;
			int unk4;
			Sexy::RtWeakPtr<void>* weakPtrPtr;
		};

		struct VectorManipulatorStruct
		{
		public:
			UnkStruct* unkPtr;
			void* unkPtr2;
			bool unkBool;
		};

		template <typename T>
		class TStdVectorManipulator
		{
		public:
			using GenericVector = std::vector<T>;

			virtual void NullSub() {};

			virtual void DestroyEffect(void* a1) {
				operator delete(a1);
			};

			virtual bool Edit(GenericVector* vector,
				VectorManipulatorStruct* manipInfo,
				Sexy::RtWeakPtr<void>* unkWeakPtr,
				RType* reflectionType)
			{
				if (manipInfo->unkBool)
				{
					int vecSize = 0;

					typedef bool(*func)(void*, Sexy::RtWeakPtr<void>*, int&);
					func pFunc = (func)getActualOffset(OFFSET_REFLECTION_RCUSTOMTYPE_TSTDVECTORMANIPULATOR_FUNC1);

					if (pFunc(manipInfo->unkPtr, unkWeakPtr, vecSize))
					{
						if (vecSize > 0)
						{
							LOGI("[ Reflection::RCustomType::TStdVectorManipulator::Edit ] [ Begin manip vector (size: %d) ]", vecSize);
							vector->resize(vecSize);

							for (int i = 0; i < vecSize; i++)
							{
								T* element = &vector->at(i);
								SexyString str;
								reflectionType->Function11(element, manipInfo, str);
							}
						}

						manipInfo->unkPtr->weakPtrPtr--;
						return true;
					}

					return false;
				}
				else
				{
					int** v19 = *(int***)((int64_t)manipInfo + 4);
					typedef void (*sub254104)(int**, Sexy::RtWeakPtr<void>*, int, char);
					((sub254104)getActualOffset(OFFSET_REFLECTION_RCUSTOMTYPE_TSTDVECTORMANIPULATOR_FUNC2))(v19, unkWeakPtr, vector->size(), 0xFD);

					if (!vector->empty()) {
						for (size_t i = 0; i < vector->size(); ++i) {
							T* element = &vector->at(i);
							SexyString str;
							reflectionType->Function11(element, manipInfo, str);
						}
					}

					int* v17 = *v19;
					v19[2] = (int*)((char*)v19[2] - 1);

					uint8_t v21 = 254;
					typedef int (*sub10E5340)(int*, uint8_t*, int);
					((sub10E5340)getActualOffset(OFFSET_REFLECTION_RCUSTOMTYPE_TSTDVECTORMANIPULATOR_FUNC3))(v17, &v21, 1);

					return true;

					LOGW("[ Reflection::RCustomType::TStdVectorManipulator::Edit ] [ Panic! Need to edit vector but manipInfo->unkBool is false ]");
				}
			}

			virtual int GetSize(GenericVector* vector)
			{
				return vector->size();
			}
		};
	}
}