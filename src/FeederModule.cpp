/**
 *  iotinator iotFeeder Agent module
 *  Xavier Grosjean 2022
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 
#include "FeederModule.h"

#define HOUR_PARAM_NAME "p_h_%d"
#define QUANTITY_PARAM_NAME "p_q_%d"
#define ACTIVE_PARAM_NAME "p_a_%d"
 
#define RESET_DELAY_MS 1*60*1000 // in milliseconds
#include "settingsPageHtml.h"

FeederModule::FeederModule(FeederConfigClass* config, int displayAddr, int displaySda, int displayScl, int in):XIOTModule(config, displayAddr, displaySda, displayScl, true, 255) {
  pinMode(in, INPUT);
  _inPin = in;
  _oledDisplay->setLineAlignment(2, TEXT_ALIGN_CENTER);
  _config = config;
  lastTriggerTime = 0;
  stepper = Stepper();
  initMsgSchedule();
  _oledDisplay->setLineAlignment(1, TEXT_ALIGN_CENTER);
  _oledDisplay->setLineAlignment(3, TEXT_ALIGN_CENTER);
  _oledDisplay->setTransientDuration(2, 30000);  // List to display step count at end of test session
  _server->on("/feederApi/saveSettings", HTTP_POST, [&]() {
    saveSettings();
  });
  _server->on("/", HTTP_GET, [&]() {
    settingsPage();
  });
}

void FeederModule::initMsgSchedule() {
  *messageSchedule = 0;
  char one[4];
  for (uint8_t p = 0; p < PROGRAM_COUNT; p ++) {
    Program *prgm = _config->getProgram(p);
    if (prgm->isActive()) {
      sprintf(one, "%02d ", prgm->getHour());
      strcat(messageSchedule, one);
    }
  }
  _oledDisplay->setLine(1, messageSchedule);
}

void FeederModule::settingsPage() {
  int maxSize = strlen(settingsBeginingPage) + strlen(settingsEndingPage) + PROGRAM_COUNT * (strlen(formTemplate) + 15) ;  
  Serial.printf("Size %d\n", maxSize);
  char* result = (char*)malloc(maxSize); // caller will free it
  strcpy(result, settingsBeginingPage);
  char *resultPtr = result + strlen(result);
  for (uint8_t p = 0; p < PROGRAM_COUNT; p ++) {
    Program *prgm = _config->getProgram(p);
    sprintf(resultPtr, formTemplate, p, prgm->getHour(),
                                    p, prgm->getQuantity(),
                                    p, prgm->isActive()?"checked":"");
    resultPtr = result + strlen(result);
  }
  strcat(result, settingsEndingPage);
  sendHtml(result, 200);
  free(result);
}

void FeederModule::saveSettings() {
  // sizing param names for PROGRAM_COUNT < 100
  char hourParamName[7];
  char quantityParamName[7];
  char activeParamName[7];
  for (uint8_t p = 0; p < PROGRAM_COUNT; p ++) { 
    sprintf(hourParamName, HOUR_PARAM_NAME, p);
    sprintf(quantityParamName, QUANTITY_PARAM_NAME, p);
    sprintf(activeParamName, ACTIVE_PARAM_NAME, p);
    String hour = _server->arg(hourParamName);
    String quantity = _server->arg(quantityParamName);
    String active = _server->arg(activeParamName);

    //Serial.printf("p%d Hour %s Qtity %s Active %s\n", p, hour.c_str(), quantity.c_str(), active.c_str());
    Program *prgm = _config->getProgram(p);
    prgm->setHour((uint8_t)hour.toInt());
    prgm->setQuantity((uint16_t)quantity.toInt());
    prgm->setActive(active.equals("on")?true:false);
  }
  initMsgSchedule();
}

void FeederModule::loop() {
  XIOTModule::loop();  // takes care of server, display, ...
  if(isTimeInitialized()) {
    uint16_t quantity = 0;
    // Only check programs if minute is 0
    int mi = minute();
    if (mi == 0) {
      int s = second();
      // Only check programs during the first 10 seconds of each hour
      // This is a security in case the esp restarts while dispensing food, we don't want to dispense it again.
      // The delay should be at most the one needed to obtain time from NTP after a restart
      // When a program triggers, it disables itself to not trigger again, until re enabled
      if (s < 10) {
        uint8_t h = (uint8_t)hour();
        for (uint8_t p = 0; p < PROGRAM_COUNT; p ++) {
          quantity = _config->getProgram(p)->triggerQuantity(h);        
          if (quantity != 0) {
            Serial.printf("%s\n", NTP.getTimeDateString(now()).c_str());
            char message[50];
            sprintf(message, "At %d:00, Qtity: %d\n", h, quantity);
            Serial.printf(message);
            _oledDisplay->setLine(2, message);
            lastTriggerTime = millis();
            stepper.setStepCount(quantity);
            break;
          }
        }
      }
    } 
  } 
  
  // Re enable programs after some delay since last program triggered and disabled itself
  if (lastTriggerTime != 0 && XUtils::isElapsedDelay(millis(), &lastTriggerTime, RESET_DELAY_MS)) {
    Serial.println("Re-enabling programs");
    for (uint8_t p = 0; p < PROGRAM_COUNT; p ++) {
      _config->getProgram(p)->reEnable();     
    }
    lastTriggerTime = 0; // no need to re enable before one program is triggered
  }
  if (stepper.remaining()) {
    stepper.run();
  } else {
    stepper.stop();
  }

  int level = digitalRead(_inPin);
  if (level == HIGH) {
    if (_testSession) {
      return;
    } else {
      _testSession = true;
      stepper.setStepCount(5000);
    }
  } else {
    if (_testSession) {
      _testSession = false;
      long stepCount = 5000 - stepper.remaining();
      stepper.stop();
      char message[40];
      sprintf(message, "Quantity: %d\n", stepCount);      
      _oledDisplay->setLine(2, message, true, false, true);
    }
  }
}

