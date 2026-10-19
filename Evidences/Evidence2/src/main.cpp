//
// Created by Diego Villanueva Fernandez on 18/10/26.
// Matricula: A01199495
//

#include <iostream>
#include <fstream>
#include <string>
#include "../include/Log.h"
#include "../include/Queue.h"
#include "../include/DoublyLinkedList.h"

using namespace std;

// Lee las lineas primero en una fila y despues las procesa en orden FIFO.
bool cargarArchivo(const string& ruta, DoublyLinkedList<Log>& registros) {
    ifstream archivo(ruta);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo: " << ruta << "\n";
        return false;
    }

    Queue<string> lineas;
    string linea;
    while (getline(archivo, linea)) {
        lineas.enqueue(linea);
    }
    archivo.close();

    int numeroLinea = 0;
    int omitidas = 0;
    while (!lineas.isEmpty()) {
        linea = lineas.dequeue();
        numeroLinea++;
        Log log;
        string error;
        if (Log::parse(linea, log, error, numeroLinea)) {
            registros.addLast(log);
        } else {
            omitidas++;
            cout << "Linea " << numeroLinea << " omitida: " << error << "\n";
        }
    }

    cout << "\nArchivo: " << ruta << "\n";
    cout << "Registros cargados: " << registros.getSize() << "\n";
    cout << "Lineas omitidas: " << omitidas << "\n";
    return true;
}

int main() {
    cout << "========================================\n";
    cout << "       ANALIZADOR DE LOGS DE RED\n";
    cout << "========================================\n";

    string ruta;
    while (true) {
        cout << "\nSelecciona el archivo que quieres cargar:\n";
        cout << "1. log607-1.txt\n";
        cout << "2. log607-2.txt\n";
        cout << "3. Escribir otra ruta\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";

        string opcion;
        if (!getline(cin, opcion)) return 0;
        if (opcion == "0") return 0;
        if (opcion == "1") ruta = "Evidences/Evidence2/data/log607-1.txt";
        else if (opcion == "2") ruta = "Evidences/Evidence2/data/log607-2.txt";
        else if (opcion == "3") {
            cout << "Ruta del archivo: ";
            if (!getline(cin, ruta)) return 0;
            if (ruta.empty()) {
                cout << "La ruta no puede estar vacia.\n";
                continue;
            }
        } else {
            cout << "Opcion invalida.\n";
            continue;
        }

        DoublyLinkedList<Log> registros;
        if (!cargarArchivo(ruta, registros)) continue;

        cout << "\nPrimeros 5 registros (orden de llegada):\n";
        DoubleNode<Log>* actual = registros.getHead();
        int mostrados = 0;
        while (actual != nullptr && mostrados < 5) {
            cout << actual->data << "\n";
            actual = actual->next;
            mostrados++;
        }
        cout << "\nLectura terminada correctamente.\n";
        break;
    }
    return 0;
}
