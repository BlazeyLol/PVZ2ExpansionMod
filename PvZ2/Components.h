#pragma once
#include <Sexy/RtWeakPtr.h>
#include <Sexy/RtObject.h>

class ComponentBase : public GameObject
{
public:
	int m_state;
	SexyString m_name;
	Sexy::RtWeakPtr<Sexy::RtObject> m_owner;
};

class ComponentRunnerBase : public ComponentBase {};

class ComponentRunner : public ComponentRunnerBase
{
public:
	std::vector<Sexy::RtWeakPtr<Sexy::RtObject>> m_components;
};