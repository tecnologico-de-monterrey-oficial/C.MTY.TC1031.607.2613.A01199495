//
// Created by Diego Villanueva Fernandez on 07/10/26.
// Matricula: A01199495
//

#ifndef C_MTY_TC1031_607_2613_A01199495_DOUBLYLINKEDLIST_H
#define C_MTY_TC1031_607_2613_A01199495_DOUBLYLINKEDLIST_H
#include <iostream>
#include <stdexcept>
#include "DoubleNode.h"

template<typename T>
class DoublyLinkedList {
private:
    DoubleNode<T>* head;
    DoubleNode<T>* tail;
    int size;
public:

    DoublyLinkedList()
        : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyLinkedList() {
        clear();
    }

    void addFirst(const T& data) {
        DoubleNode<T>* nuevo = new DoubleNode<T>(data);
        if (head == nullptr) {
            head = nuevo;
            tail = nuevo;
        } else {
            nuevo->next = head;
            head->prev = nuevo;
            head = nuevo;
        }

        size++;
    }

    void addLast(const T& data) {
        DoubleNode<T>* nuevo = new DoubleNode<T>(data);
        if (head == nullptr) {
            head = nuevo;
            tail = nuevo;
        }

        else {
            nuevo->prev = tail;
            tail->next = nuevo;
            tail = nuevo;
        }
        size++;
    }

    void insert(int index, const T& data) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Indice fuera de rango");
        }

        if (index == size - 1) {
            addLast(data);
            return;
        }

        DoubleNode<T>* aux = head;
        for (int i = 0; i < index; i++) {
            aux = aux->next;
        }

        DoubleNode<T>* nuevo = new DoubleNode<T>(data);
        nuevo->prev = aux;
        nuevo->next = aux->next;
        aux->next->prev = nuevo;
        aux->next = nuevo;
        size++;
    }

    bool deleteData(const T& data) {
        DoubleNode<T>* aux = head;
        while (aux != nullptr && aux->data != data) {
            aux = aux->next;
        }
        if (aux == nullptr) {
            return false;
        }

        if (aux == head) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr;
            }
        }

        else if (aux == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        }

        else {
            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;
        }
        delete aux;
        size--;

        return true;
    }

    bool deleteAt(int index) {
        if (index < 0 || index >= size) {
            return false;
        }

        DoubleNode<T>* aux = head;
        for (int i = 0; i < index; i++) {
            aux = aux->next;
        }

        if (aux == head) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }

            else {
                tail = nullptr;
            }

        }

        else if (aux == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        }

        else {
            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;
        }

        delete aux;
        size--;
        return true;

    }

    T getData(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Indice fuera de rango");
        }

        DoubleNode<T>* aux = head;

        for (int i = 0; i < index; i++) {
            aux = aux->next;
        }
        return aux->data;
    }

    void updateData(const T& oldData, const T& newData) {
        DoubleNode<T>* aux = head;
        while (aux != nullptr && aux->data != oldData) {
            aux = aux->next;
        }
        if (aux == nullptr) {
            throw std::out_of_range("Dato no encontrado");
        }
        aux->data = newData;
    }

    void updateAt(int index, const T& newData) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Indice fuera de rango");
        }

        DoubleNode<T>* aux = head;
        for (int i = 0; i < index; i++) {
            aux = aux->next;
        }
        aux->data = newData;
    }

    int findData(const T& data) const {
        DoubleNode<T>* aux = head;
        int index = 0;
        while (aux != nullptr) {
            if (aux->data == data) {
                return index;
            }
            aux = aux->next;
            index++;
        }
        return -1;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Indice fuera de rango");
        }

        DoubleNode<T>* aux = head;

        for (int i = 0; i < index; i++) {
            aux = aux->next;
        }
        return aux->data;
    }

    DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& other) {
        if (this == &other) {
            return *this;
        }

        clear();
        DoubleNode<T>* aux = other.head;
        while (aux != nullptr) {
            addLast(aux->data);
            aux = aux->next;
        }
        return *this;
    }

    void clear() {
        DoubleNode<T>* aux = head;
        while (aux != nullptr) {
            DoubleNode<T>* temp = aux;
            aux = aux->next;
            delete temp;
        }

        head = nullptr;
        tail = nullptr;

        size = 0;

    }

    void sort() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        for (int i = 0; i < size - 1; i++) {
            DoubleNode<T>* aux = head;
            for (int j = 0; j < size - i - 1; j++) {
                if (aux->data > aux->next->data) {
                    T temp = aux->data;
                    aux->data = aux->next->data;
                    aux->next->data = temp;
                }
                aux = aux->next;
            }
        }
    }

    void duplicate() {
        DoubleNode<T>* aux = head;
        while (aux != nullptr) {
            DoubleNode<T>* copia =
                new DoubleNode<T>(aux->data);
            copia->next = aux->next;
            copia->prev = aux;
            if (aux->next != nullptr) {
                aux->next->prev = copia;
            } else {
                tail = copia;
            }
            aux->next = copia;
            size++;
            aux = copia->next;
        }
    }

    void removeDuplicates() {
        sort();
        DoubleNode<T>* aux = head;

        while (aux != nullptr && aux->next != nullptr) {
            if (aux->data == aux->next->data) {
                DoubleNode<T>* duplicado = aux->next;
                aux->next = duplicado->next;
                if (duplicado->next != nullptr) {
                    duplicado->next->prev = aux;
                }
                else {
                    tail = aux;
                }
                delete duplicado;
                size--;
            } else {
                aux = aux->next;
            }
        }

    }

    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void print() const {
        DoubleNode<T>* aux = head;
        while (aux != nullptr) {
            std::cout << aux->data;
            if (aux->next != nullptr) {
                std::cout << " <-> ";
            }
            aux = aux->next;
        }
        std::cout << std::endl;
    }
};


#endif //C_MTY_TC1031_607_2613_A01199495_DOUBLYLINKEDLIST_H
