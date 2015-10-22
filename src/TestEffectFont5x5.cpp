#include "TestEffectFont5x5.h"
#include <unistd.h>


TestEffectFont5x5::TestEffectFont5x5()
{
    m_Eff.effectcfg = &m_Cfg;
    m_Eff.effectdata = &m_Data;
    m_Eff.update = &EffectFont5x5Update;
    m_Eff.reset = &EffectFont5x5Reset;
    m_Eff.p_next = &m_ColorEff;

    m_ColorEff.effectcfg = &m_ColorCfg;
    m_ColorEff.effectdata = &m_ColorData;
    m_ColorEff.update = &EffectSimpleUpdate;
    m_ColorEff.reset = &EffectSimpleReset;
    m_ColorEff.p_next = NULL;

    m_ColorCfg.color.R = 0;
    m_ColorCfg.color.G = 255;
    m_ColorCfg.color.B = 0;
    m_ColorCfg.fillbuffer = false;

    m_CharSequence = "0123456789abcdefghijklmnopqrstuvwxyz";
    m_CharSequenceIdx = 0;
}


void TestEffectFont5x5::Update(systime_t ticks, DisplayBuffer& buffer)
{
	m_Cfg.text[0] = m_CharSequence.at(m_CharSequenceIdx);

    EffectUpdate(&m_Eff, 0, 0, ticks,&buffer);

    if (ticks % 1000 == 0)
    {
    	++m_CharSequenceIdx;
    	if (m_CharSequenceIdx == m_CharSequence.size())
    	{
    		m_CharSequenceIdx = 0;
    	}
    }
}

void TestEffectFont5x5::Reset(systime_t ticks)
{

}
