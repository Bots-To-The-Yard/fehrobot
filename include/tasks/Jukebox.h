#ifndef JUKEBOX_H
#define JUKEBOX_H

#include "../Task.h"

namespace task {
  /**
   * The jukebox task.
   */
  class Jukebox: public Task {
    public:
      /**
       * Construct a new Jukebox object
       */
      Jukebox();
      /**
       * Construct a new Jukebox object
       * @param waypoint A reference to the waypoint.
       */
      Jukebox(Waypoint* waypoint);
      void init();
      void stop();
      void telemetry();
      bool align();
      bool execute();
  };
};

#endif