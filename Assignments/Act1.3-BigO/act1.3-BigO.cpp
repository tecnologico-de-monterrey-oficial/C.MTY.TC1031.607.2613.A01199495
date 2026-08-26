//
// Created by Diego Villanueva Fernandez on 26/08/26.
// Matricula: A01199495
//
#include <iostream>
#include <vector>
using namespace std;

int sumaImparesIterativa(const vector<int>& v) {
    int suma = 0;
    for (int i = 0; i < (int)v.size(); i++) {
        if (v[i] % 2 != 0) {
            suma += v[i];
        }
    }
    return suma;
}

int sumaImparesRecursiva(const vector<int>& v, int indice = 0) {
    if (indice >= (int)v.size()) {
        return 0;
    }

    int resto = sumaImparesRecursiva(v, indice + 1);

    if (v[indice] % 2 != 0) {
        return v[indice] + resto;
    } else {
        return resto;
    }
}

int main() {
    vector<int> numeros = {3, 8, 15, 22, 7, 10, 1, 4, 9};

    cout << "Vector: ";
    for (int n : numeros) cout << n << " ";
    cout << endl;

    cout << "Suma de impares (iterativa): "
         << sumaImparesIterativa(numeros) << " -> Orden: O(n)" << endl;

    cout << "Suma de impares (recursiva): "
         << sumaImparesRecursiva(numeros) << " -> Orden: O(n)" << endl;

    return 0;
}