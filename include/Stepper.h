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

   int IN1 = 12;   // D6
   int IN2 = 13;   // D7
   int EN = 15;    // D8

   uint16_t stepCount = 0;
};