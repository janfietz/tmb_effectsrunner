#include "TestEffectPlasma.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


TestEffectPlasma::TestEffectPlasma(int16_t width, int16_t height)
{
    m_Data.pixelColors = (struct Color*)malloc(width * height * sizeof(struct Color));
    memset(m_Data.pixelColors, 0, width * height * sizeof(struct Color));

    m_Cfg.spawninterval = 100;
    m_Cfg.period1 = 1;

    //generate palette
    for(uint16_t i = 0; i < 256; ++i)
    {
        Color& c = m_Cfg.palette[i];

        c.R = 128 + (127 * sin(M_PI * ((float)i / 32.0f)));
        c.G = 128 + (127 * sin(M_PI * ((float)i / 64.0f)));
        c.B = 128 + (127 * sin(M_PI * ((float)i / 128.0f)));
    }

    m_Eff.effectcfg = &m_Cfg;
    m_Eff.effectdata = &m_Data;
    m_Eff.update = &EffectPlasmaUpdate;
    m_Eff.reset = &EffectPlasmaReset;
    m_Eff.p_next = NULL;
}
