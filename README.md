# Obstacle Avoidance Rover

An autonomous obstacle avoidance rover built using an Arduino UNO, L298N motor driver, two 300 RPM DC geared motors, and three HC-SR04 ultrasonic sensors.

## 📌 Project Overview

The Obstacle Avoidance Rover is a small autonomous robotic vehicle that detects obstacles and automatically changes its direction to avoid collisions.

Three ultrasonic sensors are used to measure the distance in the front, left, and right directions. The Arduino UNO processes these distance measurements and controls the two DC motors through the L298N motor driver.

When there is no obstacle in front of the rover, it moves forward. When an obstacle is detected within the predefined distance, the rover stops, compares the available space on the left and right sides, and turns toward the side with more free space.

## 🎯 Objectives

- Build an autonomous obstacle avoidance rover.
- Detect obstacles using ultrasonic sensors.
- Measure distances in three directions.
- Control two DC motors using an L298N motor driver.
- Automatically select the safer direction when an obstacle is detected.
- Develop and test an Arduino-based robotic system.

## 🛠️ Components Used

| Component | Quantity |
|---|---:|
| Arduino UNO | 1 |
| L298N Motor Driver | 1 |
| 300 RPM DC Geared Motors | 2 |
| HC-SR04 Ultrasonic Sensors | 3 |
| 12V Battery | 1 |
| Caster Wheel | 1 |
| Robot Chassis | 1 |
| Jumper Wires | As required |

## ⚙️ Working Principle

The rover continuously measures the distance using three HC-SR04 ultrasonic sensors.

### Normal Movement

If the front distance is greater than **23 cm**, the rover moves forward.

### Obstacle Detection

If the front distance is **23 cm or less**, an obstacle is considered to be present.

The rover then:

1. Stops the motors.
2. Checks the left and right distances.
3. Compares the available space on both sides.
4. Turns toward the side with greater available space.
5. Stops briefly after turning.
6. Continues moving forward and repeats the process.

### Decision Logic

```text
              Start
                |
                v
       Measure 3 distances
                |
                v
       Is front distance > 23 cm?
          /              \
        YES              NO
         |                |
         v                v
    Move Forward        Stop
                          |
                          v
                  Compare Left/Right
                     /          \
             Left > Right     Right >= Left
                  |                |
                  v                v
              Turn Left        Turn Right
                  \                /
                   \              /
                    v            v
                    Continue


## ⚙️ Adjustable Parameters

The following parameters can be modified in the Arduino code according to the rover's design and operating requirements:

- **Motor Speed:** The motor speed can be adjusted from **0 to 255** using PWM according to the required rover speed.
- **Front Detection Distance:** The front obstacle detection distance can be modified according to the **chassis size and rover layout**.
- **Turning Delay:** The turning delay can be adjusted according to the **rover's turning angle, motor speed, and chassis design**.
- **Customization:** These parameters can be tuned during testing to achieve the desired obstacle-avoidance performance.
