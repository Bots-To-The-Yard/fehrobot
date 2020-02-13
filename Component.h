#ifndef COMPONENT_H
#define COMPONENT_H

class Component {
  public:
    virtual void init() = 0;
    virtual void stop() = 0;
    virtual void telemetry() = 0;
};

#endif