#include "CdSCellTest.h"
using namespace program;

CdSCellTest::CdSCellTest(): Program("CdS Cell Test") {}

void CdSCellTest::init() {
  Program::init();
}

void CdSCellTest::loop() {}

void CdSCellTest::telemetry() {
  Program::telemetry();
  logger->telemetry("CdS Voltage: %f", robot->getDrivetrain()->cdsCell.Value());
}