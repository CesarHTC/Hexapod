void IK(float p[3], float q[6][5],int L) {
    float q4 = q[L][3];
    float q5 = q[L][4];
    float px = p[0];
    float py = p[1];
    float pz = p[2];
    float x1 = 81.5;
    float x2 = 43;
    float x3 = 77.04;
    float x4 = 52.87;
    float x5 = 254.41; // x Curve
    float z2 = 0;
    float z3 = 21.76;
    float z4 = -123.53;
    float z5 = -101.97; // z Curve
    // ----------------Calculation of the joint variable q1 -------------------
    float d1 = sign((py * cos(q4 - q5) - px * sin(q4 - q5)) * (x2 + x3 + x4));
    q[L][0] = d1 * abs(acos(((x2 + x3 + x4) * (x5 - x1 + px * cos(q4 - q5)
                    + py * sin(q4 - q5))) / (abs(x2 + x3 + x4) * sqrt(pow(py * cos(q4 - q5) - px * sin(q4 - q5),2)
                    + pow(x5 - x1 + px * cos(q4 - q5) + py * sin(q4 - q5),2)))));

    // ----------------Calculation of the joint variable q3 -------------------
    float d3 = -1;
    q[L][2] = d3 * (acos((x3 * x3 - pow(pz - z2 + z5,2) - pow(x5 - x2 - x1 + px * cos(q4 - q5)
                    + py * sin(q4 - q5),2) - pow(py * cos(q4 - q5) - px * sin(q4 - q5),2)
                    + pow(x4,2) + pow(z3,2) + pow(z4,2)) / (2 * sqrt(pow(x3,2) + pow(z3,2)) * sqrt(pow(x4,2) + pow(z4,2))))
                    - PI + acos((x3 * x4 + z3 * z4) / (sqrt(pow(x3,2) + pow(z3,2)) * sqrt(pow(x4,2) + pow(z4,2)))));
                    
    // ----------------Calculation of the joint variable q2 -------------------
    float d2 = -sign((x3 + x4) * (pz - z2 + z5) - (z3 + z4) * (x5 - x2 - x1 + px * cos(q4 - q5)
                    + py * sin(q4 - q5)));
    q[L][1] = -d2 * abs(acos(((z3 + z4) * (pz - z2 + z5) + (x3 + x4) * (x5 - x2 - x1 + px * cos(q4 - q5)
                    + py * sin(q4 - q5))) / (sqrt(pow(abs(pz - z2 + z5),2) + pow(abs(x5 - x2 - x1 + px * cos(q4 - q5)
                    + py * sin(q4 - q5)),2)) * sqrt(pow(abs(x3 + x4),2) + pow(abs(z3 + z4),2)))));

}
//=============================================================================
float sign(float valor) {
    if (valor > 0) {
        return 1; // Positivo
    } else if (valor < 0) {
        return -1; // Negativo
    } else {
        return 0; // Cero
    }
}
