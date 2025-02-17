# Rain Rain Go Away

## Overview
Rain Rain Go Away is an automated wiper system developed for the Inter-Hostel Tech Competition at IIT Guwahati in the Electronics domain. The project aimed to design a wiper control system that dynamically adjusts speed based on rainfall intensity, without relying on mechanical components or a microcontroller for angle control. The system is highly power-efficient and cost-effective, operating solely on a 5V rail and consuming only 800mW of power. Full details are available in the PS attached.

## Features
- **Fully Automated Wiper Control**: Detects rain intensity and adjusts speed accordingly.
- **Custom Motor Driver Circuit**: Uses buck converters to achieve 4 discrete speed levels.
- **H-Bridge Circuit**: Designed using MOSFETs instead of relays to avoid penalties for mechanical components.
- **Dynamic Speed Indicator**: A needle dynamically points to one of four LEDs on a semicircular speedometer.
- **Microcontroller-Free and Fully Electrical Design**: A Hall sensor at 0° and 180° switches motor direction using a JK flip-flop in toggling mode, eliminating the need for mechanical components and microcontrollers.
- **Low Power Consumption**: Operates entirely on a 5V rail, consuming only 800mW, significantly lower than competing designs (30W).
- **Economical Design**: Entire system built under ₹2000.

## System Architecture
1. **Rain Detection**: A rain sensor outputs a voltage between 0-5V based on rain intensity.
2. **Analog to Digital Conversion**: A flash-type ADC converts sensor data to discrete levels.
3. **Speed Control**: The ADC output is fed into a custom buck converter-based motor driver to set one of four speeds.
4. **Wiper Motion Control**: A normal DC motor (360° rotation) switches direction using Hall sensors placed at 0° and 180°.
5. **Direction Control**: A JK flip-flop in toggling mode ensures bidirectional movement.
6. **Speed Indication**: A moving needle dynamically points to one of four LEDs indicating the speed level.

## Circuit Design
- **Custom H-Bridge Circuit**: Built using MOSFETs for bidirectional motor control.
- **Flash ADC**: Converts analog rain sensor data to digital control signals.
- **Motor Driver Circuit**: Uses buck converters to select different speed levels.
- **Hall Sensor Integration**: Used for precise angle switching without mechanical limit switches.

## Advantages Over Other Designs
- **No Mechanical Components or Microcontroller**: Avoids penalties by eliminating limit switches, relays, and microcontrollers, making the system purely electrical.
- **Lower Power Dissipation**: Only 800mW compared to 30W in competing designs.
- **Compact and Efficient**: Works entirely on a 5V rail.
- **Cost-Effective**: Designed within ₹2000, making it highly affordable.

## Components Used
- Rain Sensor
- Flash ADC
- Buck Converters (Motor Speed Control)
- JK Flip-Flop (Toggling Mode)
- DC Motor (360° rotation)
- Hall Sensors (for 0° and 180° detection)
- LEDs (Speed Indication)

## How to Replicate
1. Connect the rain sensor and interface it with a flash-type ADC.
2. Use the ADC output to control the custom buck converter-based motor driver.
3. Implement an H-Bridge circuit for bidirectional motor control.
4. Position Hall sensors at 0° and 180° for direction switching.
5. Connect a JK flip-flop in toggling mode to drive the motor direction.
6. Design a speedometer with LEDs to indicate different speed levels.

## Future Improvements
- Integrating a low-power microcontroller for finer control (if allowed in other competitions).
- Implementing a wireless interface for remote control.
- Using a brushless motor for increased efficiency.
