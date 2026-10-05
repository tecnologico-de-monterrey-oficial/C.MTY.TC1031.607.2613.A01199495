//
// Created by Diego Villanueva Fernandez on 05/10/26.
// Matricula: A01199495
//
#include <iostream>
#include "../Act2.1-LinkedList/Node.h"
#include <stdexcept>

using namespace std;

struct Cliente {
    string nombre;
    int boletos;
};

template<typename T>
class QueueNotas {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    QueueNotas() : head(nullptr),tail(nullptr),size(0) {}
    ~QueueNotas() {
        Node<T>* aux = head;
        while (aux != nullptr) {
            Node<T>* temp = aux;
            aux = aux->next;
            delete temp;
        }

        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void push(const T& data) {
        Node<T>* nuevo = new Node<T>(data);
        if (head == nullptr) {
            head = nuevo;
            tail = nuevo;
        } else {
            tail->next = nuevo;
            tail = nuevo;
        }
        size++;
    }

        T pop() {
            if (head == nullptr) {
                throw out_of_range("La fila esta vacia");
            }

            Node<T>* temp = head;
            T data = head->data;

            head = head->next;
            delete temp;

            size--;

            if (head == nullptr) {
                tail = nullptr;
            }

        return data;
        }

    T front() {
        if (head == nullptr) {
            throw out_of_range("La fila esta vacia");
        }
        return head->data;
    }

    int getSize() {
        return size;
    }

};
int main() {
    //Queue
    /*Una fila funciona como un FIFO, First In First Out
     * Una fila el primer elemento que entra es el primer elemento que sale
     * Tienen @head que apunta a el primer elemento de la lista
     * Y @tail que apunta al ultimo elemento de la lista
     */

    Node<int>* head = nullptr;//primer elemento
    Node<int>* tail = nullptr;// ultimo elemento

    Node<int>* nodo1 = new Node<int>(10);// primer elemento

    head = nodo1;//asignas el head
    tail = nodo1;//asignas el tail

    cout << head->data << endl;
    cout <<tail->data << endl;

    Node<int>* nodo2 = new Node<int>(20);// segundo elemento

    tail->next = nodo2; // pones que el siguiente va a ser el nuevo
    tail = nodo2;// tail si lo actualizas su data

    cout << head->data << endl;
    cout <<tail->data << endl;

    Node<int>* nodo3 = new Node<int>(30);//T3r elemento

    tail->next = nodo3;
    tail = nodo3;

    cout << head->data << endl;
    cout <<tail->data << endl;

    //RECORRER LA QUEUE
    Node<int>* aux = head;
    while (aux != nullptr) {
        cout << aux->data << "->";
        aux = aux->next;
    }

    cout << "nullptr" << endl;

    //LIBERAR MEMORIA
    aux = head;
    while (aux != nullptr) {
        Node<int>* temp = aux;
        aux = aux->next;
        delete temp;
    }

    head = nullptr;
    tail = nullptr;

    QueueNotas<int> fila;
    fila.push(10);
    fila.push(20);
    fila.push(30);

    cout << fila.getSize() <<endl;
    cout<< fila.front() << endl;

    cout << fila.pop() << endl;
    cout << fila.getSize() << endl;
    cout << fila.front() << endl;

    QueueNotas<Cliente> filaClientes;
    Cliente c1;
    c1.nombre = "Diego";
    c1.boletos = 2;

    filaClientes.push(c1);

    Cliente c2;
    c2.nombre = "Ana";
    c2.boletos = 4;

    filaClientes.push(c2);
    return 0;

}
