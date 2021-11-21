/**
 *
 *  Definition of the config data structure for the iotFeeder module and the class to persist it to EEPROM 
 *  Xavier Grosjean 2018
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 
#pragma once

#include <XIOTConfig.h>
#include <XUtils.h>

#define CONFIG_VERSION 1
#define MODULE_NAME "Feeder"

struct FeederConfigStruct:ModuleConfigStruct {
  // Add config fields needed if any
};

class FeederConfigClass:public ModuleConfigClass {
public:
  FeederConfigClass(unsigned int version, const char* name);
  void initFromDefault();
  const char* getDefaultUIClassName() override;

protected:
  FeederConfigStruct* _getDataPtr(void);  
};
