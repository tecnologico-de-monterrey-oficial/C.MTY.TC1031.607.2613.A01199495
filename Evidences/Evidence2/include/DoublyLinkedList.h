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

    // Divide la cadena de nodos en dos mitades.
    static DoubleNode<T>* split(DoubleNode<T>* first) {
        DoubleNode<T>* slow = first;
        DoubleNode<T>* fast = first;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        DoubleNode<T>* second = slow->next;
        slow->next = nullptr;
        if (second != nullptr) second->prev = nullptr;
        return second;
    }

    // Une dos mitades ordenadas; elige la izquierda si hay empate.
    static DoubleNode<T>* mergeNodes(DoubleNode<T>* left, DoubleNode<T>* right,
                                     long long& comparisons) {
        DoubleNode<T>* first = nullptr;
        DoubleNode<T>* last = nullptr;
        while (left != nullptr || right != nullptr) {
            DoubleNode<T>* selected;
            if (left == nullptr) {
                selected = right;
                right = right->next;
            } else if (right == nullptr) {
                selected = left;
                left = left->next;
            } else {
                comparisons++;
                if (!(right->data < left->data)) {
                    selected = left;
                    left = left->next;
                } else {
                    selected = right;
                    right = right->next;
                }
            }
            selected->prev = last;
            selected->next = nullptr;
            if (last != nullptr) last->next = selected;
            else first = selected;
            last = selected;
        }
        return first;
    }

    static DoubleNode<T>* mergeSortNodes(DoubleNode<T>* first, long long& comparisons,
                                         int depth, int& maxDepth) {
        if (depth > maxDepth) maxDepth = depth;
        if (first == nullptr || first->next == nullptr) return first;
        DoubleNode<T>* second = split(first);
        first = mergeSortNodes(first, comparisons, depth + 1, maxDepth);
        second = mergeSortNodes(second, comparisons, depth + 1, maxDepth);
        return mergeNodes(first, second, comparisons);
    }
public:

    DoublyLinkedList()
        : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyLinkedList() {
        clear();
    }

    DoublyLinkedList(const DoublyLinkedList<T>& other)
        : head(nullptr), tail(nullptr), size(0) {
        for (DoubleNode<T>* aux = other.head; aux != nullptr; aux = aux->next) {
            addLast(aux->data);
        }
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

    // Inserta despues de un nodo existente, en O(1).
    void insertAfter(DoubleNode<T>* nodo, const T& data) {
        if (nodo == nullptr) {
            throw std::invalid_argument("El nodo no puede ser nulo");
        }
        if (nodo == tail) {
            addLast(data);
            return;
        }
        DoubleNode<T>* nuevo = new DoubleNode<T>(data, nodo, nodo->next);
        nodo->next->prev = nuevo;
        nodo->next = nuevo;
        size++;
    }

    // Elimina un nodo conocido sin recorrer la lista: O(1).
    bool removeNode(DoubleNode<T>* nodo) {
        if (nodo == nullptr) {
            return false;
        }
        if (nodo->prev != nullptr) {
            nodo->prev->next = nodo->next;
        } else {
            head = nodo->next;
        }
        if (nodo->next != nullptr) {
            nodo->next->prev = nodo->prev;
        } else {
            tail = nodo->prev;
        }
        delete nodo;
        size--;
        return true;
    }

    void insert(int index, const T& data) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Indice fuera de rango");
        }
        if (index == 0) {
            addFirst(data);
            return;
        }
        if (index == size) {
            addLast(data);
            return;
        }
        DoubleNode<T>* aux = head;
        for (int i = 0; i < index - 1; i++) {
            aux = aux->next;
        }
        insertAfter(aux, data);
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

    // Merge Sort estable; reacomoda nodos sin usar arreglos.
    void sort(long long& comparisons, int& maxDepth) {
        comparisons = 0;
        maxDepth = 0;
        if (head == nullptr || head->next == nullptr) return;
        head = mergeSortNodes(head, comparisons, 1, maxDepth);
        tail = head;
        while (tail->next != nullptr) tail = tail->next;
    }

    // Permite mantener las llamadas anteriores a sort().
    void sort() {
        long long comparisons;
        int maxDepth;
        sort(comparisons, maxDepth);
    }

    bool isSorted() const {
        for (DoubleNode<T>* aux = head; aux != nullptr && aux->next != nullptr;
             aux = aux->next) {
            if (aux->next->data < aux->data) return false;
        }
        return true;
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

    DoubleNode<T>* getHead() const {
        return head;
    }

    DoubleNode<T>* getTail() const {
        return tail;
    }

    void printReverse() const {
        DoubleNode<T>* aux = tail;
        while (aux != nullptr) {
            std::cout << aux->data;
            if (aux->prev != nullptr) {
                std::cout << " <-> ";
            }
            aux = aux->prev;
        }
        std::cout << std::endl;
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
