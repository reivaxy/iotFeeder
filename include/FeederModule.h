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
 
#define MAX_STATUS_LENGTH 150

class FeederModule:public XIOTModule {
public:
  FeederModule(FeederConfigClass* config, int displayAddr, int displaySda, int displayScl, int forwardPin, int reversePin);
  
  void loop() override;
  void initMsgSchedule();
  void settingsPage();
  void saveSettings();
  void feedOnce();
  void logProgramedDispensing(uint16_t quantity);
  void setCustomModuleRecordFields(JsonObject *jsonBufferRoot) override;
  void dispensingFailed(bool transientDisplay);
  
  long checkQuantity();
  
  char *customFormInitPage() override;
  int customSaveConfig() override;

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
  bool _programRunning = false;

  bool foodDetected = false;

  char lastStatus[MAX_STATUS_LENGTH + 1];


};