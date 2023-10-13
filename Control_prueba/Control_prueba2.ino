#include <ESP32Servo.h>
// Include Wire Library for I2C
#include <Wire.h>
// Include Adafruit PCA9685 Servo Library
#include <Adafruit_PWMServoDriver.h>
#include <Bluepad32.h>
 
// Creat object to represent PCA9685 at default I2C address

Adafruit_PWMServoDriver pca41 = Adafruit_PWMServoDriver(0x41); 

 
// Define servo motor connections 0X41
#define PATA1Q1       14
#define PATA1Q2       9
#define PATA1Q3       10

#define PATA2Q1       13 
#define PATA2Q2       5
#define PATA2Q3       4

#define PATA3Q1       12
#define PATA3Q2       2
#define PATA3Q3       1

// Define servo motor connections 0X40
/*
#define PATA4Q1       3
#define PATA4Q2       13
#define PATA4Q3       12

#define PATA5Q1       2
#define PATA5Q2       9
#define PATA5Q3       8

#define PATA6Q1       1
#define PATA6Q2       5
#define PATA6Q3       4
*/


int angle = 135;
int selector;

GamepadPtr myGamepads[BP32_MAX_GAMEPADS]; //constante que sale del archivo sdkconfig.h su valor es

// This callback gets called any time a new gamepad is connected.
// Up to 4 gamepads can be connected at the same time.
void onConnectedGamepad(GamepadPtr gp) {
  bool foundEmptySlot = false;
  for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
    if (myGamepads[i] == nullptr) {
      Serial.printf("CALLBACK: Gamepad is connected, index=%d\n", i);
      // Additionally, you can get certain gamepad properties like:
      // Model, VID, PID, BTAddr, flags, etc.
      GamepadProperties properties = gp->getProperties();
      Serial.printf("Gamepad model: %s, VID=0x%04x, PID=0x%04x\n",
                    gp->getModelName().c_str(), properties.vendor_id,
                    properties.product_id);
      myGamepads[i] = gp;
      foundEmptySlot = true;
      break;
    }
  }
  if (!foundEmptySlot) {
    Serial.println(
        "CALLBACK: Gamepad connected, but could not found empty slot");
  }
}

void onDisconnectedGamepad(GamepadPtr gp) {
  bool foundGamepad = false;

  for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
    if (myGamepads[i] == gp) {
      Serial.printf("CALLBACK: Gamepad is disconnected from index=%d\n", i);
      myGamepads[i] = nullptr;
      foundGamepad = true;
      break;
    }
  }

  if (!foundGamepad) {
    Serial.println(
        "CALLBACK: Gamepad disconnected, but not found in myGamepads");
  }
}

// Arduino setup function. Runs in CPU 1
void setup() {
  ///////////////////////////////////////     Encoder     ///////////////////////////////////////
    // Serial monitor setup
  Serial.begin(115200);
 
  // Print to monitor
  Serial.println("PCA9685 Servo Test");
 
  // Initialize PCA9685

  pca41.begin();
 
  // Set PWM Frequency to 60Hz
  //pca40.setPWMFreq(60);
  pca41.setPWMFreq(60);





  Serial.begin(115200);
  Serial.printf("Firmware: %s\n", BP32.firmwareVersion());
  const uint8_t *addr = BP32.localBdAddress();
  Serial.printf("BD Addr: %2X:%2X:%2X:%2X:%2X:%2X\n", addr[0], addr[1], addr[2],
                addr[3], addr[4], addr[5]);

  // Setup the Bluepad32 callbacks
  BP32.setup(&onConnectedGamepad, &onDisconnectedGamepad);

  // "forgetBluetoothKeys()" should be called when the user performs
  // a "device factory reset", or similar.
  // Calling "forgetBluetoothKeys" in setup() just as an example.
  // Forgetting Bluetooth keys prevents "paired" gamepads to reconnect.
  // But might also fix some connection / re-connection issues.
  BP32.forgetBluetoothKeys();
}

// Arduino loop function. Runs in CPU 1
void loop() {
  // This call fetches all the gamepad info from the NINA (ESP32) module.
  // Just call this function in your main loop.
  // The gamepads pointer (the ones received in the callbacks) gets updated
  // automatically.
  BP32.update();

  // It is safe to always do this before using the gamepad API.
  // This guarantees that the gamepad is valid and connected.
  for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
    GamepadPtr myGamepad = myGamepads[i];

    if (myGamepad && myGamepad->isConnected()) {
      
      //verifica que botones estan presionados en caso de que el control este conectado
        switch (myGamepad->buttons()) {
          case 0x0001:
            // Boton "A"
            standUP(); 
            break;
          case 0x0002:
            // Boton "B"
            
            break;
          case 0x0004:
            //Boton "X"

            break;
          case 0x0008:
            //Boton "X"

          break;
          //ningun boton presionado
          default:
          break;

        }


      Serial.printf(
          "idx=%d, dpad: 0x%02x, buttons: 0x%04x, axis L: %4d, %4d, axis R: "
          "%4d, %4d, brake: %4d, throttle: %4d",
          i,                        // Gamepad Index
          myGamepad->dpad(),        // DPAD
          myGamepad->buttons(),     // bitmask of pressed buttons
          myGamepad->axisX(),       // (-511 - 512) left X Axis
          myGamepad->axisY(),       // (-511 - 512) left Y axis
          myGamepad->axisRX(),      // (-511 - 512) right X axis
          myGamepad->axisRY(),      // (-511 - 512) right Y axis
          myGamepad->brake(),       // (0 - 1023): brake button
          myGamepad->throttle()    // (0 - 1023): throttle (AKA gas) button
      );

    }
  }

  delay(150);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
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
void standUP() 
{
  pca41.setPWM(PATA1Q3, 0, getPWM(190));
  delay(500);
  pca41.setPWM(PATA1Q2, 0, getPWM(135));
  delay(500);
  pca41.setPWM(PATA1Q1, 0, getPWM(135));
  delay(500);
  pca41.setPWM(PATA1Q2, 0, getPWM(90));
  pca41.setPWM(PATA1Q3, 0, getPWM(120));
  delay(500);
  pca41.setPWM(PATA1Q2, 0, getPWM(110));
  pca41.setPWM(PATA1Q3, 0, getPWM(115));
  delay(500);
  pca41.setPWM(PATA1Q2, 0, getPWM(135));
  pca41.setPWM(PATA1Q3, 0, getPWM(135));
}


 

 



