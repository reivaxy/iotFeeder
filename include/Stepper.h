/**
 *  iotinator iotFeeder Agent module
 *  Xavier Grosjean 2022
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */

#pragma once

#include <Arduino.h>
#include <AccelStepper.h>



class Stepper {
public:
   Stepper();
   void setStepCount(long count);
   long remaining();
   void stop();
   void run();

   int IN1 = 13; 
   int IN2 = 12; 
   int EN = 14;  

   uint16_t stepCount = 0;
   AccelStepper stepper;

};