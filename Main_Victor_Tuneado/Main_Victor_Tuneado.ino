#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#define PI 3.1415926535897932384626433832795

// Creat object to represent PCA9685 at default I2C address
Adafruit_PWMServoDriver pca40 = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver pca41 = Adafruit_PWMServoDriver(0x41);


float a = 150 / 2; // Máximo desplazamiento horizontal.
float b = 50; // Máximo desplazamiento vertical.
float vx = 100; // Velocidad lineal.
float q5 = PI / 2;
float T; // tiempo Real
float t;
float tau = a / vx; // Constante de ciclo
float p[3]; // Definir p
int L;

// -------------------------------------------

float deg2rad(float deg) 
{
  float rad = deg * 1/57.2958;
  return rad;
}

float q4[6] = 
{
  0 * (2 * PI / 6), 
  3 * (2 * PI / 4), 
  0 * (2 * PI / 6), 
  3 * (2 * PI / 6), 
  0 * (2 * PI / 6), 
  3 * (2 * PI / 6)
};

float q[6][5] = 
{
  {0.0, 0.0, 0.0, q4[0], q5}, // Definir L1
  {0.0, 0.0, 0.0, q4[1], q5}, // Definir L2
  {0.0, 0.0, 0.0, q4[2], q5}, // Definir L3
  {0.0, 0.0, 0.0, q4[3], q5}, // Definir L4
  {0.0, 0.0, 0.0, q4[4], q5}, // Definir L5
  {0.0, 0.0, 0.0, q4[5], q5} // Definir L6
};

// -------------------------------------------

float q_offset[6][3] = 
{
  {135, 135, 135}, // Definir L1
  {135, 135, 135}, // Definir L2
  {135, 135, 135}, // Definir L3
  {125, 125, 125}, // Definir L4
  {125, 125, 125}, // Definir L5
  {125, 125, 125}  // Definir L6
};

// -------------------------------------------

void setup() 
{
  Serial.begin(115200);    // Inicializa la comunicación serial           

  pca40.begin();           // Initialize PCA9685
  pca41.begin();

  pca40.setPWMFreq(60);    // Set PWM Frequency to 60Hz
  pca41.setPWMFreq(60);

  Initialization_set_1();
}

// -------------------------------------------

void loop() 
{
  T = millis() * 0.001; // Capturamos el tiempo actual
  //Serial.println(rad2deg(q[1][4]),2);
  Motion_set_1();
}
