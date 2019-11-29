/******************************************************************************
TB6612.cpp
TB6612FNG H-Bridge Motor Driver Example code
Michelle @ SparkFun Electronics
8/20/16
https://github.com/sparkfun/SparkFun_TB6612FNG_Arduino_Library

Uses 2 motors to show examples of the functions in the library.  This causes
a robot to do a little 'jig'.  Each movement has an equal and opposite movement
so assuming your motors are balanced the bot should end up at the same place it
started.

Resources:
TB6612 SparkFun Library

Development environment specifics:
Developed on Arduino 1.6.4
Developed with ROB-9457
******************************************************************************/

#include "SparkFun_TB6612.h"
#include <Arduino.h>

Motor::Motor(int In1pin, int In2pin, int PWMpin, int STBYpin, int Chpin)
{
  In1 = In1pin;
  In2 = In2pin;
  PWM = PWMpin;
  Standby = STBYpin;
  Ch = Chpin;
  
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(PWM, OUTPUT);
  pinMode(Standby, OUTPUT);

  ledcSetup(Ch, 12800, 8);
  ledcAttachPin(PWM, Ch);
}

void Motor::drive(int speed)
{
  digitalWrite(Standby, HIGH);
  if (speed>=0) fwd(speed);
  else rev(-speed);
}

void Motor::drive(int speed, int duration)
{
  drive(speed);
  delay(duration);
}

void Motor::fwd(int speed)
{
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  ledcWrite(Ch, speed);

}

void Motor::rev(int speed)
{
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  ledcWrite(Ch, speed);
}

void Motor::brake()
{
  digitalWrite(In1, HIGH);
  digitalWrite(In2, HIGH);
  ledcWrite(Ch,0);
}

void Motor::standby()
{
  digitalWrite(Standby, LOW);
}
