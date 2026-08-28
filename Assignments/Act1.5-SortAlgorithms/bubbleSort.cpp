//
// Created by Diego Villanueva Fernandez on 28/08/26.
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
    return 0;
}
