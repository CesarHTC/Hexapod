void Motion_set_1() {

  int Pin[6][3] = 
  {
    {  2,   9,   8},  // Definir Pin L1
    {  3,  13,  12},  // Definir Pin L2
    { 12,   2,   1},  // Definir Pin L3
    { 13,   5,   4},  // Definir Pin L4
    { 14,   9,  10},  // Definir Pin L5
    {  1,   5,   4},  // Definir Pin L6
  };

  Trajectory(p, 0);

  L = 0;
  q[L][4]=q5_Smoothed;
  IK(p, q, L);

  for (int i = 0; i <= 2; i++) 
  {
    q[L][i] = q[L][i] + delta_q[L][i];
  }

  //          (   pin   , 0,                          angle                                          )
  
  
  pca40.setPWM(Pin[L][0], 0, getPWM(    (q_offset[L][0] + int(          rad2deg( q[L][0] )   )   )   )   );      // L1_q1
  pca40.setPWM(Pin[L][1], 0, getPWM(    (q_offset[L][1] + int( PI -     rad2deg( q[L][1] )   )   )   )   );      // L1_q2
  pca40.setPWM(Pin[L][2], 0, getPWM(    (q_offset[L][2] + int(          rad2deg( q[L][2] )   )   )   )   );      // L1_q3
  
//-------------------------------------------------------------------------------------------------------------------

  L = 2;
  q[L][4]=q5_Smoothed;
  IK(p, q, L);

  for (int i = 0; i <= 2; i++) 
  {
    q[L][i] = q[L][i] + delta_q[L][i];
  }
  
  //          (   pin   , 0,                          angle                                          )
  pca41.setPWM(Pin[L][0], 0, getPWM(    (q_offset[L][0] + int(          rad2deg( q[L][0] )   )   )   )   );      // L3_q1
  pca41.setPWM(Pin[L][1], 0, getPWM(    (q_offset[L][1] + int(          rad2deg( q[L][1] )   )   )   )   );      // L3_q2
  pca41.setPWM(Pin[L][2], 0, getPWM(    (q_offset[L][2] + int( PI -     rad2deg( q[L][2] )   )   )   )   );      // L3_q3
  
//-------------------------------------------------------------------------------------------------------------------

  L = 4;
  q[L][4]=q5_Smoothed;
  IK(p, q, L);

  for (int i = 0; i <= 2; i++) 
  {
    q[L][i] = q[L][i] + delta_q[L][i];
  }
  
  //          (   pin   , 0,                          angle                                          )
  pca41.setPWM(Pin[L][0], 0, getPWM(    (q_offset[L][0] + int(          rad2deg( q[L][0] )   )   )   )   );      // L5_q1
  pca41.setPWM(Pin[L][1], 0, getPWM(    (q_offset[L][1] + int(          rad2deg( q[L][1] )   )   )   )   );      // L5_q2
  pca41.setPWM(Pin[L][2], 0, getPWM(    (q_offset[L][2] + int( PI -     rad2deg( q[L][2] )   )   )   )   );      // L5_q3
  
//===================================================================================================================
    
  Trajectory(p, 2 * tau);

  L = 1;
  q[L][4]=q5_Smoothed;
  IK(p, q, L);


  for (int i = 0; i <= 2; i++) 
  {
    q[L][i] = q[L][i] + delta_q[L][i];
  }
  ////////////////////////////////////////////////    Monitorear el comportamiento de q
  /*
  Serial.print("Q0:");
  Serial.print(q_offset[L][0] + int(      rad2deg( q[L][0] )   )   );
  Serial.print("\t");
  Serial.print("Q1:");
  Serial.print(q_offset[L][1] + int(PI-      rad2deg( q[L][1] )   )   );
  Serial.print("\t");
  Serial.print("\Q2:");
  Serial.println(q_offset[L][2] + int(      rad2deg( q[L][2] )   )   );
  delay(10);
  */
  
  
  //          (   pin   , 0,                          angle                                          )
  pca40.setPWM(Pin[L][0], 0, getPWM(    (q_offset[L][0] + int(          rad2deg( q[L][0] )   )   )   )   );      // L2_q1
  pca40.setPWM(Pin[L][1], 0, getPWM(    (q_offset[L][1] + int( PI -     rad2deg( q[L][1] )   )   )   )   );      // L2_q2
  pca40.setPWM(Pin[L][2], 0, getPWM(    (q_offset[L][2] + int(          rad2deg( q[L][2] )   )   )   )   );      // L2_q3

  
//-------------------------------------------------------------------------------------------------------------------

  L = 3;
  q[L][4]=q5_Smoothed;
  IK(p, q, L);

  for (int i = 0; i <= 2; i++) 
  {
    q[L][i] = q[L][i] + delta_q[L][i];
  }
  
  //          (   pin   , 0,                          angle                                          )
  pca41.setPWM(Pin[L][0], 0, getPWM(    (q_offset[L][0] + int(          rad2deg( q[L][0] )   )   )   )   );      // L4_q1
  pca41.setPWM(Pin[L][1], 0, getPWM(    (q_offset[L][1] + int(          rad2deg( q[L][1] )   )   )   )   );      // L4_q2
  pca41.setPWM(Pin[L][2], 0, getPWM(    (q_offset[L][2] + int( PI -     rad2deg( q[L][2] )   )   )   )   );      // L4_q3
  
//-------------------------------------------------------------------------------------------------------------------

  L = 5;
  q[L][4]=q5_Smoothed;
  IK(p, q, L);

  for (int i = 0; i <= 2; i++) 
  {
    q[L][i] = q[L][i] + delta_q[L][i];
  }
  
  //          (   pin   , 0,                          angle                                          )
  pca40.setPWM(Pin[L][0], 0, getPWM(    (q_offset[L][0] + int(          rad2deg( q[L][0] )   )   )   )   );      // L6_q1
  pca40.setPWM(Pin[L][1], 0, getPWM(    (q_offset[L][1] + int( PI -     rad2deg( q[L][1] )   )   )   )   );      // L6_q2
  pca40.setPWM(Pin[L][2], 0, getPWM(    (q_offset[L][2] + int(          rad2deg( q[L][2] )   )   )   )   );      // L6_q3
  

  //---------------------------------------------------   Control         --------------------------------------------------------------------//
  BP32.update();// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Importante, saber donde se tiene que actualizar el objeto myGamepad para evitar problemas con las ecuaciones

  // It is safe to always do this before using the gamepad API.
  // This guarantees that the gamepad is valid and connected.

    if (myGamepad && myGamepad->isConnected()) {


      
      int xReading = myGamepad->axisX();
      int yReading = -myGamepad->axisY();// el signo menos es por que y esta invertida 
      /////////////////////////////////////////     Tratamiento de q5 para cumpplir con los nuevos parametros de q5       /////////////////////////////////
      if (abs(xReading) < 14 && abs(yReading) < 14) {
          xReading = 0;
          yReading = 0;
      }
      if(q5_Smoothed !=0){
        T_Propia=T_Propia+0.00422;// no se pone en un else del if de la linea 142 porque nececitamos que que 
                                  //el tiempo no pare y siga el comportamiento de q5 amortiguada
      }
      /////////////////////////////////////////     Amortiguamiento de q5       /////////////////////////////////////////////////////////////////////////////
      xSmoothed = alpha * xReading + (1 - alpha) * xSmoothed;
      ySmoothed = alpha * yReading + (1 - alpha) * ySmoothed;
      q5_Smoothed=atan2(ySmoothed,xSmoothed);
      if ((yReading<13) && (xReading>13||xReading<-13)){
        q5_Smoothed=-(q5_Smoothed+PI);
        }
      ///////////////////////////////////////////     Esto evita que q5 pueda tomar valores de 0 o PI     ////////////////////////////////////////////////// 
      if (q5_Smoothed < -4.0 || (q5_Smoothed <= -0.009 && q5_Smoothed > -0.04)) {
          q5_Smoothed = -0.05;
      }
      if ((q5_Smoothed<-3.10 && q5_Smoothed>-3.2)) {
        q5_Smoothed=-3.09;

      }



    }

  
}
