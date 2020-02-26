#ifndef PERFORMANCE02_H
#define PERFORMANCE02_H

#include "../../include/Program.h"

namespace program {
  /**
   * A program to complete exploration task 2.
   */
  class Performance02: public Program {
    private:
      /**
       * The program state.
       */
      int state;
    public:
      /**
       * Construct a new Exploration02 object
       */
      Performance02();
      void init();
      void loop();
      void telemetry();
  };
};

#endif