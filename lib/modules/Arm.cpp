#include "../../include/modules/Arm.h"
using namespace module;

Arm::Arm(Logger* logger): Module(logger), servo(FEHServo::Servo7) {}

Arm::Arm(Logger* logger, FEHServo::FEHServoPort servoPort): Module(logger), servo(servoPort) {}

void Arm::init() {
  servo.SetMin(SERVO_MIN);
  servo.SetMax(SERVO_MAX);
}

void Arm::stop() {}

void Arm::telemetry() {}