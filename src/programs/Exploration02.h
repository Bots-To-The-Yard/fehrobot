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
       * 
       * @param robot A reference to the robot object.
       * @param course A reference to the course object.
       * @param logger A reference to the logger object.
       */
      Exploration02(Robot* robot, Course* course, Logger* logger);
      void init();
      void loop();
  };
};

#endif