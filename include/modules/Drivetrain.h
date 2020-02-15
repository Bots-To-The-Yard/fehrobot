#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "FEHMotor.h"
#include "FEHIO.h"
#include "../Module.h"

#define WHEEL_CIRCUMFERENCE 2.5
#define COUNTS_PER_ROTATION 318.0
#define PI 3.14159265359
#define LEFT_VOLTAGE 2.1
#define CENTER_VOLTAGE 2.1
#define RIGHT_VOLTAGE 2.1

/**
 * The line detection state.
 */
enum LineState {
  NO_LINE, // No sensor detects the line
  ON_LINE, // Center sensor detects the line
  AT_LINE, // All sensor detect the line
  RIGHT_OF_LINE, // Left sensor detects the line
  LEFT_OF_LINE // Right sensor detects the line
};

namespace module {
  /**
   * The robot drivetrain module.
   */
  class Drivetrain: public Module {
    private:
      /**
       * The left motor.
       */
      FEHMotor left;
      /**
       * The right motor.
       */
      FEHMotor right;
      /**
       * The left digital encoder.
       */
      DigitalEncoder leftEncoder;
      /**
       * The right digital encoder.
       */
      DigitalEncoder rightEncoder;
      /**
       * The line state.
       */
      LineState lineState;
      /**
       * The left analog optosensor.
       */
      AnalogInputPin leftLight;
      /**
       * The center analog optosensor.
       */
      AnalogInputPin centerLight;
      /**
       * The right analog optosensor.
       */
      AnalogInputPin rightLight;
    public:
      /**
       * Construct a new Drivetrain object.
       */
      Drivetrain();
      /**
       * Construct a new Drivetrain object.
       * 
       * @param leftPin The left optosensor pin.
       * @param centerPin The center optosensor pin.
       * @param rightPin The right optosensor pin.
       * @param leftPort The left motor port.
       * @param rightPort The right motor port.
       * @param leftEncoderPin The left encoder pin.
       * @param rightEncoderPin The right encoder pin.
       */
      Drivetrain(
        FEHIO::FEHIOPin leftPin,
        FEHIO::FEHIOPin centerPin,
        FEHIO::FEHIOPin rightPin,
        FEHMotor::FEHMotorPort leftPort,
        FEHMotor::FEHMotorPort rightPort,
        FEHIO::FEHIOPin leftEncoderPin,
        FEHIO::FEHIOPin rightEncoderPin
      );
      void init();
      void stop();
      void update(double time);
      void telemetry();
      /**
       * Set the percent for all motors.
       * @param percent The percent.
       */
      void setPercent(float percent);
      /**
       * Set the percent for the left motor.
       * @param percent The percent.
       */
      void setLeftPercent(float percent);
      /**
       * Set the percent for the right motor.
       * @param percent The percent.
       */
      void setRightPercent(float percent);
      /**
       * Get the LineState.
       * @return The current LineState.
       */
      LineState getLineState();
      /**
       * Get the left encoder counts.
       * @return The encoder counts.
       */
      int getLeftCounts();
      /**
       * Get the right encoder counts.
       * @return The encoder counts.
       */
      int getRightCounts();
      /**
       * Get the average encoder counts for both motors.
       * @return The encoder counts.
       */
      int getAverageCounts();
      /**
       * Get the delta between the two encoder counts.
       * @return The encoder count delta.
       */
      int getCountDelta();
      /**
       * Reset the left motor encoder.
       */
      void resetLeftEncoder();
      /**
       * Reset the right motor encoder.
       */
      void resetRightEncoder();
      /**
       * Reset all motor encoders.
       */
      void resetEncoders();
      /**
       * Get the left motor distance.
       * @return The distance traveled in inches.
       */
      float getLeftDistance();
      /**
       * Get the right motor distance.
       * @return The distance traveled in inches.
       */
      float getRightDistance();
      /**
       * Get the average distance.
       * @return The distance traveled in inches.
       */
      float getAverageDistance();
  };
};

#endif