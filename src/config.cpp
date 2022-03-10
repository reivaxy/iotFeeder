/**
 *  Class to persist the iotFeeder module configuration data structure to EEPROM 
 *  Xavier Grosjean 2021
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 
#include "Config.h"


FeederConfigClass::FeederConfigClass(unsigned int version, const char* name):ModuleConfigClass(version, "iotFeeder", name, sizeof(FeederConfigStruct)) {
  for (uint8_t p = 0 ; p < PROGRAM_COUNT; p ++) {
    _programs[p] = new Program(&(_getDataPtr()->programs[p]));
  }
}

/**
 * Reset the config data structure to the default values.
 * This is done each time the data structure version is different from the one saved in EEPROM
 * NB: version and name are handled by base class 
 */
void FeederConfigClass::initFromDefault() {
  Serial.println("Reset iotFeeder Config to defaults");
  ModuleConfigClass::initFromDefault(); // handles version and name init, ssid and pwd
  for (uint8_t p = 0 ; p < PROGRAM_COUNT; p ++) {
    FeederProgram *fp = &(_getDataPtr()->programs[p]);
    fp->active = false;
    fp->hour = 0;
    fp->quantity = 0;
    Serial.printf("fp config init default 2 - %d hour:%d\n", p, fp->hour);
  }
  saveToEeprom();
}

const char* FeederConfigClass::getDefaultUIClassName() {
  Serial.println("FeederConfigClass::getDefaultUIClassName");
  return "FeederUIClass";
}

Program* FeederConfigClass::getProgram(uint8_t offset) {
  return _programs[offset];
}

/**
 * Return the typed data structure object
 *
 */
FeederConfigStruct* FeederConfigClass::_getDataPtr(void) {
  return (FeederConfigStruct*)ModuleConfigClass::_getDataPtr();
}