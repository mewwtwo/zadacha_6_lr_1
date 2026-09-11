#pragma once
#include <string>
#include <vector>
#include <set>
#include <random>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <functional>
#include <compare>

using namespace std;

struct Variants {
    set<size_t, less<size_t>> indices;

    auto operator<=>(const Variants& other) const = default;
};

struct NoMoreVariants : runtime_error {
    NoMoreVariants() : runtime_error("Усі унікальні варіанти вже згенеровано") {}
};
class Generator {
    vector<string> q;
    size_t n;

    set<Variants, less<Variants>> used;
    mt19937 rng{random_device{}()};

    static unsigned long long C(unsigned long long M, unsigned long long n) {
        if (n > M) return 0;
        n = min(n, M - n);
        unsigned long long r = 1;
        for (unsigned long long i = 1; i <= n; ++i) {
            r = r * (M - n + i) / i;
        }
        return r;
    }

public:
    Generator(const string& filename, size_t tasksCount) {
        this->n = tasksCount;
        ifstream in(filename);
        if (!in)
            throw runtime_error("Не вдалося відкрити файл " + filename);

        string line, para;

        auto flush = [&para, this]() {
            if (!para.empty()) {
                q.push_back(para);
                para.clear();
            }
        };

        auto isBlank = [](const string& s) {
            return s.find_first_not_of(" \t\r") == string::npos;
        };

        while (getline(in, line)) {
            if (isBlank(line))
                flush();
            else
                para += (para.empty() ? "" : "\n") + line;
        }
        flush();

        if (q.empty())
            throw runtime_error("У файлі немає жодного питання");
        if (n == 0 || n > q.size())
            throw invalid_argument("n має бути в межах 1.." + to_string(q.size()));
    }
    unsigned long long total() const {
        return C(q.size(), n);
    }
    string operator()() {
        if (used.size() >= total())
            throw NoMoreVariants();

        uniform_int_distribution<size_t> dist(0, q.size() - 1);
        Variants ticket;

        do {
            ticket.indices.clear();
            while (ticket.indices.size() < n) {
                ticket.indices.insert(dist(rng));
            }
        } while (used.contains(ticket));

        used.insert(ticket);

        return "";
    }
};