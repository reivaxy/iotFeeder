/**
 *
 *  Class to handle one program setting for iotFeeder
 *  Xavier Grosjean 2022
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */

#include "Program.h"

Program::Program(FeederProgram *program) {
   feederProgram = program;
   disable = false;
}


uint8_t Program::getHour() {
   return feederProgram->hour;
}

uint16_t Program::getQuantity() {
   return feederProgram->quantity;
}
bool Program::isActive() {
   return feederProgram->active;
}

void Program::setHour(uint8_t hour) {
   feederProgram->hour = hour;
}
void Program::setQuantity(uint16_t qtity) {
   feederProgram->quantity = qtity;
}
void Program::setActive(bool active) {
   feederProgram->active = active;
}

void Program::reEnable() {
   disable = false;
}

// Returns the program quantity if :
// - program is active
// - nowSec is < 10
// - nowMin is 0
// - nowHour is equals to program hour
uint16_t Program::triggerQuantity(uint8_t nowHour) {
   if (feederProgram->active && !disable) {
      if (nowHour == feederProgram->hour) {
         // Security to not trigger this program again. Will need to be reset externally
         // after a delay that ensures no faulty triggering 
         disable = true;
         return feederProgram->quantity;
      }
   }
   return 0;
}