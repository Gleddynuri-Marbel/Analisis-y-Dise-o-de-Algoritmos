#include <iostream>
#include <vector>

using namespace std;

//selecciona un pivote y reorganiza los elementos del arreglo de tal manera que todos los elementos menores o iguales al pivote estén antes que él

int particion(vector<int>& arr, int izquierda, int derecha) {
    int pivot = arr[derecha];
    int i = izquierda - 1;

    for (int j = izquierda; j <= derecha - 1; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[derecha]);
    return i + 1;
}
//dividiendo recursivamente el arreglo en subarreglos más pequeños utilizando la función particion.
void quickSort(vector<int>& arr, int izquierda, int derecha) {
    if (izquierda < derecha) {
        int pivotIndex = particion(arr, izquierda, derecha);

        quickSort(arr, izquierda, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, derecha);
    }
}

int main() {
    vector<int> arr = {9, 2, 5, 4, 10, 1, 8, 3, 6};
    int size = arr.size();

    quickSort(arr, 0, size - 1);

    cout << "Arreglo ordenado: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
