#ifndef MODULE_H
#define MODULE_H

#include "Component.h"

class Module: public Component {
  public:
    virtual void update(double time) = 0;
};

#endif