#pragma once

#ifndef _TEST_EFFECT_DEFAULT_H_
#define _TEST_EFFECT_DEFAULT_H_

#include "TestEffect.h"
#include "effect_simplecolor.h"

class TestEffectDefault : public TestEffect
{
public:

    TestEffectDefault(int16_t width, int16_t height);

    virtual void Update(systime_t ticks, DisplayBuffer& buffer);

private:

    EffectSimpleColorCfg m_Cfg;
    EffectSimpleColorData m_Data;
};

#endif