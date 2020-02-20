#ifndef ROBOT_H
#define ROBOT_H

#include "FEHIO.h"
#include "Module.h"
#include "Waypoint.h"
#include "Course.h"
#include "Modules.h"
using namespace module;

#define DEFAULT_PERCENT 40
#define TURN_DISTANCE 5.2

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
     * @param cdsCellPin The CdS cell Pin
     */
    Robot(
      FEHIO::FEHIOPin leftPin,
      FEHIO::FEHIOPin centerPin,
      FEHIO::FEHIOPin rightPin,
      FEHMotor::FEHMotorPort leftMotorPort,
      FEHMotor::FEHMotorPort rightMotorPort,
      FEHIO::FEHIOPin leftEncoderPin,
      FEHIO::FEHIOPin rightEncoderPin,
      FEHIO::FEHIOPin cdsCellPin
    );
    void init();
    void stop();
    void update(double time);
    void telemetry();
    /**
     * Initilize the program
     * 
     * @param enableRps Enable the RPS initilization screen.
     */
    void init(bool enableRps);
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
     * Turn the robot left.
     * 
     * @param degree The desired angle to turn.
     * @return true The robot has turned desired angle.
     * @return false The robot is still turning.
     */
    bool turnLeftDegree(float degree, float percent);
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
     * Turn the robot right.
     * 
     * @param degree The desired angle to turn.
     * @return true The robot has turned desired angle.
     * @return false The robot is still turning.
     */
    bool turnRightDegree(float degree, float percent);
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