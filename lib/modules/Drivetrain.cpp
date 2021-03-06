#include "../include/modules/Drivetrain.h"
#include <FEHLCD.h>
using namespace module;

Drivetrain::Drivetrain(Logger* logger): Module(logger), leftOpto(FEHIO::P1_0), centerOpto(FEHIO::P1_1), rightOpto(FEHIO::P1_2), left(FEHMotor::Motor0, 9.0), right(FEHMotor::Motor1, 9.0), leftEncoder(FEHIO::P0_0), rightEncoder(FEHIO::P0_1), cdsCell(FEHIO::P2_0) {}

Drivetrain::Drivetrain(
  Logger* logger,
  FEHIO::FEHIOPin leftPin,
  FEHIO::FEHIOPin centerPin,
  FEHIO::FEHIOPin rightPin,
  FEHMotor::FEHMotorPort leftPort,
  FEHMotor::FEHMotorPort rightPort,
  FEHIO::FEHIOPin leftEncoderPin,
  FEHIO::FEHIOPin rightEncoderPin,
  FEHIO::FEHIOPin cdsCellPin
): 
  Module(logger), 
  leftOpto(leftPin),
  centerOpto(centerPin),
  rightOpto(rightPin), 
  left(leftPort, 9.0), 
  right(rightPort, 9.0), 
  leftEncoder(leftEncoderPin), 
  rightEncoder(rightEncoderPin),
  cdsCell(cdsCellPin)
{
  this->logFile = logFile;
}

void Drivetrain::init() {
  logger->debug("Drivetrain::init", "Initialize Drivetrain");
  resetEncoders();
}

void Drivetrain::telemetry() {
  // TODO: Print current encoder counts to screen
  switch (getLineState()) {
    case OnLine: {
      logger->telemetry("Line State: ON LINE");
      break;
    }
    case LeftOfLine: {
      logger->telemetry("Line State: LEFT OF LINE");
      break;
    };
    case RightOfLine: {
      logger->telemetry("Line State: RIGHT OF LINE");
      break;
    };
    case AtLine: {
      logger->telemetry("Line State: AT LINE");
      break;
    };
    default: {
      logger->telemetry("Line State: NO LINE");
    }
  }
  logger->telemetry("Left Counts: %d", getLeftCounts());
  logger->telemetry("Right Counts: %d", getRightCounts());
  switch (getCdsColor()) {
    case Red:
      logger->telemetry("CdS Color: RED");
      break;
    case Blue:
      logger->telemetry("CdS Color: BLUE");
      break;
    default:
      logger->telemetry("CdS Color: NONE");
      break;
  }
}

void Drivetrain::stop() {
  setPercent(0);
  resetEncoders();
}

void Drivetrain::setPercent(float percent) {
  left.SetPercent(percent);
  right.SetPercent(percent);
}

void Drivetrain::setLeftPercent(float percent) {
  left.SetPercent(percent);
}


void Drivetrain::setRightPercent(float percent) {
  right.SetPercent(percent);
}

LineState Drivetrain::getLineState() {
  if (leftOpto.Value() > LEFT_VOLTAGE && centerOpto.Value() > CENTER_VOLTAGE && rightOpto.Value() > RIGHT_VOLTAGE) {
    return AtLine;
  } else if (leftOpto.Value() > LEFT_VOLTAGE) {
    return RightOfLine;
  } else if (rightOpto.Value() > RIGHT_VOLTAGE) {
    return LeftOfLine;
  } else if (centerOpto.Value() > CENTER_VOLTAGE) {
    return OnLine;
  } else {
    return NoLine;
  }
}

CdsColor Drivetrain::getCdsColor() {
  // Check the color detected by the CdS cell
  if (cdsCell.Value() <= 0.92 && cdsCell.Value() >= 0.6) return Blue;
  if (cdsCell.Value() <= 0.3) return Red;
  return None;
}

int Drivetrain::getLeftCounts() {
  return leftEncoder.Counts();
}

int Drivetrain::getRightCounts() {
  return rightEncoder.Counts();
}

int Drivetrain::getAverageCounts() {
  return (rightEncoder.Counts() + leftEncoder.Counts()) / 2;
}

void Drivetrain::resetLeftEncoder() {
  leftEncoder.ResetCounts();
}

void Drivetrain::resetRightEncoder() {
  rightEncoder.ResetCounts();
}

void Drivetrain::resetEncoders() {
  leftEncoder.ResetCounts();
  rightEncoder.ResetCounts();
}

int Drivetrain::getCountDelta() {
  int delta = getLeftCounts() - getRightCounts();
  if (delta < 0) {
    return -1 * delta;
  } else {
    return delta;
  }
}

float Drivetrain::getLeftDistance() {
  return (PI * WHEEL_DIAMETER * getLeftCounts()) / COUNTS_PER_ROTATION;
}

float Drivetrain::getRightDistance() {
  return (PI * WHEEL_DIAMETER * getRightCounts()) / COUNTS_PER_ROTATION;
}

float Drivetrain::getAverageDistance() {
  return (getLeftDistance() + getRightDistance()) / 2;
}
