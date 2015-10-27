#include "TestEffectDefault.h"
#include <unistd.h>


TestEffectDefault::TestEffectDefault(int16_t width, int16_t height)
{
    m_Data.reset = false;

    m_Cfg.fillbuffer = true;

    m_Eff.effectcfg = &m_Cfg;
    m_Eff.effectdata = &m_Data;
    m_Eff.update = &EffectSimpleUpdate;
    m_Eff.reset = &EffectSimpleReset;
    m_Eff.p_next = NULL;
}


void TestEffectDefault::Update(systime_t ticks, DisplayBuffer& buffer)
{
    ColorRandom(&m_Cfg.color);

    EffectUpdate(&m_Eff, -1, -1, ticks,&buffer);
}
