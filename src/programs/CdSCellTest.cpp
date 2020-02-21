#include "CdSCellTest.h"
using namespace program;

CdSCellTest::CdSCellTest(Robot* robot, Course* course, Logger* logger): Program("CdS Cell Test", robot, course, logger) {}

void CdSCellTest::loop() {}

void CdSCellTest::telemetry() {
  Program::telemetry();
  logger->telemetry("CdS Voltage: %f", robot->getDrivetrain()->cdsCell.Value());
}