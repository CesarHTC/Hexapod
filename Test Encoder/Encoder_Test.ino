/*
  ESP32 PCA9685 Servo Control
  esp32-pca9685.ino
  Driving multiple servo motors with ESP32 and PCA9685 PWM module
  Use I2C Bus
 
  DroneBot Workshop 2020
  https://dronebotworkshop.com
*/
#include <ESP32Servo.h>
// Include Wire Library for I2C
#include <Wire.h>
 
// Include Adafruit PCA9685 Servo Library
#include <Adafruit_PWMServoDriver.h>
 
// Creat object to represent PCA9685 at default I2C address
Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver(0x41); 
 
// Define servo motor connections (expand as required)
#define SER0  12   //Servo Motor 1 on connector 0
#define SER1  3   //Servo Motor 2 on connector 1
#define SER2  2   //Servo Motor 3 on connector 2

int angle = 135;
int selector;
 
void setup() {
 
  // Serial monitor setup
  Serial.begin(115200);
 
  // Print to monitor
  Serial.println("PCA9685 Servo Test");
 
  // Initialize PCA9685
  pca9685.begin();
 
  // Set PWM Frequency to 60Hz
  pca9685.setPWMFreq(60);
  
  // Standing Up
  //standUP();
}
 

void loop() { 
  while (Serial.available()==0)
  {

  }
  
  selector = Serial.parseInt();     // Reads the Serial Monitor for incoming byte:
  
  switch(selector){
    case 1:
      Serial.println("Q1 ");  
      while (Serial.available()==0)
      {
      }
      angle = Serial.parseFloat();
      Serial.println(angle);         // Prints the received data
      pca9685.setPWM(SER0, 0, getPWM(angle));
      break;

    case 2:
      Serial.println("Q2 "); 
      while (Serial.available()==0)
      {
      }
      angle = Serial.parseFloat(); 
      Serial.println(angle);         // Prints the received data
      pca9685.setPWM(SER1, 0, getPWM(angle));
      break;

    case 3:
      Serial.println("Q3 "); 
      while (Serial.available()==0)
      {
      }
      angle = Serial.parseFloat(); 
      Serial.println(angle);         // Prints the received data
      pca9685.setPWM(SER2, 0, getPWM(angle));
      break;
  }
}
