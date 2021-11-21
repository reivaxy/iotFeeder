/**
 *  Class to persist the iotFeeder module configuration data structure to EEPROM 
 *  Xavier Grosjean 2021
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 
#include "config.h"


FeederConfigClass::FeederConfigClass(unsigned int version, const char* name):ModuleConfigClass(version, "iotFeeder", name, sizeof(FeederConfigStruct)) {
}

/**
 * Reset the config data structure to the default values.
 * This is done each time the data structure version is different from the one saved in EEPROM
 * NB: version and name are handled by base class 
 */
void FeederConfigClass::initFromDefault() {
  ModuleConfigClass::initFromDefault(); // handles version and name init, ssid and pwd

}

const char* FeederConfigClass::getDefaultUIClassName() {
  Serial.println("FeederConfigClass::getDefaultUIClassName");
  return "FeederUIClass";
}

/**
 * Return the typed data structure object
 *
 */
FeederConfigStruct* FeederConfigClass::_getDataPtr(void) {
  return (FeederConfigStruct*)ModuleConfigClass::_getDataPtr();
}