//
// Created by Diego Villanueva Fernandez on 31/08/26.
// Matricula: A01199495
//
#include <iostream>
#include <string>
using namespace std;

int secuencial(string &s, char &resultado) {
    int n = s.size();
    int comparaciones = 0;
    int i = 0;
    while (i < n - 1) {
        comparaciones++;
        if (s[i] != s[i + 1]) {
            resultado = s[i];
            return comparaciones;
        }
        i += 2;
    }
    resultado = s[n - 1];
    return comparaciones;
}

int binaria(string &s, char &resultado) {
    int n = s.size();
    int k = (n - 1) / 2;
    int low = 0, high = k;
    int comparaciones = 0;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (mid == k) {
            high = mid;
        } else {
            comparaciones++;
            if (s[2 * mid] != s[2 * mid + 1]) high = mid;
            else low = mid + 1;
        }
    }
    resultado = (low == k) ? s[n - 1] : s[2 * low];
    return comparaciones;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        char r1, r2;
        int c1 = secuencial(s, r1);
        int c2 = binaria(s, r2);
        cout << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
    }
    return 0;
}