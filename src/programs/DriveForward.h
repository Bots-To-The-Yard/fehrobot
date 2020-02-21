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
       * 
       * @param robot A reference to the robot object.
       * @param course A reference to the course object.
       * @param logger A reference to the logger object.
       */
      DriveForward(Robot* robot, Course* course, Logger* logger);
      void init();
      void loop();
  };
};

#endif