//
// Created by Diego Villanueva Fernandez on 14/08/26.
//

#ifndef C_MTY_TC1031_607_2613_A01199495_LIST_H
#define C_MTY_TC1031_607_2613_A01199495_LIST_H
#include <vector>
using namespace std;
template <typename T>
class List {
private:
    vector<T> list;
    int size;
public:
    List();
    void insert(T data);
    void removeLast();
    T getData(int pos);
    int getSize();
    T getMax();
    void print();
    void insertAt(int pos, T data);
    void removeAt(int pos);
};

template<typename T>
List<T>::List() {
    size = 0;
}

template <typename T>
void List<T>::insert(T data) {
    list.push_back(data);
    size++;
}

template <typename T>
void List<T>::removeLast() {
    if (size > 0) {
        cout << list[size-1] << endl;
        list.pop_back();
        size--;
    } else {
        cout << "NO HAY ELEMENTOS" << endl;
    }
}

template <typename T>
T List<T>::getData(int pos) {
    return list[pos];
}

template <typename T>
int List<T>::getSize() {
    return size;
}

template <typename T>
T List<T>::getMax() {
    T maxVal = list[0];
    for (int i = 1; i < size; i++) {
        if (list[i] > maxVal) {
            maxVal = list[i];
        }
    }
    return maxVal;
}

template <typename T>
void List<T>::print() {
    for (int i = 0; i < size; i++) {
        cout << "[" << i << "] - " << list[i] << endl;
    }
}

template <typename T>
void List<T>::insertAt(int pos, T data) {
    if (pos < 0 || pos > size) {
        cout << "POSICIÓN INVÁLIDA" << endl;
        return;
    }
    list.push_back(data);
    for (int i = size; i > pos; i--) {
        list[i] = list[i-1];
    }
    list[pos] = data;
    size++;
}

template <typename T>
void List<T>::removeAt(int pos) {
    if (size == 0) {
        cout << "NO HAY ELEMENTOS" << endl;
        return;
    }
    if (pos < 0 || pos >= size) {
        cout << "POSICIÓN INVÁLIDA" << endl;
        return;
    }
    cout << list[pos] << endl;
    for (int i = pos; i < size-1; i++) {
        list[i] = list[i+1];
    }
    list.pop_back();
    size--;
}

#endif //C_MTY_TC1031_607_2613_A01199495_LIST_H
