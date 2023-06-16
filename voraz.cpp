#include <iostream>
#include <vector>

using namespace std;

int mochila(int W, vector<int>& peso, vector<int>& beneficio, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    //almacenar los subproblemas resueltos y calcula el valor máximo que se puede obtener
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (peso[i - 1] <= w) {
                dp[i][w] = max(beneficio[i - 1] + dp[i - 1][w - peso[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int W = 10;  // Capacidad máxima de la mochila
    vector<int> peso = {1, 2, 4, 5};  // Pesos de los elementos
    vector<int> beneficio = {3, 4, 5, 6};  // Valores de los elementos
    int n = peso.size();  // Número de elementos

    int max_value = mochila(W, peso, beneficio, n);

    cout << "El valor máximo: " << max_value << endl;
    
    return 0;
}