#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void cambioMonedas(int n, int P, const vector<int>& monedas, vector<int>& x) {
    vector<vector<int>> D(n + 1, vector<int>(P + 1, INT_MAX));

    for (int i = 0; i <= n; ++i) {
        D[i][0] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= P; ++j) {
            if (monedas[i] <= j) {
                D[i][j] = min(D[i - 1][j], 1 + D[i][j - monedas[i]]);
            } else {
                D[i][j] = D[i - 1][j];
            }
        }
    }

    x.resize(n + 1, 0);
    int i = n, j = P;
    while (i != 0 && j != 0) {
        if (D[i][j] == D[i - 1][j]) {
            i--;
        } else {
            x[i]++;
            j -= monedas[i];
        }
    }
}

int main() {
    int n, P;
    cout << "Ingrese el numero de monedas disponibles: ";
    cin >> n;
    cout << "Ingrese la cantidad que desea pagar: ";
    cin >> P;
    vector<int> monedas(n + 1);
    cout << "Ingrese los valores de las monedas:" << endl;
    for (int i = 1; i <= n; ++i) {
        cin >> monedas[i];
    }

    
    vector<int> x;
    cambioMonedas(n, P, monedas, x);

    cout << "Cantidad de monedas necesarias:" << endl;
    for (int i = 1; i <= n; ++i) {
        cout << "Moneda de valor " << monedas[i] << ": " << x[i] << " monedas" << endl;
    }

    return 0;
}
