#include <iostream>
#include <vector>

using namespace std;
//funcion merge, divide y venceras
//Se combina dos subarreglos ordenados en un único arreglo ordenado.
void merge(vector<long long>& arr, long long izquierda, long long medio, long long derecha) {
    long long n1 = medio - izquierda + 1;
    long long n2 = derecha - medio;

    vector<long long> Arrizquierda(n1);
    vector<long long> Arrderecha(n2);

    for (long long i = 0; i < n1; ++i) {
        Arrizquierda[i]= arr[izquierda + i];
    }

    for (long long j = 0; j < n2; ++j) {
        Arrderecha[j] = arr[medio + 1 + j];
    }

    long long i = 0,j = 0;
    long long k = izquierda;

    while (i < n1 && j < n2) {
        if (Arrizquierda[i]<= Arrderecha[j]) {
            arr[k] = Arrizquierda[i];
            ++i;
        } else {
            arr[k] = Arrderecha[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = Arrizquierda[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = Arrderecha[j];
        ++j;
        ++k;
    }
}
//implementa el algoritmo de Merge Sort dividiendo recursivamente el arreglo en subarreglos más pequeños 

void mergeSort(vector<long long>& arr, long long izquierda, long long derecha) {
    if (izquierda < derecha) {
        long long medio = izquierda + (derecha - izquierda) / 2;

        mergeSort(arr, izquierda, medio);
        mergeSort(arr, medio + 1, derecha);

        merge(arr, izquierda, medio, derecha);
    }
}

int main() {
    long long a;
    vector<long long> arr;
    vector<long long> mediana;
    
    while(cin>>a){
            arr.push_back(a);
            long long size = arr.size();
            mergeSort(arr, 0, size-1);
            long long v, me;
            v=size/2;
            if(size%2==0){
                me=(arr[v]+arr[v-1])/2;
            }
            else{
                me=arr[v];  
            }
            mediana.push_back(me);
            cout << endl;
        }
        for(long long num:mediana){
            cout<<num<<endl;

        }
    
    return 0;
}