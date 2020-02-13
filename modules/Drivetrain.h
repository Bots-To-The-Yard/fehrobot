#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "FEHMotor.h"
#include "FEHIO.h"
#include "../Module.h"

#define WHEEL_DIAMETER 2.5
#define COUNTS_PER_ROTATION 318
#define PI 3.14159
#define CIRCUMFERENCE WHEEL_DIAMETER * PI

class Drivetrain: public Module {
  private:
    FEHMotor left;
    FEHMotor right;
    DigitalEncoder leftEncoder;
    DigitalEncoder rightEncoder;
    float maxLeftPercent;
    float minLeftPercent;
    float maxRightPercent;
    float minRightPercent;
    float leftTargetDistance;
    float rightTargetDistance;
    float accelDistance;
    int getLeftCounts();
    int getRightCounts();
    int getCountDelta();
    void resetLeftCounts();
    void resetRightCounts();
    void resetCounts();
  public:
    Drivetrain();
    Drivetrain(FEHMotor::FEHMotorPort leftPort, FEHMotor::FEHMotorPort rightPort, FEHIO::FEHIOPin leftEncoderPin, FEHIO::FEHIOPin rightEncoderPin);
    void init();
    void stop();
    void update(double time);
    void telemetry();
    void setPercent(float percent);
    void setLeftPercent(float percent);
    void setRightPercent(float percent);
    void setMinPercent(float percent);
    void setMinLeftPercent(float percent);
    void setMinRightPercent(float percent);
    void setAccelDistance(float accelDistance);
    float getLeftPercent();
    float getRightPercent();
    float getLeftDistance();
    float getRightDistance();
    float getAverageDistance();
    void resetLeftDistance();
    void resetRightDistance();
    void setTargetDistance(float targetDistance);
    void setLeftTargetDistance(float targetDistance);
    void setRightTargetDistance(float targetDistance);
    bool leftAtTarget();
    bool rightAtTarget();
};

#endif