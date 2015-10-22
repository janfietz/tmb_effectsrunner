#pragma once

#ifndef _TEST_EFFECT_WANDERING_H_
#define _TEST_EFFECT_WANDERING_H_

#include "ITestEffect.h"
#include "effect_wandering.h"
#include "effect_simplecolor.h"


class TestEffectWandering : public ITestEffect
{
public:

    TestEffectWandering();

    virtual void Update(systime_t ticks, DisplayBuffer& buffer);
    virtual void Reset(systime_t ticks);

private:

    EffectWanderingCfg m_Cfg;
    EffectWanderingData m_Data;
    Effect m_Eff;

    EffectSimpleColorCfg m_ColorCfg;
    EffectSimpleColorData m_ColorData;
    Effect m_ColorEff;
};

#endif