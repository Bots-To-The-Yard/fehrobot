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
       */
      CdSCellTest();
      void init();
      void loop();
      void telemetry();
  };
};

#endif