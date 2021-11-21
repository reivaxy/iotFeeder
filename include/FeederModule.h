/**
 *  iotinator Feeder module 
 *  Xavier Grosjean 2018
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 
#pragma once 
#include "config.h"
#include <XIOTModule.h>
 
class FeederModule:public XIOTModule {
public:
  FeederModule(FeederConfigClass* config, int displayAddr, int displaySda, int displayScl);
  
protected:
  bool _status = true;  
  char* _customData() override;
  char* useData(const char *, int *) override;

};