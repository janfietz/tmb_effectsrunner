#pragma once

#ifndef _TEST_EFFECT_FALLINGPIXELS_H_
#define _TEST_EFFECT_FALLINGPIXELS_H_

#include "TestEffect.h"
#include "effect_fallingpixels.h"

class TestEffectFallingPixels : public TestEffect
{
public:

    TestEffectFallingPixels(int16_t width, int16_t height);

private:

    EffectFallingPixelsCfg m_Cfg;
    EffectFallingPixelsData m_Data;
};

#endif
