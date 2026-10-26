#include <iostream>
#include "BST.h"
using namespace std;

int main() {
    BST<int> arbol;
    int opcion, dato, recorrido;

    do {
        cout << "\n--- Arbol Binario de Busqueda ---\n";
        cout << "1. Insertar\n";
        cout << "2. Recorridos\n";
        cout << "3. Buscar\n";
        cout << "4. Altura\n";
        cout << "5. Ancestros\n";
        cout << "6. Nivel de un nodo\n";
        cout << "7. Eliminar\n";
        cout << "8. Imprimir\n";
        cout << "9. Salir\n";
        cout << "Opcion: ";
        if (!(cin >> opcion)) break;

        switch (opcion) {
            case 1:
                cout << "Valor a insertar: ";
                cin >> dato;
                if (cin) arbol.insert(dato);
                break;
            case 2:
                cout << "1. Preorder\n2. Inorder\n3. Postorder\n4. Por niveles\nOpcion: ";
                cin >> recorrido;
                if (cin) arbol.visit(recorrido);
                break;
            case 3:
                cout << "Valor a buscar: ";
                cin >> dato;
                if (cin) cout << (arbol.find(dato) ? "Encontrado\n" : "No encontrado\n");
                break;
            case 4:
                cout << "Altura: " << arbol.height() << "\n";
                break;
            case 5:
                cout << "Valor: ";
                cin >> dato;
                if (cin) arbol.ancestors(dato);
                break;
            case 6:
                cout << "Valor: ";
                cin >> dato;
                if (cin) cout << "Nivel: " << arbol.whatLevelAmI(dato) << "\n";
                break;
            case 7:
                cout << "Valor a eliminar: ";
                cin >> dato;
                if (cin) arbol.remove(dato);
                break;
            case 8:
                arbol.print();
                break;
            case 9:
                cout << "Adios\n";
                break;
            default:
                cout << "Opcion invalida\n";
        }
    } while (cin && opcion != 9);

    return 0;
}
