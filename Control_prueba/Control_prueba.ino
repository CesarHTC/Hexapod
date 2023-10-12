#include <Bluepad32.h>

int led1 = 2;
int led2 = 4;
int led3 = 16;
int led4 = 17;
GamepadPtr myGamepad = nullptr; // Solo un gamepad

// Arduino setup function. Runs in CPU 1
void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.begin(115200);
  Serial.printf("Firmware: %s\n", BP32.firmwareVersion());
  const uint8_t *addr = BP32.localBdAddress();
  Serial.printf("BD Addr: %2X:%2X:%2X:%2X:%2X:%2X\n", addr[0], addr[1], addr[2],
                addr[3], addr[4], addr[5]);

  // Setup the Bluepad32 callback for the single gamepad
  BP32.setup(
    [](GamepadPtr gp) {
      if (myGamepad == nullptr) {
        myGamepad = gp;
        Serial.println("Gamepad is connected.");
      }
    },
    [](GamepadPtr gp) {
      if (myGamepad == gp) {
        myGamepad = nullptr;
        Serial.println("Gamepad is disconnected.");
      }
    }
  );

  // "forgetBluetoothKeys()" should be called when the user performs
  // a "device factory reset," or similar.
  // Calling "forgetBluetoothKeys" in setup() just as an example.
  // Forgetting Bluetooth keys prevents "paired" gamepads from reconnecting.
  // But it might also fix some connection / reconnection issues.
  BP32.forgetBluetoothKeys();
}

// Arduino loop function. Runs in CPU 1
void loop() {
  // This call fetches gamepad info from the NINA (ESP32) module.
  // Just call this function in your main loop.
  BP32.update();

  if (myGamepad && myGamepad->isConnected()) {
    // Verifica qué botones están presionados cuando el control está conectado
    switch (myGamepad->buttons()) {
      case 0x0001:
        // Botón "A"
        digitalWrite(led1, HIGH);
        break;
      case 0x0002:
        // Botón "B"
        digitalWrite(led2, HIGH);
        break;
      default:
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
    }

    int axisXValue = myGamepad->axisX() / 2;

    if (axisXValue > 9) {
      analogWrite(led3, axisXValue / 2);
      analogWrite(led4, 0);
    } else if (axisXValue < -9) {
      analogWrite(led4, -axisXValue / 2);
      analogWrite(led3, 0);
    } else {
      analogWrite(led3, 0);
      analogWrite(led4, 0);
    }

    // Resto del código para obtener información del gamepad
    Serial.printf(
      "dpad: 0x%02x, buttons: 0x%04x, axis L: %4d, %4d, axis R: %4d, %4d, brake: %4d, throttle: %4d, misc: 0x%02x, gyro x:%6d y:%6d z:%6d, accel x:%6d y:%6d z:%6d\n",
      myGamepad->dpad(),
      myGamepad->buttons(),
      myGamepad->axisX(),
      myGamepad->axisY(),
      myGamepad->axisRX(),
      myGamepad->axisRY(),
      myGamepad->brake(),
      myGamepad->throttle(),
      myGamepad->miscButtons(),
      myGamepad->gyroX(),
      myGamepad->gyroY(),
      myGamepad->gyroZ(),
      myGamepad->accelX(),
      myGamepad->accelY(),
      myGamepad->accelZ()
    );
  }

  // Delay for a short period
  delay(150);
}
