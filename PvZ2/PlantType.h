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
	int IntegerID;
	bool HasShadow;
	bool HasStoreShadow;
	float ShadowScale = 1.0f;
	SexyVector2 ShadowOffset;

	static Reflection::CRefManualSymbolBuilder::BuildSymbolsFunc oPlantTypeBuildSymbols;

	static void buildSymbols(Reflection::CRefManualSymbolBuilder* builder, Reflection::RClass* rclass)
	{
		oPlantTypeBuildSymbols(builder, rclass);
		REGISTER_STANDARD_PROPERTY(builder, rclass, PlantType, IntegerID);
		REGISTER_STANDARD_PROPERTY(builder, rclass, PlantType, HasShadow);
		REGISTER_STANDARD_PROPERTY(builder, rclass, PlantType, HasStoreShadow);
		REGISTER_STANDARD_PROPERTY(builder, rclass, PlantType, ShadowScale);
		REGISTER_CLASS_PROPERTY(builder, rclass, PlantType, SexyVector2, ShadowOffset);
	}
};

static_assert(sizeof(PlantType) == 0xB8);
static_assert(offsetof(PlantType, PlantFramework) == 0x10);
static_assert(offsetof(PlantType, AnimRigClass) == 0x1C);
static_assert(offsetof(PlantType, PopAnim) == 0x28);
static_assert(offsetof(PlantType, Properties) == 0x38);
static_assert(offsetof(PlantType, Enabled) == 0x40);
static_assert(offsetof(PlantType, Premium) == 0x41);
static_assert(offsetof(PlantType, Families) == 0x44);
static_assert(offsetof(PlantType, MasteryType) == 0x50);
static_assert(offsetof(PlantType, HomeWorld) == 0x54);
static_assert(offsetof(PlantType, AlmanacBackdropName) == 0x60);
static_assert(offsetof(PlantType, SeedChooserVerticalOffset) == 0x6C);
static_assert(offsetof(PlantType, SeedChooserBigVerticalOffset) == 0x70);
static_assert(offsetof(PlantType, SeedChooserBigHorizontalOffset) == 0x74);
static_assert(offsetof(PlantType, SeedChooserBigScale) == 0x78);
static_assert(offsetof(PlantType, BundleVerticalOffset) == 0x80);
static_assert(offsetof(PlantType, HideInPlantViewers) == 0x84);
static_assert(offsetof(PlantType, DenyPlantfoodCooldownReset) == 0x85);
static_assert(offsetof(PlantType, CannotBeImitated) == 0x86);
static_assert(offsetof(PlantType, SeasonsVerticalOffset) == 0x88);
static_assert(offsetof(PlantType, PlantResourceGroups) == 0x8C);
static_assert(offsetof(PlantType, PlantPreviewResourceGroups) == 0x98);
static_assert(offsetof(PlantType, IntegerID) == 0xA4);
static_assert(offsetof(PlantType, HasShadow) == 0xA8);
static_assert(offsetof(PlantType, HasStoreShadow) == 0xA9);
static_assert(offsetof(PlantType, ShadowScale) == 0xAC);
static_assert(offsetof(PlantType, ShadowOffset) == 0xB0);