//
// Created by Diego Villanueva Fernandez on 05/10/26.
// Matricula: A01199495
//
#include "Queue.h"
#include "../Act2.1-LinkedList/Node.h"
#include <iostream>
#include <string>

using namespace std;

struct Cliente {
    string nombre;
    int boletos;
};

int main() {

    Queue<Cliente> fila;

    int op = 0;

    while (op !=5) {
        cout << endl;
        cout << " TAQUILLA DE BOLETOS" << endl;
        cout << "1. nuevo cliente" << endl;
        cout << "2. Atender siguiente cliente" << endl;
        cout << "3. ver sig cliente" << endl;
        cout << "4. Cuantas personas hay en fila" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        cin >> op;

        try {
            switch (op) {

                case 1: {
                    Cliente nuevo;
                    cout <<" Nombre: ";
                    cin >> nuevo.nombre;

                    cout <<"# boletos: ";
                    cin >> nuevo.boletos;

                    fila.push(nuevo);

                    cout << "Cliente ingresado a la fila";
                    break;
                }
                case 2: {
                    Cliente atendido = fila.pop();
                    cout << "Atendiendo a: " << atendido.nombre << endl;
                    cout << "Boletos solicitados: " << atendido.boletos << endl;
                    break;
                }
                case 3: {
                    Cliente siguiente = fila.front();
                    cout << "Siguiente Cliente: " << siguiente.nombre << endl;
                    cout << "Boletos solicitados: " << siguiente.boletos << endl;
                    break;
                }
                case 4: {
                    cout << "Personas en la fila: " << fila.getSize() << endl;
                    break;
                }
                case 5: {
                    cout << "Saliendooooo" << endl;
                    break;
                }
                default: {
                    cout << "invalido" << endl;
                    break;
                }
            }
        }
        catch (const out_of_range& error) {
            cout << "Error: " << error.what() << endl;
        }
    }
    return 0;
}
