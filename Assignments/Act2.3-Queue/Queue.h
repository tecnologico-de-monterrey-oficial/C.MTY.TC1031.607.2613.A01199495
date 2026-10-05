//
// Created by Diego Villanueva Fernandez on 05/10/26.
// Matricula: A01199495
//

#ifndef C_MTY_TC1031_607_2613_A01199495_QUEUE_H
#define C_MTY_TC1031_607_2613_A01199495_QUEUE_H
#include <stdexcept>
#include "../Act2.1-LinkedList/Node.h"
using namespace std;
template<typename T>

class Queue{
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    Queue() : head(nullptr),tail(nullptr),size(0){}
    ~Queue() {
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
#endif //C_MTY_TC1031_607_2613_A01199495_QUEUE_H
