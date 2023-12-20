#include <bits/stdc++.h>

#include "../shared.hpp"

int hash(std::string s) {
    int currValue = 0;

    for (char c : s) {
        currValue += (int)c;
        currValue *= 17;
        currValue %= 256;
    }
    return currValue;
}

int main(void) {
    std::vector<std::string> data = readFile("input.txt");
    data = split(data.at(0), ',');

    long long sum = 0;

    for (std::string s : data) {
        sum += hash(s);
    }

    std::cout << sum << std::endl;

    return 0;
}

// Solution: 514639