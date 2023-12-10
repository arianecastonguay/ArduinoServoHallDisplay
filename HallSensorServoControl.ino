#include <Servo.h>

#define HALL_SENSOR_PIN A0
#define DIGIT1_COMMON_PIN 10
#define DIGIT2_COMMON_PIN 11
#define SERVO_PIN 12
#define BUZZER_PIN 13
#define SENSOR_READ_INTERVAL 80
#define DISPLAY_UPDATE_INTERVAL 5
#define NUM_SEGMENTS 8
#define MAX_DISPLAY_VALUE 99

const int segmentPins[NUM_SEGMENTS] = {2, 3, 4, 5, 6, 7, 8, 9};

// Segment bit patterns for numbers 0-9
const byte numberPatterns[10] = {
  0b01100000, // 0
  0b01101111, // 1
  0b11000100, // 2
  0b01000101, // 3
  0b01001011, // 4
  0b01010001, // 5
  0b01010000, // 6
  0b01100011, // 7 
  0b01000000, // 8
  0b01000001  // 9
};

Servo servoMotor;
unsigned long lastSensorReadTime = 0;
unsigned long lastDisplayUpdateTime = 0;

void setup() {
  initializeDisplayPins();
  servoMotor.attach(SERVO_PIN);
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();
  static int lastAnalogValue = 0;
  static int lastDisplayValue = -1;

  if (isTimeToUpdate(currentMillis, lastSensorReadTime, SENSOR_READ_INTERVAL)) {
    lastAnalogValue = analogRead(HALL_SENSOR_PIN);
  }

  int displayValue = calculateDisplayValue(lastAnalogValue);

  if (lastDisplayValue != displayValue) {
    updateServo(displayValue);
    lastDisplayValue = displayValue;
  }

  if (isTimeToUpdate(currentMillis, lastDisplayUpdateTime, DISPLAY_UPDATE_INTERVAL)) {
    updateDisplay(displayValue);
  }
}

void initializeDisplayPins() {
  for (int i = 0; i < NUM_SEGMENTS; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  pinMode(DIGIT1_COMMON_PIN, OUTPUT);
  pinMode(DIGIT2_COMMON_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

bool isTimeToUpdate(unsigned long currentMillis, unsigned long& lastUpdateTime, long interval) {
  if (currentMillis - lastUpdateTime >= interval) {
    lastUpdateTime = currentMillis;
    return true;
  }
  return false;
}

int calculateDisplayValue(int sensorValue) {
  int value = map(sensorValue, 200, 900, 0, 99);
  value = abs(value - 50) * 2;
  return min(max(value, 0), MAX_DISPLAY_VALUE);
}

void updateServo(int value) {
  servoMotor.write(value);
  Serial.print("Display Value: ");
  Serial.println(value);
}

void updateDisplay(int number) {
  static bool displayingFirstDigit = true;
  displayingFirstDigit = !displayingFirstDigit;
  int digitToShow = displayingFirstDigit ? number % 10 : number / 10;

  setSegments(numberPatterns[digitToShow]);
  digitalWrite(DIGIT1_COMMON_PIN, displayingFirstDigit ? LOW : HIGH);
  digitalWrite(DIGIT2_COMMON_PIN, displayingFirstDigit ? HIGH : LOW);
}

void setSegments(byte segments) {
  for (int i = 0; i < NUM_SEGMENTS; i++) {
    digitalWrite(segmentPins[i], bitRead(segments, i) ? HIGH : LOW);
  }
}

