#pragma once

#ifndef _TEST_EFFECT_NIGHTSKY_H_
#define _TEST_EFFECT_NIGHTSKY_H_

#include "TestEffect.h"
#include "effect_nightsky.h"

class TestEffectNightSky : public TestEffect
{
public:

    TestEffectNightSky(int16_t width, int16_t height);

private:

    EffectNightSkyCfg m_Cfg;
    EffectNightSkyData m_Data;
};

#endif
