/**
 *  iotinator Feeder module 
 *  Xavier Grosjean 2018
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 
#pragma once 
#include "Config.h"
#include <XIOTModule.h>
#include "Messages.h"
 
class FeederModule:public XIOTModule {
public:
  FeederModule(FeederConfigClass* config, int displayAddr, int displaySda, int displayScl);
  
  char* customFormInitPage() override;
  int customSaveConfig() override;
  FeederConfigClass* _config;
  unsigned long lastTriggerTime = 0;  

  void loop() override;

};