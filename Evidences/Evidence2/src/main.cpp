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
#include <map>
#include "../include/Log.h"
#include "../include/Queue.h"
#include "../include/DoublyLinkedList.h"
#include "../include/Stack.h"

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

// Pide un dia con formato Mmm DD AAAA y verifica que exista.
bool pedirDia(Log& fecha) {
    cout << "Ingresa el dia (ejemplo: Sep 14 2024): ";
    string texto;
    if (!getline(cin, texto)) return false;
    istringstream entrada(texto);
    string mes, diaTexto, anioTexto, extra;
    if (!(entrada >> mes >> diaTexto >> anioTexto) || (entrada >> extra)) {
        cout << "Formato invalido. Usa Mmm DD AAAA.\n";
        return false;
    }
    auto esNumero = [](const string& valor) {
        if (valor.empty()) return false;
        for (char c : valor) {
            if (c < '0' || c > '9') return false;
        }
        return true;
    };
    int numeroMes = Log::monthNumber(mes);
    if (numeroMes == 0 || !esNumero(diaTexto) || diaTexto.size() != 2 ||
        !esNumero(anioTexto) || anioTexto.size() != 4) {
        cout << "Formato invalido. Usa Mmm DD AAAA.\n";
        return false;
    }
    int dia = stoi(diaTexto);
    int anio = stoi(anioTexto);
    if (!Log::validDate(anio, numeroMes, dia)) {
        cout << "La fecha no existe.\n";
        return false;
    }
    fecha.year = anio;
    fecha.month = numeroMes;
    fecha.day = dia;
    return true;
}

// Compara solo anio, mes y dia.
int compararDias(const Log& a, const Log& b) {
    if (a.year != b.year) return a.year < b.year ? -1 : 1;
    if (a.month != b.month) return a.month < b.month ? -1 : 1;
    if (a.day != b.day) return a.day < b.day ? -1 : 1;
    return 0;
}

// Guarda la ultima fecha consultada para reutilizarla en la opcion 3.
void buscarPorDia(const DoublyLinkedList<Log>& registros, Log& ultimaFecha,
                  bool& hayBusqueda) {
    if (!registros.isSorted()) {
        cout << "Primero debes ordenar los logs con la opcion 1.\n";
        return;
    }
    Log fecha;
    if (!pedirDia(fecha)) return;
    ultimaFecha = fecha;
    hayBusqueda = true;
    int total = 0;
    cout << "\nLogs del dia " << fecha.dayString() << ":\n";
    for (DoubleNode<Log>* aux = registros.getHead(); aux != nullptr; aux = aux->next) {
        int comparacion = compararDias(aux->data, fecha);
        if (comparacion > 0) break;
        if (comparacion == 0) {
            cout << aux->data << '\n';
            total++;
        }
    }
    if (total == 0) cout << "No se encontraron registros para ese dia.\n";
    cout << "Total encontrados: " << total << '\n';
}

// Invierte los resultados mediante la pila implementada en la Parte A.
void mostrarDescendente(const DoublyLinkedList<Log>& registros, Log& ultimaFecha,
                        bool& hayBusqueda) {
    if (!registros.isSorted()) {
        cout << "Primero debes ordenar los logs con la opcion 1.\n";
        return;
    }
    if (!hayBusqueda) {
        cout << "Aun no has buscado un dia.\n";
        if (!pedirDia(ultimaFecha)) return;
        hayBusqueda = true;
    }
    Stack<Log> pila;
    for (DoubleNode<Log>* aux = registros.getHead(); aux != nullptr; aux = aux->next) {
        int comparacion = compararDias(aux->data, ultimaFecha);
        if (comparacion > 0) break;
        if (comparacion == 0) pila.push(aux->data);
    }
    int total = pila.size();
    cout << "\nLogs del dia " << ultimaFecha.dayString() << " en orden descendente:\n";
    if (total == 0) cout << "No se encontraron registros para ese dia.\n";
    while (!pila.isEmpty()) cout << pila.pop() << '\n';
    cout << "Total encontrados: " << total << '\n';
}
// Muestra todos los elementos que tienen la frecuencia mas alta.
void mostrarMaximos(const map<string, int>& conteos) {
    if (conteos.empty()) {
        cout << "No hay datos disponibles.\n";
        return;
    }

    int maximo = 0;
    for (const auto& elemento : conteos) {
        if (elemento.second > maximo) maximo = elemento.second;
    }

    for (const auto& elemento : conteos) {
        if (elemento.second == maximo) {
            cout << "  " << elemento.first << ": " << elemento.second << " apariciones\n";
        }
    }
}

// Recorre los logs y cuenta las fechas, los tipos de evento y las IP.
void mostrarEstadisticas(const DoublyLinkedList<Log>& registros) {
    cout << "\n========== ESTADISTICAS DEL ARCHIVO ==========\n";
    cout << "Total de registros: " << registros.getSize() << '\n';

    if (registros.isEmpty()) {
        cout << "No hay registros para analizar.\n";
        return;
    }

    map<string, int> conteoDias;
    map<string, int> conteoEventos;
    map<string, int> conteoIPs;

    for (DoubleNode<Log>* actual = registros.getHead(); actual != nullptr; actual = actual->next) {
        const Log& log = actual->data;
        conteoDias[log.dayString()]++;
        conteoEventos[log.event]++;
        conteoIPs[log.ip]++;
    }

    cout << "\nDia(s) con mas incidentes:\n";
    mostrarMaximos(conteoDias);
    cout << "\nTipo(s) de evento mas frecuente(s):\n";
    mostrarMaximos(conteoEventos);
    cout << "\nDireccion(es) IP mas frecuente(s):\n";
    mostrarMaximos(conteoIPs);
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

        Log ultimaFecha;
        bool hayBusqueda = false;

        while (true) {
            cout << "\n========================================\n";
            cout << "               MENU PRINCIPAL\n";
            cout << "========================================\n";
            cout << "1. Ordenar logs por fecha y hora\n";
            cout << "2. Buscar logs por dia\n";
            cout << "3. Mostrar por dia en orden descendente\n";
            cout << "4. Estadisticas del archivo\n";
            cout << "5. Salir\n";
            cout << "Opcion: ";
            string opcionMenu;
            if (!getline(cin, opcionMenu)) return 0;
            if (opcionMenu == "1") {
                ordenarLogs(registros, ruta);
            } else if (opcionMenu == "2") {
                buscarPorDia(registros, ultimaFecha, hayBusqueda);
            } else if (opcionMenu == "3") {
                mostrarDescendente(registros, ultimaFecha, hayBusqueda);
            } else if (opcionMenu == "4") {
                mostrarEstadisticas(registros);
            } else if (opcionMenu == "5") {
                cout << "Hasta luego.\n";
                return 0;
            } else {
                cout << "Opcion invalida.\n";
            }
        }
    }
    return 0;
}
