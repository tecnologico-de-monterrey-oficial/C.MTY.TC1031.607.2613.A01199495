//
// Created by Diego Villanueva Fernandez on 14/08/26.
//
#include <iostream>
#include "List.h"
using namespace std;

int main() {
    List<int> list;
    list.insert(5);
    list.insert(10);
    list.insert(15);
    list.print();

    cout << endl << "getSize: " << list.getSize() << endl;
    cout << "getData(1): " << list.getData(1) << endl;
    cout << "getMax: " << list.getMax() << endl;

    cout << endl << "insertAt(1, 99):" << endl;
    list.insertAt(1, 99);
    list.print();

    cout << endl << "removeAt(0):" << endl;
    list.removeAt(0);
    list.print();

    cout << endl << "removeLast:" << endl;
    list.removeLast();
    list.print();

    cout << endl << "insertAt posición inválida (10):" << endl;
    list.insertAt(10, 1);

    cout << endl << "removeAt lista vacía:" << endl;
    List<int> empty;
    empty.removeAt(0);

    cout << endl << "List<string>:" << endl;
    List<string> things;
    things.insert("Laptop");
    things.insert("Bottle");
    things.insert("Mouse");
    things.print();

    cout << endl << "removeAt(1):" << endl;
    things.removeAt(1);
    things.print();

    return 0;
}