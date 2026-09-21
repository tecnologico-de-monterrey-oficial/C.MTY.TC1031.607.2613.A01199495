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
    long long timestamp;
};

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

    cout << "Timestamp: " << entries[0].timestamp << endl;

    return 0;
}