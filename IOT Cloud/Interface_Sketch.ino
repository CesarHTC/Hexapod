/* 
 Alan de Jesus Fabian Garcia 10/10/2023
*/

#include<ArduinoIoTCloud.h>
#include<Arduino_ConnectionHandler.h>
#include<ACS712.h>//Libreria para ACS712 El sensor de corriente
#include "thingProperties.h"
//Pines Sensores 
const int AnalogPin1=A0;
const int  AnalogPin2=A1;
const int AnalogPin3=A2;
const int AnalogPin4=A3;
const int AnalogPin5=A4;
const int  AnalogPin6=A5;


//Pines Medidores de Voltajes,Corriente,Baterias Modificar los pines de los sensores una ves esten conectados
const int AnalogPin= A6;        //Pin para el sensor de voltaje 
const int CurrentSensorPin=A7;  //Pin para el sensor de corriente
const int batteryPin=A8;        //Pin analogo al que va conectado la bateria que suministra el voltaje 

float minVoltage = 6.5;  //Minimo voltaje para 0% de carga 
float maxVoltage = 8.4;  //Maximo voltaje para 100% de carga 
int threshold = 512;

ACS712 sensor(ACS712_20A, CurrentSensorPin);// Asumiendo 20A de sensibilidad para el sensor 
//--------------------------------------------------------------------------
void setup() {
  Serial.begin(115200);
  delay(1500); 

  // Defined in thingProperties.h
  setProperty(Voltage,0.0,"V");
  setProperty(Current,0.0,"A");
  setProperty(BatteryCharge,0,"%");
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
   // Connect to WiFi
  connectArduinoIoTCloud();
  //valores iniciales de los sensores 
  Sensor1=0;
  Sensor2=0;
  Sensor3=0;
  Sensor4=0;
  Sensor5=0;
  Sensor6=0;
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  checkAndSendSensorValue(AnalogPin1, Sensor1);
  checkAndSendSensorValue(AnalogPin2, Sensor2);
  checkAndSendSensorValue(AnalogPin3, Sensor3);
  checkAndSendSensorValue(AnalogPin4, Sensor4);
  checkAndSendSensorValue(AnalogPin5, Sensor5);
  checkAndSendSensorValue(AnalogPin6, Sensor6);
  
}
//----------------------Voltaje y Corriente-----------------------------
void onVoltajeChange()  {
  float voltageValue = analogRead(AnalogPin)*(3*3/4095);//Eso asumiendo que 3.3 es nuestro voltaje de referencia con una resolucion de 12 bits
  ArduinoCloud.write(Voltage,voltageValue);
}

void onCorrienteChange()  {
  float current=sensor.getCurrentDC();
  ArduinoCloud.write(Current,current);
}
//-------------------------------------------------------------------------
//---------------------------Bateria------------------------------------------
void PercentageBattery() {
  int rawValue = analogRead(batteryPin);
  float batteryVoltage =(rawValue/4095.0)*;//Asumiendo de voltaje de referencia 3.3
  int batteryChargePercentage=map(batteryVoltage*1000,minVoltage*1000,maxVoltage*1000,0,100);
  ArduinoCloud.write(BatteryCharge, batteryChargePercentage);
}
//---------------------------SENSORES-----------------------------------------
void checkAndSendSensorValue(int pin,PropertyInt &property) {
  int sensorValue = analogRead(pin);
  if (sensorValue>threshold) {
    Serial.println("Sensor Value is above the threshold.");
  }else {
    Serial.println("Sensor Value is below or equal to the threshold.");
  }
   property = sensorValue;//Cambiar la propiedad del valor del sensor
  delay(1000);
}
void onSensor1Change() {
  checkAndSendSensorValue(AnalogPin1, Sensor1);
}

void onSensor2Change() {
  checkAndSendSensorValue(AnalogPin2, Sensor2);
}

void onSensor3Change() {
  checkAndSendSensorValue(AnalogPin3, Sensor3);
}

void onSensor4Change() {
  checkAndSendSensorValue(AnalogPin4, Sensor4);
}

void onSensor5Change() {
  checkAndSendSensorValue(AnalogPin5, Sensor5);
}

void onSensor6Change() {
  checkAndSendSensorValue(AnalogPin6, Sensor6);
}
//-----------------------SENSORES-------------------------------------------


