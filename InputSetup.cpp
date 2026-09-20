#include "InputSetup.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

using namespace std;

namespace {
    bool fileExists(const string& name) {
        return ifstream(name).good();
    }

    void buildFile(const string& name, unsigned long long M) {
        ofstream out(name);
        if (!out)
            throw runtime_error("Не вдалося створити файл " + name);
        for (unsigned long long i = 1; i <= M; ++i)
            out << "Питання номер " << i << "." << (i < M ? "\n\n" : "");
    }
    bool parseNumber(const string& text, unsigned long long& value, const string& label) {
        if (text.find('-') != string::npos) {
            cerr << "Помилка: " << label << " не може бути від'ємним\n";
            return false;
        }
        try {
            size_t pos = 0;
            value = stoull(text, &pos);
            if (pos != text.size())
                throw invalid_argument(text);
        } catch (const exception&) {
            cerr << "Помилка: некоректне значення " << label << " = \"" << text << "\"\n";
            return false;
        }
        return true;
    }
}

bool prepareInput(int argc, char* argv[], RunConfig& config) {
    if (argc >= 3 && fileExists(argv[1])) {
        if (!parseNumber(argv[2], config.n, "n"))
            return false;
        config.filename = argv[1];
        config.experiment = false;
        return true;
    }

    unsigned long long M = 0;
    if (argc >= 3) {
        if (!parseNumber(argv[1], M, "M") || !parseNumber(argv[2], config.n, "n"))
            return false;
    } else {
        cout << "M (розмір бази питань): ";
        if (!(cin >> M)) {
            cerr << "Помилка введення M\n";
            return false;
        }
        cout << "n (питань у варіанті): ";
        if (!(cin >> config.n)) {
            cerr << "Помилка введення n\n";
            return false;
        }
    }

    config.filename = "output.txt";
    try {
        buildFile(config.filename, M);
    } catch (const exception& e) {
        cerr << "Помилка: " << e.what() << "\n";
        return false;
    }
    cout << "Файл \"" << config.filename << "\" з " << M << " питань створено.\n";
    config.experiment = true;
    return true;
}
