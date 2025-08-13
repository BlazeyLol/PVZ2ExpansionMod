#pragma once
#include "ObjectTypeDescriptor.h"
#include "Plant.h"

#include <Sexy/RtWeakPtr.h>

enum PlantMasteryFocusType {
	health,
	piercing
};

class PlantType : public ObjectTypeDescriptor
{
public:
	SexyString PlantFramework;
	SexyString AnimRigClass;
	SexyString PopAnim;
	int unk1;
	Sexy::RtWeakPtr<PlantPropertySheet> Properties;
	bool Enabled;
	bool Premium;
	std::vector<SexyString> Families;
	PlantMasteryFocusType MasteryType;
	SexyString HomeWorld;
	SexyString AlmanacBackdropName;
	float SeedChooserVerticalOffset;
	float SeedChooserBigVerticalOffset;
	float SeedChooserBigHorizontalOffset;
	float SeedChooserBigScale;
	int unk3;
	int BundleVerticalOffset;
	bool HideInPlantViewers;
	bool DenyPlantfoodCooldownReset;
	bool CannotBeImitated;
	float SeasonsVerticalOffset;
	std::vector<SexyString> PlantResourceGroups;
	std::vector<SexyString> PlantPreviewResourceGroups;

	// new properties
	int IntegerID = 0;
	bool HasShadow = true;
	bool HasStoreShadow;
	float ShadowScale = 1.0f;
	SexyVector2 ShadowOffset;

	static Reflection::CRefManualSymbolBuilder::BuildSymbolsFunc oPlantTypeBuildSymbols;

	static void buildSymbols(Reflection::CRefManualSymbolBuilder* builder, Reflection::RClass* rclass)
	{
		oPlantTypeBuildSymbols(builder, rclass);
		LOGI("Building symbols for PlantType");
		REGISTER_STANDARD_PROPERTY(builder, rclass, PlantType, IntegerID);
		REGISTER_STANDARD_PROPERTY(builder, rclass, PlantType, HasShadow);
		REGISTER_STANDARD_PROPERTY(builder, rclass, PlantType, HasStoreShadow);
		REGISTER_STANDARD_PROPERTY(builder, rclass, PlantType, ShadowScale);
		REGISTER_CLASS_PROPERTY(builder, rclass, PlantType, SexyVector2, ShadowOffset);
	}
};

#ifdef A32
static_assert(sizeof(PlantType) == 0xB8);
static_assert(offsetof(PlantType, PlantFramework) == 0x10);
static_assert(offsetof(PlantType, HomeWorld) == 0x54);
static_assert(offsetof(PlantType, AlmanacBackdropName) == 0x60);
static_assert(offsetof(PlantType, HideInPlantViewers) == 0x84);
static_assert(offsetof(PlantType, PlantResourceGroups) == 0x8C);
static_assert(offsetof(PlantType, IntegerID) == 0xA4);
static_assert(offsetof(PlantType, HasShadow) == 0xA8);
static_assert(offsetof(PlantType, HasStoreShadow) == 0xA9);
static_assert(offsetof(PlantType, ShadowScale) == 0xAC);
static_assert(offsetof(PlantType, ShadowOffset) == 0xB0);
#else
static_assert(sizeof(PlantType) == 0x130);
static_assert(offsetof(PlantType, PlantFramework) == 0x20);
static_assert(offsetof(PlantType, HomeWorld) == 0x98);
static_assert(offsetof(PlantType, AlmanacBackdropName) == 0xB0);
static_assert(offsetof(PlantType, HideInPlantViewers) == 0xE0);
static_assert(offsetof(PlantType, PlantResourceGroups) == 0xE8);
static_assert(offsetof(PlantType, IntegerID) == 0x118);
static_assert(offsetof(PlantType, HasShadow) == 0x11C);
static_assert(offsetof(PlantType, HasStoreShadow) == 0x11D);
static_assert(offsetof(PlantType, ShadowScale) == 0x120);
static_assert(offsetof(PlantType, ShadowOffset) == 0x124);
#endif