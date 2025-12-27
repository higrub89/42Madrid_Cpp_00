#include <iostream>
#include "telemetria.h"

int main() {
    // Elimina el "std::" delante de double
    double p = calcular_potencia(100, 5000) * FACTOR_CORRECCION; 
    
    // Usa std::cout para que el flag -Wall no te dé error por variable sin uso
    std::cout << "Potencia calculada: " << p << std::endl; 
    
    return 0;
}