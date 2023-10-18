//#include <Servo.h>  //Include the Servo Library
#include <ESP32Servo.h> 
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define PI 3.1415926535897932384626433832795
/*
// --------------------------------------------
Servo L1_q1; // "Servos" objects are created
Servo L1_q2; // "Servos" objects are created
Servo L1_q3; // "Servos" objects are created

Servo L2_q1; // "Servos" objects are created
Servo L2_q2; // "Servos" objects are created
Servo L2_q3; // "Servos" objects are created

Servo L3_q1; // "Servos" objects are created
Servo L3_q2; // "Servos" objects are created
Servo L3_q3; // "Servos" objects are created

Servo L4_q1; // "Servos" objects are created
Servo L4_q2; // "Servos" objects are created
Servo L4_q3; // "Servos" objects are created

Servo L5_q1; // "Servos" objects are created
Servo L5_q2; // "Servos" objects are created
Servo L5_q3; // "Servos" objects are created

Servo L6_q1; // "Servos" objects are created
Servo L6_q2; // "Servos" objects are created
Servo L6_q3; // "Servos" objects are created
*/
//========================================================
#define SERVOMIN 123 //Minimo Valor  
#define SERVOMAX 614 //Maximo Valor 
//========================================================
//Leg 1.       Pin
#define L1_q1  14
#define L1_q2   9
#define L1_q3  10
//========================================================
//Leg 2        Pin
#define L2_q1  13
#define L2_q2   5
#define L2_q3   4
//========================================================
//Leg 3         Pin
#define L3_q1   12
#define L3_q2    2
#define L3_q3    1
//========================================================
//Leg 4         Pin
#define L4_q1    3
#define L4_q2   13
#define L4_q3   12
//========================================================
//Leg 5         Pin
#define L5_q1    2
#define L5_q2    9
#define L5_q3    8
//========================================================
//Leg 6         Pin
#define L6_q1    1
#define L6_q2    5
#define L6_q3    4
//========================================================
//OBJETOS CREADOS PARA LA COMUNICACION CON LAS PCA 9685
Adafruit_PWMServoDriver pca9685_Leg_1_2_3 = Adafruit_PWMServoDriver(0x41);
Adafruit_PWMServoDriver pca9685_Leg_4_5_6 = Adafruit_PWMServoDriver(0x40);
//========================================================
float a = 150 / 2; // Máximo desplazamiento horizontal.
float b = 55; // Máximo desplazamiento vertical.
float vx = 400; // Velocidad lineal.
float q5 = PI / 2;
float T; // tiempo Real
float t;
float tau = a / vx; // Constante de ciclo
float p[3]; // Definir p
int L;
// -------------------------------------------
float deg2rad(float deg) {
  float rad = deg * 1/57.2958;
  return rad;
}

float q4[6] = {
0 * (2 * PI / 6), 
3 * (2 * PI / 4), 
0 * (2 * PI / 6), 
3 * (2 * PI / 6), 
0 * (2 * PI / 6), 
3 * (2 * PI / 6)
};

float q[6][5] = {
  {0.0, 0.0, 0.0, q4[0], q5}, // Definir L1
  {0.0, 0.0, 0.0, q4[1], q5}, // Definir L2
  {0.0, 0.0, 0.0, q4[2], q5}, // Definir L3
  {0.0, 0.0, 0.0, q4[3], q5}, // Definir L4
  {0.0, 0.0, 0.0, q4[4], q5}, // Definir L5
  {0.0, 0.0, 0.0, q4[5], q5} // Definir L6
};
// -------------------------------------------
float q_offset[6][3] = {
  {135, 135, 135}, // Definir L1
  {135, 135, 135}, // Definir L2
  {135, 135, 135}, // Definir L3
  {125, 125, 125}, // Definir L4
  {125, 125, 125}, // Definir L5
  {125, 125, 125} // Definir L6
};
// -------------------------------------------
void setup() {
  Serial.begin(115200);  // Inicializa la comunicación serial
  //================
  pca9685_Leg_1_2_3.begin();
  pca9685_Leg_4_5_6.begin();
  //================
  pca9685_Leg_1_2_3.setPWMFreq(60);
  pca9685_Leg_4_5_6.setPWMFreq(60);
  //================
  Initialization_set_1();
}
void loop(){
  T = millis() * 0.001;//Capturamos el tiempo actual 
   //================
  Serial.println(map(pca9685_Leg_1_2_3.getPWM(0), 0, 270, 123, 614));
  Serial.println(map(pca9685_Leg_4_5_6.getPWM(0), 0, 270, 123, 614));
  Motion_set_1();
}
