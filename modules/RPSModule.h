#ifndef RPS_H
#define RPS_H

#include "FEHRPS.h"
#include "../Module.h"

class RPSModule: public Module {
  public:
    RPSModule();
    void init();
    void stop();
    void telemetry();
    void update(double time);
    float getX();
    float getY();
    float getHeading();
};

#endif