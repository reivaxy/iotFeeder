/**
 *  iotinator iotFeeder Agent module
 *  Xavier Grosjean 2021
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 
#include "FeederModule.h"
 
FeederModule::FeederModule(FeederConfigClass* config, int displayAddr, int displaySda, int displayScl):XIOTModule(config, displayAddr, displaySda, displayScl, true, 128) {
  _oledDisplay->setLineAlignment(2, TEXT_ALIGN_CENTER);
}

char* FeederModule::_customData() {
//  Serial.println("FeederModule::_customData");
  char* data = (char *)malloc(100);
  sprintf(data, "{\"status\":\"%s\"}", _status ? "on": "off");
  return data;  
}

char* FeederModule::useData(const char* data, int* httpCode) {
  Serial.println("Feeder");
  Serial.println(data);

  *httpCode = 200;
  return emptyMallocedResponse();
}

const char* FeederModule::customFormInitPage() {
  return "Some more fields for feeder<br/>";
}

const char* FeederModule::customPageInitPage() {
  return "Some more HTML for feeder";
}