#pragma once

#ifdef A32
#define OFFSET_RTWEAKPTR_GETREGISTRY 0x10D99A4
#define OFFSET_RTWEAKPTR_UNKFUNC1 0x10DFA5C
#define OFFSET_RTWEAKPTR_UNKFUNC2 0x10DF644
#define OFFSET_RTWEAKPTR_EQUALS 0x24D110
#define OFFSET_RTWEAKPTR_ISVALIDPTR 0x279198
#define OFFSET_RTWEAKPTR_RESOLVE 0x10DB9C0
#define OFFSET_RTWEAKPTR_FROMOTHER 0x10C8BF8
#define OFFSET_RTWEAKPTR_SETWEAKPTR 0x10C88C8
#define OFFSET_RTWEAKPTR_MOVE 0x10C8BB0
#else

#define OFFSET_RTWEAKPTR_GETREGISTRY 0x14EAD90
#define OFFSET_RTWEAKPTR_UNKFUNC1 0x14F39CC
#define OFFSET_RTWEAKPTR_UNKFUNC2 0x14F31A4
#define OFFSET_RTWEAKPTR_EQUALS 0x0
#define OFFSET_RTWEAKPTR_ISVALIDPTR 0x0
#define OFFSET_RTWEAKPTR_RESOLVE 0x14EDE00
#define OFFSET_RTWEAKPTR_FROMOTHER 0x14D920C
#define OFFSET_RTWEAKPTR_SETWEAKPTR 0x14D8B08
#define OFFSET_RTWEAKPTR_MOVE 0x0
#endif

namespace Sexy
{
	template <typename T>
	class RtWeakPtr
	{
	public:

		RtWeakPtr()
		{
			data1 = NULL;
			data2 = NULL;
		}

		~RtWeakPtr()
		{
			typedef void(*func)(RtWeakPtr*, int64_t);
			func pSetValue = (func)getActualOffset(OFFSET_RTWEAKPTR_SETWEAKPTR);
			pSetValue(this, 0LL);
		}

		RtWeakPtr(RtWeakPtr* other) {
			data1 = NULL;
			data2 = NULL;

			this->FromOther(other);
		}

		RtWeakPtr(RtWeakPtr&& other) {
			data1 = NULL;
			data2 = NULL;

			typedef void(*func)(RtWeakPtr*, RtWeakPtr*);
			func pFunc = (func)getActualOffset(OFFSET_RTWEAKPTR_MOVE);
			pFunc(this, &other);
		}

		RtWeakPtr(const RtWeakPtr& other) {
			data1 = NULL;
			data2 = NULL;

			typedef void(*func)(RtWeakPtr*, const RtWeakPtr&);
			func pSetValue = (func)getActualOffset(OFFSET_RTWEAKPTR_FROMOTHER);
			pSetValue(this, other);
		}

		bool operator==(const RtWeakPtr<T>& other) const
		{
			typedef bool(*eqOp)(RtWeakPtr<T>*, RtWeakPtr<T>*);
			eqOp pEqOp = (eqOp)getActualOffset(OFFSET_RTWEAKPTR_EQUALS);
			return pEqOp(this, &other);
		}

		bool operator==(RtWeakPtr<T>& other)
		{
			typedef bool(*eqOp)(RtWeakPtr<T>*, RtWeakPtr<T>*);
			eqOp pEqOp = (eqOp)getActualOffset(OFFSET_RTWEAKPTR_EQUALS);
			return pEqOp(this, &other);
		}


		RtWeakPtr<T>& operator=(const RtWeakPtr<T>& other)
		{
			typedef void(*func)(RtWeakPtr*, const RtWeakPtr&);
			func pSetValue = (func)getActualOffset(OFFSET_RTWEAKPTR_FROMOTHER);
			pSetValue(this, other);

			// This is how I've been using the assignment operator so far
			data1 = other.data1;
			data2 = other.data2;

			return *this;
		}

		RtWeakPtr<T>& operator=(RtWeakPtr<T>& other)
		{
			typedef void(*func)(RtWeakPtr*, RtWeakPtr&);
			func pSetValue = (func)getActualOffset(OFFSET_RTWEAKPTR_FROMOTHER);
			pSetValue(this, other);
		}

		RtWeakPtr<T>& operator=(RtWeakPtr<T>* other)
		{
			typedef void(*func)(RtWeakPtr*, RtWeakPtr*);
			func pSetValue = (func)getActualOffset(OFFSET_RTWEAKPTR_FROMOTHER);
			pSetValue(this, other);
		}

		RtWeakPtr<T>& operator=(const RtWeakPtr<T>* other)
		{
			typedef void(*func)(RtWeakPtr*, RtWeakPtr*);
			func pSetValue = (func)getActualOffset(OFFSET_RTWEAKPTR_FROMOTHER);
			pSetValue(this, other);
		}

		bool Equals(RtWeakPtr<T>* other) {
			typedef bool(*eqOp)(RtWeakPtr<T>*, RtWeakPtr<T>*);
			eqOp pEqOp = (eqOp)getActualOffset(OFFSET_RTWEAKPTR_EQUALS);
			return pEqOp(this, other);
		}

		bool IsInvalid()
		{
			return data1 == NULL;
		}

		bool IsValid()
		{
			typedef bool(*func)(RtWeakPtr<T>*);
			func pFunc = (func)getActualOffset(OFFSET_RTWEAKPTR_ISVALIDPTR);
			return pFunc(this);
		}

		int TypeID()
		{
			return (this->data2 >> 0x11) & 0x3FFF;
		}

		int GetSomething()
		{
			return this->data2 >> 0x1F;
		}

		void FromOther(RtWeakPtr* other)
		{
			typedef void(*func)(RtWeakPtr*, RtWeakPtr*);
			func pSetValue = (func)getActualOffset(OFFSET_RTWEAKPTR_FROMOTHER);
			pSetValue(this, other);
		}

		// Get the object this points to, if valid.
		T* Get()
		{
			typedef void* (*getV8)();
			getV8 pGetRegistry = (getV8)getActualOffset(OFFSET_RTWEAKPTR_GETREGISTRY);

			void* registry = pGetRegistry();

			typedef void (*sub10CC81C)(RtWeakPtr*, void*, RtWeakPtr*);
			sub10CC81C pSub10CC81C = (sub10CC81C)getActualOffset(OFFSET_RTWEAKPTR_UNKFUNC1);

			RtWeakPtr<T> temp;
			pSub10CC81C(&temp, registry, this);

			T* retVal = NULL;
			if (!temp.IsInvalid())
			{
				//typedef void* (*sub10B5924)(RtWeakPtr*);
				//sub10B5924 pSub10B5924 = (sub10B5924)getActualOffset(0x10B5924);

				//void* v10 = pSub10B5924(&temp);
				int typeId = temp.TypeID();

				typedef void* (*sub10CC404)(void*, int);
				sub10CC404 pSub10CC404 = (sub10CC404)getActualOffset(OFFSET_RTWEAKPTR_UNKFUNC2);

				void* v11 = pSub10CC404(registry, typeId);
				if (v11)
				{
					LOGI("Valid and is correct type");
					typedef T* (*sub10C8780)(void*, RtWeakPtr*);
					sub10C8780 pResolveWeakPtr = (sub10C8780)getActualOffset(OFFSET_RTWEAKPTR_RESOLVE);
					retVal = pResolveWeakPtr(v11, &temp);
				}
			}
			//temp.MarkForDeletion();

			return retVal;
		}

	private:
		int data1;
		int data2;
	};
}

int64_t getWeakPtr(int64_t addr);
