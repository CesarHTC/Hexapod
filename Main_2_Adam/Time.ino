void ciclo() {
  int n = 4;
  if (T <= n * tau) {
    t = T;
  }
  else {
    t = T - int(T / (n * tau)) * (n * tau);
  }
}
float rad2deg(float rad) {
  float deg = rad * 57.2958;
  return deg;
}
