#include <iostream>
#include <vector>

using namespace std;

struct Item {
    int peso;
    int beneficio;
};

class mochila {
private:
    vector<Item> items;
    int capacidad;
    int maxTotalbeneficio;

    void combinacion(int index, int pesoactual, int totalbeneficio) {
        if (index >= items.size()) {
            if (pesoactual <= capacidad) {
                maxTotalbeneficio = max(maxTotalbeneficio, totalbeneficio);
            }
            return;
        }

        combinacion(index + 1, pesoactual, totalbeneficio); // Exclude current item

        if (pesoactual + items[index].peso <= capacidad) {
            combinacion(index + 1, pesoactual + items[index].peso, totalbeneficio + items[index].beneficio); // Include current item
        }
    }

public:
    mochila(const vector<Item>& items, int capacidad) : items(items), capacidad(capacidad), maxTotalbeneficio(0) {}

    int resolucion() {
        combinacion(0, 0, 0);
        return maxTotalbeneficio;
    }
};

int main() {
    vector<Item> items = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    int capacidad = 7;

    mochila mochila(items, capacidad);
    int maxbeneficio = mochila.resolucion();

    cout << "maxiomo beneficio: " << maxbeneficio << endl;

    return 0;
}



