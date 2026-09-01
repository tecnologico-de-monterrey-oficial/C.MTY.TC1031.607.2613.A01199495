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

template <typename T>
void seleSort(vector<T> &list) {
    for (int i = 0; i < list.size() - 1;i++) {
        int min = i;
        for (int j = i + 1; j < list.size(); j++) {
            if (list[j] < list[min]) {
                min = j;
            }
        }
        swap(list[i], list[min]);
    }
}

template <typename T>
void insertSort(vector<T> &list) {
    for (int i = 1; i < list.size(); i++){
        T current = list[i];
        int j = i -1;
        while (j >= 0 && list[j] > current) {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = current;
    }
}

int main() {
    vector<int> test = {3,7,9,12,15,5,2};

    for (int n : test) {
        cout << n << " ";
    }

    cout << endl;
    insertSort(test);
    // seleSort(test);
    // swpaSort(test);
    // bubbleSort(test);

    for (int n : test) {
        cout << n << " ";
    }

    cout << endl;

    return 0;
}