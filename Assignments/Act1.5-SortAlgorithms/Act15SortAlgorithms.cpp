//
// Created by Diego Villanueva Fernandez on 31/08/26.
// Matricula: A01199495
//
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <fstream>
#include <string>
using namespace std;

template <class T>
void bubbleSort(vector<T> &list, long long &comparisons, long long &swaps) {
    comparisons = 0;
    swaps = 0;

    for (int i = 0; i < list.size() - 1; i++) {
        for (int j = 0; j < list.size() - 1 - i; j++) {
            comparisons++;

            if (list[j] > list[j + 1]) {
                swap(list[j], list[j + 1]);
                swaps++;
            }
        }
    }
}

template <typename T>
void swapSort(vector<T> &list, long long &comparisons, long long &swaps) {
    comparisons = 0;
    swaps = 0;

    for (int i = 0; i < list.size() - 1; i++) {
        for (int j = i + 1; j < list.size(); j++) {
            comparisons++;

            if (list[i] > list[j]) {
                swap(list[i], list[j]);
                swaps++;
            }
        }
    }
}

template <typename T>
void selectionSort(vector<T> &list, long long &comparisons, long long &swaps) {
    comparisons = 0;
    swaps = 0;

    for (int i = 0; i < list.size() - 1; i++) {
        int min = i;

        for (int j = i + 1; j < list.size(); j++) {
            comparisons++;

            if (list[j] < list[min]) {
                min = j;
            }
        }

        if (min != i) {
            swap(list[i], list[min]);
            swaps++;
        }
    }
}

template <typename T>
void insertionSort(vector<T> &list, long long &comparisons, long long &swaps) {
    comparisons = 0;
    swaps = 0;

    for (int i = 1; i < list.size(); i++) {
        T current = list[i];
        int j = i - 1;

        while (j >= 0) {
            comparisons++;

            if (list[j] > current) {
                list[j + 1] = list[j];
                swaps++;
                j--;
            }
            else {
                break;
            }
        }

        list[j + 1] = current;
    }
}

template <typename T>
void merge(vector<T> &list, int left, int middle, int right) {
    vector<T> leftList;
    vector<T> rightList;

    for (int i = left; i <= middle; i++) {
        leftList.push_back(list[i]);
    }

    for (int i = middle + 1; i <= right; i++) {
        rightList.push_back(list[i]);
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < leftList.size() && j < rightList.size()) {
        if (leftList[i] <= rightList[j]) {
            list[k] = leftList[i];
            i++;
        }
        else {
            list[k] = rightList[j];
            j++;
        }

        k++;
    }

    while (i < leftList.size()) {
        list[k] = leftList[i];
        i++;
        k++;
    }

    while (j < rightList.size()) {
        list[k] = rightList[j];
        j++;
        k++;
    }
}

template <typename T>
void mergeSort(vector<T> &list, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(list, left, middle);
        mergeSort(list, middle + 1, right);

        merge(list, left, middle, right);
    }
}

template <typename T>
void mergeSort(vector<T> &list) {
    mergeSort(list, 0, list.size() - 1);
}

template <typename T>
int partition(vector<T> &list, int left, int right) {
    T pivot = list[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (list[j] <= pivot) {
            i++;
            swap(list[i], list[j]);
        }
    }

    swap(list[i + 1], list[right]);

    return i + 1;
}

template <typename T>
void quickSort(vector<T> &list, int left, int right) {
    if (left < right) {
        int pivot = partition(list, left, right);

        quickSort(list, left, pivot - 1);
        quickSort(list, pivot + 1, right);
    }
}

template <typename T>
void quickSort(vector<T> &list) {
    quickSort(list, 0, list.size() - 1);
}

template <typename T>
void shellSort(vector<T> &list) {
    for (int gap = list.size() / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < list.size(); i++) {
            T current = list[i];
            int j = i;

            while (j >= gap && list[j - gap] > current) {
                list[j] = list[j - gap];
                j -= gap;
            }

            list[j] = current;
        }
    }
}

vector<int> createIntList(int size) {
    vector<int> list;

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(0, 1000000);

    for (int i = 0; i < size; i++) {
        list.push_back(distribution(generator));
    }

    return list;
}

vector<double> createDoubleList(int size) {
    vector<double> list;

    random_device rd;
    mt19937 generator(rd());
    uniform_real_distribution<double> distribution(0, 1000000);

    for (int i = 0; i < size; i++) {
        list.push_back(distribution(generator));
    }

    return list;
}

vector<char> createCharList(int size) {
    vector<char> list;

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(65, 90);

    for (int i = 0; i < size; i++) {
        list.push_back((char) distribution(generator));
    }

    return list;
}

template <typename T>
void printList(vector<T> &list) {
    for (T n : list) {
        cout << n << " ";
    }

    cout << endl;
}

template <typename T>
long long sortList(vector<T> &list, int algorithm, long long &comparisons, long long &swaps) {
    comparisons = 0;
    swaps = 0;

    auto start = chrono::high_resolution_clock::now();

    if (algorithm == 1) {
        swapSort(list, comparisons, swaps);
    }
    else if (algorithm == 2) {
        bubbleSort(list, comparisons, swaps);
    }
    else if (algorithm == 3) {
        selectionSort(list, comparisons, swaps);
    }
    else if (algorithm == 4) {
        insertionSort(list, comparisons, swaps);
    }
    else if (algorithm == 5) {
        mergeSort(list);
    }
    else if (algorithm == 6) {
        quickSort(list);
    }
    else if (algorithm == 7) {
        shellSort(list);
    }

    auto end = chrono::high_resolution_clock::now();

    return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

template <typename T>
long long getTime(vector<T> originalList, int algorithm) {
    long long comparisons;
    long long swaps;

    return sortList(originalList, algorithm, comparisons, swaps);
}

string getAlgorithmName(int algorithm) {
    if (algorithm == 1) {
        return "Swap Sort";
    }
    else if (algorithm == 2) {
        return "Bubble Sort";
    }
    else if (algorithm == 3) {
        return "Selection Sort";
    }
    else if (algorithm == 4) {
        return "Insertion Sort";
    }
    else if (algorithm == 5) {
        return "Merge Sort";
    }
    else if (algorithm == 6) {
        return "Quick Sort";
    }
    else if (algorithm == 7) {
        return "Shell Sort";
    }

    return "";
}

void intAnalysis(ofstream &file) {
    vector<int> list1000 = createIntList(1000);
    vector<int> list10000 = createIntList(10000);
    vector<int> list100000 = createIntList(100000);

    for (int algorithm = 1; algorithm <= 7; algorithm++) {
        cout << "Probando " << getAlgorithmName(algorithm) << " con int..." << endl;

        long long time1000 = getTime(list1000, algorithm);
        long long time10000 = getTime(list10000, algorithm);
        long long time100000 = getTime(list100000, algorithm);

        file << getAlgorithmName(algorithm) << ",int,"
             << time1000 << ","
             << time10000 << ","
             << time100000 << endl;
    }
}

void doubleAnalysis(ofstream &file) {
    vector<double> list1000 = createDoubleList(1000);
    vector<double> list10000 = createDoubleList(10000);
    vector<double> list100000 = createDoubleList(100000);

    for (int algorithm = 1; algorithm <= 7; algorithm++) {
        cout << "Probando " << getAlgorithmName(algorithm) << " con double..." << endl;

        long long time1000 = getTime(list1000, algorithm);
        long long time10000 = getTime(list10000, algorithm);
        long long time100000 = getTime(list100000, algorithm);

        file << getAlgorithmName(algorithm) << ",double,"
             << time1000 << ","
             << time10000 << ","
             << time100000 << endl;
    }
}

void charAnalysis(ofstream &file) {
    vector<char> list1000 = createCharList(1000);
    vector<char> list10000 = createCharList(10000);
    vector<char> list100000 = createCharList(100000);

    for (int algorithm = 1; algorithm <= 7; algorithm++) {
        cout << "Probando " << getAlgorithmName(algorithm) << " con char..." << endl;

        long long time1000 = getTime(list1000, algorithm);
        long long time10000 = getTime(list10000, algorithm);
        long long time100000 = getTime(list100000, algorithm);

        file << getAlgorithmName(algorithm) << ",char,"
             << time1000 << ","
             << time10000 << ","
             << time100000 << endl;
    }
}

void comparativeAnalysis() {
    ofstream file("sort_times.csv");

    file << "algoritmo,tipoDato,tiempo1000,tiempo10000,tiempo100000" << endl;

    intAnalysis(file);
    doubleAnalysis(file);
    charAnalysis(file);

    file.close();

    cout << endl;
    cout << "Archivo sort_times.csv creado" << endl;
}

int chooseSize() {
    int option;

    cout << endl;
    cout << "1. 1,000 datos" << endl;
    cout << "2. 10,000 datos" << endl;
    cout << "3. 100,000 datos" << endl;
    cout << "Selecciona una opcion: ";
    cin >> option;

    if (option == 1) {
        return 1000;
    }
    else if (option == 2) {
        return 10000;
    }
    else if (option == 3) {
        return 100000;
    }

    return 0;
}

int main() {
    vector<int> intList;
    vector<double> doubleList;
    vector<char> charList;

    int dataType = 0;
    int option = -1;

    while (option != 0) {
        cout << endl;
        cout << "Act 1.5 Sort Algorithms" << endl;
        cout << endl;
        cout << "1. Crear lista" << endl;
        cout << "2. Swap Sort" << endl;
        cout << "3. Bubble Sort" << endl;
        cout << "4. Selection Sort" << endl;
        cout << "5. Insertion Sort" << endl;
        cout << "6. Merge Sort" << endl;
        cout << "7. Quick Sort" << endl;
        cout << "8. Shell Sort" << endl;
        cout << "9. Mostrar lista" << endl;
        cout << "10. Analisis comparativo CSV" << endl;
        cout << "0. Salir" << endl;
        cout << endl;
        cout << "Selecciona una opcion: ";

        cin >> option;

        if (option == 1) {
            cout << endl;
            cout << "1. int" << endl;
            cout << "2. double" << endl;
            cout << "3. char" << endl;
            cout << "Selecciona el tipo de dato: ";

            cin >> dataType;

            int size = chooseSize();

            if (size == 0) {
                cout << "Tamano invalido" << endl;
                continue;
            }

            if (dataType == 1) {
                intList = createIntList(size);
            }
            else if (dataType == 2) {
                doubleList = createDoubleList(size);
            }
            else if (dataType == 3) {
                charList = createCharList(size);
            }
            else {
                cout << "Tipo de dato invalido" << endl;
                dataType = 0;
                continue;
            }

            cout << "Lista creada con " << size << " datos" << endl;
        }

        else if (option >= 2 && option <= 8) {
            if (dataType == 0) {
                cout << "Primero debes crear una lista" << endl;
                continue;
            }

            int algorithm = option - 1;

            long long comparisons = 0;
            long long swaps = 0;
            long long time = 0;

            if (dataType == 1) {
                time = sortList(intList, algorithm, comparisons, swaps);

                cout << endl;
                cout << "Lista ordenada:" << endl;
                printList(intList);
            }
            else if (dataType == 2) {
                time = sortList(doubleList, algorithm, comparisons, swaps);

                cout << endl;
                cout << "Lista ordenada:" << endl;
                printList(doubleList);
            }
            else if (dataType == 3) {
                time = sortList(charList, algorithm, comparisons, swaps);

                cout << endl;
                cout << "Lista ordenada:" << endl;
                printList(charList);
            }

            cout << endl;
            cout << "Algoritmo: " << getAlgorithmName(algorithm) << endl;
            cout << "Tiempo: " << time << " nanosegundos" << endl;

            if (algorithm <= 4) {
                cout << "Comparaciones: " << comparisons << endl;
                cout << "Intercambios: " << swaps << endl;
            }
        }

        else if (option == 9) {
            if (dataType == 1) {
                printList(intList);
            }
            else if (dataType == 2) {
                printList(doubleList);
            }
            else if (dataType == 3) {
                printList(charList);
            }
            else {
                cout << "Primero debes crear una lista" << endl;
            }
        }

        else if (option == 10) {
            comparativeAnalysis();
        }

        else if (option != 0) {
            cout << "Opcion invalida" << endl;
        }
    }

    return 0;
}