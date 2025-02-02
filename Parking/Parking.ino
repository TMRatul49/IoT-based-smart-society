#include <Servo.h> 
int t1 = D2;
int e1 = D5;
int t2 = D4;
int e2 = D7;

long duration;
int distance, d1, d2;
int val5, val6;

Servo myservo1;
Servo myservo2;
int servoPin1 = D3;
int servoPin2 = D7;

void setup()
{
  Serial.begin(115200);
  Serial.begin(115200);
  pinMode(t1, OUTPUT);
  pinMode(t2, OUTPUT);
  pinMode(e1, INPUT);
  pinMode(e2, INPUT);
  myservo1.attach(servoPin1);
  myservo2.attach(servoPin2);

}

void loop()
{
  SonarSensor(t1, e1);
  d1 = distance;
  SonarSensor(t2, e2);
  d2 = distance;

  Serial.print(d1);
  Serial.print("-");
  Serial.print(d2);
  Serial.println(" cm");

  if (d1 > 10) {
    myservo1.write(0);
    val5=0;
  } else {
    myservo1.write(180);
    val5=1;
  }
  if (d2 > 10) {
    myservo2.write(180);
    val6=0;
  } else {
    myservo2.write(0);
    val6=1;
  }

  delay(700);
 }


// ---
void SonarSensor(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034 / 2);
}