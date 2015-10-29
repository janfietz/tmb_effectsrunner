#pragma once

#ifndef _TEST_COLORBLEND_H_
#define _TEST_COLORBLEND_H_

#include "TestEffect.h"
#include "color.h"

class TestColorBlend : public TestEffect
{
public:

    TestColorBlend(int16_t width, int16_t height);

    virtual void Update(systime_t ticks, DisplayBuffer& buffer);
    virtual void Reset(systime_t ticks);

private:
};

#endif