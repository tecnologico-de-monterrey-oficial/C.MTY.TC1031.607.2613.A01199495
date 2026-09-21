//
// Created by Diego Villanueva Fernandez on 20/09/26.
// Matricula: A01199495
//
//
// Created by Diego Villanueva Fernandez on 20/09/26.
// Student ID: A01199495
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> readFile(const string &filePath) {
    vector<string> lines;

    ifstream file(filePath);

    if (!file.is_open()) {
        cout << "Could not open the file." << endl;
        return lines;
    }

    string line;

    while (getline(file, line)) {
        lines.push_back(line);
    }

    file.close();

    return lines;
}

int main() {

    string filePath = "../Assignments/Evidencia1/log607-1.txt";

    vector<string> lines = readFile(filePath);

    if (lines.empty()) {
        cout << "The file is empty or could not be read." << endl;
        return 1;
    }

    cout << "File read successfully." << endl;
    cout << "Total records: " << lines.size() << endl;

    cout << endl;
    cout << "First record:" << endl;
    cout << lines[0] << endl;

    return 0;
}