#include "Fx.h"
using namespace LPD6803;
namespace Effects {

    Fx::Fx(LEDStrip &strip,unsigned long patternInterval){
        this->strip = &strip;
        LED_NUMB = strip.numPixels();
        PatternInterval = patternInterval;
    }

}