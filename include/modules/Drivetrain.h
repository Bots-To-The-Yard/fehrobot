#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include <FEHMotor.h>
#include <FEHIO.h>
#include <FEHSD.h>
#include "../Module.h"

#define WHEEL_CIRCUMFERENCE 2.5f
#define COUNTS_PER_ROTATION 318.0f
#define PI 3.14159265359f
#define LEFT_VOLTAGE 2.1f
#define CENTER_VOLTAGE 2.1f
#define RIGHT_VOLTAGE 2.1f
#define RED_VOLTAGE 0.5f
#define BLUE_VOLTAGE 0.8f

/**
 * The line detection state.
 */
enum LineState {
  NoLine, // No sensor detects the line
  OnLine, // Center sensor detects the line
  AtLine, // All sensor detect the line
  RightOfLine, // Left sensor detects the line
  LeftOfLine // Right sensor detects the line
};

/**
 * The detected color from the CdS cell.
 */
enum CdsColor {
  None, // No color is detected
  Red, // Red is detected
  Blue // Blue is detected
};

namespace module {
  /**
   * The robot drivetrain module.
   */
  class Drivetrain: public Module {
    private:
      /**
       * The log file pointer.
       */
      FEHFile* logFile;
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
      AnalogInputPin leftOpto;
      /**
       * The center analog optosensor.
       */
      AnalogInputPin centerOpto;
      /**
       * The right analog optosensor.
       */
      AnalogInputPin rightOpto;
    public:
      /**
       * The CdS cell
       */
      AnalogInputPin cdsCell;
      /**
       * Construct a new Drivetrain object.
       * 
       * @param logger A reference to the logger.
       */
      Drivetrain(Logger* logger);
      /**
       * Construct a new Drivetrain object.
       * 
       * @param logger A reference to the logger.
       * @param leftPin The left optosensor pin.
       * @param centerPin The center optosensor pin.
       * @param rightPin The right optosensor pin.
       * @param leftPort The left motor port.
       * @param rightPort The right motor port.
       * @param leftEncoderPin The left encoder pin.
       * @param rightEncoderPin The right encoder pin.
       * @param cdsCellPin The CdS cell pin.
       */
      Drivetrain(
        Logger* logger,
        FEHIO::FEHIOPin leftPin,
        FEHIO::FEHIOPin centerPin,
        FEHIO::FEHIOPin rightPin,
        FEHMotor::FEHMotorPort leftPort,
        FEHMotor::FEHMotorPort rightPort,
        FEHIO::FEHIOPin leftEncoderPin,
        FEHIO::FEHIOPin rightEncoderPin,
        FEHIO::FEHIOPin cdsCellPin
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
       * Get the detected color from the CdS cell.
       * 
       * @return The current CdsColor.
       */
      CdsColor getCdsColor();
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