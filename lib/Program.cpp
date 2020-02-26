#include "../include/Program.h"
#include "FEHUtility.h"
#include "FEHLCD.h"

Program::Program(const char* name) {
  this->name = name;
  this->robot = robot;
  this->course = course;
  this->logger = logger;
  startTime = 0;
  lastTelemetry = 0;
  running = false;
}

void Program::setRobot(Robot* robot) {
  this->robot = robot;
}

void Program::setCourse(Course* course) {
  this->course = course;
}

void Program::setLogger(Logger* logger) {
  this->logger = logger;
}

const char* Program::getName() {
  return name;
}

void Program::init() {
  logger->debug("Program::init", "Initialize Program: %s", name);
  // Initialize the robot
  robot->init();
  // Reset running and start time
  running = false;
  startTime = 0;
}

void Program::stop() {
  logger->debug("Program::stop", "Stop Program: %s", name);
  // Stop the program
  running = false;
  startTime = 0;
  // Stop the robot
  robot->stop();
  // Stop task execution
  course->stop();
}

void Program::run() {
  run(true);
}

void Program::telemetry() {
  robot->telemetry();
  course->telemetry();
}

void Program::update(double time) {
  robot->update(time);
  course->update(time);
}

void Program::run(bool telemetry) {
  logger->debug("Program::run", "Run Program: %s", name);
  // Set running to true
  running = true;
  // Set the start time
  startTime = TimeNow();
  // Set the last telemetry time
  lastTelemetry = TimeNow();
  logger->debug("Program::run", "Program Start Time: %d", int(startTime * 1000));
  // Run the program loop
  while (running) {
    float time = TimeNow();
    // Update the components
    this->update(time);
    // Write telemetry
    if (telemetry) {
      if ((time - lastTelemetry) > 0.15) {
        lastTelemetry = TimeNow();
        LCD.Clear(FEHLCD::Black);
        // Display the program name at the top
        LCD.WriteLine(getName());
        LCD.WriteLine("--------------------------");
        // Write the program telemetry
        this->telemetry();
      }
    }
    // Run the program update function
    this->loop();
  }
}