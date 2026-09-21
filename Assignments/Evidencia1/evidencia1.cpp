//
// Created by Diego Villanueva Fernandez on 20/09/26.
// Matricula:  A01199495
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

struct LogEntry {
    string month;
    int day;
    int year;
    string time;
    string ip;
    string message;
    long long timestamp;
};

bool operator>(const LogEntry &a, const LogEntry &b) {
    return a.timestamp > b.timestamp;
}

bool operator<(const LogEntry &a, const LogEntry &b) {
    return a.timestamp < b.timestamp;
}

bool operator<=(const LogEntry &a, const LogEntry &b) {
    return a.timestamp <= b.timestamp;
}

int getMonthNumber(const string &month) {
    if (month == "Jan") return 1;
    if (month == "Feb") return 2;
    if (month == "Mar") return 3;
    if (month == "Apr") return 4;
    if (month == "May") return 5;
    if (month == "Jun") return 6;
    if (month == "Jul") return 7;
    if (month == "Aug") return 8;
    if (month == "Sep") return 9;
    if (month == "Oct") return 10;
    if (month == "Nov") return 11;
    if (month == "Dec") return 12;

    return 0;
}

long long createTimestamp(const LogEntry &entry) {
    int month = getMonthNumber(entry.month);
    int hour = stoi(entry.time.substr(0, 2));
    int minute = stoi(entry.time.substr(3, 2));
    int second = stoi(entry.time.substr(6, 2));
    long long timestamp = entry.year;

    timestamp = timestamp * 100 + month;
    timestamp = timestamp * 100 + entry.day;
    timestamp = timestamp * 100 + hour;
    timestamp = timestamp * 100 + minute;
    timestamp = timestamp * 100 + second;

    return timestamp;
}

LogEntry parseLine(const string &line) {
    LogEntry entry;
    stringstream ss(line);

    ss >> entry.month;
    ss >> entry.day;
    ss >> entry.year;
    ss >> entry.time;
    ss >> entry.ip;

    getline(ss, entry.message);

    if (!entry.message.empty() && entry.message[0] == ' ') {
        entry.message.erase(0, 1);
    }

    entry.timestamp = createTimestamp(entry);

    return entry;
}

vector<LogEntry> readFile(const string &filePath) {
    vector<LogEntry> entries;
    ifstream file(filePath);

    if (!file.is_open()) {
        cout << "Could not open the file." << endl;
        return entries;
    }

    string line;

    while (getline(file, line)) {
        LogEntry entry = parseLine(line);
        entries.push_back(entry);
    }

    file.close();

    return entries;
}

void printLogEntry(const LogEntry &entry) {
    cout << entry.month << " "
         << entry.day << " "
         << entry.year << " "
         << entry.time << " "
         << entry.ip << " "
         << entry.message << endl;
}

void swapSort(vector<LogEntry> &list) {
    for (int i = 0; i < list.size() - 1; i++) {
        for (int j = i + 1; j < list.size(); j++) {
            if (list[i] > list[j]) {
                swap(list[i], list[j]);
            }
        }
    }
}

void bubbleSort(vector<LogEntry> &list) {
    for (int i = 0; i < list.size() - 1; i++) {
        for (int j = 0; j < list.size() - 1 - i; j++) {
            if (list[j] > list[j + 1]) {
                swap(list[j], list[j + 1]);
            }
        }
    }
}

void selectionSort(vector<LogEntry> &list) {
    for (int i = 0; i < list.size() - 1; i++) {
        int min = i;

        for (int j = i + 1; j < list.size(); j++) {
            if (list[j] < list[min]) {
                min = j;
            }
        }

        if (min != i) {
            swap(list[i], list[min]);
        }
    }
}

void insertionSort(vector<LogEntry> &list) {
    for (int i = 1; i < list.size(); i++) {
        LogEntry current = list[i];
        int j = i - 1;

        while (j >= 0 && list[j] > current) {
            list[j + 1] = list[j];
            j--;
        }

        list[j + 1] = current;
    }
}

void merge(vector<LogEntry> &list, int left, int middle, int right) {
    vector<LogEntry> leftList;
    vector<LogEntry> rightList;

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

void mergeSort(vector<LogEntry> &list, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(list, left, middle);
        mergeSort(list, middle + 1, right);

        merge(list, left, middle, right);
    }
}

void mergeSort(vector<LogEntry> &list) {
    mergeSort(list, 0, list.size() - 1);
}

int partition(vector<LogEntry> &list, int left, int right) {
    LogEntry pivot = list[right];
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

void quickSort(vector<LogEntry> &list, int left, int right) {
    if (left < right) {
        int pivot = partition(list, left, right);

        quickSort(list, left, pivot - 1);
        quickSort(list, pivot + 1, right);
    }
}

void quickSort(vector<LogEntry> &list) {
    quickSort(list, 0, list.size() - 1);
}

void shellSort(vector<LogEntry> &list) {
    for (int gap = list.size() / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < list.size(); i++) {
            LogEntry current = list[i];
            int j = i;

            while (j >= gap && list[j - gap] > current) {
                list[j] = list[j - gap];
                j -= gap;
            }

            list[j] = current;
        }
    }
}

string chooseFile(string &fileName) {
    int option;

    cout << "Choose a file:" << endl;
    cout << "1. log607-1.txt" << endl;
    cout << "2. log607-2.txt" << endl;
    cout << "Option: ";
    cin >> option;

    if (option == 1) {
        fileName = "log607-1.txt";
        return "../Assignments/Evidencia1/log607-1.txt";
    }
    else if (option == 2) {
        fileName = "log607-2.txt";
        return "../Assignments/Evidencia1/log607-2.txt";
    }

    return "";
}

int chooseAlgorithm() {
    int option;

    cout << endl;
    cout << "Choose a sorting algorithm:" << endl;
    cout << "1. Swap Sort" << endl;
    cout << "2. Bubble Sort" << endl;
    cout << "3. Selection Sort" << endl;
    cout << "4. Insertion Sort" << endl;
    cout << "5. Merge Sort" << endl;
    cout << "6. Quick Sort" << endl;
    cout << "7. Shell Sort" << endl;
    cout << "Option: ";
    cin >> option;

    return option;
}

string getAlgorithmName(int algorithm) {
    if (algorithm == 1) return "Swap Sort";
    if (algorithm == 2) return "Bubble Sort";
    if (algorithm == 3) return "Selection Sort";
    if (algorithm == 4) return "Insertion Sort";
    if (algorithm == 5) return "Merge Sort";
    if (algorithm == 6) return "Quick Sort";
    if (algorithm == 7) return "Shell Sort";

    return "";
}

string getBestComplexity(int algorithm) {
    if (algorithm == 1) return "O(n^2)";
    if (algorithm == 2) return "O(n^2)";
    if (algorithm == 3) return "O(n^2)";
    if (algorithm == 4) return "O(n)";
    if (algorithm == 5) return "O(n log n)";
    if (algorithm == 6) return "O(n log n)";
    if (algorithm == 7) return "O(n log n)";

    return "";
}

string getWorstComplexity(int algorithm) {
    if (algorithm == 1) return "O(n^2)";
    if (algorithm == 2) return "O(n^2)";
    if (algorithm == 3) return "O(n^2)";
    if (algorithm == 4) return "O(n^2)";
    if (algorithm == 5) return "O(n log n)";
    if (algorithm == 6) return "O(n^2)";
    if (algorithm == 7) return "O(n^2)";

    return "";
}

void runSort(vector<LogEntry> &entries, int algorithm) {
    if (algorithm == 1) {
        swapSort(entries);
    }
    else if (algorithm == 2) {
        bubbleSort(entries);
    }
    else if (algorithm == 3) {
        selectionSort(entries);
    }
    else if (algorithm == 4) {
        insertionSort(entries);
    }
    else if (algorithm == 5) {
        mergeSort(entries);
    }
    else if (algorithm == 6) {
        quickSort(entries);
    }
    else if (algorithm == 7) {
        shellSort(entries);
    }
}

int main() {
    string fileName;
    string filePath = chooseFile(fileName);

    if (filePath == "") {
        cout << "Invalid file option." << endl;
        return 1;
    }

    vector<LogEntry> entries = readFile(filePath);

    if (entries.empty()) {
        cout << "The file is empty or could not be read." << endl;
        return 1;
    }

    int algorithm = chooseAlgorithm();

    if (algorithm < 1 || algorithm > 7) {
        cout << "Invalid algorithm option." << endl;
        return 1;
    }

    cin.ignore();

    string prediction;
    string predictionReason;

    cout << endl;
    cout << "How fast do you expect this combination to be?" << endl;
    cout << "Examples: very fast, fast, medium, slow, very slow" << endl;
    cout << "Prediction: ";
    getline(cin, prediction);

    cout << "Why do you expect that result?" << endl;
    cout << "Reason: ";
    getline(cin, predictionReason);

    cout << endl;
    cout << "First record before sorting:" << endl;
    printLogEntry(entries[0]);

    auto start = chrono::high_resolution_clock::now();

    runSort(entries, algorithm);

    auto end = chrono::high_resolution_clock::now();

    double time = chrono::duration<double, milli>(end - start).count();

    cout << endl;
    cout << "First record after sorting:" << endl;
    printLogEntry(entries[0]);

    cout << endl;
    cout << "Last record after sorting:" << endl;
    printLogEntry(entries[entries.size() - 1]);

    cout << endl;
    cout << "Sorting results:" << endl;
    cout << "File: " << fileName << endl;
    cout << "Records: " << entries.size() << endl;
    cout << "Algorithm: " << getAlgorithmName(algorithm) << endl;
    cout << "Execution time: " << time << " ms" << endl;
    cout << "Best case: " << getBestComplexity(algorithm) << endl;
    cout << "Worst case: " << getWorstComplexity(algorithm) << endl;

    cout << endl;
    cout << "Initial prediction:" << endl;
    cout << "Expected speed: " << prediction << endl;
    cout << "Reason: " << predictionReason << endl;

    return 0;
}