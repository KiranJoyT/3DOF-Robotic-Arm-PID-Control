#include <Servo.h>

// Create servo objects
Servo servo1, servo2, servo3;

// Servo control pins
const int servoPin1 = 9;
const int servoPin2 = 10;
const int servoPin3 = 11;

void setup() {
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);

  Serial.begin(9600);

  // Move to initial positions
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);

  delay(1000); // Allow time to reach position
}

void loop() {
  // Servo 1: 0 to 180
  for (int pos = 0; pos <= 150; pos++) {
    servo1.write(pos);
    delay(10);
  }

  // Servo 2: 0 to 180
  for (int pos = 0; pos <= 130; pos++) {
    servo2.write(pos);
    delay(10);
  }

  // Servo 3: 0 to 180
  for (int pos = 0; pos <= 150; pos++) {
    servo3.write(pos);
    delay(10);
  }

  // Servo 3: 180 to 0
  for (int pos = 90; pos >= 0; pos--) {
    servo3.write(pos);
    delay(10);
  }

  // Servo 2: 180 to 0
  for (int pos = 90; pos >= 0; pos--) {
    servo2.write(pos);
    delay(10);
  }

  // Servo 1: 180 to 0
  for (int pos = 90; pos >= 0; pos--) {
    servo1.write(pos);
    delay(10);
  }

  delay(2000); // Pause before repeating
}
