#include "TestEffectFallingPixels.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


TestEffectFallingPixels::TestEffectFallingPixels(int16_t width, int16_t height)
{
    m_Data.fadeStates = (struct EffectFadeState*)malloc(width * height * sizeof(struct EffectFadeState));
    memset(m_Data.fadeStates, 0, width * height * sizeof(struct EffectFadeState));

    m_Data.pixelColors = (struct Color*)malloc(width * height * sizeof(struct Color));
    memset(m_Data.pixelColors, 0, width * height * sizeof(struct Color));

    m_Cfg.color.R = 0;
    m_Cfg.color.G = 255;
    m_Cfg.color.B = 0;

    m_Cfg.randomRed = true;
    m_Cfg.randomBlue = true;
    m_Cfg.randomGreen = true;

    m_Cfg.spawninterval = 300;
    m_Cfg.fadeperiod = 1000;

    m_Eff.effectcfg = &m_Cfg;
    m_Eff.effectdata = &m_Data;
    m_Eff.update = &EffectFallingPixelsUpdate;
    m_Eff.reset = &EffectFallingPixelsReset;
    m_Eff.p_next = NULL;
}
