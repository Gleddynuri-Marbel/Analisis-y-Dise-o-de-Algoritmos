#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int level;
    int beneficio;
    int peso;
    double bound;

    Node(int l, int b, int w, double bd) : level(l), beneficio(b), peso(w), bound(bd) {}
};

bool operator<(const Node &a, const Node &b) {
    return a.bound < b.bound;
}
//calculo de la poda
double calcularBound(int level, int beneficio, int peso, int n, const vector<int> &B, const vector<int> &W, int M) {
    double bound = beneficio;
    int capacidadresto = M - peso;

    while (level < n && W[level] <= capacidadresto) {
        bound += B[level];
        capacidadresto -= W[level];
        level++;
    }

    if (level < n) {
        bound += (double) capacidadresto / W[level] * B[level];
    }

    return bound;
}
//uso de la mochila con fifo
int mochilaLCFIFO(int n, const vector<int> &B, const vector<int> &W, int M) {
    priority_queue<Node> pq;

    Node u(-1, 0, 0, calcularBound(-1, 0, 0, n, B, W, M));
    pq.push(u);

    int maxbeneficio = 0;

    while (!pq.empty()) {
        u = pq.top();
        pq.pop();

        if (u.bound > maxbeneficio) {
            Node v1(u.level + 1, u.beneficio + B[u.level + 1], u.peso + W[u.level + 1], 0);
            v1.bound = calcularBound(v1.level, v1.beneficio, v1.peso, n, B, W, M);

            Node v2(u.level + 1, u.beneficio, u.peso, 0);
            v2.bound = calcularBound(v2.level, v2.beneficio, v2.peso, n, B, W, M);

            if (v1.peso <= M && v1.bound > maxbeneficio) {
                pq.push(v1);
                maxbeneficio = max(maxbeneficio, v1.beneficio);
            }

            if (v2.bound > maxbeneficio) {
                pq.push(v2);
                maxbeneficio = max(maxbeneficio, v2.beneficio);
            }
        }
    }

    return maxbeneficio;
}

int main() {
    int M = 61;
    int n = 5;
    vector<int> W = {1, 11, 21, 23, 33};
    vector<int> B = {11, 21, 31, 33, 43};

    int maxbeneficio = mochilaLCFIFO(n, B, W, M);

    cout << "Max beneficio: " << maxbeneficio << endl;

    return 0;
}
