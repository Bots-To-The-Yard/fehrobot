#include "../include/Program.h"

Program::Program(Robot* robot) {
  this->robot = robot;
}

void Program::init() {
  robot->init();
}

void Program::stop() {
  robot->stop();
}

void Program::update(double time) {
  robot->update(time);
}

void Program::telemetry() {
  robot->telemetry();
}