

   // Almacena el valor leído del sensor

void setup() 
{

  Serial.begin(115200);
  pinMode(2, OUTPUT);
}

void loop() 
{
  int fsrValue = analogRead(34); // Lee el valor analógico del sensor FSR


  
  

  Serial.println(fsrValue);


  // Puedes agregar aquí un mapeo personalizado para convertir el valor en una unidad de presión específica si conoces la relación entre los valores del sensor y la presión aplicada.
  if (fsrValue>1 )
  {
    digitalWrite(2,HIGH);
    delay(50);
  }
  else
  {
      digitalWrite(2,LOW);
      delay(50);

  }
  delay(50); // Puedes ajustar el tiempo de muestreo según tus necesidades
}
