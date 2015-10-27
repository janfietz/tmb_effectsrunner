#pragma once

#ifndef _TEST_EFFECT_PLASMA_H_
#define _TEST_EFFECT_PLASMA_H_

#include "TestEffect.h"
#include "effect_plasma.h"

class TestEffectPlasma : public TestEffect
{
public:

    TestEffectPlasma(int16_t width, int16_t height);

private:

    EffectPlasmaCfg m_Cfg;
    EffectPlasmaData m_Data;
};

#endif
