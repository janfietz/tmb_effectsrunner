#pragma once

#ifndef _I_TEST_EFFECT_H_
#define _I_TEST_EFFECT_H_

#include "effect_defines.h"
#include "display.h"

class ITestEffect
{
public:

	virtual void Update(systime_t ticks, DisplayBuffer& buffer) = 0;
	virtual void Reset(systime_t ticks) = 0;

};

#endif