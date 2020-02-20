#ifndef MODULE_H
#define MODULE_H

#include "Logger.h"
#include "Component.h"
using namespace util;

/**
 * A module on the robot.
 */
class Module: public Component {
  protected:
    /**
     * The logger instance.
     */
    Logger* logger;
  public:
    /**
     * Construct a new Module object
     * 
     * @param logger A reference to the logger.
     */
    Module(Logger* logger);
};

#endif