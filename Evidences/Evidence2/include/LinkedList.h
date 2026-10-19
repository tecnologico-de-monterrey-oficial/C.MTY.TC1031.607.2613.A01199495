//
// Created by Diego Villanueva Fernandez on 04/10/26.
// Matricula: A01199495
//

#ifndef C_MTY_TC1031_607_2613_A01199495_LINKEDLIST_H
#define C_MTY_TC1031_607_2613_A01199495_LINKEDLIST_H
#include "Node.h"
#include <stdexcept>
#include <iostream>
template<typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~LinkedList() {
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

    void addFirst(const T& data) {
        Node<T>* nuevo = new Node<T>(data, head);
        head = nuevo;
        if (tail == nullptr) {
            tail = nuevo;
        }
        size++;
    }

    void addLast(const T& data) {
        Node<T>* nuevo = new Node<T>(data);
        if (tail == nullptr) {
            head = nuevo;
        } else {
            tail->next = nuevo;
        }
        tail = nuevo;
        size++;
    }

    bool removeFirst() {
        if (head == nullptr) {
            return false;
        }
        Node<T>* temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        size--;
        return true;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    int getSize() const {
        return size;
    }

    void insert(int index, const T& data) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("el indice que pusiste esta fuera del rango, checa si no me pediste un numero menor a 0 o uno mayor al size");
        }
            Node<T>* aux = head;
            int i = 0;

            while (i < index) {
                aux = aux->next;
                i++;
            }

            Node<T>* nuevo = new Node<T>(data, aux->next);
            aux->next = nuevo;
            if (aux == tail) { tail = nuevo; }
            size++;
    }

    bool deleteData(const T& data) {
        if (head == nullptr) {
            return false;
        }

        if (head->data == data) {
            return removeFirst();
        }

        Node<T>* aux = head;
        while (aux->next != nullptr && aux->next->data != data) {
            aux = aux->next;
        }

        if (aux->next == nullptr) {
            return false;
        }

        Node<T>* temp = aux->next;
        aux->next = temp->next;
        if (temp == tail) { tail = aux; }
        delete temp;
        size--;

        return true;
    }

    bool deleteAt(int index) {
        if (index < 0 || index >= size) {
            return false;
        }

        if (index == 0) {
            return removeFirst();
        }

        Node<T>* aux = head;
        int i = 0;

        while (i < index - 1) {
            aux = aux->next;
            i++;
        }

        Node<T>* temp = aux->next;
        aux->next = temp->next;
        if (temp == tail) { tail = aux; }
        delete temp;
        size--;

        return true;

    }

T getData(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("o pusiste que querias un indice menor a 0 o un indice mayor al tamaño de la lista vuelve a preguntar ");
        }

        Node<T>* aux = head;
        int i = 0;

        while (i < index) {
            aux = aux->next;
            i++;
        }

        return aux->data;
    }

    void updateData(const T& oldData, const T& newData) {
        Node<T>* aux = head;

        while (aux != nullptr && aux->data != oldData) {
            aux = aux->next;
        }

        if (aux == nullptr) {
            throw std::out_of_range("El dato que quieres actualizar no existe en la lista");        }

        aux->data = newData;
    }

    void updateAt(int index, const T& newData) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("o pusiste que querias cambiar indice menor a 0 o un indice mayor al tamaño de la lista vuelve a preguntar ");
        }

        Node<T>* aux = head;
        int i = 0;

        while (i<index) {
            aux = aux->next;
            i++;
        }

        aux->data = newData;
    }

    int findData(const T& data) {
        Node<T>* aux = head;
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
            throw std::out_of_range("quisiste actualizar o leer un indice menor a 0 o mayor a la size de la lista");
        }

        Node<T>* aux = head;
        int i = 0;

        while (i < index) {
            aux = aux->next;
            i++;
        }

        return aux->data;
    }

    LinkedList(const LinkedList<T>& other) : head(nullptr), tail(nullptr), size(0) {
        Node<T>* aux = other.head;
        while (aux != nullptr) {
            addLast(aux->data);
            aux = aux->next;
        }
    }

    LinkedList<T>& operator=(const LinkedList<T>& other) {
        if (this == &other) {
            return *this;
        }

        Node<T>* aux = head;
        while (aux != nullptr) {
            Node<T>* temp = aux;
            aux = aux->next;
            delete temp;
        }

        head = nullptr;
        tail = nullptr;
        size = 0;

        aux = other.head;

        while (aux != nullptr) {
            addLast(aux->data);
            aux = aux->next;
        }

        return *this;
    }
    void print() const {
        Node<T>* aux = head;

        while (aux != nullptr) {
            std::cout << aux->data << " -> ";
            aux = aux->next;
        }

        std::cout << "nullptr" << std::endl;
    }
};
#endif //C_MTY_TC1031_607_2613_A01199495_LINKEDLIST_H
