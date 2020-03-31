#ifndef Rainbow_H
#define Rainbow_H
#include <LPD6803.h>
#include "Fx.h"
using namespace LPD6803;
namespace Effects {
class RainBowEffect : public Fx{
    public:
       
        RainBowEffect(LEDStrip &strip,unsigned long patternInterval);
        Color Wheel(byte WheelPos);
        void SetColor(Color color);
        virtual void UpdatePattern();

    };
}

#endif