//
// Created by Diego Villanueva Fernandez on 05/10/26.
// Matricula: A01199495
//

#ifndef C_MTY_TC1031_607_2613_A01199495_QUEUE_H
#define C_MTY_TC1031_607_2613_A01199495_QUEUE_H

#include <stdexcept>
#include "LinkedList.h"

template<typename T>
class Queue {
private:
    LinkedList<T> lista;

public:
    Queue() = default;

    void enqueue(const T& data) {
        lista.addLast(data);
    }

    T dequeue() {
        if (lista.isEmpty()) {
            throw std::out_of_range("La fila esta vacia");
        }
        T data = lista.getData(0);
        lista.removeFirst();
        return data;
    }

    T front() const {
        if (lista.isEmpty()) {
            throw std::out_of_range("La fila esta vacia");
        }
        return lista.getData(0);
    }

    bool isEmpty() const {
        return lista.isEmpty();
    }

    int size() const {
        return lista.getSize();
    }

    // Alias para mantener compatibilidad con ejercicios anteriores.
    void push(const T& data) {
        enqueue(data);
    }

    T pop() {
        return dequeue();
    }

    int getSize() const {
        return size();
    }
};

#endif // C_MTY_TC1031_607_2613_A01199495_QUEUE_H
