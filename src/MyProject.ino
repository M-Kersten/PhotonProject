/*
 * Project WelcomeHome
 * Author: Merijn Kersten
 * Date: 8/11/17
 */

 #include "lib1.h"
 #include <google-maps-device-locator.h>


 int bitrate[] = {300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 38400, 57600}; //bits per seconde, 9600 is standaard voor photon

 GoogleMapsDeviceLocator locator;
 Thuiskomst thuiskomst;
 Vertrek vertrek;

 void setup()
 {
     pinMode(thuiskomst.GetLed(), OUTPUT);
     pinMode(thuiskomst.GetTempSensor(), OUTPUT);
 	   Serial.begin(bitrate[5]);
 	   Particle.function("arrived", atArrived);
 	   locator.withEventName("deviceLocator");
 	   locator.withSubscribe(locationCallback).withLocatePeriodic(200);
 }

 void loop()
 {
    locator.loop();
 }

 int atArrived(String enterOrExit)
 {
      if(enterOrExit == "entered")
      {
        thuiskomst.KomThuis();
        blink(4);
        Particle.publish("postToCalender", calenderMessage.c_str ());
        Particle.publish("runProgram", programToStop.c_str ());
        Particle.publish("notify", notificationMessage.c_str ());
      }
      else
      {
          vertrek.Vertrokken();
          Particle.publish("runProgram", programToStart.c_str ());
      }
 }

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

 void locationCallback(float lat, float lon, float accuracy)
 {

 };
