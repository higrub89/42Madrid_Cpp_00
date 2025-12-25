#include "operaciones.h"
double suma(double a, double b) { return a + b; }
double potencia(double base, int exp) {
    double res = 1;
    for(int i = 0; i < exp; ++i) res *= base;
    return res;
}
double calcular_potencia(double par, double rpm) {
    // Fórmula: Potencia (kW) = (Par × RPM) / 9549
    return (par * rpm) / 9549.0;
}