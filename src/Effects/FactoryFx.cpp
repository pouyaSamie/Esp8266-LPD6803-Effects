#include "FactoryFx.h"
namespace Effects {
    Fx* FactoryFx::GetFx(uint8_t mode,LEDStrip &strip,unsigned long patternInterval){
        if(mode==1)
            return new  RainBowEffect(strip,patternInterval);
        else if(mode==2)
            return new  ClockWise(strip,patternInterval);
        
        //Default Effect
        return new RainBowEffect(strip,patternInterval);
    }

}