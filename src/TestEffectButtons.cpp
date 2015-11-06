#include "TestEffectButtons.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


TestEffectButtons::TestEffectButtons(int16_t width, int16_t height)
{
    m_Cfg.play.x = 0;
    m_Cfg.play.y = 0;
    ColorFromRGBValue(0x51BD1F , &m_Cfg.play.color);


    m_Cfg.vol_up.x = 10;
    m_Cfg.vol_up.y = 4;
    ColorFromRGBValue(0x46084E , &m_Cfg.vol_up.color);

    m_Cfg.vol_down.x = 0;
    m_Cfg.vol_down.y = 4;
    ColorFromRGBValue(0x46084E , &m_Cfg.vol_down.color);

    m_Cfg.next.x = 10;
    m_Cfg.next.y = 2;
    ColorFromRGBValue(0xFFD600 , &m_Cfg.next.color);

    m_Cfg.prev.x = 0;
    m_Cfg.prev.y = 2;
    ColorFromRGBValue(0xFFD600 , &m_Cfg.prev.color);

    m_Cfg.special.x = 10;
    m_Cfg.special.y = 0;
    ColorFromRGBValue(0xFFD600 , &m_Cfg.prev.color);

    m_Cfg.playMode = EFFECT_BUTTON_MODE_PLAY;

    m_Cfg.blendperiod = 1000;

    ColorFromRGBValue(0x290002 , &m_Cfg.colorModeEmptyPlayList);
    ColorFromRGBValue(0xFF6D00 , &m_Cfg.colorModePause);
    ColorFromRGBValue(0xE4242E , &m_Cfg.colorModeStop);

    
    m_Eff.effectcfg = &m_Cfg;
    m_Eff.effectdata = &m_Data;
    m_Eff.update = &EffectButtonsUpdate;
    m_Eff.reset = &EffectButtonsReset;
    m_Eff.p_next = NULL;
}

void TestEffectButtons::Update(systime_t ticks, DisplayBuffer& buffer)
{
    if (ticks % 1000 == 0)
    {
        m_Cfg.playMode += 1;
        if (m_Cfg.playMode > 3)
        {
            m_Cfg.playMode = 0;
        }
    }

    TestEffect::Update(ticks, buffer);
}
