void Initialization_set_1() {
  int Pin[6][3] = {
    {28, 29, 30}, // Definir L1
    {25, 26, 27}, // Definir L2
    {22, 23, 24},  // Definir L3
    {31, 32, 33}, // Definir L4
    {34, 35, 36}, // Definir L5
    {37, 38, 39}, // Definir L6
  };
  // -------------------------------------------
  L = 0;
  L1_q1.attach(Pin[L][0]);
  L1_q1.writeMicroseconds(1500);
  L1_q1.write(q_offset[L][0]);

  L1_q2.attach(Pin[L][1]);
  L1_q2.writeMicroseconds(1500);
  L1_q2.write(q_offset[L][1]);

  L1_q3.attach(Pin[L][2]);
  L1_q3.writeMicroseconds(1500);
  L1_q3.write(q_offset[L][2]);
  // -------------------------------------------
  L = 1;
  L2_q1.attach(Pin[L][0]);
  L2_q1.writeMicroseconds(1500);
  L2_q1.write(q_offset[L][0]);

  L2_q2.attach(Pin[L][1]);
  L2_q2.writeMicroseconds(1500);
  L2_q2.write(q_offset[L][1]);

  L2_q3.attach(Pin[L][2]);
  L2_q3.writeMicroseconds(1500);
  L2_q3.write(q_offset[L][2]);
  // -------------------------------------------
  L = 2;
  L3_q1.attach(Pin[L][0]);
  L3_q1.writeMicroseconds(1500);
  L3_q1.write(q_offset[L][0]);

  L3_q2.attach(Pin[L][1]);
  L3_q2.writeMicroseconds(1500);
  L3_q2.write(q_offset[L][1]);

  L3_q3.attach(Pin[L][2]);
  L3_q3.writeMicroseconds(1500);
  L3_q3.write(q_offset[L][2]);
  // -------------------------------------------
  L = 3;
  L4_q1.attach(Pin[L][0]);
  L4_q1.writeMicroseconds(1500);
  L4_q1.write(q_offset[L][0]);

  L4_q2.attach(Pin[L][1]);
  L4_q2.writeMicroseconds(1500);
  L4_q2.write(q_offset[L][1]);

  L4_q3.attach(Pin[L][2]);
  L4_q3.writeMicroseconds(1500);
  L4_q3.write(q_offset[L][2]);
  // -------------------------------------------
  L = 4;
  L5_q1.attach(Pin[L][0]);
  L5_q1.writeMicroseconds(1500);
  L5_q1.write(q_offset[L][0]);

  L5_q2.attach(Pin[L][1]);
  L5_q2.writeMicroseconds(1500);
  L5_q2.write(q_offset[L][1]);

  L5_q3.attach(Pin[L][2]);
  L5_q3.writeMicroseconds(1500);
  L5_q3.write(q_offset[L][2]);

  // -------------------------------------------
  L = 5;
  L6_q1.attach(Pin[L][0]);
  L6_q1.writeMicroseconds(1500);
  L6_q1.write(q_offset[L][0]);

  L6_q2.attach(Pin[L][1]);
  L6_q2.writeMicroseconds(1500);
  L6_q2.write(q_offset[L][1]);

  L6_q3.attach(Pin[L][2]);
  L6_q3.writeMicroseconds(1500);
  L6_q3.write(q_offset[L][2]);
}
