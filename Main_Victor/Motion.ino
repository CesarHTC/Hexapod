void Motion_set_1() {

   Trajectory(p, 0);
   L = 0;
    IK(p, q, L);
    for (int i = 0; i <= 2; i++) {
     q[L][i] = q[L][i] + delta_q[L][i];
    }
    L1_q1.write(q_offset[L][0] + int(rad2deg(q[L][0])));
    L1_q2.write(q_offset[L][1] + int(rad2deg(q[L][1])));
    L1_q3.write(q_offset[L][2] + int(PI - rad2deg(q[L][2])));

    L = 2;
    IK(p, q, L);
    for (int i = 0; i <= 2; i++) {
      q[L][i] = q[L][i] + delta_q[L][i];
    }
    L3_q1.write(q_offset[L][0] + int(rad2deg(q[L][0])));
    L3_q2.write(q_offset[L][1] + int(PI - rad2deg(q[L][1])));
    L3_q3.write(q_offset[L][2] + int(rad2deg(q[L][2])));

    L = 4;
    IK(p, q, L);
    for (int i = 0; i <= 2; i++) {
      q[L][i] = q[L][i] + delta_q[L][i];
    }
    L5_q1.write(q_offset[L][0] + int(rad2deg(q[L][0])));
    L5_q2.write(q_offset[L][1] + int(PI - rad2deg(q[L][1])));
    L5_q3.write(q_offset[L][2] + int(rad2deg(q[L][2])));
    // -------------------------------------------
//  Trajectory(p, 2 * tau);
//  L = 1;
//  IK(p, q, L);
//  for (int i = 0; i <= 2; i++) {
//    q[L][i] = q[L][i] + delta_q[L][i];
//  }
//  L2_q1.write(q_offset[L][0] + int(rad2deg(q[L][0])));
//  L2_q2.write(q_offset[L][1] + int(PI - rad2deg(q[L][1])));
//  L2_q3.write(q_offset[L][2] + int(rad2deg(q[L][2])));
//
//  L = 3;
//  IK(p, q, L);
//  for (int i = 0; i <= 2; i++) {
//    q[L][i] = q[L][i] + delta_q[L][i];
//  }
//  L4_q1.write(q_offset[L][0] + int(rad2deg(q[L][0])));
//  L4_q2.write(q_offset[L][1] + int(PI - rad2deg(q[L][1])));
//  L4_q3.write(q_offset[L][2] + int(rad2deg(q[L][2])));
//
//  L = 5;
//  IK(p, q, L);
//  for (int i = 0; i <= 2; i++) {
//    q[L][i] = q[L][i] + delta_q[L][i];
//  }
//  L6_q1.write(q_offset[L][0] + int(rad2deg(q[L][0])));
//  L6_q2.write(q_offset[L][1] + int(PI - rad2deg(q[L][1])));
//  L6_q3.write(q_offset[L][2] + int(rad2deg(q[L][2])));
  // -------------------------------------------
}
