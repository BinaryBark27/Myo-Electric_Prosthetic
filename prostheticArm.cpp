#include <Servo.h>

// Threshold for servo motor control with muscle sensor.
// You can set a threshold according to the maximum and minimum values of the muscle sensor.
#define THRESHOLD 200

// Pin number where the sensor is connected. (Analog 0)
#define EMG_PIN 0

// Define Servo motor
const int servoPinA = 4;
Servo servoA;

const int servoPinB = 5;
Servo servoB;

const int servoPinC = 6;
Servo servoC;

const int servoPinD = 7;
Servo servoD;

/-------------------------------- void setup ------------------------------------------------/

void setup() {
  // BAUDRATE set to 115200, remember it to set monitor serial properly.
  // Used this Baud Rate and "NL&CR" option to visualize the values correctly.
  Serial.begin(115200);

  servoA.attach(servoPinA);
  servoB.attach(servoPinB);
  servoC.attach(servoPinC);
  servoD.attach(servoPinD);

  openGripper();
}

/-------------------------------- void loop ------------------------------------------------/

void loop() {
  // The "Value" variable reads the value from the analog pin to which the sensor is connected.
  int value = analogRead(EMG_PIN);

  if (Serial.available()) {
    if (value > THRESHOLD) {
      closeGripper();
    } else {
      openGripper();
    }
  }

  Serial.println(value);
}

void openGripper() {
  servoB.write(150);
  servoC.write(0);
  delay(500);
  servoA.write(150);
  servoD.write(0);
}

void closeGripper() {
  servoB.write(0);
  servoC.write(150);
  delay(500);
  servoA.write(0);
  servoD.write(150);
}