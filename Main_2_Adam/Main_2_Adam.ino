
#include <ESP32Servo.h> //Include the Servo Library
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Creat object to represent PCA9685 at default I2C address

#define PI 3.1416
// This determines the pulse width
 

/*
Servo L1_q1; // "Servos" objects are created
Servo L1_q2; // "Servos" objects are created3
Servo L1_q3; // "Servos" objects are created
*/

#define SERVOMIN  123  // Minimum value
#define SERVOMAX  614  // Maximum value
// Define servo motor connections (expand as required)
#define L1_q1  0   //Servo Motor 1 on connector 0
#define L1_q2  1   //Servo Motor 2 on connector 1
#define L1_q3  2   //Servo Motor 3 on connector 2
Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver(0x40);
//========================================================
// Variables for Servo Motor positions (expand as required)
long pwm0;
int angle = 135;
float a = 150 / 2; // Máximo desplazamiento horizontal.
float b = 55; // Máximo desplazamiento vertical.
float vx = 400; // Velocidad lineal.
float q5 = PI / 2;
//========================================================
float q[6][5] = {
  {0.0, 0.0, 0.0, 0 * (2 * PI / 6), q5}, // Definir L1
  {0.0, 0.0, 0.0, 1 * (2 * PI / 6), q5}, // Definir L2
  {0.0, 0.0, 0.0, 2 * (2 * PI / 6), q5}, // Definir L3
  {0.0, 0.0, 0.0, 3 * (2 * PI / 6), q5}, // Definir L4
  {0.0, 0.0, 0.0, 4 * (2 * PI / 6), q5},  // Definir L5
  {0.0, 0.0, 0.0, 5 * (2 * PI / 6), q5} // Definir L6
};
int q0[6][3] = {
  {135, 135, 135}, // Definir L1
  {90, 0, 0}, // Definir L2
  {90, 0, 0}, // Definir L3
  {90, 0, 0}, // Definir L4
  {90, 0, 0}, // Definir L5
  {90, 0, 0} // Definir L6
};
int Pin[6][3] = {
  {2, 10, 11}, // Definir L1
  {0, 0, 0}, // Definir L2
  {0, 0, 0}, // Definir L3
  {0, 0, 0}, // Definir L4
  {0, 0, 0},  // Definir L5
  {0, 0, 0} // Definir L6
};
//========================================================
boolean flag_phi1 = false; // Bandera conjunto avanzado. NO OLVIDAR MODIFICAR
float T; // tiempo Real
float t; // tiempo
float tau = a / vx; // Constante de ciclo
float p[3]; // Definir p
int L;
//========================================================
void setup() {
  
  Serial.begin(115200);  // Inicializa la comunicación serial
   // Initialize PCA9685
  pca9685.begin();
  // Set PWM Frequency to 50Hz
  pca9685.setPWMFreq(60);
  Set_1_Initial();

}
//========================================================
void loop() {
  T = millis() * 0.001; // Capturamos el tiempo actual
  Serial.println(map(pca9685.getPWM(0), 0, 270, 123, 614));
  Set_1();
}
