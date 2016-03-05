// Description:   Simple controller showing how to use vision manager

#ifndef VISUALTRACKING_HPP
#define VISUALTRACKING_HPP

#define NMOTORS 20

#include <webots/Robot.hpp>

namespace managers {
  class DARwInOPVisionManager;
  class DARwInOPMotionManager;
  class DARwInOPGaitManager;
}

namespace webots {
  class Motor;
  class LED;
  class Camera;
  class PositionSensor;
  class Accelerometer;
  class Gyro;
  class Speaker;
};

class VisualTracking : public webots::Robot {
 public:
                                     VisualTracking();
    virtual                         ~VisualTracking();
    void                             run();
    void                             checkIfFallen();
    
  private:
    int                              mTimeStep;
    bool                             getBallCenter(double &x, double &y);

    void                             myStep();
    void                             wait(int ms);

    webots::Motor                   *mMotors[NMOTORS];
    webots::LED                     *mEyeLED;
    webots::LED                     *mHeadLED;
    webots::Camera                  *mCamera;
    webots::PositionSensor *mPositionSensors[NMOTORS];
    webots::Accelerometer           *mAccelerometer;
    
    managers::DARwInOPVisionManager *mVisionManager;
    managers::DARwInOPMotionManager *mMotionManager;
    managers::DARwInOPGaitManager   *mGaitManager;
};

#endif