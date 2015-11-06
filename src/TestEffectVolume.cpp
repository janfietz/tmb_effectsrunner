#include "TestEffectVolume.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


TestEffectVolume::TestEffectVolume(int16_t width, int16_t height)
{
    m_Cfg.fontColor.R = 0;
    m_Cfg.fontColor.G = 0;
    m_Cfg.fontColor.B = 255;

    m_Cfg.minColor.R = 0;
    m_Cfg.minColor.G = 255;
    m_Cfg.minColor.B = 0;

    m_Cfg.maxColor.R = 255;
    m_Cfg.maxColor.G = 0;
    m_Cfg.maxColor.B = 0;

    m_Cfg.volume = 0;
    m_Cfg.speed = 30;

    m_Eff.effectcfg = &m_Cfg;
    m_Eff.effectdata = &m_Data;
    m_Eff.update = &EffectVolumeUpdate;
    m_Eff.reset = &EffectVolumeReset;
    m_Eff.p_next = NULL;
}

void TestEffectVolume::Update(systime_t ticks, DisplayBuffer& buffer)
{
    if (ticks % 500 == 0)
    {
        m_Cfg.volume += 1;
        if (m_Cfg.volume > 100)
        {
            m_Cfg.volume = 0;
        }
    }

    if (m_Cfg.volume == 60)
    {
        TestEffect::Reset(ticks);
    }

    TestEffect::Update(ticks, buffer);
}