#pragma once
#include <vector>
#include <map>
#include <string>

#include <Sexy/RtClass.h>
#include "CRefManualSymbolBuilder.h"
#include "RCustomType/TStdVectorManipulator.h"

#define RT_BUILDER_REGISTERCLASS_FUNC1 0x123B308
#define RT_BUILDER_REGISTERCLASS_FUNC2 0x123B35C

template <typename T>
using RTMap = std::map<SexyString, T>;

template <typename T>
inline Reflection::ReflectionFieldType GetPropertyType()
{
    if (std::is_same<T, bool>::value)
    {
        return Reflection::Type_Bool;
    }
    if (std::is_same<T, int>::value || std::is_same<T, long>::value)
    {
        return Reflection::Type_IntType;
    }
    else if (std::is_same<T, uint>::value || std::is_same<T, ulong>::value)
    {
        return Reflection::Type_UIntType;
    }
    else if (std::is_same<T, float>::value || std::is_same<T, double>::value)
    {
        return Reflection::Type_FloatType;
    }
    else if (std::is_same<T, SexyString>::value)
    {
        return Reflection::Type_Char;
    }
}

void ForceRTClassRebuild(uint classPtr, uint getClassFunc);
void ReplaceRTClassPtr(uint classPtr, Sexy::RtClass* newClassPtr);

#define GET_SIZE(className, memberName) \
    sizeof(decltype(std::declval<className>().memberName)) \

#define GET_TYPE(className, memberName) \
    GetPropertyType<decltype(std::declval<className>().memberName)>()

// Registers a standard type property (int, float, bool...) ONLY use with standard properties. Templated properties have their own macro.
#define REGISTER_STANDARD_PROPERTY(builder, rClass, className, name) \
    void* prop_##name = (builder)->GetPropertyOfType(GET_TYPE(className, name), GET_SIZE(className, name)); \
    (builder)->RegisterProperty(rClass, #name, offsetof(className, name), prop_##name); \

#define REGISTER_INT_PROPERTY(builder, rClass, className, name) \
    void* prop_##name = (builder)->GetPropertyOfType(Reflection::Type_IntType, sizeof(int)); \
    (builder)->RegisterProperty(rClass, #name, offsetof(className, name), prop_##name); \

#define REGISTER_STANDARD_VECTOR_PROPERTY(builder, rClass, className, name, elementType) \
    void* prop_##name = (builder)->GetPropertyOfType(GetPropertyType<elementType>(), sizeof(elementType)); \
    Reflection::RCustomType::TStdVectorManipulator<elementType>* manip_##name = new Reflection::RCustomType::TStdVectorManipulator<elementType>(); \
    void* regProp_##name = (builder)->RegisterPointerProperty(2, prop_##name, manip_##name); \
    (builder)->RegisterProperty(rClass, #name, offsetof(className, name), regProp_##name); \

#define REGISTER_STANDARD_MAP_PROPERTY(builder, rClass, className, name, valueType) \
    void* prop_##name = (builder)->GetPropertyOfType(GetPropertyType<valueType>(), sizeof(valueType)); \
    Reflection::RCustomType::TStdVectorManipulator<int>* manip_##name = new Reflection::RCustomType::TStdVectorManipulator<int>(); \
    void* regProp_##name = (builder)->RegisterPointerProperty(6, prop_##name, manip_##name); \
    (builder)->RegisterProperty(rClass, #name, offsetof(className, name), regProp_##name); \

#define REGISTER_CLASS_PROPERTY(builder, rClass, className, classRefName, name) \
    void* prop_##name = (builder)->GetClassRef(#classRefName); \
    (builder)->RegisterProperty(rClass, #name, offsetof(className, name), prop_##name); \

#define REGISTER_CLASS_VECTOR_PROPERTY(builder, rClass, className, name, elementType) \
    void* prop_##name = (builder)->GetClassRef(#elementType); \
    Reflection::RCustomType::TStdVectorManipulator<elementType>* manip_##name = new Reflection::RCustomType::TStdVectorManipulator<elementType>(); \
    void* regProp_##name = (builder)->RegisterPointerProperty(2, prop_##name, manip_##name); \
    (builder)->RegisterProperty(rClass, #name, offsetof(className, name), regProp_##name); \

#define REGISTER_CLASS_MAP_PROPERTY(builder, rClass, className, name, valueType) \
    void* prop_##name = (builder)->GetClassRef(#valueType); \
    Reflection::RCustomType::TStdVectorManipulator<int>* manip_##name = new Reflection::RCustomType::TStdVectorManipulator<int>(); \
    void* regProp_##name = (builder)->RegisterPointerProperty(6, prop_##name, manip_##name); \
    (builder)->RegisterProperty(rClass, #name, offsetof(className, name), regProp_##name); \

#define REGISTER_CLASS_RTWEAKPTR_PROPERTY(builder, rClass, className, name, valueType) \
    void* prop_##name = (builder)->GetClassRef(#valueType); \
    void* regProp_##name = (builder)->RegisterPointerProperty(3, prop_##name, 0); \
    (builder)->RegisterProperty(rClass, #name, offsetof(className, name), regProp_##name); \

#define REGISTER_RTWEAKPTR_VECTOR_PROPERTY(builder, rClass, className, name, valueType) \
    void* prop_##name = (builder)->GetClassRef(#valueType); \
    void* rtWeakPtrProp_##name = (builder)->RegisterPointerProperty(3, prop_##name, 0); \
    Reflection::RCustomType::TStdVectorManipulator<RtWeakPtr<valueType>>* manip_##name = new Reflection::RCustomType::TStdVectorManipulator<RtWeakPtr<valueType>>(); \
    void* vecProp_##name = (builder)->RegisterPointerProperty(2, rtWeakPtrProp_##name, manip_##name); \
    (builder)->RegisterProperty(rClass, #name, offsetof(className, name), vecProp_##name); \

// Registers a SexyString class property. ONLY use with SexyString, not any other type of string.
#define REGISTER_STRING_PROPERTY(builder, rClass, className, name) \
    void* prop_##name = (builder)->GetPropertyOfType(Reflection::Type_Char, sizeof(char)); \
    void* regProp_##name = (builder)->RegisterPointerProperty(0, prop_##name, NULL); \
    (builder)->RegisterProperty(rClass, #name, offsetof(className, name), regProp_##name); \

#define REGISTER_CLASS_WITH_PROPERTIES(builder, className) \
    (builder)->RegisterClassWithProperties(#className, className::buildSymbols, sizeof(className), 0); \

#define DECLARE_STATIC_RT_CLASS_MEMBERS(className) \
    public: \
        static void* vftable; \
        static Sexy::RtClass* s_rtClass; \
        static void modInit();

#define DECLARE_STATIC_RT_CLASS_MEMBERS_NO_VFTABLE_PATCH(className) \
    public: \
        static Sexy::RtClass* s_rtClass; \
        static void modInit();

#define DEFINE_STATIC_RT_CLASS_MEMBERS(className) \
    void* className::vftable = NULL; \
    Sexy::RtClass* className::s_rtClass = NULL;

#define DEFINE_STATIC_RT_CLASS_MEMBERS_NO_VFTABLE_PATCH(className) \
    Sexy::RtClass* className::s_rtClass = NULL;

#define RT_CLASS_BUILD_SYMBOLS() \
    static void buildSymbols(Reflection::CRefManualSymbolBuilder* builder, Reflection::RClass* rclass) \

#define DEFINE_RT_CLASS_BUILD_SYMBOLS_WITHOUT_CLASS_PROPERTIES(className, parentClassName) \
    static void buildSymbols(Reflection::CRefManualSymbolBuilder* builder, Reflection::RClass* rclass) \
    { \
        Sexy::RtClass* rtClass = getRtClass(); \
        rtClass->SetRClass(rclass); \
        rclass->m_rtclass = rtClass; \
        Reflection::RClassRef* ref = builder->GetClassRef(#parentClassName); \
        Reflection::RClass* parent = ref->GetRClass(); \
        builder->SetRClassWithParent(rclass, parent, 0); \
    } \

#define DEFINE_RT_CLASS_NAME_MACRO(className)

#define RT_CLASS_BUILD_SYMBOLS_BEGIN(className, parentClassName) \
    static void buildSymbols(Reflection::CRefManualSymbolBuilder* builder, Reflection::RClass* rclass) \
    { \
        Sexy::RtClass* rtClass = getRtClass(); \
        rtClass->SetRClass(rclass); \
        rclass->m_rtclass = rtClass; \
        Reflection::RClassRef* ref = builder->GetClassRef(#parentClassName); \
        Reflection::RClass* parent = ref->GetRClass(); \

#define RT_CLASS_BUILD_SYMBOLS_END() \
        builder->SetRClassWithParent(rclass, parent, 0); \
    } \

#define RT_CLASS_STANDARD_PROPERTY(className, name) \
    REGISTER_STANDARD_PROPERTY(builder, rclass, className, name);

#define RT_CLASS_CLASS_PROPERTY(className, propClassName, name) \
    REGISTER_CLASS_PROPERTY(builder, rclass, className, propClassName, name);

#define DEFINE_RT_CLASS_REGISTER_CLASS_FUNCTION(className) \
    static void registerClass() \
    { \
        typedef void* (*func123B308)(); \
        func123B308 func_0x123B308 = (func123B308)getActualOffset(RT_BUILDER_REGISTERCLASS_FUNC1); \
        void* v0 = (void*)func_0x123B308(); \
        if (v0) \
        { \
            typedef void* (*func123B35C)(void*); \
            func123B35C func_0x123B35C = (func123B35C)getActualOffset(RT_BUILDER_REGISTERCLASS_FUNC2); \
            auto* builder = (Reflection::CRefManualSymbolBuilder*)func_0x123B35C(v0); \
            if (builder) \
            { \
                REGISTER_CLASS_WITH_PROPERTIES(builder, className); \
            } \
        } \
    }

#define DEFINE_RT_CLASS_REGISTER_CLASS_AND_STATES_FUNCTION(className) \
    static void registerClass() \
    { \
        typedef void* (*func123B308)(); \
        func123B308 func_0x123B308 = (func123B308)getActualOffset(RT_BUILDER_REGISTERCLASS_FUNC1); \
        void* v0 = (void*)func_0x123B308(); \
        if (v0) \
        { \
            typedef void* (*func123B35C)(void*); \
            func123B35C func_0x123B35C = (func123B35C)getActualOffset(RT_BUILDER_REGISTERCLASS_FUNC2); \
            auto* builder = (Reflection::CRefManualSymbolBuilder*)func_0x123B35C(v0); \
            if (builder) \
            { \
                REGISTER_CLASS_WITH_PROPERTIES(builder, className); \
            } \
        } \
        buildStates(); \
    }*/

#define DEFINE_RT_CLASS_CONSTRUCT_FUNCTION(className, baseCtorAddr) \
	static void* construct() \
	{ \
		auto* instance = new className(); \
		typedef void* (*ctorWithThisPtr)(void*); \
		ctorWithThisPtr baseCtor = (ctorWithThisPtr)getActualOffset(baseCtorAddr); \
		baseCtor(instance); \
		setVFTable(instance, (uintptr_t)vftable); \
		return instance; \
	};

#define DEFINE_RT_CLASS_CONSTRUCT_FUNCTION_WITH_TI(className, baseCtorAddr, typeInfoAddr) \
    static void* construct() \
    { \
        auto* instance = new className(); \
        typedef void* (*ctorWithThisPtr)(void*); \
        ctorWithThisPtr baseCtor = (ctorWithThisPtr)getActualOffset(baseCtorAddr); \
        baseCtor(instance); \
        setVFTable(instance, (uintptr_t)vftable); \
        ((int*)instance)[4] = getActualOffset(typeInfoAddr); \
        return instance; \
    }

#define DEFINE_RT_CLASS_CONSTRUCT_FUNCTION_NO_VFTABLE_PATCH(className) \
    static void* construct() \
    { \
		return new className(); \
    }

#define DEFINE_RT_CLASS_CONSTRUCT_FUNCTION_BEGIN(className, baseCtorAddr) \
	static void* construct() \
	{ \
		auto* instance = new className(); \
		typedef void* (*ctorWithThisPtr)(void*); \
		ctorWithThisPtr baseCtor = (ctorWithThisPtr)getActualOffset(baseCtorAddr);

#define DEFINE_RT_CLASS_CONSTRUCT_FUNCTION_END() \
		baseCtor(instance); \
		setVFTable(instance, (uintptr_t)vftable); \
		return instance; \
	};

#define DEFINE_RT_CLASS_GET_CLASS_FUNCTION(className, parentGetTypeAddr) \
    static Sexy::RtClass* getRtClass() \
    { \
        if (!s_rtClass) \
        { \
            Sexy::RtClass* rtClass = new Sexy::RtClass(); \
            s_rtClass = rtClass; \
            rtClassGetClassFunc parentGetType = (rtClassGetClassFunc)getActualOffset(parentGetTypeAddr); \
            Sexy::RtClass* parent = parentGetType(); \
            rtClass->RegisterClass(#className, parent, className::construct); \
            registerClass(); \
        } \
        return s_rtClass; \
    }

#ifdef __arm__
#define DEFINE_RT_CLASS_GET_CLASS_OVERRIDE(className, parentGetTypeAddr, existingGetTypeAddr, existingTypeAddr) \
    static Sexy::RtClass* getRtClass() \
    { \
        if (!s_rtClass) \
        { \
            Sexy::RtClass* rtClass = new Sexy::RtClass(); \
            s_rtClass = rtClass; \
            rtClassGetClassFunc parentGetType = (rtClassGetClassFunc)getActualOffset(parentGetTypeAddr); \
            Sexy::RtClass* parent = parentGetType(); \
            rtClass->RegisterClass(#className, parent, className::construct); \
            registerClass(); \
            uint dummy; \
            MSHookFunction((void*)getActualOffset(existingGetTypeAddr), (void*)className::getRTClass, (void**)&dummy); \
            ReplaceRTClassPtr(getActualOffset(existingTypeAddr), rtClass); \
            LOGI("Override...");    \
        } \
        return s_rtClass; \
    }
#endif

#define DEFINE_RT_CLASS_GET_CLASS_WRAPPER(getTypeAddr) \
    static Sexy::RtClass* getRtClass() \
    { \
        typedef Sexy::RtClass* (*getType)(); \
        getType pGetType = (getType)getActualOffset(getTypeAddr); \
        return pGetType(); \
    } 

#define DEFINE_RT_CLASS_GET_CLASS_NO_PROPERTIES_FUNCTION(className, parentGetTypeAddr) \
    static Sexy::RtClass* getRtClass() \
    { \
        if (!s_rtClass) \
        { \
            Sexy::RtClass* rtClass = new Sexy::RtClass(); \
            s_rtClass = rtClass; \
            rtClassGetClassFunc parentGetType = (rtClassGetClassFunc)getActualOffset(parentGetTypeAddr); \
            Sexy::RtClass* parent = parentGetType(); \
            rtClass->RegisterClass(#className, parent, className::construct); \
        } \
        return s_rtClass; \
    }

#define DEFINE_RTOBJECT_OVERRIDE_GETTYPE(className) \
    Sexy::RtClass* GetType() override { return className::getRtClass(); }

#define DECLARE_RTOBJECT_DTORS(className) \
    static void* Destroy(className* self); \
    static void DestroyAndDealloc(className* self) { \
        auto ptr = Destroy(self); \
        operator delete(ptr); \
    }