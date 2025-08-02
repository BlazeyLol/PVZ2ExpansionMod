#pragma once
#include <algorithm>
#include <vector>

enum RestrictionSetType
{
	excludelist,
	includelist
};

class StringRestrictionSet
{
public:
	std::vector<SexyString> List;
	RestrictionSetType ListType;
};

class PlantRestrictionSet : public StringRestrictionSet
{
public:
};

class PlantingRestrictionSet : public PlantRestrictionSet
{
public:
};

class GridItemRestrictionSet : public StringRestrictionSet
{
public:

};