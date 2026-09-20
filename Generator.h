#pragma once
#include <string>
#include <vector>
#include <set>
#include <random>
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

    static unsigned long long C(unsigned long long M, unsigned long long n);

public:
    Generator(const string& filename, size_t tasksCount);
    unsigned long long total() const;
    string operator()();
};
