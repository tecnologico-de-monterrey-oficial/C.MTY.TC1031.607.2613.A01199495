//
// Created by Diego Villanueva Fernandez on 20/09/26.
// Matricula: A01199495
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>
#include <iomanip>

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

bool isLeapYear(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    return year % 4 == 0;
}

int getDaysInMonth(int month, int year) {
    if (month == 2) {
        if (isLeapYear(year)) return 29;
        return 28;
    }

    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }

    return 31;
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

bool parseDateTime(const string &dateTime, long long &timestamp) {
    string month;
    string time;
    int day;
    int year;

    stringstream ss(dateTime);

    if (!(ss >> month >> day >> year >> time)) {
        return false;
    }

    string extra;

    if (ss >> extra) {
        return false;
    }

    int monthNumber = getMonthNumber(month);

    if (monthNumber == 0) {
        return false;
    }

    if (year < 1) {
        return false;
    }

    if (day < 1 || day > getDaysInMonth(monthNumber, year)) {
        return false;
    }

    if (time.length() != 8 || time[2] != ':' || time[5] != ':') {
        return false;
    }

    for (int i = 0; i < time.length(); i++) {
        if (i == 2 || i == 5) continue;

        if (time[i] < '0' || time[i] > '9') {
            return false;
        }
    }

    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));
    int second = stoi(time.substr(6, 2));

    if (hour < 0 || hour > 23) {
        return false;
    }

    if (minute < 0 || minute > 59) {
        return false;
    }

    if (second < 0 || second > 59) {
        return false;
    }

    LogEntry entry;
    entry.month = month;
    entry.day = day;
    entry.year = year;
    entry.time = time;

    timestamp = createTimestamp(entry);

    return true;
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

void writeLogEntry(ostream &output, const LogEntry &entry) {
    output << entry.month << " "
           << setw(2) << setfill('0') << entry.day << " "
           << entry.year << " "
           << entry.time << " "
           << entry.ip << " "
           << entry.message;

    output << setfill(' ');
}

void printLogEntry(const LogEntry &entry) {
    writeLogEntry(cout, entry);
    cout << endl;
}

void saveOutput(const vector<LogEntry> &entries, const string &filePath) {
    ofstream file(filePath);

    if (!file.is_open()) {
        cout << "Could not create output607.txt." << endl;
        return;
    }

    for (const LogEntry &entry : entries) {
        writeLogEntry(file, entry);
        file << endl;
    }

    file.close();
}

void saveRange(
    const vector<LogEntry> &entries,
    int startIndex,
    int endIndex,
    const string &filePath
) {
    ofstream file(filePath);

    if (!file.is_open()) {
        cout << "Could not create range607.txt." << endl;
        return;
    }

    for (int i = startIndex; i < endIndex; i++) {
        writeLogEntry(file, entries[i]);
        file << endl;
    }

    file.close();
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

int lowerBoundTimestamp(
    const vector<LogEntry> &entries,
    long long target
) {
    int left = 0;
    int right = entries.size();

    while (left < right) {
        int middle = left + (right - left) / 2;

        if (entries[middle].timestamp < target) {
            left = middle + 1;
        }
        else {
            right = middle;
        }
    }

    return left;
}

int upperBoundTimestamp(
    const vector<LogEntry> &entries,
    long long target
) {
    int left = 0;
    int right = entries.size();

    while (left < right) {
        int middle = left + (right - left) / 2;

        if (entries[middle].timestamp <= target) {
            left = middle + 1;
        }
        else {
            right = middle;
        }
    }

    return left;
}

string chooseFile(string &fileName) {
    int option;

    while (true) {
        cout << "Choose a file:" << endl;
        cout << "1. log607-1.txt" << endl;
        cout << "2. log607-2.txt" << endl;
        cout << "Option: ";

        if (cin >> option && (option == 1 || option == 2)) {
            break;
        }

        cout << "Invalid option. Enter 1 or 2." << endl;
        cout << endl;

        cin.clear();
        cin.ignore(10000, '\n');
    }

    if (option == 1) {
        fileName = "log607-1.txt";
        return "../Evidences/Evidence1/Evidencia1/log607-1.txt";
    }

    fileName = "log607-2.txt";
    return "../Evidences/Evidence1/Evidencia1/log607-2.txt";
}

int chooseAlgorithm() {
    int option;

    while (true) {
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

        if (cin >> option && option >= 1 && option <= 7) {
            break;
        }

        cout << "Invalid option. Enter a number from 1 to 7." << endl;

        cin.clear();
        cin.ignore(10000, '\n');
    }

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
    bool runAgain = true;

    while (runAgain) {
        cout << endl;
        cout << "----------------------------------------" << endl;
        cout << "Evidence 1 - Sorting and Range Search" << endl;
        cout << "----------------------------------------" << endl;
        cout << endl;

        string fileName;
        string filePath = chooseFile(fileName);
        vector<LogEntry> entries = readFile(filePath);

        if (entries.empty()) {
            cout << "The file is empty or could not be read." << endl;
            return 1;
        }

        int algorithm = chooseAlgorithm();

        cin.ignore(10000, '\n');

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

        double time =
            chrono::duration<double, milli>(end - start).count();

        string outputPath =
            "../Evidences/Evidence1/Evidencia1/output607.txt";

        saveOutput(entries, outputPath);

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
        cout << "Output saved in output607.txt" << endl;

        cout << endl;
        cout << "Initial prediction:" << endl;
        cout << "Expected speed: " << prediction << endl;
        cout << "Reason: " << predictionReason << endl;

        string predictionMatch;

        cout << endl;
        cout << "Did the measured result match your initial prediction? ";
        getline(cin, predictionMatch);

        cout << "Prediction comparison: "
             << predictionMatch
             << endl;

        string startDate;
        string endDate;

        long long startTimestamp;
        long long endTimestamp;

        cout << endl;
        cout << "Range search" << endl;
        cout << "Enter dates using this format: "
             << "Sep 29 2024 14:37:38"
             << endl;
        cout << "The start and end limits are inclusive." << endl;
        cout << "If duplicate timestamps match either limit, "
             << "all duplicates are included."
             << endl;

        while (true) {
            cout << "Start date and time: ";
            getline(cin, startDate);

            if (parseDateTime(startDate, startTimestamp)) {
                break;
            }

            cout << "Invalid date format. Try again." << endl;
        }

        while (true) {
            cout << "End date and time: ";
            getline(cin, endDate);

            if (!parseDateTime(endDate, endTimestamp)) {
                cout << "Invalid date format. Try again." << endl;
                continue;
            }

            if (startTimestamp > endTimestamp) {
                cout << "The end date must be equal to or after "
                     << "the start date."
                     << endl;
                continue;
            }

            break;
        }

        int startIndex =
            lowerBoundTimestamp(entries, startTimestamp);

        int endIndex =
            upperBoundTimestamp(entries, endTimestamp);

        string rangePath =
            "../Evidences/Evidence1/Evidencia1/range607.txt";

        saveRange(
            entries,
            startIndex,
            endIndex,
            rangePath
        );

        cout << endl;
        cout << "Range results:" << endl;

        if (startIndex >= endIndex) {
            cout << "No records were found in this range." << endl;
        }
        else {
            cout << "Records found: "
                 << endIndex - startIndex
                 << endl;

            cout << endl;

            for (int i = startIndex; i < endIndex; i++) {
                printLogEntry(entries[i]);
            }
        }

        cout << endl;
        cout << "Range saved in range607.txt" << endl;

        string repeatOption;

        while (true) {
            cout << endl;
            cout << "Do you want to run another test? (yes/no): ";
            getline(cin, repeatOption);

            if (
                repeatOption == "yes" ||
                repeatOption == "Yes" ||
                repeatOption == "y" ||
                repeatOption == "Y"
            ) {
                runAgain = true;
                break;
            }

            if (
                repeatOption == "no" ||
                repeatOption == "No" ||
                repeatOption == "n" ||
                repeatOption == "N"
            ) {
                runAgain = false;
                break;
            }

            cout << "Invalid option. Enter yes or no." << endl;
        }
    }

    cout << endl;
    cout << "Program finished." << endl;

    return 0;
}