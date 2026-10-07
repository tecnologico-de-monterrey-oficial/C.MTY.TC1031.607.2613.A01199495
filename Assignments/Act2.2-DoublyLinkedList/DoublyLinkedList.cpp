//
// Created by Diego Villanueva Fernandez on 07/10/26.
// Matricula: A01199495
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <type_traits>

#include "DoublyLinkedList.h"

using namespace std;

string randomString() {
    string resultado = "";

    for (int i = 0; i < 5; i++) {
        char letra = 'A' + rand() % 26;
        resultado += letra;
    }

    return resultado;
}

template<typename T>
void menuLista(DoublyLinkedList<T>& lista) {

    int opcionCreacion;

    cout << "Como quieres crear la lista?" << endl;
    cout << "1. Datos aleatorios" << endl;
    cout << "2. Datos capturados" << endl;
    cout << "Opcion: ";
    cin >> opcionCreacion;

    int cantidad;

    cout << "Cuantos datos quieres agregar? ";
    cin >> cantidad;

    if (opcionCreacion == 1) {

        if constexpr (is_same<T, int>::value) {

            for (int i = 0; i < cantidad; i++) {
                int dato = rand() % 100;
                lista.addLast(dato);
            }
        }
        else if constexpr (is_same<T, string>::value) {

            for (int i = 0; i < cantidad; i++) {
                lista.addLast(randomString());
            }
        }
    }
    else if (opcionCreacion == 2) {

        for (int i = 0; i < cantidad; i++) {

            T dato;

            cout << "Dato " << i + 1 << ": ";
            cin >> dato;

            lista.addLast(dato);
        }
    }
    else {
        cout << "Opcion invalida." << endl;
        return;
    }

    cout << endl;
    cout << "Lista creada:" << endl;
    lista.print();

    DoublyLinkedList<T> copia;

    int opcion = -1;

    while (opcion != 0) {

        cout << endl;
        cout << "========== MENU ==========" << endl;
        cout << "1. Agregar elemento al principio" << endl;
        cout << "2. Agregar elemento al final" << endl;
        cout << "3. Insertar elemento despues de un indice" << endl;
        cout << "4. Borrar un elemento por dato" << endl;
        cout << "5. Borrar un elemento por posicion" << endl;
        cout << "6. Obtener elemento por posicion" << endl;
        cout << "7. Actualizar elemento por dato" << endl;
        cout << "8. Actualizar elemento por posicion" << endl;
        cout << "9. Encontrar un elemento" << endl;
        cout << "10. Leer elemento con operador []" << endl;
        cout << "11. Actualizar elemento con operador []" << endl;
        cout << "12. Duplicar lista con operador =" << endl;
        cout << "13. Limpiar lista" << endl;
        cout << "14. Ordenar lista" << endl;
        cout << "15. Duplicar cada elemento" << endl;
        cout << "16. Remover elementos duplicados" << endl;
        cout << "17. Imprimir lista" << endl;
        cout << "0. Salir" << endl;

        cout << "Opcion: ";
        cin >> opcion;

        cout << endl;

        try {

            switch (opcion) {

                case 1: {
                    T dato;

                    cout << "Dato: ";
                    cin >> dato;

                    lista.addFirst(dato);

                    cout << "Lista:" << endl;
                    lista.print();

                    break;
                }

                case 2: {
                    T dato;

                    cout << "Dato: ";
                    cin >> dato;

                    lista.addLast(dato);

                    cout << "Lista:" << endl;
                    lista.print();

                    break;
                }

                case 3: {
                    int index;
                    T dato;

                    cout << "Indice: ";
                    cin >> index;

                    cout << "Dato: ";
                    cin >> dato;

                    lista.insert(index, dato);

                    cout << "Lista:" << endl;
                    lista.print();

                    break;
                }

                case 4: {
                    T dato;

                    cout << "Dato a borrar: ";
                    cin >> dato;

                    bool resultado = lista.deleteData(dato);

                    if (resultado) {
                        cout << "Dato borrado correctamente." << endl;
                    }
                    else {
                        cout << "Dato no encontrado." << endl;
                    }

                    lista.print();

                    break;
                }

                case 5: {
                    int index;

                    cout << "Indice a borrar: ";
                    cin >> index;

                    bool resultado = lista.deleteAt(index);

                    if (resultado) {
                        cout << "Dato borrado correctamente." << endl;
                    }
                    else {
                        cout << "Indice invalido." << endl;
                    }

                    lista.print();

                    break;
                }

                case 6: {
                    int index;

                    cout << "Indice: ";
                    cin >> index;

                    cout << "Dato: "
                         << lista.getData(index)
                         << endl;

                    break;
                }

                case 7: {
                    T oldData;
                    T newData;

                    cout << "Dato actual: ";
                    cin >> oldData;

                    cout << "Dato nuevo: ";
                    cin >> newData;

                    lista.updateData(oldData, newData);

                    lista.print();

                    break;
                }

                case 8: {
                    int index;
                    T newData;

                    cout << "Indice: ";
                    cin >> index;

                    cout << "Dato nuevo: ";
                    cin >> newData;

                    lista.updateAt(index, newData);

                    lista.print();

                    break;
                }

                case 9: {
                    T dato;

                    cout << "Dato a buscar: ";
                    cin >> dato;

                    int index = lista.findData(dato);

                    if (index == -1) {
                        cout << "Dato no encontrado." << endl;
                    }
                    else {
                        cout << "Dato encontrado en indice: "
                             << index
                             << endl;
                    }

                    break;
                }

                case 10: {
                    int index;

                    cout << "Indice: ";
                    cin >> index;

                    cout << "Dato: "
                         << lista[index]
                         << endl;

                    break;
                }

                case 11: {
                    int index;
                    T dato;

                    cout << "Indice: ";
                    cin >> index;

                    cout << "Nuevo dato: ";
                    cin >> dato;

                    lista[index] = dato;

                    lista.print();

                    break;
                }

                case 12: {

                    copia = lista;

                    cout << "Lista original:" << endl;
                    lista.print();

                    cout << "Lista duplicada:" << endl;
                    copia.print();

                    break;
                }

                case 13: {

                    lista.clear();

                    cout << "Lista limpiada." << endl;
                    lista.print();

                    break;
                }

                case 14: {

                    lista.sort();

                    cout << "Lista ordenada:" << endl;
                    lista.print();

                    break;
                }

                case 15: {

                    lista.duplicate();

                    cout << "Lista con elementos duplicados:" << endl;
                    lista.print();

                    break;
                }

                case 16: {

                    lista.removeDuplicates();

                    cout << "Lista sin duplicados:" << endl;
                    lista.print();

                    break;
                }

                case 17: {

                    cout << "Lista:" << endl;
                    lista.print();

                    cout << "Size: "
                         << lista.getSize()
                         << endl;

                    break;
                }

                case 0: {

                    cout << "Saliendo..." << endl;

                    break;
                }

                default: {

                    cout << "Opcion invalida." << endl;

                    break;
                }
            }
        }
        catch (const out_of_range& error) {

            cout << "Error: "
                 << error.what()
                 << endl;
        }
    }
}

int main() {

    srand(time(nullptr));

    int tipo;

    cout << "Que tipo de lista quieres crear?" << endl;
    cout << "1. Enteros" << endl;
    cout << "2. Strings" << endl;
    cout << "Opcion: ";
    cin >> tipo;

    if (tipo == 1) {

        DoublyLinkedList<int> lista;

        menuLista(lista);
    }
    else if (tipo == 2) {

        DoublyLinkedList<string> lista;

        menuLista(lista);
    }
    else {

        cout << "Opcion invalida." << endl;
    }

    return 0;
}