#include "Effects/Fx.h"
#include "Effects/Rainbow.h"
#include "Effects/ClockWise.h"
namespace Effects{
    class FactoryFx{
        public:
            Fx* GetFx(uint8_t mode,LEDStrip &strip,unsigned long patternInterval);
    };
}
