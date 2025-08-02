#pragma once
#include <Sexy/RtObject.h>
#include <Sexy/RtWeakPtr.h>
#include <Reflection/ReflectionBuilder.h>

#define GAMEOBJECT_CONSTRUCTOR_OFFSET 0x53EF3C
#define GAMEOBJECT_GETTYPE_OFFSET 0x53EA0C
#define GAMEOBJECT_FUNCTION_DIE_OFFSET 0x53F498

class Renderable
{
public:
    virtual ~Renderable() {};
    virtual void Draw(void* g) {};
    virtual int GetRenderOrder() {};
};

class GameObject : public Sexy::RtObject
{
public:
    DEFINE_RT_CLASS_GET_CLASS_WRAPPER(GAMEOBJECT_GETTYPE_OFFSET);

    int unk_0x4;
    Sexy::RtWeakPtr<Sexy::RtObject> m_thisPtr;

    void Die()
    {
        typedef void(*func)(void*);
        func pFunc = (func)getActualOffset(GAMEOBJECT_FUNCTION_DIE_OFFSET);
        pFunc(this);
    }

    // Called when the object is serialized from a JSON
    virtual void RegisterForEvents() {};
    virtual void Function8() {};
    virtual void Function9() {};
    virtual void Function10() {};
    virtual void Function11() {};
    virtual void Destroy() {};
};