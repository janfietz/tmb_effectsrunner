#include "TestEffectFadingPixels.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


TestEffectFadingPixels::TestEffectFadingPixels(int16_t width, int16_t height)
{
    m_Data.fadeStates = (struct EffectFadeState*)malloc(width * height * sizeof(struct EffectFadeState));
    memset(m_Data.fadeStates, 0, width * height * sizeof(struct EffectFadeState));

    m_Data.pixelColors = (struct Color*)malloc(width * height * sizeof(struct Color));
    memset(m_Data.pixelColors, 0, width * height * sizeof(struct Color));

    m_Cfg.randomColor = true;
    m_Cfg.number = 1;
    m_Cfg.spawninterval = 100;
    m_Cfg.fadeperiod = 10000;

    m_Eff.effectcfg = &m_Cfg;
    m_Eff.effectdata = &m_Data;
    m_Eff.update = &EffectFadingPixelsUpdate;
    m_Eff.reset = &EffectFadingPixelsReset;
    m_Eff.p_next = NULL;
}
