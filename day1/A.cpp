#include <bits/stdc++.h>

#include "../shared.hpp"

int evalValue(std::string& s) {
    int value = 0;

    for (char c : s) {
        if (isdigit(c)) {
            value += int(c - '0') * 10;
            break;
        }
    }

    reverse(s.begin(), s.end());

    for (char c : s) {
        if (isdigit(c)) {
            value += int(c - '0');
            break;
        }
    }


    return value;
}

int main(void) {

    std::vector<std::string> data = readFile("input.txt");

    long long sum = 0;

    for (std::string s : data) {
        sum += evalValue(s);
    }

    std::cout << sum << std::endl;

    return 0;
}