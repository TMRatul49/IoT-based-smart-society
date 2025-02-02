#include <Servo.h>

Servo servo;  // create a servo object to control the servo
int servoPin = D3; // servo signal pin
int trigPin = D2; // ultrasonic sensor trigger pin
int echoPin = D5; // ultrasonic sensor echo pin
long duration; // variable for ultrasonic sensor reading

void setup() {
  servo.attach(servoPin);  // attaches the servo on the specified pin to the servo object
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // read ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  long distance = duration / 58;  // convert ultrasonic sensor reading to distance in cm
  
  // control servo based on ultrasonic reading
  if (distance > 10) {
    servo.write(0);  // rotate servo to 0 degrees
  } else {
    servo.write(90);  // rotate servo to 90 degrees
  }
  
  delay(100);  // wait for next ultrasonic reading
}