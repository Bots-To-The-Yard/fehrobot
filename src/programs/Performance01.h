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
       * 
       * @param robot A reference to the robot object.
       * @param course A reference to the course object.
       */
      Performance01(Robot* robot, Course* course);
      void init();
      void loop();
  };
};