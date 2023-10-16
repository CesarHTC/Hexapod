float delta_q[6][3] = {
  {0, 0, 0}, // Definir L1
  {0, 0, 0}, // Definir L2
  {0, 0, 0}, // Definir L3
  {0, 0, 0}, // Definir L4
  {0, 0, 0}, // Definir L5
  {0, 0, 0} // Definir L6
};
//========================================================
void IK(float p[3], float q[6][5], int L) {
  float q1 = q[L][0];
  float q2 = q[L][1];
  float q3 = q[L][2];
  float q4 = q[L][3];
  float q5 = q[L][4];
  float px = p[0];
  float py = p[1];
  float pz = p[2];
  float x1 = 81.5;
  float x2 = 43;
  float x3 = 77.04;
  float x4 = 52.87;
  float x5 = 254.41; // Curva de la x
  float z2 = 0;
  float z3 = 21.76;
  float z4 = -123.53;
  float z5 = -101.97;
  // ----------------Calculation of the joint variable q1 -------------------
  float d1 = sign((py * cos(q1 + q4 - q5) - px * sin(q1 + q4 - q5)
                   + x1 * sin(q1) - x5 * sin(q1)) * (x2 + x4 * cos(q2 + q3)
                       + z4 * sin(q2 + q3) + x3 * cos(q2) + z3 * sin(q2)));
  float delta_q1 = -d1 * abs(acos(S2(((px * cos(q1 + q4 - q5) + py * sin(q1
                                      + q4 - q5) - x1 * cos(q1) + x5 * cos(q1)) * (x2 + x4 * cos(q2 + q3)
                                          + z4 * sin(q2 + q3) + x3 * cos(q2) + z3 * sin(q2))) / S2((abs(x2
                                              + x4 * cos(q2 + q3) + z4 * sin(q2 + q3) + x3 * cos(q2)
                                              + z3 * sin(q2)) * sqrt(S1(pow(px, 2) - 2 * cos(q4 - q5) * px * x1 + 2 * cos(q4
                                                  - q5) * px * x5 + pow(py, 2) - 2 * sin(q4 - q5) * py * x1 + 2 * sin(q4
                                                      - q5) * py * x5 + pow(x1, 2) - 2 * x1 * x5 + pow(x5, 2))))))));
  float d3 = 1;
  float delta_q3 = d3 * (acos(S2((pow(x3, 2) - pow((x5 - x1 - x2 * cos(q1) + px * cos(q4
                                  - q5) + py * sin(q4 - q5)), 2) - pow((pz - z2 + z5), 2) - pow((x2 * sin(q1)
                                      - py * cos(q4 - q5) + px * sin(q4 - q5)), 2) + pow(x4, 2) + pow(z3, 2)
                                  + pow(z4, 2)) / S2((2 * sqrt(pow(x3, 2) + pow(z3, 2)) * sqrt(pow(x4, 2) + pow(z4, 2))))))
                         - PI + acos(S2((x3 * x4 * cos(q3) + z3 * z4 * cos(q3) + x3 * z4 * sin(q3)
                                         - x4 * z3 * sin(q3)) / (sqrt(pow(x3, 2) + pow(z3, 2)) * sqrt(pow(x4, 2) + pow(z4, 2))))));
  float d2 = sign((z4 * cos(q2 + q3) - x4 * sin(q2 + q3) + z3 * cos(q2) - x3 * sin(q2)) * (x5 - x1 - x2 * cos(q1)
                  + px * cos(q4 - q5) + py * sin(q4 - q5)) - cos(q1) * (pz - z2 + z5) * (x4 * cos(q2 + q3) + z4 * sin(q2 + q3)
                      + x3 * cos(q2) + z3 * sin(q2)));
  float delta_q2 = -d2 * abs(acos(S2(((pz - z2 + z5) * (z4 * cos(q2 + q3) - x4 * sin(q2 + q3) + z3 * cos(q2) - x3 * sin(q2))
                                     + cos(q1) * (x4 * cos(q2 + q3) + z4 * sin(q2 + q3) + x3 * cos(q2) + z3 * sin(q2)) * (x5 - x1 - x2 * cos(q1)
                                         + px * cos(q4 - q5) + py * sin(q4 - q5))) / (sqrt(S1(pow((x5 - x1 - x2 * cos(q1) + px * cos(q4 - q5) + py * sin(q4 - q5)), 2)
                                             + pow((pz - z2 + z5), 2))) * sqrt(S1(pow((z4 * cos(q2 + q3) - x4 * sin(q2 + q3) + z3 * cos(q2) - x3 * sin(q2)), 2)
                                                 + pow(cos(q1), 2) * pow((x4 * cos(q2 + q3) + z4 * sin(q2 + q3) + x3 * cos(q2) + z3 * sin(q2)), 2)))))));
    if (isnan(delta_q1)) {
      delta_q1 = 0.0;
    }
    if (isnan(delta_q2)) {
      delta_q2 = 0.0;
    }
    if (isnan(delta_q3)) {
      delta_q3 = 0.0;
    }
  delta_q[L][0] = delta_q1;
  delta_q[L][1] = delta_q2;
  delta_q[L][2] = delta_q3;
}

// Truncated Sigmoid Function

float S1(float x) {
//  if (x < 0) {
//    x = 0.0;
//  }
  return x;
}

float S2(float x) {
//  if (abs(x) > 1) {
//    x = sign(x) * 1;
//  }
  return x;
}