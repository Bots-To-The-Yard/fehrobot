#ifndef PROGRAM_H
#define PROGRAM_H

#include "Component.h"
#include "Robot.h"

class Program {
  private:
    Robot* robot;
  public:
    Program(Robot* robot);
    virtual void loop() = 0;
};

#endif