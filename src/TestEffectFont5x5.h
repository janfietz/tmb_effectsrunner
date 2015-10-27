#pragma once

#ifndef _TEST_EFFECT_FONT5x5_H_
#define _TEST_EFFECT_FONT5x5_H_

#include "TestEffect.h"
#include "effect_font_5x5.h"
#include "effect_simplecolor.h"

#include <string>

class TestEffectFont5x5 : public TestEffect
{
public:

    TestEffectFont5x5(int16_t width, int16_t height);

    virtual void Update(systime_t ticks, DisplayBuffer& buffer);

private:

    EffectFont5x5Cfg m_Cfg;
    EffectFont5x5Data m_Data;

    EffectSimpleColorCfg m_ColorCfg;
    EffectSimpleColorData m_ColorData;
    Effect m_ColorEff;

    std::string m_CharSequence;
    size_t m_CharSequenceIdx;
};

#endif
