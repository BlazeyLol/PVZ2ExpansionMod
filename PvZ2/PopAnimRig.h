#pragma once
#include "GameObject.h"

#include <Sexy/RtReflectionDelegateBase.h>
#include <Sexy/Color.h>
#include <Sexy/Graphics.h>
#include <Sexy/PopAnim.h>

#define POPANIMRIG_DTOR_ADDR 0x659DCC

#define TRANSANDRENDER_ADDR 0x668EE8 // 9.4
#define RENDER_ADDR 0x65DB9C

class PopAnimRig : public GameObject
{
public:
	int unk;
	float m_saturation;
	Sexy::PopAnim* m_popAnim;
	int unk6;
	Sexy::RtWeakPtr<PopAnimRig> m_selfPtr;
	int m_activeAnim;
	std::string m_activeAnimBaseLabel;
	int m_activeAnimPlayStyle;
	int m_activeAnimSeqEndCount;
	std::vector<int> m_animRandomDistribution;
	int m_activeAnimSelectMethod;
	int m_activeAnimLastPlayedVariation;
	int unk7;
	Sexy::RtWeakPtr<Sexy::RtObject> m_audioObject;
	bool m_manageDeletion;
	bool m_mirrorX;
	bool m_disabled;
	bool m_useShaderOverrideColor;
	int unk3;
	Sexy::Color m_shaderOverrideColor;
	Sexy::Color unk4;
	Sexy::DelegateBase unkDelegateOnStop;
	Sexy::DelegateBase unkDelegateOnLoop;
	Sexy::DelegateBase unkDelegateOnCommand;
	Sexy::RtReflectionDelegateBase m_serialOnAnimStopped;
	Sexy::RtReflectionDelegateBase m_serialOnLoopingAnimContinued;
	Sexy::RtReflectionDelegateBase m_serialOnPopAnimCommand;
	bool m_registeredInAudioMgr;
	char unk5[11];
	int m_state;

	void TransformAndRender(Sexy::Graphics* graphics, Sexy::Transform2D& trans) {
		typedef void (*func)(PopAnimRig*, Sexy::Graphics*, Sexy::Transform2D*);
		((func)getActualOffset(TRANSANDRENDER_ADDR))(this, graphics, &trans);
	}

	void Render(Sexy::Graphics* graphics) {
		typedef void (*func)(PopAnimRig*, Sexy::Graphics*);
		((func)getActualOffset(RENDER_ADDR))(this, graphics);
	}

	Sexy::Color GetColor() {
		return this->m_popAnim->m_color;
	}

	void SetColor(Sexy::Color& color) {
		this->m_popAnim->m_color = color;
	}

	virtual int SetActiveAnim(SexyString* animName, int a3, uint unk_stateNum, int a5) {}
	virtual int SetAnimModifier(float multiplier) {}
	virtual int Function16() {}
	virtual int Function17() {}
	virtual int Function18() {}
	virtual int Function19() {}
	virtual int Function20() {}
	virtual int Function21() {}
	virtual int Function22() {}
	virtual int Function23() {}
	virtual int Function24() {}
	virtual int Function25() {}
	virtual int Function26() {}
	virtual int Function27() {}
	virtual int Function28() {}
	virtual int DamageFlash() {}
	virtual int GetUserShaderOverrideColor() {}
	virtual int Function31() {}

};

static_assert(offsetof(PopAnimRig, m_selfPtr) == 0x20);
static_assert(offsetof(PopAnimRig, m_audioObject) == 0x58);
static_assert(offsetof(PopAnimRig, m_registeredInAudioMgr) == 0x160);
static_assert(offsetof(PopAnimRig, unk5) == 0x161);