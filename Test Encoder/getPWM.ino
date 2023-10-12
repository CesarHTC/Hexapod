int getPWM(int angle)
{
  int pwm = 0.00;

  // Define maximum and minimum number of "ticks" for the servo motors
  // Range from 0 to 4095
  // This determines the pulse width
  //pwm = map(angle, 0, 270, SERVOMIN, SERVOMAX);
  pwm = map(angle, 0, 270, 123, 614);

  return pwm;
}