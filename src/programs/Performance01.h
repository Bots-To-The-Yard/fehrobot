#ifndef PERFORMANCE01_H
#define PERFORMANCE01_H

#include "../../include/Program.h"

namespace program {
  /**
   * A program to complete exploration task 2.
   */
  class Performance01: public Program {
    private:
      /**
       * The program state.
       */
      int state;
    public:
      /**
       * Construct a new Exploration02 object
       */
      Performance01();
      void init();
      void loop();
      void telemetry();
  };
};

#endif