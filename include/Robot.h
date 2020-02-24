#ifndef ROBOT_H
#define ROBOT_H

#include "FEHIO.h"
#include "Module.h"
#include "Waypoint.h"
#include "Course.h"
#include "Modules.h"
using namespace module;

#define DEFAULT_PERCENT 15
#define TURN_DISTANCE 2.8

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
    /**
     * The current time
     */
    double time;
    /**
     * When the sleep started.
     */
    double sleepStart;
    /**
     * Is the robot currently sleeping.
     */
    bool sleeping;
  public:
    /**
     * Construct a new Robot object.
     * 
     * @param logger A reference to the logger.
     */
    Robot(Logger* logger);
    /**
     * Construct a new Robot object.
     * 
     * @param logger A reference to the logger.
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
      Logger* logger,
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
     * Drive until the robot hits a line with any optosensor.
     * 
     * @param percent The maximum motor percent.
     * @param maxDistance The maximum distance the robot can go before failing.
     * @return true The robot has hit the line or failed.
     * @return false The robot is still looking for the line.
     */
    bool driveUntilLine(float percent, float maxDistance);
    /**
     * Drive until the robot hits a line with any optosensor.
     * 
     * @param percent The maximum motor percent.
     * @return true The robot has hit the line.
     * @return false The robot is still looking for the line.
     */
    bool driveUntilLine(float percent);
    /**
     * Turn the robot left 90 degrees at the default speed.
     * 
     * @return true The robot has turned.
     * @return false The robot is still turning.
     */
    bool turnLeft();
    /**
     * Turn the robot left at the default speed.
     * 
     * @param angle The desired angle to turn.
     * @return true The robot has turned.
     * @return false The robot is still turning.
     */
    bool turnLeft(int angle);
    /**
     * Turn the robot left.
     * 
     * @param angle The desired angle to turn.
     * @param percent The maximum motor percent.
     * @return true The robot has turned.
     * @return false The robot is still turning.
     */
    bool turnLeft(int angle, float percent);
    /**
     * Turn the right 90 degrees at the default speed.
     * 
     * @return true The robot has turned.
     * @return false The robot is still turning.
     */
    bool turnRight();
    /**
     * Turn the robot right at the default speed.
     * 
     * @param angle The desired angle to turn.
     * @return true The robot has turned.
     * @return false The robot is still turning.
     */
    bool turnRight(int angle);
    /**
     * Turn the robot right.
     * 
     * @param angle The desired angle to turn.
     * @param percent The maximum motor percent.
     * @return true The robot has turned.
     * @return false The robot is still turning.
     */
    bool turnRight(int angle, float percent);
    /**
     * Sleep for a number of seconds.
     * 
     * @param seconds The number of seconds to sleep for.
     * @return true The sleep has finished.
     * @return false The sleep is not yet done.
     */
    bool sleep(double seconds);
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