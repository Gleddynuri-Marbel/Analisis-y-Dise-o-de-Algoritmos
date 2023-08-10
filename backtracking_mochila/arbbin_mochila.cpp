#include <iostream>
#include <vector>

using namespace std;
// se usa la estructura para los item de peso y beneficio
struct Item {
    int peso;
    int beneficio;
};

class mochilabinarytree {
private:
    vector<Item> items;
    int capacidad;
    int n;
    int maxTotalbeneficio;

    void combinar(int level, int pact, int bact) {
        if (level == n) {
            maxTotalbeneficio = max(maxTotalbeneficio, pact);
            return;
        }

        // Exclude the current item
        combinar(level + 1, pact, bact);

        // Include the current item if it fits
        if (bact + items[level].peso <= capacidad) {
            combinar(level + 1, pact + items[level].beneficio, bact + items[level].peso);
        }
    }

public:
    mochilabinarytree(const vector<Item>& items, int capacidad) : items(items), capacidad(capacidad) {
        n = items.size();
        maxTotalbeneficio = 0;
    }

    int resolver() {
        combinar(0, 0, 0);
        return maxTotalbeneficio;
    }
};

int main() {
    vector<Item> items = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    int capacidad = 7;

    mochilabinarytree mochila(items, capacidad);
    int maxbeneficio = mochila.resolver();

    cout << "Msximo beneficio: " << maxbeneficio << endl;

    return 0;
}
