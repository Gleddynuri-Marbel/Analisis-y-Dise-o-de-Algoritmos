#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;
const double INF = numeric_limits<double>::infinity();
// Estructura para representar una ciudad
struct ciudad {
    double x;
    double y;
    ciudad(double _x, double _y) : x(_x), y(_y) {}
};
// Función para calcular la distancia euclidiana entre dos ciudades
double distancia(const ciudad& ciudad1, const ciudad& ciudad2) {
    double dx = ciudad1.x - ciudad2.x;
    double dy = ciudad1.y - ciudad2.y;
    return sqrt(dx * dx + dy * dy);
}
// Función para encontrar la arista más corta entre dos conjuntos de ciudades
pair<int, int> arista_mas_corta(const vector<vector<double>>& distancias, const vector<bool>& visitado, const vector<int>& currentruta) {
    int num_ciudades = visitado.size();
    double min_distancia = INF;
    pair<int, int> arista_corta;
    for (int i = 0; i < num_ciudades; ++i) {
        if (visitado[i]) {
            for (int j = 0; j < num_ciudades; ++j) {
                if (!visitado[j]) {
                    double distance = distancias[i][j];
                    if (distance < min_distancia) {
                        min_distancia = distance;
                        arista_corta = make_pair(i, j);
                    }
                }
            }
        }
    }
    return arista_corta;
}
// Función para resolver el problema del viajante utilizando la heurística de inserción de aristas
vector<int> tsp_heuristica(const vector<ciudad>& ciudades) {
    int num_ciudades = ciudades.size();
    vector<bool> visitado(num_ciudades, false);
    // Elegir la primera ciudad aleatoriamente
    int ciudad_actual = rand() % num_ciudades;
    visitado[ciudad_actual] = true;
    vector<int> ruta;
    ruta.push_back(ciudad_actual);
    vector<vector<double>> distancias(num_ciudades, vector<double>(num_ciudades));
    // Calcular todas las distancias entre ciudades
    for (int i = 0; i < num_ciudades; ++i) {
        for (int j = 0; j < num_ciudades; ++j) {
            distancias[i][j] = distancia(ciudades[i], ciudades[j]);
        }
    }
    while (ruta.size() < num_ciudades) {
        pair<int, int> arista_corta = arista_mas_corta(distancias, visitado, ruta);
        visitado[arista_corta.second] = true;
        ruta.push_back(arista_corta.second);
    }
    // Regresar a la ciudad inicial
    ruta.push_back(ruta[0]);

    return ruta;
}
// Función para imprimir la ruta del viajante
void imprimir_ruta(const vector<int>& ruta) {
    cout << "Ruta del viajante: ";
    for (int ciudad : ruta) {
        cout << ciudad << " ";
    }
    cout << endl;
}
int main() {
    vector<ciudad> ciudades = {
        {0.0, 0.0},
        {1.0, 2.0},
        {2.0, 3.0},
        {4.0, 4.0}
    };
    vector<int> ruta = tsp_heuristica(ciudades);
    imprimir_ruta(ruta);
    return 0;
}
