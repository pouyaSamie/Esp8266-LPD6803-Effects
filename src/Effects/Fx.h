#ifndef Fx_H
#define Fx_H
#include <LPD6803.h>
using namespace LPD6803;

namespace Effects{
    class Fx{
        public:
            int LED_NUMB;
            LEDStrip* strip;
            Fx(LEDStrip &strip,unsigned long patternInterval);
            unsigned long PatternInterval ; // time between steps in the pattern
            void virtual UpdatePattern()=0;

    };
}

#endif