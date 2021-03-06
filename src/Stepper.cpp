/**
 *  iotinator iotFeeder Agent module
 *  Xavier Grosjean 2022
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */


#include "Stepper.h"

Stepper::Stepper() {
   stepper = AccelStepper(AccelStepper::FULL2WIRE, IN1, IN2);
   stepper.setEnablePin(EN);
   stepper.setCurrentPosition(0);
   stepper.setMaxSpeed(200.0);
   stepper.setAcceleration(100.0);
   stepper.disableOutputs();
   stepCount = 0;
}

void Stepper::start(long count) {
   firstStep = true;
   stepper.move(count);
   stepper.enableOutputs();
}

long Stepper::remaining() {
   return stepper.distanceToGo();
}

void Stepper::run() {
   firstStep = false;
   stepper.run();
}

boolean Stepper::isFirstStep() {
   return firstStep;
}

void Stepper::stop() {
   stepper.stop();
   stepper.setCurrentPosition(0);
   stepper.disableOutputs();
}