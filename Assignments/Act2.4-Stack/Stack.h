//
// Created by Diego Villanueva Fernandez on 05/10/26.
// Matricula: A01199495
//

#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include "../Act2.1-LinkedList/Node.h"

template<typename T>
class Stack {
private:
    Node<T>* topNode;
    int size;

public:
    Stack() : topNode(nullptr), size(0) {}

    ~Stack() {
        Node<T>* aux = topNode;

        while (aux != nullptr) {
            Node<T>* temp = aux;
            aux = aux->next;
            delete temp;
        }

        topNode = nullptr;
        size = 0;
    }

    void push(const T& data) {
        Node<T>* nuevo = new Node<T>(data);

        nuevo->next = topNode;
        topNode = nuevo;

        size++;
    }

    T pop() {
        if (topNode == nullptr) {
            throw std::out_of_range("La pila esta vacia");
        }

        Node<T>* temp = topNode;
        T data = topNode->data;

        topNode = topNode->next;
        delete temp;

        size--;

        return data;
    }

    T top() const {
        if (topNode == nullptr) {
            throw std::out_of_range("La pila esta vacia");
        }

        return topNode->data;
    }

    int getSize() const {
        return size;
    }
};

#endif