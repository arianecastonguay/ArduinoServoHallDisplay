# ServoHallDisplay Project

## Project Overview
The ServoHallDisplay project is an Arduino-based system that uses a Hall effect sensor to control a servo motor and display values on a 7-segment display. This project is ideal for those interested in learning about magnetic field detection, servo control, basic display techniques, and sound signaling in microcontroller applications.

## Features
- **Hall Effect Sensor**: Utilizes a Hall sensor to detect magnetic fields.
- **Servo Motor Control**: Controls a servo motor based on the Hall sensor readings.
- **7-Segment Display**: Shows the processed sensor values on a 7-segment display.
- **Buzzer Feedback**: Provides audible feedback when a certain threshold is exceeded.
- **Non-Blocking Design**: Uses efficient coding practices to ensure non-blocking operation of the loop.

## Hardware Requirements
- Arduino (Uno, Mega, or similar)
- Servo Motor
- Hall Effect Sensor
- 7-Segment Display
- Buzzer
- Jumper Wires and Breadboard

## Pin Configuration
- **Hall Sensor Pin**: A0
- **7-Segment Display Pins**: 2, 3, 4, 5, 6, 7, 8, 9
- **Common Pins for Display Digits**: 10 (Digit 1), 11 (Digit 2)
- **Servo Pin**: 12
- **Buzzer Pin**: 13


## Setup Instructions
1. Connect the Hall sensor, servo motor, 7-segment display, and buzzer to the Arduino according to the pin configuration.
2. Upload the provided `.ino` file to the Arduino.
3. Power the Arduino and bring a magnet close to the Hall sensor to see the display, servo motor, and buzzer respond.

## Software Description
The code is structured into several key functions:
- `setup()`: Initializes the pin modes, attaches the servo, and sets up serial communication.
- `loop()`: Main program loop that reads sensor data, calculates display values, updates the servo and display, and controls the buzzer.
- `updateDisplay()`: Manages the logic for updating the 7-segment display.
- `setSegments()`: Controls individual segments of the display.
- `calculateDisplayValue()`: Processes the sensor reading into a display value.
- `isTimeToUpdate()`: Checks if it's time to update the sensor reading or display.
- `controlBuzzer()`: Handles buzzer activation based on display values.

## Circuit Design and Display Information

### 7-Segment LED Display
The project utilizes a common-cathode 7-segment LED display to show the numeric values. The pin layout for the 7-segment display is as follows:

- **Pin 1**: Segment E
- **Pin 2**: Segment D
- **Pin 3**: Common Cathode (Ground)
- **Pin 4**: Segment C
- **Pin 5**: Segment DP (Decimal Point)
- **Pin 6**: Segment B
- **Pin 7**: Segment A
- **Pin 8**: Common Cathode (Ground)
- **Pin 9**: Segment G
- **Pin 10**: Segment F

### Connecting the Display
- Connect pins 3 and 8 of the 7-segment display to the ground on the Arduino.
- Connect the remaining segment pins (1, 2, 4, 5, 6, 7, 9, 10) to the corresponding Arduino pins defined in the `segmentPins` array. Make sure to use current-limiting resistors in series with each segment to prevent damage to the LEDs.
- The decimal point (DP) is typically not used in this project, but you can connect it if needed, remembering to include a current-limiting resistor.

### Circuit Assembly
- The servo motor's control wire should be connected to `SERVO_PIN` on the Arduino, and the power and ground wires should be connected to the appropriate power supply, ensuring that it can provide sufficient current.
- The Hall effect sensor's output should be connected to `HALL_SENSOR_PIN` (A0), with the sensor's power and ground appropriately connected.
- If included, the buzzer should have one pin connected to `BUZZER_PIN` (13) and the other to the ground.

Always ensure that your circuit is powered off while making connections to prevent any damage.

For a detailed schematic, please refer to the circuit diagrams provided within the repository.
