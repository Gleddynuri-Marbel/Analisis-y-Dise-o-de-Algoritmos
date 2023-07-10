#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> matrizsuma(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

vector<vector<int>> matrizresta(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

vector<vector<int>> multiplicacionmatrizstrassen(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    // Caso base: matrices de 1x1
    if (n == 1) {
        result[0][0] = A[0][0] * B[0][0];
        return result;
    }

    // Dividir las matrices en submatrices más pequeñas
    int mitad = n / 2;

    vector<vector<int>> A11(mitad, vector<int>(mitad, 0));
    vector<vector<int>> A12(mitad, vector<int>(mitad, 0));
    vector<vector<int>> A21(mitad, vector<int>(mitad, 0));
    vector<vector<int>> A22(mitad, vector<int>(mitad, 0));

    vector<vector<int>> B11(mitad, vector<int>(mitad, 0));
    vector<vector<int>> B12(mitad, vector<int>(mitad, 0));
    vector<vector<int>> B21(mitad, vector<int>(mitad, 0));
    vector<vector<int>> B22(mitad, vector<int>(mitad, 0));

    for (int i = 0; i < mitad; ++i) {
        for (int j = 0; j < mitad; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mitad];
            A21[i][j] = A[i + mitad][j];
            A22[i][j] = A[i + mitad][j + mitad];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mitad];
            B21[i][j] = B[i + mitad][j];
            B22[i][j] = B[i + mitad][j + mitad];
        }
    }

    // Cálculo de las submatrices del resultado
    vector<vector<int>> P1 = multiplicacionmatrizstrassen(matrizsuma(A11, A22), matrizsuma(B11, B22));
    vector<vector<int>> P2 = multiplicacionmatrizstrassen(matrizsuma(A21, A22), B11);
    vector<vector<int>> P3 = multiplicacionmatrizstrassen(A11, matrizresta(B12, B22));
    vector<vector<int>> P4 = multiplicacionmatrizstrassen(A22, matrizresta(B21, B11));
    vector<vector<int>> P5 = multiplicacionmatrizstrassen(matrizsuma(A11, A12), B22);
    vector<vector<int>> P6 = multiplicacionmatrizstrassen(matrizresta(A21, A11), matrizsuma(B11, B12));
    vector<vector<int>> P7 = multiplicacionmatrizstrassen(matrizresta(A12, A22), matrizsuma(B21, B22));

    vector<vector<int>> C11 = matrizsuma(matrizresta(matrizsuma(P1, P4), P5), P7);
    vector<vector<int>> C12 = matrizsuma(P3, P5);
    vector<vector<int>> C21 = matrizsuma(P2, P4);
    vector<vector<int>> C22 = matrizsuma(matrizresta(matrizsuma(P1, P3), P2), P6);

    for (int i = 0; i < mitad; ++i) {
        for (int j = 0; j < mitad; ++j) {
            result[i][j] = C11[i][j];
            result[i][j + mitad] = C12[i][j];
            result[i + mitad][j] = C21[i][j];
            result[i + mitad][j + mitad] = C22[i][j];
        }
    }

    return result;
}

// Función para imprimir una matriz
void printmatriz(const vector<vector<int>>& matriz) {
    int n = matriz.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> A = {
        {1, 2, 3, 4},
        {5, 3, 3, 2},
        {9, 1, 6, 3},
        {3, 4, 5, 1}
    };

    vector<vector<int>> B = {
        {7, 4, 1, 2},
        {4, 7, 3, 2},
        {2, 6, 2, 8},
        {9, 5, 3, 3}
    };

    vector<vector<int>> C = multiplicacionmatrizstrassen(A, B);
    cout << "matriz A:\n";
    printmatriz(A);

    cout << "matriz B:\n";
    printmatriz(B);

    cout << "A X B:\n";
    printmatriz(C);

    return 0;
}
