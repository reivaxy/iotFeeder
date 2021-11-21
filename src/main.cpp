
/**
 *  iotinator Scheduler Agent module
 *  Xavier Grosjean 2021
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 
#include <stdio.h>
#include "FeederModule.h"
#include "config.h"

#define API_VERSION "1.0"    // modules can check API version to make sure they are compatible...

// Global object to store config
FeederConfigClass *config;
XIOTModule* module;

int scl = 5;
int sda = 4;

void setup() {
  Serial.begin(9600);
  config = new FeederConfigClass((unsigned int)CONFIG_VERSION, (char*)MODULE_NAME);
  config->init();
 
  module = new FeederModule(config, 0x3C, sda, scl);
}

void loop() {
  // Mandatory periodic call, to refresh display, Clock, check requests
  // on the http API, ...
  module->loop();
}