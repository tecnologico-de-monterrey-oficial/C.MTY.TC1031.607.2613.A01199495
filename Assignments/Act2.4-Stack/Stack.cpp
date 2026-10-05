//
// Created by Diego Villanueva Fernandez on 05/10/26.
// Matricula: A01199495
//

#include <iostream>
#include <string>

#include "Stack.h"

using namespace std;

struct PaginaWeb {
    string titulo;
    string url;
};

int main() {

    Stack<PaginaWeb> historial;

    int opcion = 0;

    while (opcion != 5) {

        cout << endl;
        cout << "===== HISTORIAL DEL NAVEGADOR =====" << endl;
        cout << "1. Visitar una nueva pagina" << endl;
        cout << "2. Retroceder a la pagina anterior" << endl;
        cout << "3. Ver la pagina actual" << endl;
        cout << "4. Mostrar cuantas paginas hay en el historial" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        try {

            switch (opcion) {

                case 1: {
                    PaginaWeb nueva;

                    cout << "Titulo de la pagina: ";
                    cin >> nueva.titulo;

                    cout << "URL: ";
                    cin >> nueva.url;

                    historial.push(nueva);

                    cout << "Pagina agregada al historial." << endl;

                    break;
                }

                case 2: {
                    PaginaWeb cerrada = historial.pop();

                    cout << "Pagina cerrada: " << cerrada.titulo << endl;
                    cout << "URL: " << cerrada.url << endl;

                    break;
                }

                case 3: {
                    PaginaWeb actual = historial.top();

                    cout << "Pagina actual: " << actual.titulo << endl;
                    cout << "URL: " << actual.url << endl;

                    break;
                }

                case 4: {
                    cout << "Paginas en el historial: "
                         << historial.getSize() << endl;

                    break;
                }

                case 5: {
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

    return 0;
}