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

int main(int argc, char* argv[]) {
    return 0;
}