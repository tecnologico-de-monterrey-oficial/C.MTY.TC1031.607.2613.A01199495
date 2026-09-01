//
// Created by Diego Villanueva Fernandez on 31/08/26.
// Matricula: A01199495
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

int busquedaSecuencial(vector<int> &lista, int target) {
    for (int i = 0; i < lista.size(); i++) {
        if (lista[i] == target) return i;
    }
    return -1;
}

int busquedaBinaria(vector<int> &lista, int target) {
    int low = 0, high = lista.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (lista[mid] == target) return mid;
        if (lista[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    srand(time(0));
    vector<int> numeros(10000);
    for (int i = 0; i < 10000; i++) {
        numeros[i] = rand() % 1000000 + 1;
    }
    sort(numeros.begin(), numeros.end());

    int num;
    do {
        cout << "Ingresa un numero entre 1 y 1000000 (0 para salir): ";
        cin >> num;
        if (num == 0) break;

        auto inicio1 = high_resolution_clock::now();
        int pos1 = busquedaSecuencial(numeros, num);
        auto fin1 = high_resolution_clock::now();
        auto duracion1 = duration_cast<nanoseconds>(fin1 - inicio1);

        auto inicio2 = high_resolution_clock::now();
        int pos2 = busquedaBinaria(numeros, num);
        auto fin2 = high_resolution_clock::now();
        auto duracion2 = duration_cast<nanoseconds>(fin2 - inicio2);

        if (pos1 != -1) cout << num << " se encuentra en la lista." << endl;
        else cout << num << " no se encuentra en la lista." << endl;

        cout << "Busqueda secuencial: " << duracion1.count() << " ns" << endl;
        cout << "Busqueda binaria: " << duracion2.count() << " ns" << endl;

    } while (num != 0);

    return 0;
}