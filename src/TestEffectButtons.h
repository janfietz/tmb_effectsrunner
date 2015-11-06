#pragma once

#ifndef _TEST_EFFECT_BUTTONS_H_
#define _TEST_EFFECT_BUTTONS_H_

#include "TestEffect.h"
#include "effect_buttons.h"

class TestEffectButtons : public TestEffect
{
public:

    TestEffectButtons(int16_t width, int16_t height);

    virtual void Update(systime_t ticks, DisplayBuffer& buffer);

private:

    EffectButtonsCfg m_Cfg;
    EffectButtonsData m_Data;
};

#endif
