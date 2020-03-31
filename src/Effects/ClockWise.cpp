#include "ClockWise.h"
using namespace LPD6803;

#define arrayLength(array) (sizeof((array))/sizeof((array)[0]))
namespace Effects {

    LPD6803::Color colors[] = {{242, 66, 245},{93, 245, 66},{239, 245, 66},{66, 245, 236}};
    ClockWise::ClockWise(LEDStrip &strip,unsigned long patternInterval) : Fx(strip,patternInterval){
        this->strip = &strip;
        LED_NUMB = strip.numPixels();
    }


int Size = arrayLength(colors);
int i = 0;
int currentColor = 0;

void ClockWise::UpdatePattern(){
    i++; 

    int j = LED_NUMB - i;
    i %= LED_NUMB;
    strip->setPixel(j,pickColor(currentColor));
    strip->show();
    if(j==0)
    {
        currentColor++;
        strip->SetColor(pickColor(currentColor));      
    }
    strip->setPixel(j, Color(0));
    strip->show();
    //delay(wait);

    // strip->SetColor(Color(255,255,255));
}

Color ClockWise::pickColor(int currentIndex)
{
  
    if(currentIndex >Size -1)
           currentIndex = 0;
           
    currentColor = currentIndex;
    return colors[currentColor];
}


// void ClockWise::CounterClockwiseEffect(){
//   (this->strip)->setPixel(i, Color(0));
//   i++; i %= LED_NUMB;
  
//   (this->strip)->setPixel(i,pickColor(currentColor));
//   (this->strip)->show();
//   if(i==LED_NUMB-1)
//   {
//     currentColor++;
//     SetColor(pickColor(currentColor));      
// }
// }

}
