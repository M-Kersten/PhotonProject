#include "lib1.h"

ParticleFunctions::ParticleFunctions()
{
    led = 7;
    tempSensor = 0;
    double tempC = 0;
    int GetLed();
};

Thuiskomst::Thuiskomst()
{
    blinking = 5;
    programToStop = "programOff1";
    calenderMessage = "Thuisgekomen";
    notificationMessage = GetTemp();
};

Vertrek::Vertrek()
{
    programToStart = "program1";
};
