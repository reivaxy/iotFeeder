/**
 *  iotinator Feeder module 
 *  Xavier Grosjean 2018
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 
#pragma once 
#include "Config.h"
#include <XIOTModule.h>
#include "Messages.h"
#include "Stepper.h"
 
class FeederModule:public XIOTModule {
public:
  FeederModule(FeederConfigClass* config, int displayAddr, int displaySda, int displayScl, int inPin);
  
  void loop() override;
  void initMsgSchedule();
  void settingsPage();
  void saveSettings();

  Stepper stepper;
  FeederConfigClass* _config;
  unsigned long lastTriggerTime = 0;  

  char messageSchedule[40];
  int _inPin;
  bool _testSession = false;

};