#ifndef ROBOT_H
#define ROBOT_H

#include "FEHIO.h"
#include "Module.h"
#include "Waypoint.h"
#include "modules/Drivetrain.h"
#include "modules/RPSModule.h"

#define LINE_VOLTAGE 3.0

enum LineState {
  NO_LINE, // No sensor detects the line
  ON_LINE, // Center sensor detects the line
  AT_LINE, // All sensor detect the line
  RIGHT_OF_LINE, // Left sensor detects the line
  LEFT_OF_LINE // Right sensor detects the line
};

class Robot: public Module {
  private:
    int target;
    Waypoint* waypoints;
    bool navEnabled;
    float leftPercent;
    float rightPercent;
    bool followLine;
    void updateLineFollow();
    LineState lineState;
    AnalogInputPin leftLight;
    AnalogInputPin centerLight;
    AnalogInputPin rightLight;
    Drivetrain drivetrain;
    RPSModule rps;
  public:
    Robot(Waypoint* waypoints);
    Robot(
      Waypoint* waypoints,
      FEHIO::FEHIOPin leftPin,
      FEHIO::FEHIOPin centerPin,
      FEHIO::FEHIOPin rightPin,
      FEHMotor::FEHMotorPort leftMotorPort,
      FEHMotor::FEHMotorPort rightMotorPort,
      FEHIO::FEHIOPin leftEncoderPin,
      FEHIO::FEHIOPin rightEncoderPin
    );
    void init();
    void stop();
    void update(double time);
    void telemetry();
    void startNavigation();
    void stopNavigation();
    bool startLineFollow();
    void stopLineFollow();
    void setTarget(int target);
    Waypoint* getTarget();
    Drivetrain* getDrivetrain();
    RPSModule* getRPSModule();
};

#endif