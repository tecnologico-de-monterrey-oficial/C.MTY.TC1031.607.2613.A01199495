//
// Created by Diego Villanueva Fernandez on 18/10/26.
// Matricula: A01199495
//

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <cmath>
#include <filesystem>
#include <iomanip>
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

// Guarda todos los registros en el formato original.
bool guardarOrdenados(const DoublyLinkedList<Log>& registros) {
    const string rutaSalida = "Evidences/Evidence2/out/output608.out";
    ofstream salida(rutaSalida);
    if (!salida.is_open()) {
        cout << "No se pudo crear " << rutaSalida << "\n";
        return false;
    }
    for (DoubleNode<Log>* actual = registros.getHead(); actual != nullptr; actual = actual->next) {
        salida << actual->data.toString() << '\n';
    }
    cout << "Archivo generado: " << rutaSalida << "\n";
    return true;
}

void ordenarLogs(DoublyLinkedList<Log>& registros, const string& ruta) {
    if (registros.isSorted()) {
        cout << "\nLa lista ya esta ordenada cronologicamente.\n";
        guardarOrdenados(registros);
        return;
    }

    string prediccion;
    while (true) {
        cout << "\nQue crecimiento de comparaciones esperas?\n";
        cout << "1. n log n\n";
        cout << "2. n^2\n";
        cout << "Prediccion: ";
        if (!getline(cin, prediccion)) return;
        if (prediccion == "1" || prediccion == "2") break;
        cout << "Opcion invalida, intenta otra vez.\n";
    }

    long long comparaciones = 0;
    int profundidad = 0;
    auto inicio = chrono::steady_clock::now();
    registros.sort(comparaciones, profundidad);
    auto fin = chrono::steady_clock::now();
    double milisegundos = chrono::duration<double, milli>(fin - inicio).count();

    cout << "\n========== RESULTADOS DEL ORDENAMIENTO ==========\n";
    cout << "Algoritmo: Merge Sort (estable)\n";
    cout << "Archivo: " << ruta << '\n';
    cout << "Registros: " << registros.getSize() << '\n';
    cout << fixed << setprecision(3);
    cout << "Tiempo: " << milisegundos << " ms\n";
    cout << "Comparaciones: " << comparaciones << '\n';
    cout << "Profundidad maxima de recursion: " << profundidad << '\n';
    cout << "Prediccion: " << (prediccion == "1" ? "n log n" : "n^2") << '\n';
    cout << "Coincidio con el crecimiento teorico del algoritmo: "
         << (prediccion == "1" ? "Si" : "No") << '\n';
    cout << "Orden cronologico correcto: " << (registros.isSorted() ? "Si" : "No") << '\n';
    guardarOrdenados(registros);
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

        while (true) {
            cout << "\n========================================\n";
            cout << "               MENU PRINCIPAL\n";
            cout << "========================================\n";
            cout << "1. Ordenar logs por fecha y hora\n";
            cout << "2. Buscar logs por dia (proximamente)\n";
            cout << "3. Mostrar por dia en orden descendente (proximamente)\n";
            cout << "4. Estadisticas del archivo (proximamente)\n";
            cout << "5. Salir\n";
            cout << "Opcion: ";
            string opcionMenu;
            if (!getline(cin, opcionMenu)) return 0;
            if (opcionMenu == "1") {
                ordenarLogs(registros, ruta);
            } else if (opcionMenu == "5") {
                cout << "Hasta luego.\n";
                return 0;
            } else if (opcionMenu == "2" || opcionMenu == "3" || opcionMenu == "4") {
                cout << "Esta opcion se implementara en el siguiente commit.\n";
            } else {
                cout << "Opcion invalida.\n";
            }
        }
    }
    return 0;
}
