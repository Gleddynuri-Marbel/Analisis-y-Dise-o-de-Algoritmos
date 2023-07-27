#include <iostream>
#include <vector>

using namespace std;

int mochila(int n, int P, const vector<int>& peso, const vector<int>& valores, vector<int>& seleccionado) {
    vector<vector<int>> V(n + 1, vector<int>(P + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= P; ++j) {
            if (peso[i] <= j) {
                V[i][j] = max(V[i - 1][j], V[i - 1][j - peso[i]] + valores[i]);
            } else {
                V[i][j] = V[i - 1][j];
            }
        }
    }

    seleccionado.resize(n + 1, 0);
    int j = P;
    for (int i = n; i >= 1; --i) {
        if (V[i][j] != V[i - 1][j]) {
            seleccionado[i] = 1;
            j -= peso[i];
        }
    }

    return V[n][P];
}

int main() {
    int n, P;
    cout << "Ingrese el numero de elementos: ";
    cin >> n;

    cout << "Ingrese la capacidad maxima de la mochila: ";
    cin >> P;

    vector<int> peso(n + 1), valores(n + 1);
    cout << "Ingrese los pesos de los elementos:" << endl;
    for (int i = 1; i <= n; ++i) {
        cin >> peso[i];
    }

    cout << "Ingrese los valores de los elementos:" << endl;
    for (int i = 1; i <= n; ++i) {
        cin >> valores[i];
    }

    vector<int> seleccionado;
    int maxValue = mochila(n, P, peso, valores, seleccionado);

    cout << "Valor maximo obtenido: " << maxValue << endl;
    cout << "Elementos seleccionados: ";
    for (int i = 1; i <= n; ++i) {
        if (seleccionado[i] == 1) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
