void Motion_set_1() {

  int Pin[6][3] = 
  {
    {14,  9, 10},  // Definir Pin L1
    {13,  5,  4},  // Definir Pin L2
    {12,  2,  1},  // Definir Pin L3
    { 3, 13, 12},  // Definir Pin L4
    { 2,  9,  8},  // Definir Pin L5
    { 1,  5,  4},  // Definir Pin L6
  };

  Trajectory(p, 0);
  L = 0;
  IK(p, q, L);

  for (int i = 0; i <= 2; i++) 
  {
    q[L][i] = q[L][i] + delta_q[L][i];
  }

  //          (   pin   , 0,                          angle                                          )
  pca41.setPWM(Pin[L][0], 0, getPWM(    (q_offset[L][0] + int(      rad2deg( q[L][0] )   )   )   )   );      // L1_q1
  pca41.setPWM(Pin[L][1], 0, getPWM(    (q_offset[L][1] + int(      rad2deg( q[L][1] )   )   )   )   );      // L1_q2
  pca41.setPWM(Pin[L][2], 0, getPWM(    (q_offset[L][2] + int(PI -  rad2deg( q[L][2] )   )   )   )   );      // L1_q3
//-------------------------------------------------------------------------------------------------------------------

  L = 2;
  IK(p, q, L);

  for (int i = 0; i <= 2; i++) 
  {
    q[L][i] = q[L][i] + delta_q[L][i];
  }

  //          (   pin   , 0,                          angle                                          )
  //pca41.setPWM(Pin[L][0], 0, getPWM(    (q_offset[L][0] + int(      rad2deg( q[L][0] )   )   )   )   );      // L3_q1
  //pca41.setPWM(Pin[L][1], 0, getPWM(    (q_offset[L][1] + int(PI -  rad2deg( q[L][1] )   )   )   )   );      // L3_q2
  //pca41.setPWM(Pin[L][2], 0, getPWM(    (q_offset[L][2] + int(      rad2deg( q[L][2] )   )   )   )   );      // L3_q3

//-------------------------------------------------------------------------------------------------------------------

  L = 4;
  IK(p, q, L);

  for (int i = 0; i <= 2; i++) 
  {
    q[L][i] = q[L][i] + delta_q[L][i];
  }

  //          (   pin   , 0,                          angle                                          )
  //pca40.setPWM(Pin[L][0], 0, getPWM(    (q_offset[L][0] + int(      rad2deg( q[L][0] )   )   )   )   );      // L5_q1
  //pca40.setPWM(Pin[L][1], 0, getPWM(    (q_offset[L][1] + int(PI -  rad2deg( q[L][1] )   )   )   )   );      // L5_q2
  //pca40.setPWM(Pin[L][2], 0, getPWM(    (q_offset[L][2] + int(      rad2deg( q[L][2] )   )   )   )   );      // L5_q3

//===================================================================================================================
    
  Trajectory(p, 2 * tau);
  L = 1;
  IK(p, q, L);

  for (int i = 0; i <= 2; i++) 
  {
    q[L][i] = q[L][i] + delta_q[L][i];
  }

  //          (   pin   , 0,                          angle                                          )
  //pca41.setPWM(Pin[L][0], 0, getPWM(    (q_offset[L][0] + int(      rad2deg( q[L][0] )   )   )   )   );      // L2_q1
  //pca41.setPWM(Pin[L][1], 0, getPWM(    (q_offset[L][1] + int(PI -  rad2deg( q[L][1] )   )   )   )   );      // L2_q2
  //pca41.setPWM(Pin[L][2], 0, getPWM(    (q_offset[L][2] + int(      rad2deg( q[L][2] )   )   )   )   );      // L2_q3

//-------------------------------------------------------------------------------------------------------------------

  L = 3;
  IK(p, q, L);

  for (int i = 0; i <= 2; i++) 
  {
    q[L][i] = q[L][i] + delta_q[L][i];
  }

  //          (   pin   , 0,                          angle                                          )
  //pca40.setPWM(Pin[L][0], 0, getPWM(    (q_offset[L][0] + int(      rad2deg( q[L][0] )   )   )   )   );      // L4_q1
  //pca40.setPWM(Pin[L][1], 0, getPWM(    (q_offset[L][1] + int(PI -  rad2deg( q[L][1] )   )   )   )   );      // L4_q2
  //pca40.setPWM(Pin[L][2], 0, getPWM(    (q_offset[L][2] + int(      rad2deg( q[L][2] )   )   )   )   );      // L4_q3

//-------------------------------------------------------------------------------------------------------------------

  L = 5;
  IK(p, q, L);

  for (int i = 0; i <= 2; i++) 
  {
    q[L][i] = q[L][i] + delta_q[L][i];
  }

  //          (   pin   , 0,                          angle                                          )
  //pca40.setPWM(Pin[L][0], 0, getPWM(    (q_offset[L][0] + int(      rad2deg( q[L][0] )   )   )   )   );      // L6_q1
  //pca40.setPWM(Pin[L][1], 0, getPWM(    (q_offset[L][1] + int(PI -  rad2deg( q[L][1] )   )   )   )   );      // L6_q2
  //pca40.setPWM(Pin[L][2], 0, getPWM(    (q_offset[L][2] + int(      rad2deg( q[L][2] )   )   )   )   );      // L6_q3
  
}
