#pragma once

#ifndef _TEST_EFFECT_DEFAULT_H_
#define _TEST_EFFECT_DEFAULT_H_

#include "ITestEffect.h"
#include "effect_simplecolor.h"

class TestEffectDefault : public ITestEffect
{
public:

    TestEffectDefault();

    virtual void Update(systime_t ticks, DisplayBuffer& buffer);
    virtual void Reset(systime_t ticks);

private:

    EffectSimpleColorCfg m_Cfg;
    EffectSimpleColorData m_Data;
    Effect m_Eff;
};

#endif