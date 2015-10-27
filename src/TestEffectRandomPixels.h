#pragma once

#ifndef _TEST_EFFECT_RANDOMPIXELS_H_
#define _TEST_EFFECT_RANDOMPIXELS_H_

#include "TestEffect.h"
#include "effect_randompixels.h"

class TestEffectRandomPixels : public TestEffect
{
public:

    TestEffectRandomPixels(int16_t width, int16_t height);

private:

    EffectRandomPixelsCfg m_Cfg;
    EffectRandomPixelsData m_Data;
};

#endif
