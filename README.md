# micro rosso bno08x

This a module for the [micro_rosso](https://github.com/xopxe/micro_rosso_platformio) system.

It provides support for the BNO08x IMU by publishing ROS2 topics.

## Loading and starting

First, import the module into your project's `platformio.ini`:

```ini
lib_deps =
    ...
    https://github.com/xopxe/micro_rosso_bno08x.git
```

Then, in your `main.cpp`:

```cpp
...
#include "micro_rosso_bno08x.h"
ImuBNO08x imu;
...
void setup() {
  Wire.begin(I2C_SDA, I2C_SCL); // initialize I2C as needed
  ...
  imu.setup(Wire);
  ...
}
```

The setup method allows passing optional topic names and different micro_rosso timers.

This module uses two timers. The first is used to poll the I2C bus, and a fast timer is needed. The default 20Hz micro_rosso::timer_control works well. The second controls the topic publication, and the 5Hz micro_rosso::timer_report is used by default.

```h
  static bool setup(TwoWire &wire = Wire,
                    const char *topic_raw = "/imu/raw",
                    const char *topic_mag = "/mag",
                    timer_descriptor &timer_control = micro_rosso::timer_control,
                    timer_descriptor &timer = micro_rosso::timer_report);
```

## Using the module

The module emits the following topics:

* raw imu: [sensor_msgs/msg/imu]([https://docs.ros2.org/foxy/api/sensor_msgs/msg/Imu.html))
* magnetometer: [sensor_msgs/msg/magnetic_field](https://docs.ros2.org/latest/api/sensor_msgs/msg/MagneticField.html)

## Authors and acknowledgment

jvisca@fing.edu.uy - [Grupo MINA](https://www.fing.edu.uy/inco/grupos/mina/), Facultad de Ingeniería - Udelar, 2024

## License

MIT
