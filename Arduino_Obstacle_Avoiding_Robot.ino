//Obsatcle avoiding robot
//Requirements. Arduino Uno (1X), Motor Drive shield (1X), Li-ON batteries (2X), Ultrasonic sensor (1X)
//Servo motor (1X), TT Motor Drives (X4). Thereis an option of using two motors if the robot is two-wheeled

#include <Servo.h>
#include <NewPing.h>
#include <AFMotor.h>

#define TRIG A0;
#define ECHO A1
#define MAX_DIST 200   //sets the maximum allowable distance from the barrier
#define MAX_SPEED 190 //sets the speed of the DC motors
#define MAX_SPEED_OFFSET 20

NewPing sonar (TRIG, ECHO, MAX_DIST);

AF_DCMotor motor1 (1, MOTOR12_1KHZ);
AF_DCMotor motor2 (2, MOTOR12_1KHZ);
AF_DCMotor motor3 (3, MOTOR34_1KHZ);
AF_DCMotor motor4 (4, MOTOR34_1KHZ);

Servo myServo;

boolean goesForward = false;
int distace = 100;
int speedSet = 0;

void setup() {
  // put your setup code here, to run once:
myServo.attach(10);
myServo.write(115);
delay(2000);
distance = readPing();
delay (100);
distance = readPing();
delay (100);
distance = readPing();
delay (100);
distance = readPing();
delay (100);
}

void loop() {
  // put your main code here, to run repeatedly:
int distanceR = 0;
int distanceL = 0;
delay (40);

if (distance<=15)
{
  moveStop ();
  delay (100);
  moveBackward();
  delay (300);
  moveStop();
  delay(200);
  distanceR= lookRight();
  delay(200);
  distanceL = lookLeft();
  delay (200);
}
if (distanceR>=distanceL)
{
  turnRight ();
  moveStop()
}
else
{
  turnLeft ();
  moveStop();
}
else
{
 moveForward();
}
 distance = readPing ();

}

int lookRight ()
{
  myServo.write (50);
  delay (500);
  int distance = readPing();
  delay (100);
  myServo.write (115);
  return distance;
  delay (100);
  
}
int lookLeft ()
{
  myServo.write (170);
  delay (500);
  int distance = readPing();
  delay (100);
  myServo.write (115);
  return distance;
  delay (100);
}
int readPing ()
{
  delay (70);
  int cm = sonar.ping_cm();
  if (cm ==0)
  {
    cm = 250;
  }
  return cm;
}

void moveStop ()
{
  motor1.run (RELEASE);
  motor2.run (RELEASE);
  motor3.run (RELEASE);
  motor4.run (RELEASE);
}
void moveForward()
{
  if (!goesForward)
  {
    goesForward = true;
    motor1.run (FORWARD);
    motor2.run (FORWARD);
    motor3.run (FORWARD);
    motor4.run (FORWARD);

    for ( speedSet = 0; speedSet < MAX_SPEED; speedSet = speedSet=+2)  //slowly bring the speed up to avoid loading down the batteries too quickly
    {
      motor1.setSpeed (speedSet);
      motor2.setSpeed (speedSet);
      motor3.setSpeed (speedSet);
      motor4.setSpeed (speedSet);
      delay (5);
    }
  }
}
void movebackward ()
{
  goesForward = false;
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);

  for (speedSet = 0; speedSet<MAX_SPEED; speedSet = speedSet+2)
  {
    motor1.setSpeed(speedSet);
    motor2.setSpeed(speedSet);
    motor3.setSpeed(speedSet);
    motor4.setSpeed(speedSet);
    delay (5);
  }
}
void turnRight()
{
  motor1.run (FORWARD);
  motor2.run (FORWARD);
  motor3.run (BACKWARD);
  motor4.run (BACKWARD);
  delay (500);
  motor1.run (FORWARD);
  motor2.run (FORWARD);
  motor3.run (FORWARD);
  motor4.run (FORWARD);
}
void turnLeft()
{
  motor1.run (BACKWARD);
  motor2.run (BACKWARD);
  motor3.run (FORWARD);
  motor4.run (FORWARD);
  delay (500);
  motor1.run (FORWARD);
  motor2.run (FORWARD);
  motor3.run (FORWARD);
  motor4.run (FORWARD);
}
