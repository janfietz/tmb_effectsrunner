#include "TestColorBlend.h"
#include <unistd.h>


TestColorBlend::TestColorBlend(int16_t width, int16_t height)
{

}


void TestColorBlend::Update(systime_t ticks, DisplayBuffer& buffer)
{
    Color first = {.R = 255, .G = 0, .B = 0};
    Color last = {.R = 0, .G = 255, .B = 0};

    Color intermediate;
    ColorBlend(&first, &last, 0, &intermediate);
    DisplayDraw(0, 0, &intermediate, &buffer);

    ColorBlend(&first, &last, 0.5f, &intermediate);
    DisplayDraw(1, 0, &intermediate, &buffer);

    ColorBlend(&first, &last, 1, &intermediate);
    DisplayDraw(2, 0, &intermediate, &buffer);

    for (uint16_t pixel = 0; pixel < buffer.width; ++pixel)
    {
        float step = (float)pixel / (float)buffer.width;
    	Color intermediate;
    	ColorBlend(&first, &last, step, &intermediate);
    	DisplayDraw(pixel, buffer.height / 2, &intermediate, &buffer);
    }
}

void TestColorBlend::Reset(systime_t ticks)
{

}
