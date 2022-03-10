/**
 *
 *  Class to handle one program setting for iotFeeder
 *  Xavier Grosjean 2022
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */

#pragma once
#include <Arduino.h>

// If this structure memory footprint changes, need to update CONFIG_VERSION
typedef struct {
  uint8_t hour = 0;  // time at which the feeder should be triggered
  uint16_t quantity = 0;  // quantity the feeder should provide: Number of steps for the stepper
  bool active = false;  // Activate this program
} FeederProgram;

class Program {
public:   
   Program(FeederProgram *feederProgram);

   uint16_t triggerQuantity(uint8_t hour);
   uint8_t getHour();
   uint16_t getQuantity();
   bool isActive();
   void reEnable();

   void setHour(uint8_t hour);
   void setQuantity(uint16_t qtity);
   void setActive(bool active);

   bool disable = false;
   FeederProgram* feederProgram;

};
