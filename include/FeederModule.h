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
  FeederModule(FeederConfigClass* config, int displayAddr, int displaySda, int displayScl, int forwardPin, int reversePin);
  
  void loop() override;
  void initMsgSchedule();
  void settingsPage();
  void saveSettings();
  void logProgramedDispensing(uint16_t quantity);

  Stepper stepper;
  FeederConfigClass* _config;
  unsigned long lastTriggerTime = 0;  
  unsigned long lastReverseTime = 0;  

  char messageSchedule[20]; // We display 6 digit pairs separated with spaces
  int _forwardPin;
  int _reversePin;

  int _previousLevel = -1;

  bool _manualForward = false;
  bool _manualReverse = false;

  bool mustWarnNoFoodDetected = false;

};