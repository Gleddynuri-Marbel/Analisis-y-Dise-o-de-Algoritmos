#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <ctime>
using namespace std;

//EJERCICIO1
void ec1(int N){
    for(int i=0;i<=N;i++ ){
        if(i%2==0){
            cout<<i;
        }
    }
}
//EJERCICIO2
void ec2(int N){
    for(int i=0;i<=N;i++ )   {
        for(int j=i;j<=N;j++){
            cout<<i<<","<<j<<endl;
        }
    }
}
//FUNCIONES EJEMPLO 3:
// Función para generar un arreglo dinámico con elementos aleatorios
int* generarArregloAleatorio(int size) {
    int* arreglo = new int[size];
    for (int i = 0; i < size; i++) {
        arreglo[i] = rand() % 10; // Genera un número aleatorio entre 0 y 9
    }
    return arreglo;
}

// Función para imprimir un arreglo
void imprimirArreglo(const int* arreglo, int size) {
    for (int i = 0; i < size; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

// Función para sumar los elementos de los arreglos
void Arreglos(const int* arregloA, const int* arregloB, int sizeA, int sizeB) {
    
    for (int i = 0; i < sizeA; i++)
        for (int j = 0; j < sizeB; j++){
            cout<< arregloA[i] <<"," <<arregloB[j]<<endl;
        }
}
//EJEMPLO 4:
void ec4(int N){
    for(int i=0;i<=N;i++)   {
        int j=1;
        while (j<N){
            cout<<j<<endl;
            j=j*2;
        }
    }
}
//EJEMPLO 5:
void ec5(int N){
    for(int i=0;i<=N;i++ )   {
        if(i%2!=0){
            cout<<i;
        }
    }
}
//EJEMPLO 6:
void ec6(int N){ 
    int i;
    while (i<N){
            cout<<i<<endl;
            i=i*2;
        }
}
//EJEMPLO 7:
void ec7(){
    int N=1000;
    int i;
    if(N%2==0){
        cout<<"par";
    }
    else{
        cout<<"impar";
    }
}
int main()
{
    
    int N=5;
    //EJERCICIOS1
    cout<<"\nEJERCICIO 1:"<<endl;
    // Iniciar el cronómetro
    chrono::steady_clock::time_point inicio = chrono::steady_clock::now();

    // Juntar los arreglos
    ec1(N);

    // Detener el cronómetro
    chrono::steady_clock::time_point fin = chrono::steady_clock::now();
    // Calcular la duración en milisegundos
    chrono::duration<double, milli> duracion = fin - inicio;
    // Mostrar el resultado y el tiempo de ejecución
    cout << "\nTiempo de ejecución1: " << duracion.count() << " milisegundos" << endl;


    //EJERCICIOS2
    cout<<"\nEJERCICIO 2:"<<endl;
    // Iniciar el cronómetro
    chrono::steady_clock::time_point inicio2 = chrono::steady_clock::now();

    // Juntar los arreglos
    ec2(N);

    // Detener el cronómetro
    chrono::steady_clock::time_point fin2 = chrono::steady_clock::now();
    // Calcular la duración en milisegundos
    chrono::duration<double, milli> duracion2 = fin2 - inicio2;
    // Mostrar el resultado y el tiempo de ejecución
    cout << "\nTiempo de ejecución1: " << duracion2.count() << " milisegundos" << endl;



    //EJERCICIO 3:
    cout<<"\nEJERCICIO 3:"<<endl;
    srand(static_cast<unsigned int>(time(0))); // Inicializar la semilla de generación de números aleatorios
    int n,m;
    cout << "Ingrese el tamaño de los arreglos A (n): ";
    cin >> n;
    cout << "Ingrese el tamaño de los arreglos B (m): ";
    cin >> m;

    int* arregloA = generarArregloAleatorio(n);
    int* arregloB = generarArregloAleatorio(n);

    // Imprimir arreglos generados
    cout << "Arreglo A: ";
    imprimirArreglo(arregloA, n);

    cout << "Arreglo B: ";
    imprimirArreglo(arregloB, m);

    // Iniciar el cronómetro
    chrono::steady_clock::time_point inicio3 = chrono::steady_clock::now();

    // Juntar los arreglos
    Arreglos(arregloA, arregloB, n, m);

    // Detener el cronómetro
    chrono::steady_clock::time_point fin3 = chrono::steady_clock::now();

    // Calcular la duración en milisegundos
    chrono::duration<double, milli> duracion3 = fin3 - inicio3;

    // Mostrar el resultado y el tiempo de ejecución
    cout << "\nTiempo de ejecución1: " << duracion3.count() << " milisegundos" << endl;
    // Liberar memoria
    delete[] arregloA;
    delete[] arregloB;
    
    
    //EJERCICIO 4
    cout<<"\nEJERCICIO 4:"<<endl;
    // Iniciar el cronómetro
    chrono::steady_clock::time_point inicio4 = chrono::steady_clock::now();

    // Juntar los arreglos
    ec4(N);

    // Detener el cronómetro
    chrono::steady_clock::time_point fin4 = chrono::steady_clock::now();
    // Calcular la duración en milisegundos
    chrono::duration<double, milli> duracion4 = fin4 - inicio4;
    // Mostrar el resultado y el tiempo de ejecución
    cout << "\nTiempo de ejecución1: " << duracion4.count() << " milisegundos" << endl;


    //EJERCICIO 5
    cout<<"\nEJERCICIO 5:"<<endl;
    // Iniciar el cronómetro
    chrono::steady_clock::time_point inicio5 = chrono::steady_clock::now();

    // Juntar los arreglos
    ec5(N);

    // Detener el cronómetro
    chrono::steady_clock::time_point fin5 = chrono::steady_clock::now();
    // Calcular la duración en milisegundos
    chrono::duration<double, milli> duracion5 = fin5 - inicio5;
    // Mostrar el resultado y el tiempo de ejecución
    cout << "\nTiempo de ejecución1: " << duracion5.count() << " milisegundos" << endl;


    //EJERCICIO 6
    cout<<"\nEJERCICIO 6:"<<endl;
    // Iniciar el cronómetro
    chrono::steady_clock::time_point inicio6 = chrono::steady_clock::now();

    // Juntar los arreglos
    ec6(N);

    // Detener el cronómetro
    chrono::steady_clock::time_point fin6 = chrono::steady_clock::now();
    // Calcular la duración en milisegundos
    chrono::duration<double, milli> duracion6 = fin6 - inicio6;
    // Mostrar el resultado y el tiempo de ejecución
    cout << "\nTiempo de ejecución1: " << duracion6.count() << " milisegundos" << endl;


    //EJERCICIO 7
    cout<<"\nEJERCICIO 7:"<<endl;
    // Iniciar el cronómetro
    chrono::steady_clock::time_point inicio7 = chrono::steady_clock::now();

    // Juntar los arreglos
    ec7();

    // Detener el cronómetro
    chrono::steady_clock::time_point fin7 = chrono::steady_clock::now();
    // Calcular la duración en milisegundos
    chrono::duration<double, milli> duracion7 = fin7 - inicio7;
    // Mostrar el resultado y el tiempo de ejecución
    cout << "\nTiempo de ejecución1: " << duracion7.count() << " milisegundos" << endl;


    return 0;
}
