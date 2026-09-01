//
// Created by Diego Villanueva Fernandez on 31/08/26.
// Matricula: A01199495
//
#include <iostream>
using namespace std;

template <class T>
void bubbleSort(vector<T> &list) {
    for (int i = 0; i<list.size() -1; i++) {
        for (int j = 0; j<list.size() - 1; j++) {
            if (list[j] > list[j+1]) {
                swap(list[j],list[j+1]);
            }
        }
    }
}

template <typename T>
void swpaSort(vector<T> &list) {
    for (int i = 0; i < list.size() - 1;i++) {
        for (int j = i + 1; j < list.size();j++) {
            if (list[i] > list[j]) {
                swap(list[i], list[j]);
            }
        }

    }
}


int main() {
    vector<int> test = {15,7,3,9,12,5,2};
    for (int n : test) {
        cout << n << " ";
    };
    cout << endl;
    bubbleSort(test);
    for (int n : test) {
        cout << n << " ";
    };

    for (int n : test) {
        cout << n << " ";
    }
    cout << endl;
    swpaSort(test);
    for (int n : test) {
        cout << n << " ";
    }
    return 0;
}