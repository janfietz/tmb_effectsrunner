#include "TestEffect.h"


void TestEffect::Update(systime_t ticks, DisplayBuffer& buffer)
{
    EffectUpdate(&m_Eff, -1, -1, ticks, &buffer);
}

void TestEffect::Reset(systime_t ticks)
{
	EffectReset(&m_Eff, -1, -1, ticks);
}
