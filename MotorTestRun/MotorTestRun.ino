#include "SparkFun_TB6612.h"

Motor motor_la = Motor(26, 27, A16, 12, 0);
Motor motor_lb = Motor(25, 33, A4, 12, 1);

Motor motor_ra = Motor(5, 18, A11, 19, 2);
Motor motor_rb = Motor(17, 16, A10, 19, 3);

void setup()
{
  motor_la.standby();
  motor_lb.standby();

  motor_ra.standby();
  motor_rb.standby();
}

void loop()
{
  motor_la.drive(100);
  delay(500);
  motor_la.drive(-100);
  delay(500);
  motor_la.brake();

  motor_lb.drive(100);
  delay(500);
  motor_lb.drive(-100);
  delay(500);
  motor_lb.brake();

  motor_ra.drive(100);
  delay(500);
  motor_ra.drive(-100);
  delay(500);
  motor_ra.brake();

  motor_rb.drive(100);
  delay(500);
  motor_rb.drive(-100);
  delay(500);
  motor_rb.brake();
}