#include "Rainbow.h"
using namespace LPD6803;
namespace Effects {


    RainBowEffect::RainBowEffect(LEDStrip &strip,unsigned long patternInterval): Fx(strip,patternInterval){
        this->strip = &strip;
        LED_NUMB = strip.numPixels();
    }

    
    void  RainBowEffect::UpdatePattern(){
      
      static uint16_t j=0;
      for(int i=0; i<LED_NUMB; i++) {
        strip->setPixel(i, Wheel((i+j) & 255));
      }
        strip->show();
      j++;
      if(j >= 256) j=0;
      // if(strip->outputReady())
      //   for (j = 0; j < 256; j++) {
      //       for (i = 0; i < LED_NUMB; i++) {
      //          (this->strip)->setPixel(i, Wheel((i * 1 + j) & 255));
      //       }
      //       (this->strip)->show();
      //       //delay(wait);
      //   }

    }

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
Color RainBowEffect::Wheel(byte WheelPos) {
  if (WheelPos < 85) {
    return Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
  else if (WheelPos < 170) {
    WheelPos -= 85;
    return Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  else {
    WheelPos -= 170;
    return Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}



}