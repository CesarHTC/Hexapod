#include <Bluepad32.h>

GamepadPtr myGamepad = nullptr;

// ========================================================
const float delta_t = 0.001;
int xReading = 0;
int yReading = 0;
float t=3.44;
// ========================================================
float q5 = 0;
float q5_real = 0.001;  // q5 y q5_real se utilizan para mantener el valor actual y el valor deseado del sistema 
float dt = 0;
float u;
float ti = 0;

// Parametros del control PID
float Kp = 5;  // Ganancia Proporcional
float Ki = 0.0001; // Ganancia integral
float Kd = 0.45;  // Ganancia derivativa
float integral = 0;
float prev_error = 0;

// ========================================================
void setup() {
    BP32.setup(&onConnectedGamepad, &onDisconnectedGamepad);
    BP32.forgetBluetoothKeys();
    Serial.begin(115200);
}
// ========================================================
void loop() {
    BP32.update();

    if (myGamepad && myGamepad->isConnected()) {
        int xReading = myGamepad->axisX();
        int yReading = myGamepad->axisY();

        // este condicional funciona para eliminar el punto muerto del joystick
        // ya que al soltar el jostick se queda con valores 
        if (abs(xReading) < 18 && abs(yReading) < 18) {
          xReading = 0;
          yReading = 0;
        }
        
        q5_real = atan2(yReading,xReading);
        //  calculoel error como la diferencia entre q5_real(valor del joystick) y q5(valor que arroga el sistema).
        float error = q5_real - q5;

        // Se calcula la señal de control u utilizando el controlador PID. El valor u se calcula como la suma de 
        //tres términos: el término proporcional (Kp * error), 
        //el término integral (Ki * integral), y el término derivativo (Kd * (error - prev_error)).
        u = Kp * error + Ki * integral + Kd * (error - prev_error);
        //-----------------------------   Explicacion del calculo de u    ---------------------------------------------------------
        //  1-Término Proporcional (P): Este término es proporcional al error actual. 
        //  Multiplica el error por la ganancia proporcional Kp. Si el error es grande, 
        //  este término contribuirá de manera significativa al valor de u. Valores mas pequeños de Kp significa que el sistema respondera 
        //  de manera mas lenta pero reducirlo demaciado provoca que aparezca un sobre impulso 
        
        //  2-Este término acumula la suma de los errores a lo largo del tiempo y lo multiplica por la ganancia integral Ki. 
        //  Ayuda a eliminar errores constantes en el sistema y a ajustarse a las condiciones de estado estable.
        //  le tuve que dar un valor de 0 ya que provoca un sobre impulso

        //  3-Este término tiene en cuenta la tasa de cambio del error y lo multiplica por la ganancia derivativa Kd.
        //  Ayuda a prevenir oscilaciones excesivas y a estabilizar el sistema rápidamente.
        //  ------------------------------------------------    Fin de U  ---------------------------------------------
        
        
        //  La variable integral acumula la suma de los errores a lo largo del tiempo y 
        //  se utiliza en el término integral del control PID. Esto ayuda a eliminar los errores persistentes en el sistema.
        integral += error;
        //  La variable prev_error se actualiza con el valor del error actual,
        //  es necesario para calcular el término derivativo en la siguiente iteración.
        prev_error = error;

        // Apply control input
        q5 += u * delta_t;

        // Ensure q5 remains within a reasonable range (e.g., -pi to pi)
        
        if (q5 > M_PI) {
            q5 -= 2* M_PI;
        } else if (q5 < -M_PI) {
            q5 += 2* M_PI;// Imoratnte cambar este valor para que empieze en 0 
        }
        
        /*
        if ((yReading<17) && (xReading>17||xReading<-17)){
            q5=-(q5+(PI));
        }
        */
        

        // Print values for debugging
        Serial.print("t:");
        Serial.print(3.17);
        Serial.print("\t");
        Serial.print("-t:");
        Serial.print(-3.17);
        Serial.print("\t");
        Serial.print("q5_inter:");
        Serial.print(q5);
        Serial.print("\t");
        Serial.print("x:");
        Serial.print(xReading);
        Serial.print("\t");
        Serial.print("y:");
        Serial.print(yReading);
        Serial.print("\t");
        Serial.print("q5_real:");
        Serial.println(q5_real);
    }
}

//////////////////////////////////    Control     //////////////////////////////
void onConnectedGamepad(GamepadPtr gp) {
  bool foundEmptySlot = false;
    if (myGamepad == nullptr) {
      Serial.printf("CALLBACK: Gamepad is connected");
      // Additionally, you can get certain gamepad properties like:
      // Model, VID, PID, BTAddr, flags, etc.
      GamepadProperties properties = gp->getProperties();
      Serial.printf("Gamepad model: %s, VID=0x%04x, PID=0x%04x\n",
                    gp->getModelName().c_str(), properties.vendor_id,
                    properties.product_id);
      myGamepad = gp;
      foundEmptySlot = true;
     
    }
  

}
void onDisconnectedGamepad(GamepadPtr gp) {
  bool foundGamepad = false;
    if (myGamepad == gp) {
      Serial.printf("CALLBACK: Gamepad is disconnected ");
      myGamepad = nullptr;
      foundGamepad = true;

    }

  if (!foundGamepad) {
    Serial.println(
        "CALLBACK: Gamepad disconnected, but not found in myGamepads");
  }
}


