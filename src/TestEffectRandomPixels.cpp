#include "TestEffectRandomPixels.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


TestEffectRandomPixels::TestEffectRandomPixels(int16_t width, int16_t height)
{
	m_Data.pixelColors = (struct Color*)malloc(width * height * sizeof(struct Color));
    memset(m_Data.pixelColors, 0, width * height * sizeof(struct Color));

	m_Cfg.color.R = 255;
	m_Cfg.color.G = 255;
	m_Cfg.color.B = 255;

    m_Cfg.randomRed = true;
    m_Cfg.randomBlue = true;
    m_Cfg.randomGreen = true;

    m_Cfg.spawninterval = 400;

    m_Eff.effectcfg = &m_Cfg;
    m_Eff.effectdata = &m_Data;
    m_Eff.update = &EffectRandomPixelsUpdate;
    m_Eff.reset = &EffectRandomPixelsReset;
    m_Eff.p_next = NULL;
}
