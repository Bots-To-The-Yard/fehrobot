#ifndef ARM_H
#define ARM_H

#include "../Module.h"
#include <FEHServo.h>

#define SERVO_MIN 740
#define SERVO_MAX 2500

namespace module {
  /**
   * The arm module.
   */
  class Arm: public Module {
    private:
      /**
       * The arm servo.
       */
      FEHServo servo;
    public:
      /**
       * Construct a new Arm object
       * 
       * @param logger A reference to the logger.
       */
      Arm(Logger* logger);
      /**
       * Construct a new Arm object
       * 
       * @param logger A reference to the logger.
       * @param servoPort The arm servo port.
       */
      Arm(Logger* logger, FEHServo::FEHServoPort servoPort);
      void init();
      void stop();
      void telemetry();
  };
};

#endif