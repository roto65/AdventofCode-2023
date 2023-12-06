#include <bits/stdc++.h>

#include "../shared.hpp"

int main(void) {
    std::vector<std::string> data = readFile("input.txt");

    long long time = std::stoull(std::regex_replace(data.at(0).substr(5), std::regex("\\s+"), ""));

    long long distance = std::stoull(std::regex_replace(data.at(1).substr(9), std::regex("\\s+"), ""));

    long long sum = 0;

    for (long long i = 1; i <= time; i++) {
        if (i * (time - i) > distance) {
            sum++;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}

// Solution: 29432455