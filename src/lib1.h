#ifndef LIB1_H_INCLUDED
#define LIB1_H_INCLUDED
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

class ParticleFunctions
{
    public:
        int led;
        int tempSensor;
        void blink(int blinkTimes);
        ParticleFunctions();
        ~ParticleFunctions();
};

class Thuiskomst : public ParticleFunctions
{
        string programToStop;
        string calenderMessage;
        string notificationMessage;
        int blinking;

    public:
        Thuiskomst();
        ~Thuiskomst();

        int GetLed()
        {
            return led;
        };

        int GetTempSensor()
        {
            return tempSensor;
        };

        string GetTemp(){
            double Number = 123; //(((analogRead((GetTempSensor())) * 3.3)/4095) - 0.5) * 100;
            std::string Result;
            std::stringstream convert;
            convert << Number;
            Result = convert.str();


            std::stringstream oss;
            oss << "Welkom thuis, het is " << Result << " graden";
            std::string Result2 = oss.str();
            return Result2;
        };

        void KomThuis()
        {

            blink(blinking);
	          Particle.publish("postToCalender", calenderMessage.c_str ());
    	      Particle.publish("runProgram", programToStop.c_str ());
	          Particle.publish("notify", notificationMessage.c_str

        };

        void blink(int numBlinks)
        {
            for(int i = 0; i < numBlinks; i++)
            {
                digitalWrite(Thuiskomst::GetLed(), HIGH);
                delay(1000);
                digitalWrite(Thuiskomst::GetLed(), LOW);
                delay(2000);
            };
        }
};

class Vertrek : public ParticleFunctions
{
        string programToStart;
    public:
        Vertrek();
        ~Vertrek();

        void Vertrokken()
        {
    	     //Particle.publish("runProgram", programToStart.c_str ());
        }
};
#endif
