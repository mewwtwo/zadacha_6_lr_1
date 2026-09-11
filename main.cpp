// Dmytro Demchuk K-25 & Polina Harchenko K-28
// GCC 13+ (g++ -std=c++23) | MSVC v19.36+ (/std:c++latest)

#include "Generator.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

static bool fileExists(const string& name) {
    return ifstream(name).good();
}

static void buildFile(const string& name, unsigned long long M) {
    ofstream out(name);
    for (unsigned long long i = 1; i <= M; ++i)
        out << "Питання номер " << i << "." << (i < M ? "\n\n" : "");
}

int main(int argc, char* argv[]) {
    string filename;
    unsigned long long n = 0;
    bool experiment = true;

    if (argc >= 3 && fileExists(argv[1])) {
        filename = argv[1];
        n = stoull(argv[2]);
        experiment = false;
    } else {
        unsigned long long M = 0;
        if (argc >= 3) {
            M = stoull(argv[1]);
            n = stoull(argv[2]);
        } else {
            cout << "M (розмір бази питань): ";
            if (!(cin >> M)) {
                cerr << "Помилка введення M\n";
                return 1;
            }
            cout << "n (питань у варіанті): ";
            if (!(cin >> n)) {
                cerr << "Помилка введення n\n";
                return 1;
            }
        }
        filename = "output.txt";
        buildFile(filename, M);
        cout << "Файл \"" << filename << "\" з " << M << " питань створено.\n";
    }

    return 0;
}