#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#define PI 3.1415926535897932384626433832795
#include <Bluepad32.h>
////////////////////////////////////////////////////////////////////////////////
float alpha = 0.1;  // Factor de suavizado (mejor ajuste 0.2)
int xSmoothed = 0.0;
int ySmoothed = 0.0;
float q5 = 0.0;
float q5_Smoothed = 0.0;


GamepadPtr myGamepad = nullptr; 
///////////////////////////////////////////////////////////////////////////////////

// Creat object to represent PCA9685 at default I2C address
Adafruit_PWMServoDriver pca40 = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver pca41 = Adafruit_PWMServoDriver(0x41);


float a  = 120 / 2;   // Máximo desplazamiento horizontal.    ///solo esta variable se puede modificar con el gatillo   cuantificador de estados
float b  = 40;        // Máximo desplazamiento vertical.
float vx = 130;       // Velocidad lineal.
//float q5 = (PI/2);
float T;              // tiempo Real
float t;
float tau = a / vx;   // Constante de ciclo
float p[3];           // Definir p
int L;

// -------------------------------------------



float q4[6] = {
0 * (2 * PI / 6), 
1 * (2 * PI / 6), 
2 * (2 * PI / 6), 
3 * (2 * PI / 6), 
4 * (2 * PI / 6), 
5 * (2 * PI / 6)
};

float q[6][5] = 
{
  {0.0, 0.0, 0.0, q4[0], q5}, // Definir L1
  {0.0, 0.0, 0.0, q4[1], q5}, // Definir L2
  {0.0, 0.0, 0.0, q4[2], q5}, // Definir L3
  {0.0, 0.0, 0.0, q4[3], q5}, // Definir L4
  {0.0, 0.0, 0.0, q4[4], q5}, // Definir L5
  {0.0, 0.0, 0.0, q4[5], q5}  // Definir L6
};

// -------------------------------------------


float q_offset[6][3] = 
{
  {125, 125, 125}, // Definir L1
  {125, 125, 125}, // Definir L2
  {135, 135, 135}, // Definir L3
  {135, 135, 135}, // Definir L4
  {135, 135, 135}, // Definir L5
  {145, 125, 125}  // Definir L6   Warning
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
  BP32.setup(&onConnectedGamepad, &onDisconnectedGamepad);
  BP32.forgetBluetoothKeys();
  delay(5000);
}

// -------------------------------------------

void loop() 
{
  
  //delay(100);

  T = millis() * 0.001; // Capturamos el tiempo actual
  //Serial.println(rad2deg(q[1][4]),2);
  Motion_set_1();
  ///////////////////////////////////     Control         /////////////////////////////////
  BP32.update();// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Importante, saber donde se tiene que actualizar el objeto myGamepad para evitar problemas con las ecuaciones

  // It is safe to always do this before using the gamepad API.
  // This guarantees that the gamepad is valid and connected.

    if (myGamepad && myGamepad->isConnected()) {

      
      int xReading = myGamepad->axisX();
      int yReading = -myGamepad->axisY();// el signo menos es por que y esta invertida 

      if (xReading < 14 && xReading > -14){xReading=0;}//para eliminar el punto muerto de jostick
      if (yReading < 14 && yReading > -14){yReading=0;}
      xSmoothed = alpha * xReading + (1 - alpha) * xSmoothed;
      ySmoothed = alpha * yReading + (1 - alpha) * ySmoothed;
      q5=atan2(yReading,xReading);
      q5_Smoothed=atan2(ySmoothed,xSmoothed);
      if ((yReading<13) && (xReading>13||xReading<-13)){q5=-(q5+PI);q5_Smoothed=-(q5_Smoothed+PI);}
      if(q5<-3.2){q5=PI; q5_Smoothed=PI;}
      /*
      Serial.print("Q5:");

      //Serial.print(rad2deg(q5));
      Serial.print(q5);
      Serial.print("\t");
      Serial.print("Q5_Smoth:");
      Serial.println(q5_Smoothed);
      */
      //verifica que botones estan presionados en caso de que el control este conectado
    }

}
