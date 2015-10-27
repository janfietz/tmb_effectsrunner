#pragma once

#ifndef _TEST_EFFECT_FADINGPIXELS_H_
#define _TEST_EFFECT_FADINGPIXELS_H_

#include "TestEffect.h"
#include "effect_fadingpixels.h"

class TestEffectFadingPixels : public TestEffect
{
public:

    TestEffectFadingPixels(int16_t width, int16_t height);

private:

    EffectFadingPixelsCfg m_Cfg;
    EffectFadingPixelsData m_Data;
};

#endif
