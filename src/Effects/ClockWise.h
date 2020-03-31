#ifndef ClockWise_H
#define ClockWise_H
#include <LPD6803.h>
#include "Fx.h"

using namespace LPD6803;

namespace Effects {
    class ClockWise : public Fx {
    public:

        ClockWise(LEDStrip &strip,unsigned long patternInterval);
        Color pickColor(int currentIndex);
        void virtual UpdatePattern();

    };

}
#endif