void Trajectory(float p[3], bool phi) {
  float x_c = 0; // Coordenada x del origen.
  float z_c = 0; // Coordenada z del origen.
  ciclo();
  if (phi && t <= tau / 2) {
    p[0] = x4();
    p[2] = z4(a, b, t, vx);
  }
  else if (phi && t <= tau) {
    p[0] = x5(a, t, vx, x_c);
    p[2] = z5(a, b, t, vx, z_c);
  }
  else if (phi && t <= 2 * tau) {
    p[0] = x6(a, t, vx);
    p[2] = z6();
  }
  else if (phi) {
    t = t + 2 * tau;
    ciclo();
    flag_phi1 = true;
  }
  if (!phi || flag_phi1) {
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
}

// ====================================================

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
float x4() {
  return 0;
}
float z4(float a, float b, float t, float vx) {
  return (b * t * vx * 2.0) / a;
}
float x5(float a, float t, float vx, float x_c) {
  return x_c + a * cos(PI / 2.0 + (vx * (t - a / (vx * 2.0)) * (PI / 2.0 + acos((a + x_c) / a)) * 2.0) / a);
}
float z5(float a, float b, float t, float vx, float z_c) {
  return z_c + b * sin(PI / 2.0 + (vx * (PI / 2.0 + asin(z_c / b)) * (t - a / (vx * 2.0)) * 2.0) / a);
}
float x6(float a, float t, float vx) {
  return -a + vx * (t - a / vx);
}
float z6() {
  return 0;
}
