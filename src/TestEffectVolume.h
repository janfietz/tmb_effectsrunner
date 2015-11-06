#pragma once

#ifndef _TEST_EFFECT_VOLUME_H_
#define _TEST_EFFECT_VOLUME_H_

#include "TestEffect.h"
#include "effect_volume.h"

class TestEffectVolume : public TestEffect
{
public:

    TestEffectVolume(int16_t width, int16_t height);

    virtual void Update(systime_t ticks, DisplayBuffer& buffer);

private:

    EffectVolumeCfg m_Cfg;
    EffectVolumeData m_Data;
};

#endif
