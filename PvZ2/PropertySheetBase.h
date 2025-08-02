#pragma once
#include "GameObject.h"

#define PROPSHEETBASE_VFTABLE_FUNC_COUNT 14
#define PROPSHEETBASE_VFTABLE 0x1CB3AA8
#define PROPSHEETBASE_GETTYPE 0x980F74
#define PROPSHEETBASE_CTOR 0x253C50
#define PROPSHEETBASE_DTOR 0x253C50

class BoardEntityScaledPropsEntry
{
public:
	SexyString Key;
	int Formula;
	float Arg1;
	float Arg2;
};

class PropertySheetBase : public GameObject
{
public:
	PropertySheetBase() {}
	~PropertySheetBase()
	{
		typedef void(*propertySheetBaseDtor)(PropertySheetBase*);
		propertySheetBaseDtor destructor = (propertySheetBaseDtor)getActualOffset(0x253CE8);
		destructor(this);
	}

	std::vector<BoardEntityScaledPropsEntry> ScaledProps;

	virtual void Function13() {}
	virtual void Function14() {}
	virtual void Function15() {}
};