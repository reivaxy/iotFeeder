
/**
 *  iotinator Feeder module
 *  Xavier Grosjean 2022
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 
#include <stdio.h>
#include "FeederModule.h"
#include "config.h"

#define API_VERSION "1.0"    // modules can check API version to make sure they are compatible...

// Global object to store config
FeederConfigClass *config;
XIOTModule* module;

int scl = 5;   // D1
int sda = 4;   // D2
int in = 16;   // D0

void setup() {
  Serial.begin(115200);
  config = new FeederConfigClass((unsigned int)CONFIG_VERSION, (char*)MODULE_NAME);
  config->init();
  // to avoid side effects when these pins are not connected.
  pinMode(0, OUTPUT); digitalWrite(0, HIGH);
  pinMode(2, OUTPUT); digitalWrite(2, HIGH);
  module = new FeederModule(config, 0x3C, sda, scl, in);
}

void loop() {
  // Mandatory periodic call, to refresh display, Clock, check requests
  // on the http API, ...
  module->loop();
}