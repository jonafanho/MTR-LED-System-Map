#include "sequence.h"

LED led;
Sequence sequence(led);

void setup()
{
    led.init(0x7F);
}

void loop()
{
    sequence.tick();
}
