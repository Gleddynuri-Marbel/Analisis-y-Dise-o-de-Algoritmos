#include <iostream>
#include <vector>

using namespace std;
//funcion merge, divide y venceras
//Se combina dos subarreglos ordenados en un único arreglo ordenado.
void merge(vector<int>& arr, int izquierda, int medio, int derecha) {
    int n1 = medio - izquierda + 1;
    int n2 = derecha - medio;

    vector<int> Arrizquierda(n1);
    vector<int> Arrderecha(n2);

    for (int i = 0; i < n1; ++i) {
        Arrizquierda[i]= arr[izquierda + i];
    }

    for (int j = 0; j < n2; ++j) {
        Arrderecha[j] = arr[medio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = izquierda;

    while (i < n1 && j < n2) {
        if (Arrizquierda[i]<= Arrderecha[j]) {
            arr[k] = Arrizquierda[i];
            ++i;
        } else {
            arr[k] = Arrderecha[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = Arrizquierda[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = Arrderecha[j];
        ++j;
        ++k;
    }
}
//implementa el algoritmo de Merge Sort dividiendo recursivamente el arreglo en subarreglos más pequeños 

void mergeSort(vector<int>& arr, int izquierda, int derecha) {
    if (izquierda < derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        mergeSort(arr, izquierda, medio);
        mergeSort(arr, medio + 1, derecha);

        merge(arr, izquierda, medio, derecha);
    }
}

int main() {
    vector<int> arr = {9, 2, 7, 4, 5, 1, 8, 3, 6};
    int size = arr.size();

    mergeSort(arr, 0, size - 1);

    cout << "Arreglo ordenado: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
