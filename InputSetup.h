#pragma once
#include <string>

struct RunConfig {
    std::string filename;
    unsigned long long n = 0;
    bool experiment = true;
};

bool prepareInput(int argc, char* argv[], RunConfig& config);
