#include "RPSModule.h"

RPSModule::RPSModule(): Module() {}

void RPSModule::init() {
  RPS.InitializeTouchMenu();
}

void RPSModule::stop() {}

void RPSModule::telemetry() {}

void RPSModule::update(double time) {}

float RPSModule::getX() {
  return RPS.X();
}

float RPSModule::getY() {
  return RPS.Y();
}

float RPSModule::getHeading() {
  return RPS.Heading();
}