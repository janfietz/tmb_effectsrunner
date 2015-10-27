#pragma once

#ifndef _TEST_EFFECT_H_
#define _TEST_EFFECT_H_

#include "ITestEffect.h"
#include "effect.h"

class TestEffect : public ITestEffect
{
public:

	virtual void Update(systime_t ticks, DisplayBuffer& buffer);
    virtual void Reset(systime_t ticks);

protected:

    Effect m_Eff;
};

#endif