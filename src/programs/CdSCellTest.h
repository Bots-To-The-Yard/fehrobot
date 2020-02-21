#ifndef CDSCELLTEST_H
#define CDSCELLTEST_H

#include "../../include/Program.h"

namespace program {
  /**
   * A program to test the CdS cell.
   */
  class CdSCellTest: public Program {
    public:
      /**
       * Construct a new CdSCellTest object
       * 
       * @param robot A reference to the robot object.
       * @param course A reference to the course object.
       * @param logger A reference to the Logger object.
       */
      CdSCellTest(Robot* robot, Course* course, Logger* logger);
      void loop();
      void telemetry();
  };
};

#endif