//
// Created by Diego Villanueva Fernandez on 18/10/26.
// Matricula: A01199495
//

#include <iostream>
#include <stdexcept>
#include "../include/LinkedList.h"
#include "../include/Queue.h"
#include "../include/Stack.h"
#include "../include/DoublyLinkedList.h"

using namespace std;

int main() {
    cout << "===== PARTE A: PRUEBAS DE ESTRUCTURAS =====\n";

    cout << "\n[1] Lista ligada simple\n";
    LinkedList<int> lista;
    cout << "Vacia: " << (lista.isEmpty() ? "si" : "no") << "\n";
    cout << "Eliminar al inicio estando vacia: "
         << (lista.removeFirst() ? "eliminado" : "lista vacia") << "\n";
    lista.addFirst(10);
    cout << "Un elemento: " << lista.getData(0) << "\n";
    lista.addFirst(5);
    lista.addLast(20);
    cout << "Despues de insertar en ambos extremos: ";
    for (int i = 0; i < lista.getSize(); i++) cout << lista.getData(i) << ' ';
    cout << "\n";
    lista.removeFirst();
    cout << "Despues de eliminar el primero: ";
    for (int i = 0; i < lista.getSize(); i++) cout << lista.getData(i) << ' ';
    cout << "\nTamano: " << lista.getSize() << "\n";

    cout << "\n[2] Pila (LIFO)\n";
    Stack<int> pila;
    cout << "Vacia: " << (pila.isEmpty() ? "si" : "no") << "\n";
    try {
        pila.pop();
    } catch (const out_of_range& e) {
        cout << "Pop vacio: " << e.what() << "\n";
    }
    pila.push(10);
    cout << "Un elemento, peek: " << pila.peek() << "\n";
    pila.push(20);
    pila.push(30);
    cout << "Orden de pop (esperado 30 20 10): ";
    while (!pila.isEmpty()) cout << pila.pop() << ' ';
    cout << "\nTamano final: " << pila.size() << "\n";

    cout << "\n[3] Fila (FIFO)\n";
    Queue<int> fila;
    cout << "Vacia: " << (fila.isEmpty() ? "si" : "no") << "\n";
    try {
        fila.dequeue();
    } catch (const out_of_range& e) {
        cout << "Dequeue vacio: " << e.what() << "\n";
    }
    fila.enqueue(10);
    cout << "Un elemento, front: " << fila.front() << "\n";
    fila.enqueue(20);
    fila.enqueue(30);
    cout << "Orden de dequeue (esperado 10 20 30): ";
    while (!fila.isEmpty()) cout << fila.dequeue() << ' ';
    cout << "\nTamano final: " << fila.size() << "\n";

    cout << "\n[4] Lista doblemente ligada\n";
    DoublyLinkedList<int> doble;
    cout << "Vacia: " << (doble.isEmpty() ? "si" : "no") << "\n";
    doble.addFirst(10);
    cout << "Un elemento: " << doble.getHead()->data << "\n";
    doble.addFirst(5);
    doble.addLast(30);
    doble.insertAfter(doble.getHead()->next, 20);
    cout << "Recorrido hacia adelante: ";
    for (DoubleNode<int>* actual = doble.getHead(); actual != nullptr; actual = actual->next)
        cout << actual->data << ' ';
    cout << "\nRecorrido hacia atras: ";
    for (DoubleNode<int>* actual = doble.getTail(); actual != nullptr; actual = actual->prev)
        cout << actual->data << ' ';
    cout << "\n";
    doble.removeNode(doble.getHead());
    doble.removeNode(doble.getTail());
    cout << "Tras eliminar ambos extremos: ";
    for (DoubleNode<int>* actual = doble.getHead(); actual != nullptr; actual = actual->next)
        cout << actual->data << ' ';
    cout << "\nTamano: " << doble.getSize() << "\n";

    cout << "\n===== FIN DE PRUEBAS =====\n";
    return 0;
}
