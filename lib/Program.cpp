#include "../include/Program.h"
#include "FEHUtility.h"
#include "FEHLCD.h"

Program::Program(char* name, Robot* robot, Course* course, Logger* logger) {
  this->name = name;
  this->robot = robot;
  this->course = course;
  this->logger = logger;
  startTime = 0;
  lastTelemetry = 0;
  running = false;
}

char* Program::getName() {
  return name;
}
void Program::init() {
  logger->debug("Initialize Program: %s", name);
  // Initialize the robot
  robot->init();
  // Reset running and start time
  running = false;
  startTime = 0;
}

void Program::run() {
  run(true);
}

void Program::telemetry() {}

void Program::run(bool telemetry) {
  logger->debug("Run Program: %s", name);
  // Set running to true
  running = true;
  // Set the start time
  startTime = TimeNow();
  logger->debug("Program Start Time: %f", startTime);
  // Run the program loop
  while (running) {
    float time = TimeNow();
    // Update the robot
    robot->update(time - startTime);
    // Update the course
    course->update(time - startTime);
    // Write telemetry
    if (telemetry) {
      if ((time - lastTelemetry) > 0.25) {
        lastTelemetry = TimeNow();
        LCD.Clear(FEHLCD::Black);
        // Display the program name at the top
        LCD.WriteLine(getName());
        LCD.WriteLine("------------------------");
        // Have the robot write the telemetry to the screen
        robot->telemetry();
        course->telemetry();
        this->telemetry();
      }
    }
    // Run the program loop function
    loop();
  }
}

void Program::stop() {
  logger->debug("Stop Program: %s", name);
  // Stop the program
  running = false;
  startTime = 0;
  // Stop the robot
  robot->stop();
  // Stop task execution
  course->stop();
}