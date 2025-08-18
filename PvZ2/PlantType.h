#pragma once
#include "ObjectTypeDescriptor.h"
#include "Plant.h"

#include <Sexy/RtWeakPtr.h>

class PlantType : public ObjectTypeDescriptor
{
public:
	enum PlantMasteryFocusType {
		health,
		piercing
	};

	SexyString PlantFramework;
	SexyString AnimRigClass;
	SexyString PopAnim;
	int unk1;
	Sexy::RtWeakPtr<PlantPropertySheet> Properties;
	bool Enabled = true;
	bool Premium;
	std::vector<SexyString> Families;
	PlantMasteryFocusType MasteryType = piercing;
	SexyString HomeWorld;
	SexyString AlmanacBackdropName;
	float SeedChooserVerticalOffset;
	float SeedChooserBigVerticalOffset;
	float SeedChooserBigHorizontalOffset;
	float SeedChooserBigScale;
	int unk2;
	int BundleVerticalOffset;
	bool HideInPlantViewers;
	bool DenyPlantfoodCooldownReset;
	bool CannotBeImitated;
	float SeasonsVerticalOffset = 1.4f;
	std::vector<SexyString> PlantResourceGroups;
	std::vector<SexyString> PlantPreviewResourceGroups;

	// new properties
	int IntegerID = 0;
	bool HasShadow = true;
	bool HasStoreShadow = true;
	float ShadowScale = 1.0f;
	SexyVector2 ShadowOffset;

	static Reflection::CRefManualSymbolBuilder::BuildSymbolsFunc oPlantTypeBuildSymbols;
	static Reflection::CRefManualSymbolBuilder::ConstructFunc oPlantTypeConstruct;

	static void* construct(PlantType* self)
	{
		oPlantTypeConstruct(self);

		self->IntegerID = 0;
		self->HasShadow = true;
		self->HasStoreShadow = true;
		self->ShadowScale = 1.0f;
		self->ShadowOffset = SexyVector2();

		return self;
	}

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
static_assert(offsetof(PlantType, HomeWorld) == 0x54);
static_assert(offsetof(PlantType, AlmanacBackdropName) == 0x60);
static_assert(offsetof(PlantType, HideInPlantViewers) == 0x84);
static_assert(offsetof(PlantType, PlantResourceGroups) == 0x8C);
static_assert(offsetof(PlantType, IntegerID) == 0xA4);
static_assert(offsetof(PlantType, HasShadow) == 0xA8);
static_assert(offsetof(PlantType, HasStoreShadow) == 0xA9);
static_assert(offsetof(PlantType, ShadowScale) == 0xAC);
static_assert(offsetof(PlantType, ShadowOffset) == 0xB0);