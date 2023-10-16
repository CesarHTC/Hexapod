void Trajectory(float p[3], float phi) {
  float x_c = 0;
  float z_c = 0;
  ciclo(T,phi);
    if (t <= tau) {
      p[0] = x1(vx, t);
      p[2] = z1();
    }
    else if (t <= 3 * tau) {
      p[0] = x2(a, t, vx, x_c);
      p[2] = z2(a, b, t, vx, z_c);
    }
    else if (t <= 4 * tau) {
      p[0] = x3(a, t, vx);
      p[2] = z3();
  }
}
// ====================================================
float x1(float vx, float t) {
  return vx * t;
}
float z1() {
  return 0;
}
float x2(float a, float t, float vx, float x_c) {
  return x_c + a * cos(((a - t * vx) * (PI - acos((a + x_c) / a))) / (a * 2.0));
}
float z2(float a, float b, float t, float vx, float z_c) {
  return z_c - b * sin(((a - t * vx) * (PI + asin(z_c / b))) / (a * 2.0));
}
float x3(float a, float t, float vx) {
  return -a + vx * (t - (a * 3.0) / vx);
}
float z3() {
  return 0;
}
