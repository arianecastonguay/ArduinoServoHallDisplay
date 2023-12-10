# ServoHallDisplay Project

## Project Overview
The ServoHallDisplay project is an Arduino-based system that uses a Hall effect sensor to control a servo motor and display values on a 7-segment display. This project is ideal for those interested in learning about magnetic field detection, servo control, and basic display techniques in microcontroller applications.

## Features
- **Hall Effect Sensor**: Utilizes a Hall sensor to detect magnetic fields.
- **Servo Motor Control**: Controls a servo motor based on the Hall sensor readings.
- **7-Segment Display**: Shows the processed sensor values on a 7-segment display.
- **Non-Blocking Design**: Uses efficient coding practices to ensure non-blocking operation of the loop.

## Hardware Requirements
- Arduino (Uno, Mega, or similar)
- Servo Motor
- Hall Effect Sensor
- 7-Segment Display
- Jumper Wires and Breadboard

## Pin Configuration
- **Hall Sensor Pin**: A0
- **7-Segment Display Pins**: 2, 3, 4, 5, 6, 7, 8, 9
- **Common Pins for Display Digits**: 10 (Digit 1), 11 (Digit 2)
- **Servo Pin**: 12
- **Buzzer Pin** (optional): 13

## Setup Instructions
1. Connect the Hall sensor, servo motor, and 7-segment display to the Arduino according to the pin configuration.
2. Upload the provided `.ino` file to the Arduino.
3. Power the Arduino and bring a magnet close to the Hall sensor to see the display and servo motor respond.

## Software Description
The code is structured into several key functions:
- `setup()`: Initializes the pin modes and attaches the servo.
- `loop()`: Main program loop that reads sensor data, calculates display values, and updates the servo and display.
- `updateDisplay()`: Handles the logic for updating the 7-segment display.
- `setSegments()`: Controls individual segments of the display.
- `calculateDisplayValue()`: Processes the sensor reading into a display value.
- `isTimeToUpdate()`: Determines if it's time to update the sensor reading or display.

## Contributing
Feel free to fork this repository and contribute to its development. Any improvements or feature additions are welcome!
