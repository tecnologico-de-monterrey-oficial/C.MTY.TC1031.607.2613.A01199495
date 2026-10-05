//
// Created by Diego Villanueva Fernandez on 05/10/26.
// Matricula: A01199495
//
#include <iostream>
#include "../Act2.1-LinkedList/Node.h"

using namespace std;
template<typename T>
class StackNotas {
private:
    Node<T>* topNode;
    int size;

public:
    StackNotas() : topNode(nullptr), size(0) {}

    void push(const T& data) {
        Node<T>* nuevo = new Node<T>(data);

        nuevo->next = topNode;
        topNode = nuevo;

        size++;
    }
};

//Stack
/**
 * Un Stack funciona como un LIFO;
 * Last In, First Out;
 * El ultimo elemento que entra es el primer elemento que sale.
 * En una Stack normalmente solo necesitamos un pointer llamado top;
*/


int main() {
    Node<int>* top = nullptr;

    Node<int>* n1 = new Node<int>(10);//Primer elemento
    n1->next = top;
    top = n1;

    cout << "Top: " << top->data << endl;

    Node<int>* n2 = new Node<int>(20);// Segundo elemento
    n2->next = top;
    top = n2;

    cout << "Top: " << top->data << endl;

    Node<int>* n3 = new Node<int>(30);// T3r elemento
    n3->next = top;
    top = n3;

    cout << "Top: " << top->data << endl;

    //Recorrer el stack
    Node<int>* aux = top;
    while (aux != nullptr) {
        cout << aux->data << "->";
        aux = aux->next;
    }
    cout << "nullptr" << endl;

    //LIBERAR MEMORIA
    aux = top;
    while (aux != nullptr) {
        Node<int>* temp = aux;
        aux = aux->next;
        delete temp;
    }
    top = nullptr;


    return 0;
}
