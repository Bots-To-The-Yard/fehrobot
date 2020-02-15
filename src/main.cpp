#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include "../include/Robot.h"

int main() {

  float x, y;

  LCD.Clear(FEHLCD::Black);
  LCD.SetFontColor(FEHLCD::White);

  Course course;

  Robot robot(&course);

  LCD.WriteLine("Waiting for touch...");

  while (!LCD.Touch(&x, &y));

  LCD.WriteLine("Starting Program...");

  int state = 0;

  double time = 0;
  double lastTelemetry = 0;
  while (true) {
    time = TimeNow();
    robot.update(time);
    if ((time - lastTelemetry) > 0.15) {
      lastTelemetry = time;
      LCD.Clear(FEHLCD::Black);
      robot.telemetry();
    }
    switch (state) {
      case 0:
        if (robot.drive(14, 40)) state = 1;
        break;
      case 1:
        if (robot.turnLeft(40)) state = 2;
        break;
      case 3:
        if (robot.drive(10, 40)) state = 4;
        break;
      case 4:
        if (robot.turnRight(60)) state = 5;
        break;
      case 5:
        if (robot.drive(4, 60)) state = 6;
        break;
      default:
        robot.stop();
        break;
    }
  }

  return 0;
}