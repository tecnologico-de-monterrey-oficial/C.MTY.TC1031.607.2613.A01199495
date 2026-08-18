// Created by Diego Villanueva Fernandez on 18/08/26.
// A01199495

#include "Act12Recursion.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Suma iterativa:    " << Act12Recursion::sumIterative(5) << endl;
    cout << "Suma recursiva:    " << Act12Recursion::sumRecursive(5) << endl;
    cout << "Suma formula:      " << Act12Recursion::sumFormula(5) << endl;
    cout << "FibonacciIterative: " << Act12Recursion::fibonacciIterative(6) << endl;
    cout << "FibonacciRecursive: " << Act12Recursion::fibonacciRecursive(6) << endl;
    cout << "bacteriasIterative: " << Act12Recursion::bacteriasIterative(5) << endl;
    cout << "bacteriasRecursive: " << Act12Recursion::bacteriasRecursive(5) << endl;
    cout << "investmentIterative: " << Act12Recursion::investmentIterative(100,5) << endl;
    cout << "investmentRecursive: " << Act12Recursion::investmentRecursive(100,5) << endl;
    cout << "powIterative:       " << Act12Recursion::powIterative(5,5) << endl;
    cout << "powRecursive:       " << Act12Recursion::powRecursive(5,5) << endl;





    return 0;
}
