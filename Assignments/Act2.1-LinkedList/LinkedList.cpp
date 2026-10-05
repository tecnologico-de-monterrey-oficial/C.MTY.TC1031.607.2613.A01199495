#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <type_traits>

#include "LinkedList.h"

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
void menuLista(LinkedList<T>& lista) {
    int opcionCreacion;

    cout << "Como quieres crear la lista?" << endl;
    cout << "1. Datos aleatorios" << endl;
    cout << "2. Datos capturados" << endl;
    cout << "Opcion: ";
    cin >> opcionCreacion;

    if (opcionCreacion == 2) {
        int cantidad;

        cout << "Cuantos datos quieres agregar? ";
        cin >> cantidad;

        for (int i = 0; i < cantidad; i++) {
            T dato;
            cout << "Dato " << i + 1 << ": ";
            cin >> dato;
            lista.addLast(dato);
        }
    }
    else if (opcionCreacion == 1) {
        int cantidad;

        cout << "Cuantos datos aleatorios quieres agregar? ";
        cin >> cantidad;

        if constexpr (is_same<T, int>::value) {
            for (int i = 0; i < cantidad; i++) {
                int dato = rand() % 100;
                lista.addLast(dato);
            }
        }
        else if constexpr (is_same<T, string>::value) {
            for (int i = 0; i < cantidad; i++) {
                string dato = randomString();
                lista.addLast(dato);
            }
        }
    }
    else {
        cout << "Opcion de creacion invalida." << endl;
        return;
    }

    cout << endl;
    cout << "Lista creada:" << endl;
    lista.print();

    LinkedList<T> copia;
    int opcion = -1;

    while (opcion != 0) {
        cout << endl;
        cout << "========== MENU ==========" << endl;
        cout << "1. Agregar elemento al principio" << endl;
        cout << "2. Agregar elemento al final" << endl;
        cout << "3. Insertar elemento despues de un indice" << endl;
        cout << "4. Borrar un elemento por dato" << endl;
        cout << "5. Borrar un elemento por posicion" << endl;
        cout << "6. Obtener elemento de una posicion (getData)" << endl;
        cout << "7. Actualizar un elemento por dato" << endl;
        cout << "8. Actualizar un elemento por posicion" << endl;
        cout << "9. Encontrar un elemento" << endl;
        cout << "10. Leer elemento con operador []" << endl;
        cout << "11. Actualizar elemento con operador []" << endl;
        cout << "12. Duplicar lista con operador =" << endl;
        cout << "13. Imprimir lista" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        cout << endl;

        try {
            switch (opcion) {
                case 1: {
                    T dato;
                    cout << "Dato a agregar al principio: ";
                    cin >> dato;
                    lista.addFirst(dato);
                    cout << "Lista actualizada:" << endl;
                    lista.print();
                    break;
                }

                case 2: {
                    T dato;
                    cout << "Dato a agregar al final: ";
                    cin >> dato;
                    lista.addLast(dato);
                    cout << "Lista actualizada:" << endl;
                    lista.print();
                    break;
                }

                case 3: {
                    int index;
                    T dato;
                    cout << "Indice despues del cual quieres insertar: ";
                    cin >> index;
                    cout << "Dato a insertar: ";
                    cin >> dato;
                    lista.insert(index, dato);
                    cout << "Lista actualizada:" << endl;
                    lista.print();
                    break;
                }

                case 4: {
                    T dato;
                    cout << "Dato que quieres borrar: ";
                    cin >> dato;
                    bool resultado = lista.deleteData(dato);

                    if (resultado) {
                        cout << "Dato eliminado correctamente." << endl;
                    }
                    else {
                        cout << "El dato no se encontro en la lista." << endl;
                    }

                    lista.print();
                    break;
                }

                case 5: {
                    int index;
                    cout << "Indice que quieres borrar: ";
                    cin >> index;
                    bool resultado = lista.deleteAt(index);

                    if (resultado) {
                        cout << "Elemento eliminado correctamente." << endl;
                    }
                    else {
                        cout << "Indice invalido." << endl;
                    }

                    lista.print();
                    break;
                }

                case 6: {
                    int index;
                    cout << "Indice que quieres obtener: ";
                    cin >> index;
                    cout << "Dato: " << lista.getData(index) << endl;
                    break;
                }

                case 7: {
                    T oldData;
                    T newData;
                    cout << "Dato que quieres cambiar: ";
                    cin >> oldData;
                    cout << "Nuevo dato: ";
                    cin >> newData;
                    lista.updateData(oldData, newData);
                    cout << "Lista actualizada:" << endl;
                    lista.print();
                    break;
                }

                case 8: {
                    int index;
                    T newData;
                    cout << "Indice que quieres actualizar: ";
                    cin >> index;
                    cout << "Nuevo dato: ";
                    cin >> newData;
                    lista.updateAt(index, newData);
                    cout << "Lista actualizada:" << endl;
                    lista.print();
                    break;
                }

                case 9: {
                    T dato;
                    cout << "Dato que quieres buscar: ";
                    cin >> dato;
                    int index = lista.findData(dato);

                    if (index == -1) {
                        cout << "El dato no se encontro." << endl;
                    }
                    else {
                        cout << "El dato se encuentra en el indice: " << index << endl;
                    }

                    break;
                }

                case 10: {
                    int index;
                    cout << "Indice que quieres leer: ";
                    cin >> index;
                    cout << "Dato: " << lista[index] << endl;
                    break;
                }

                case 11: {
                    int index;
                    T dato;
                    cout << "Indice que quieres actualizar: ";
                    cin >> index;
                    cout << "Nuevo dato: ";
                    cin >> dato;
                    lista[index] = dato;
                    cout << "Lista actualizada:" << endl;
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
                    cout << "Lista actual:" << endl;
                    lista.print();
                    break;
                }

                case 0: {
                    cout << "Saliendo del programa..." << endl;
                    break;
                }

                default: {
                    cout << "Opcion invalida." << endl;
                    break;
                }
            }
        }
        catch (const out_of_range& error) {
            cout << "Error: " << error.what() << endl;
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
        LinkedList<int> lista;
        menuLista(lista);
    }
    else if (tipo == 2) {
        LinkedList<string> lista;
        menuLista(lista);
    }
    else {
        cout << "Opcion invalida." << endl;
    }

    return 0;
}