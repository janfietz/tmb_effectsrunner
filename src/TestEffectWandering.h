#pragma once

#ifndef _TEST_EFFECT_WANDERING_H_
#define _TEST_EFFECT_WANDERING_H_

#include "TestEffect.h"
#include "effect_wandering.h"
#include "effect_simplecolor.h"


class TestEffectWandering : public TestEffect
{
public:

    TestEffectWandering(int16_t width, int16_t height);

    virtual void Update(systime_t ticks, DisplayBuffer& buffer);

private:

    EffectWanderingCfg m_Cfg;
    EffectWanderingData m_Data;

    EffectSimpleColorCfg m_ColorCfg;
    EffectSimpleColorData m_ColorData;
    Effect m_ColorEff;
};

#endif
