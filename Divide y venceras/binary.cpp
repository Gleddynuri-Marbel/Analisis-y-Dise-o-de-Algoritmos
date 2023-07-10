#include <iostream>
#include <vector>
using namespace std;
int busqueda_binaria(const vector<int>& arr, int buscado) {
    int izq = 0;
    int der = arr.size() - 1;

    while (izq <= der) {
        int medio = izq + (der - izq) / 2;

        if (arr[medio] == buscado) {
            return medio;
        } else if (arr[medio] < buscado) {
            izq = medio + 1;
        } else {
            der = medio - 1;
        }
    }
    // Si el elemento buscado no esta
    return -1;
}

int main() {
    vector<int> arr = {1, 2, 3, 12, 16, 36, 39, 60, 72, 98};
    int buscado = 60;

    int indice = busqueda_binaria(arr, buscado);

    if (indice != -1) {
        cout << buscado << " se encuentra en el índice " << indice << endl;
    } else {
        cout << buscado << " no se encontró en el arreglo" << endl;
    }

    return 0;
}
