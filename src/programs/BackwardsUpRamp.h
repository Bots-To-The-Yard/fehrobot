#ifndef BACKWARDSUPRAMP_H
#define BACKWARDSUPRAMP_H

#include "../../include/Program.h"

namespace program {
  /**
   * A program to drive forwards up the ramp.
   */
  class  BackwardsUpRamp: public Program {
    private:
      /**
       * The program state.
       */
      int state;
    public:
      /**
       * Construct a new BackwardsUpRamp object
       */
      BackwardsUpRamp();
      void init();
      void loop();
  };
};

#endif