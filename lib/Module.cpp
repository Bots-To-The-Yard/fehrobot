#include "../include/Module.h"

Module::Module(Logger* logger): Component() {
  this->logger = logger;
}