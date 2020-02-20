#ifndef RPS_H
#define RPS_H

#include "FEHRPS.h"
#include "../Module.h"

namespace module {
  /**
   * The RPS module.
   */
  class RPSModule: public Module {
    public:
      /**
       * Construct a new RPSModule object
       * 
       * @param logger A reference to the logger.
       */
      RPSModule(Logger* logger);
      void init();
      void stop();
      void telemetry();
      void update(double time);
      /**
       * Get the time left in the round.
       * @return The time left in seconds.
       */
      int getTime();
      /**
       * Get the x position according to the RPS.
       * @return The x position.
       */
      float getX();
      /**
       * Get the y position according to the RPS.
       * @return The y position.
       */
      float getY();
      /**
       * Get the heading according to the RPS.
       * @return The heading.
       */
      float getHeading();
  };
};

#endif