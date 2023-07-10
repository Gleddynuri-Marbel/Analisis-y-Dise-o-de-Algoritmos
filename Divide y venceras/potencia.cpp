#include <iostream>
using namespace std;
double potencia(double base, int exponente) {
    // Caso base: exponente es 0
    if (exponente == 0) {
        return 1.0;
    }

    // Dividir el problema a la mitad
    double half = potencia(base, exponente / 2);

    // Caso exponente par
    if (exponente % 2 == 0) {
        return half * half;
    }
    // Caso exponente impar
    else {
        if (exponente > 0) {
            return base * half * half;
        } else {
            return (half * half) / base;
        }
    }
}

int main() {
    double base;
    int exponente;
    cout << "base: ";
    cin >> base;
    cout << "exponente: ";
    cin >> exponente;
    double result = potencia(base, exponente);
    cout << "resultado: " << result << endl;

    return 0;
}