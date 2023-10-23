void ciclo(float T, float phi) 
{
  if (T >= 10 * tau * 1000) 
  {
    T = 0.0;
  }

  T = T + phi;
  int n = 4;
  
  if (T <= n * tau) 
  {
    t = T;
  }
  else 
  {
    t = T - int(T / (n * tau)) * (n * tau);
  }
}

float rad2deg(float rad) {
  float deg = rad * 57.2958;
  return deg;
}



float sign(float valor) {
  if (valor > 0) {
    return 1; // Positivo
  } else if (valor < 0) {
    return -1; // Negativo
  } else {
    return 0; // Cero
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
