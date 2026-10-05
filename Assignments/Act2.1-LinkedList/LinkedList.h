//
// Created by Diego Villanueva Fernandez on 04/10/26.
// Matricula: A01199495
//

#ifndef C_MTY_TC1031_607_2613_A01199495_LINKEDLIST_H
#define C_MTY_TC1031_607_2613_A01199495_LINKEDLIST_H
#include "Node.h"
#include <stdexcept>
template<typename T>
class LinkedList {
private:
    Node<T>* head;
    int size;
public:
    LinkedList() : head(nullptr),size(0){}
    ~LinkedList() {
        Node<T>* aux = head;
        while (aux != nullptr) {
            Node<T>* temp = aux;
            aux = aux->next;
            delete temp;
        }
        head = nullptr;
        size = 0;
    }

    void addFirst(const T& data) {
        Node<T>* nuevo = new Node<T>(data,head);
        head = nuevo;
        size++;
    }

    void addLast(const T& data) {
        Node<T>* nuevo = new Node<T>(data);
        if (head == nullptr) {
            head = nuevo;
        } else {
            Node<T>* aux = head;
            while (aux->next != nullptr) {
                aux = aux->next;
            }
            aux->next = nuevo;
        }
        size++;
    }

    void insert(int index, const T& data) {
        if (index < 0 || index >= size) {
            throw out_of_range("el indice que pusiste esta fuera del rango, checa si no me pediste un numero menor a 0 o uno mayor al size");
        }
            Node<T>* aux = head;
            int i = 0;

            while (i < index) {
                aux = aux->next;
                i++;
            }

            Node<T>* nuevo = new Node<T>(data, aux->next);
            aux->next = nuevo;
            size++;
    }

    bool deleteData(const T& data) {
        if (head == nullptr) {
            return false;
        }

        if (head->data == data) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            size--;
            return true;
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
        delete temp;
        size--;

        return true;
    }

};
#endif //C_MTY_TC1031_607_2613_A01199495_LINKEDLIST_H
