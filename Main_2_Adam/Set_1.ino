void Set_1(){
  Trajectory(p, true);
  L = 0;
  IK(p, q, L);

  pca9685.setPWM(L1_q1, 0, map((q0[L][0] + int(PI+rad2deg(q[L][0]))), 0, 270, SERVOMIN, SERVOMAX));//si pones - pi el robot empieza de 180 a 0  
  pca9685.setPWM(L1_q2, 0, map((q0[L][1] + int(rad2deg(q[L][1]))), 0, 270, SERVOMIN, SERVOMAX));
  pca9685.setPWM(L1_q3, 0, map((q0[L][2] + int(rad2deg(q[L][2]))), 0, 270, SERVOMIN, SERVOMAX));
  
 
  
}
