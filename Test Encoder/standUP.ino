void standUP() 
{
  pca9685.setPWM(SER2, 0, getPWM(190));
  delay(500);
  pca9685.setPWM(SER1, 0, getPWM(135));
  delay(500);
  pca9685.setPWM(SER0, 0, getPWM(135));
  delay(500);
  pca9685.setPWM(SER1, 0, getPWM(90));
  pca9685.setPWM(SER2, 0, getPWM(120));
  delay(500);
  pca9685.setPWM(SER1, 0, getPWM(110));
  pca9685.setPWM(SER2, 0, getPWM(115));
  delay(500);
  pca9685.setPWM(SER1, 0, getPWM(135));
  pca9685.setPWM(SER2, 0, getPWM(135));
}