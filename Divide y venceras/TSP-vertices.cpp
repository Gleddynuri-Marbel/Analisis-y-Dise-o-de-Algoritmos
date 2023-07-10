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
// Función para encontrar la ciudad más cercana a un subconjunto de ciudades
int ciudad_cercana(const vector<ciudad>& ciudades, const vector<bool>& visitado, int ciudad_actual) {
    int ciudad_mas_cerca = -1;
    double mindist = INF;

    for (size_t i = 0; i < ciudades.size(); ++i) {
        if (!visitado[i] && i != ciudad_actual) {
            double dist = distancia(ciudades[ciudad_actual], ciudades[i]);
            if (dist < mindist) {
                mindist = dist;
                ciudad_mas_cerca = i;
            }
        }
    }
    return ciudad_mas_cerca;
}

// Función para resolver el problema del viajante utilizando la heurística de inserción de vértices
vector<int> tsp_heuristico(const vector<ciudad>& ciudades) {
    int numciudades = ciudades.size();
    vector<bool> visitado(numciudades, false);
    // Elegir la primera ciudad aleatoriamente
    int ciudad_actual = rand() % numciudades;
    visitado[ciudad_actual] = true;
    vector<int> ruta;
    ruta.push_back(ciudad_actual);
    while (ruta.size() < numciudades) {
        int ciudad_mas_cerca = ciudad_cercana(ciudades, visitado, ciudad_actual);
        visitado[ciudad_mas_cerca] = true;
        ruta.push_back(ciudad_mas_cerca);
        ciudad_actual = ciudad_mas_cerca;
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
        {0.0, 1.0},
        {1.0, 3.0},
        {3.0, 1.0},
        {2.0, 3.0},
        {4.0, 3.0},
        {0.0, 4.0}
    };
    vector<int> ruta = tsp_heuristico(ciudades);
    imprimir_ruta(ruta);
    return 0;
}
