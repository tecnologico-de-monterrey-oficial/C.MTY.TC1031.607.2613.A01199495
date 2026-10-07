//
// Created by Diego Villanueva Fernandez on 06/10/26.
// Matricula: A01199495
//
#include <iostream>

using namespace std;

//DublyLinkedList
/*
 * En una LinkedList cada nodo tiene: Data y Next.
 * En una DoublyLinkedList cada nodo tiene: Data, Next y prev.
 * Next apunta el siguiente nodo.
 * prev apunta al nodo anterior.
 */

template<typename T>
struct DoubleNode {
    T data;

    DoubleNode<T>* next;
    DoubleNode<T>* prev;

    DoubleNode(const T& value) : data(value),next(nullptr),prev(nullptr){}
};

template<typename T>
class DoubleLinkedListNotas {
private:
    DoubleNode<T>* head;
    DoubleNode<T>* tail;
    int size;
public:
    DoubleLinkedListNotas() : head(nullptr),tail(nullptr),size(0){}
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
        DoubleNode<T>* ultimo = new DoubleNode<T>(data);
        if (head == nullptr) {
            head = ultimo;
            tail = ultimo;
        } else {
            ultimo->prev = tail;
            tail->next = ultimo;
            tail = ultimo;
        }
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
        } else {
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
            }else {
                tail = nullptr;
            }
        }

        else if (aux == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;
        }
        delete aux;
        size--;
        return true;
    }

    T getData(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("fuera de rango");
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
            throw std::out_of_range("No se encontro el dato");
        }
        aux->data = newData;
    }

    void updateAt(int index, const T& data) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("fuera del rango");
        }

        DoubleNode<T>* aux = head;
        for (int i = 0; i < index; i++) {
            aux = aux->next;
        }
        aux->data = data;
    }

    int findData(const T& data) {
        DoubleNode<T>* aux = head;
        int index = 0;
        while (aux != nullptr) {
            if (aux->data = data) {
                return index;
            }
            aux = aux->next;
            index++;
        }
        return -1;
    }
    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("fuera de rango");
        }
        DoubleNode<T>* aux = head;
        for (int i = 0; i < index; i++) {
            aux = aux->next;
        }
        return aux->data;
    }

    DoubleLinkedListNotas<T>& operator=(const DoubleLinkedListNotas<T>& list) {
        if (this == &list) {
            return *this;
        }
        clear();

        DoubleNode<T>* aux = list.head;
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
        for (int i = 0; i < size -1; i++) {
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
            DoubleNode<T>* copia = new DoubleNode<T>(aux->data);

            copia->next = aux->next;
            copia->prev = aux;

            if (aux->next != nullptr) {
                aux->next->prev = copia;
            } else {
                tail = copia;
            }
            aux->next = copia;
            size ++;
            aux = copia->next;
        }
    }

    void removeDuplicates() {
        sort();
        DoubleNode<T>* aux = head;
        while (aux != nullptr && aux->next != nullptr) {
            if (aux->data == aux->next->data) {
                DoubleNode<T>* dup = aux->next;
                aux->next = dup->next;
                if (dup->next != nullptr) {
                    dup->next->prev = aux;
                } else {
                    tail = aux;
                }
                delete dup;
                size--;
            }
            else { aux = aux->next;}
        }
    }
};





int main () {

    DoubleNode<int>* n1 = new DoubleNode<int>(10);
    DoubleNode<int>* n2 = new DoubleNode<int>(20);
    DoubleNode<int>* n3 = new DoubleNode<int>(30);

    n1->next = n2;

    n2->prev = n1;
    n2->next = n3;

    n3->prev = n2;

    DoubleNode<int>* head = n1;
    DoubleNode<int>* tail = n3;

    cout << "Recorrido hacia adelante: " << endl;

    DoubleNode<int>* aux = head;
    while (aux != nullptr) {
        cout  << aux->data << "->";
        aux = aux->next;
    }
    cout << "nullptr" << endl;
    cout << endl;

    cout << "Recorrido hacia atras: " << endl;

    aux = tail;
    while (aux != nullptr) {
        cout  << aux->data << "->";
        aux = aux->prev;
    }

    cout << "nullptr" << endl;

    cout << "Borrar lista" << endl;

    aux = head;
    while (aux != nullptr) {
        DoubleNode<int>* temp = aux;
        aux = aux->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;


    DoubleNode<int>* nuevo = new DoubleNode<int>(25);

    nuevo->prev = n2;
    nuevo->next = n3;

    n2->next = nuevo;
    n3->prev = nuevo;





    return 0;
}