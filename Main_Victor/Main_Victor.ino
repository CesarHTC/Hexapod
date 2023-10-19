#include <Servo.h>  //Include the Servo Library
#define PI 3.1415926535897932384626433832795

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


float a = 40 / 2; // Máximo desplazamiento horizontal.
float b = 40; // Máximo desplazamiento vertical.
float vx = 100; // Velocidad lineal.
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
  {70, 100, 70}, // Definir L1
  {70, 100, 70}, // Definir L2
  {70, 100, 70}, // Definir L3
  {70, 100, 70}, // Definir L4
  {70, 100, 70}, // Definir L5
  {70, 100, 70} // Definir L6
};
// -------------------------------------------
void setup() {
  Serial.begin(9600);  // Inicializa la comunicación serial
  Initialization_set_1();
}
// -------------------------------------------
void loop() {
  T = millis() * 0.001; // Capturamos el tiempo actual
  Serial.println(rad2deg(q[1][4]),2);
  Motion_set_1();
}
