#include "TestEffectWandering.h"
#include <unistd.h>


TestEffectWandering::TestEffectWandering(int16_t width, int16_t height)
{
    m_Eff.effectcfg = &m_Cfg;
    m_Eff.effectdata = &m_Data;
    m_Eff.update = &EffectWanderingUpdate;
    m_Eff.reset = &EffectWanderingReset;
    m_Eff.p_next = &m_ColorEff;

    m_Cfg.speed = 100000;
    m_Cfg.ledbegin = 0;
    
    m_Cfg.dir;
    m_Cfg.turn = true;

    m_ColorEff.effectcfg = &m_ColorCfg;
    m_ColorEff.effectdata = &m_ColorData;
    m_ColorEff.update = &EffectSimpleUpdate;
    m_ColorEff.reset = &EffectSimpleReset;
    m_ColorEff.p_next = NULL;

    m_ColorCfg.color.R = 0;
    m_ColorCfg.color.G = 255;
    m_ColorCfg.color.B = 0;
    m_ColorCfg.fillbuffer = false;
}


void TestEffectWandering::Update(systime_t ticks, DisplayBuffer& buffer)
{
    m_Cfg.ledend = buffer.width * buffer.height - 1;
	EffectUpdate(&m_Eff, 0, 0, ticks, &buffer);

    if (ticks % 10000 == 0)
    {
        m_Cfg.dir = 1 - m_Cfg.dir;
    }
}
