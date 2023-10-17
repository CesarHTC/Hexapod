void Motion_set_1() {
 
    Trajectory(p, 0);
    L = 0;
    IK(p, q, L);
    for (int i = 0; i <= 2; i++) {
      q[L][i] = q[L][i] + delta_q[L][i];
    }
    //LEG 1
    pca9685_Leg_1_2_3.setPWM(L1_q1,0,getPWM(q_offset[L][0]+int(rad2deg[L][0])));
    pca9685_Leg_1_2_3.setPWM(L1_q2,0,getPWM(q_offset[L][1]+int(PI-rad2deg(q[L][1]))));
    pca9685_Leg_1_2_3.setPWM(L1_q3,0,getPWM(q_offset[L][2]+int(rad2deg(q[L][2]))));

    L = 2;
    IK(p, q, L);
    for (int i = 0; i <= 2; i++) {
      q[L][i] = q[L][i] + delta_q[L][i];
    }
    //LEG 3
    pca9685_Leg_1_2_3.setPWM(L3_q1,0,getPWM(q_offset[L][0]+int(rad2deg(q[L][0]))));
    pca9685_Leg_1_2_3.setPWM(L3_q2,0,getPWM(q_offset[L][1]+int(PI - rad2deg(q[L][1]))));
    pca9685_Leg_1_2_3.setPWM(L3_q3,0,getPWM(q_offset[L][2]+int(rad2deg(q[L][2]))));

    L = 4;
    IK(p, q, L);
    for (int i = 0; i <= 2; i++) {
      q[L][i] = q[L][i] + delta_q[L][i];
    }
    //LEG 5 
    pca9685_Leg_4_5_6.setPWM(L5_q1,0,getPWM(q_offset[L][0]+int(rad2deg(q[L][0]))));
    pca9685_Leg_4_5_6.setPWM(L5_q2,0,getPWM(q_offset[L][1]+int(PI - rad2deg(q[L][1]))));
    pca9685_Leg_4_5_6.setPWM(L5_q3,0,getPWM(q_offset[L][2]+int(rad2deg(q[L][2]))));
  
  Trajectory(p, 2 * tau);
    L = 1;
    IK(p, q, L);
    for (int i = 0; i <= 2; i++) {
      q[L][i] = q[L][i] + delta_q[L][i];
    }
    //LEG 2
    pca9685_Leg_1_2_3.setPWM(L2_q1,0,getPWM(q_offset[L][0]+int(rad2deg(q[L][0]))));
    pca9685_Leg_1_2_3.setPWM(L2_q2,0,getPWM(q_offset[L][1]+int(PI - rad2deg(q[L][1]))));
    pca9685_Leg_1_2_3.setPWM(L2_q3,0,getPWM(q_offset[L][2]+int(rad2deg(q[L][2]))));

    L = 3;
    IK(p, q, L);
    for (int i = 0; i <= 2; i++) {
      q[L][i] = q[L][i] + delta_q[L][i];
    }
    //LEG 4 
    pca9685_Leg_4_5_6.setPWM(L4_q1,0,getPWM(q_offset[L][0]+int(rad2deg(q[L][0]))));
    pca9685_Leg_4_5_6.setPWM(L4_q2,0,getPWM(q_offset[L][1]+int(PI - rad2deg(q[L][1]))));
    pca9685_Leg_4_5_6.setPWM(L4_q3,0,getPWM(q_offset[L][2]+int(rad2deg(q[L][2]))));

    L = 5;
    IK(p, q, L);
    for (int i = 0; i <= 2; i++) {
      q[L][i] = q[L][i] + delta_q[L][i];
    }
    //LEG 6
    pca9685_Leg_4_5_6.setPWM(L6_q1,0,getPWM(q_offset[L][0]+int(rad2deg(q[L][0]))));
    pca9685_Leg_4_5_6.setPWM(L6_q2,0,getPWM(q_offset[L][1]+int(PI - rad2deg(q[L][1]))));
    pca9685_Leg_4_2_3.setPWM(L6_q3,0,getPWM(q_offset[L][2]+int(rad2deg(q[L][2]))));
}

