//
// Created by Diego Villanueva Fernandez on 04/10/26.
// Matricula: A01199495
//

#ifndef C_MTY_TC1031_607_2613_A01199495_LINKEDLIST_H
#define C_MTY_TC1031_607_2613_A01199495_LINKEDLIST_H
#include "Node.h"
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
};
#endif //C_MTY_TC1031_607_2613_A01199495_LINKEDLIST_H
