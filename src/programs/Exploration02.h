#ifndef EXPLORATION02_H
#define EXPLORATION02_H

#include "../../include/Program.h"

namespace program {
  /**
   * A program to complete exploration task 2.
   */
  class Exploration02: public Program {
    private:
      /**
       * The program state.
       */
      int state;
    public:
      /**
       * Construct a new Exploration02 object
       */
      Exploration02();
      void init();
      void loop();
  };
};

#endif