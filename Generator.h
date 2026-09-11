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