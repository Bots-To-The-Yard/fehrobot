#include "../include/Program.h"
#include "FEHUtility.h"
#include "FEHLCD.h"

Program::Program(char* name, Robot* robot, Course* course) {
  this->name = name;
  this->robot = robot;
  this->course = course;
  startTime = 0;
  lastTelemetry = 0;
  running = false;
}

char* Program::getName() {
  return name;
}

void Program::init() {
  // Initilize the robot
  robot->init();
}

void Program::init(bool disableRps) {
  // Initilize the robot
  robot->init(disableRps);
}

void Program::run() {
  run(true);
}

void Program::run(bool telemetry) {
  // Set the internal references
  // Set running to true
  running = true;
  // Set the start time
  startTime = TimeNow();
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
      }
    }
    // Run the program loop function
    loop();
  }
}

void Program::stop() {
  // Stop the program
  running = false;
  startTime = 0;
  // Stop the robot
  robot->stop();
  // Stop task execution
  course->stop();
}