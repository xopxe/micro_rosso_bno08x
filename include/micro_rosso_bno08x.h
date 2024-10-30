#ifndef __imu_bno08x_h
#define __imu_bno08x_h

#include <Wire.h>

class ImuBNO08x {
public:
  ImuBNO08x();
  static bool setup( TwoWire &wire = Wire,
                     const char* topic_raw = "/imu/raw",
                     const char* topic_mag = "/mag"
  );
};

#endif  // __imu_bno08x_h
