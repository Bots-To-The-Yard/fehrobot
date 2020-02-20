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
       * 
       * @param robot A reference to the robot object.
       * @param course A reference to the course object.
       */
      BackwardsUpRamp(Robot* robot, Course* course);
      void init();
      void loop();
  };
};

#endif