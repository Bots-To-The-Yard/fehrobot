#ifndef ROBOT_H
#define ROBOT_H

#include "FEHIO.h"
#include "Module.h"
#include "Waypoint.h"
#include "Course.h"
#include "Modules.h"
using namespace module;

#define DEFAULT_PERCENT 25

/**
 * The robot.
 */
class Robot: public Module {
  private:
    /**
     * The robot drivetrain module.
     */
    Drivetrain drivetrain;
    /**
     * The robot RPS module.
     */
    RPSModule rps;
  public:
    /**
     * Construct a new Robot object.
     */
    Robot();
    /**
     * Construct a new Robot object.
     * 
     * @param leftPin The left optosensor pin.
     * @param centerPin The center optosensor pin.
     * @param rightPin The right optosensor pin.
     * @param leftMotorPort The left motor port.
     * @param rightMotorPort The right motor port.
     * @param leftEncoderPin The left encoder pin.
     * @param rightEncoderPin The right encoder pin.
     */
    Robot(
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
    /**
     * Follow a black line at the default speed.
     */
    void followLine();
    /**
     * Follow a black line.
     * 
     * @param percent The maximum motor percent.
     */
    void followLine(float percent);
    /**
     * Follow a black line.
     * 
     * @param percent The maximum motor percent.
     * @param distance The distance in inches.
     * @return true The robot has traveled the specified distance.
     * @return false The robot is still following the line.
     */
    bool followLine(float percent, float distance);
    /**
     * Drive a distance at the default speed.
     * 
     * @param distance The distance in inches.
     * @return true The robot has traveled the specified distance.
     * @return false The robot is still driving.
     */
    bool drive(float distance);
    /**
     * Drive a distance.
     * 
     * @param distance The distance in inches.
     * @param percent The maximum motor percent.
     * @return true The robot has traveled the specified distance.
     * @return false The robot is still driving.
     */
    bool drive(float distance, float percent);
    /**
     * Turn the robot left at the default speed.
     * 
     * @return true The robot has turned.
     * @return false The robot is still turning.
     */
    bool turnLeft();
    /**
     * Turn the robot left.
     * 
     * @param percent The maximum motor percent.
     * @return true The robot has turned.
     * @return false The robot is still turning.
     */
    bool turnLeft(float percent);
    /**
     * Turn the right at the default speed.
     * 
     * @return true The robot has turned.
     * @return false The robot is still turning.
     */
    bool turnRight();
    /**
     * Turn the robot right.
     * 
     * @param percent The maximum motor percent.
     * @return true The robot has turned.
     * @return false The robot is still turning.
     */
    bool turnRight(float percent);
    /**
     * Get a reference to the Drivetrain object.
     * 
     * @return Drivetrain* 
     */
    Drivetrain* getDrivetrain();
    /**
     * Get a reference to the RPSModule object.
     * 
     * @return RPSModule* 
     */
    RPSModule* getRPSModule();
};

#endif