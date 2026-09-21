//
// Created by Diego Villanueva Fernandez on 20/09/26.
// Matricula:  A01199495
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct LogEntry {
    string month;
    int day;
    int year;
    string time;
    string ip;
    string message;
};

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

int main() {

    string filePath = "../Assignments/Evidencia1/log607-1.txt";

    vector<LogEntry> entries = readFile(filePath);

    if (entries.empty()) {
        cout << "The file is empty or could not be read." << endl;
        return 1;
    }

    cout << "File read successfully." << endl;
    cout << "Total records: " << entries.size() << endl;

    cout << endl;
    cout << "First record:" << endl;
    printLogEntry(entries[0]);

    return 0;
}