#ifndef DRIVEFORWARD_H
#define DRIVEFORWARD_H

#include "../../include/Program.h"

namespace program {
  /**
   * A program to drive forwards up the ramp.
   */
  class DriveForward: public Program {
    private:
      /**
       * The program state.
       */
      int state;
    public:
      /**
       * Construct a new ForwardUpRamp object
       */
      DriveForward();
      void init();
      void loop();
  };
};

#endif