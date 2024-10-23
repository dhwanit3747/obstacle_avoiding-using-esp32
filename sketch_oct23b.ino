#include <Ultrasonic.h>
#include <AFMotor.h>

const int trigPin = 9;
const int echoPin = 10;
Ultrasonic ultrasonic(trigPin, echoPin);

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

void setup() {
  Serial.begin(9600);
  motor1.setSpeed(255);
  motor2.setSpeed(255);
}

void loop() {
  long distance = ultrasonic.Ranging(CM);
  
  if (distance < 20) {
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    delay(500);
    
    motor1.run(RELEASE);
    motor2.run(FORWARD);
    delay(500);
  } else {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
  }
  
  delay(100);
}
