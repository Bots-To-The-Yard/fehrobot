#include "../include/modules/RPSModule.h"
using namespace module;

void module::RPSModule::init() {
  RPS.InitializeTouchMenu();
}

void module::RPSModule::stop() {}

void module::RPSModule::telemetry() {}

void module::RPSModule::update(double time) {}

float module::RPSModule::getX() {
  return RPS.X();
}

float module::RPSModule::getY() {
  return RPS.Y();
}

float module::RPSModule::getHeading() {
  return RPS.Heading();
}

int module::RPSModule::getTime() {
  return RPS.Time();
}