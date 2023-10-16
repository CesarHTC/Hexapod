void ciclo(float T, float phi) {
  if (T >= 10 * tau * 1000) {
    T = 0.0;
  }
  T = T + phi;
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



float sign(float valor) {
  if (valor > 0) {
    return 1; // Positivo
  } else if (valor < 0) {
    return -1; // Negativo
  } else {
    return 0; // Cero
  }
}
