#include "TestEffectNightSky.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


TestEffectNightSky::TestEffectNightSky(int16_t width, int16_t height)
{
	m_Data.pixelColors = (struct Color*)malloc(width * height * sizeof(struct Color));
    memset(m_Data.pixelColors, 0, width * height * sizeof(struct Color));

    m_Data.fadeStates = (struct EffectFadeState*)malloc(width * height * sizeof(struct EffectFadeState));
    memset(m_Data.fadeStates, 0, width * height * sizeof(struct EffectFadeState));

    m_Cfg.randomizePropability = 10;
    m_Cfg.fadeperiod = 10000;
	m_Cfg.color.R = 255;
	m_Cfg.color.G = 255;
	m_Cfg.color.B = 255;

    m_Cfg.randomColor = true;

    m_Eff.effectcfg = &m_Cfg;
    m_Eff.effectdata = &m_Data;
    m_Eff.update = &EffectNightSkyUpdate;
    m_Eff.reset = &EffectNightSkyReset;
    m_Eff.p_next = NULL;
}
