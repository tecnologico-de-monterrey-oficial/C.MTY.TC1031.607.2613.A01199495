//
// Created by Diego Villanueva Fernandez on 05/10/26.
// Matricula: A01199495
//

#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include "LinkedList.h"

template<typename T>
class Stack {
private:
    LinkedList<T> lista;

public:
    Stack() = default;

    void push(const T& data) {
        lista.addFirst(data);
    }

    T pop() {
        if (lista.isEmpty()) {
            throw std::out_of_range("La pila esta vacia");
        }
        T data = lista.getData(0);
        lista.removeFirst();
        return data;
    }

    T peek() const {
        if (lista.isEmpty()) {
            throw std::out_of_range("La pila esta vacia");
        }
        return lista.getData(0);
    }

    T top() const {
        return peek();
    }

    bool isEmpty() const {
        return lista.isEmpty();
    }

    int size() const {
        return lista.getSize();
    }

    int getSize() const {
        return size();
    }
};

#endif