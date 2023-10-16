void Initialization_set_1() {
  int Pin[6][3] = {
    //modificar los datos Pines 
    {14, 9,  10}, // Definir L1
    {13, 5,   4}, // Definir L2
    {12, 2,   1},  // Definir L3
    {3,  13, 12}, // Definir L4
    {2,  9,   8}, // Definir L5
    {1,  5,   4}, // Definir L6
  };
  //========================================================
  //Direccion 0x41
  //========================================================
  //Leg 1
  L = 0;
  pca9685_Leg_1_2_3.setPWM(L1_q1,0,map(q_offset[L][0],0,270,SERVOMIN,SERVOMAX));
  pca9685_Leg_1_2_3.setPWM(L1_q2,0,map(q_offset[L][1],0,270,SERVOMIN,SERVOMAX));
  pca9685_Leg_1_2_3.setPWM(L1_q3,0,map(q_offset[L][2],0,270,SERVOMIN,SERVOMAX));
   //========================================================
  //Leg 2
  L = 1;
  pca9685_Leg_1_2_3.setPWM(L2_q1,0,map(q_offset[L][0],0,270,SERVOMIN,SERVOMAX));
  pca9685_Leg_1_2_3.setPWM(L2_q2,0,map(q_offset[L][1],0,270,SERVOMIN,SERVOMAX));
  pca9685_Leg_1_2_3.setPWM(L2_q3,0,map(q_offset[L][2],0,270,SERVOMIN,SERVOMAX));
  //========================================================
  //Leg 3
  L = 2;
  pca9685_Leg_1_2_3.setPWM(L3_q1,0,map(q_offset[L][0],0,270,SERVOMIN,SERVOMAX));
  pca9685_Leg_1_2_3.setPWM(L3_q2,0,map(q_offset[L][1],0,270,SERVOMIN,SERVOMAX));
  pca9685_Leg_1_2_3.setPWM(L3_q3,0,map(q_offset[L][2],0,270,SERVOMIN,SERVOMAX));
  //========================================================
  //Direccion 0x40
  //========================================================
  //Leg 4
  L = 3; 
  pca9685_Leg_4_5_6.setPWM(L4_q1,0,map(q_offset[L][0],0,270,SERVOMIN,SERVOMAX));
  pca9685_Leg_4_5_6.setPWM(L4_q2,0,map(q_offset[L][1],0,270,SERVOMIN,SERVOMAX));
  pca9685_Leg_4_5_6.setPWM(L4_q3,0,map(q_offset[L][2],0,270,SERVOMIN,SERVOMAX));
   //========================================================
  //Leg 5
  L = 4;
  pca9685_Leg_4_5_6.setPWM(L5_q1,0,map(q_offset[L][0],0,270,SERVOMIN,SERVOMAX));
  pca9685_Leg_4_5_6.setPWM(L5_q2,0,map(q_offset[L][1],0,270,SERVOMIN,SERVOMAX));
  pca9685_Leg_4_5_6.setPWM(L5_q3,0,map(q_offset[L][2],0,270,SERVOMIN,SERVOMAX));
   //========================================================
  //Leg 6
  L =5 ;
  pca9685_Leg_4_5_6.setPWM(L6_q1,0,map(q_offset[L][0],0,270,SERVOMIN,SERVOMAX));
  pca9685_Leg_4_5_6.setPWM(L6_q2,0,map(q_offset[L][1],0,270,SERVOMIN,SERVOMAX));
  pca9685_Leg_4_5_6.setPWM(L6_q3,0,map(q_offset[L][2],0,270,SERVOMIN,SERVOMAX));
}
