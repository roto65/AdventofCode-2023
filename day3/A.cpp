#include <bits/stdc++.h>

#include "../shared.hpp"

int len;
std::string s;

bool checkSurround(int i, int size) {
    char c;

    try {
        c = s.at(i - 1);
        if (!isdigit(c) && c != '.') return true;
    } catch (std::out_of_range ex) {
    };

    try {
        c = s.at(i + size);
        if (!isdigit(c) && c != '.') return true;
    } catch (std::out_of_range ex) {
    };

    for (int j = -1; j <= size; j++) {
        try {
            c = s.at(i - len + j);
            if (!isdigit(c) && c != '.') return true;
        } catch (std::out_of_range ex) {
        };

        try {
            c = s.at(i + len + j);
            if (!isdigit(c) && c != '.') return true;
        } catch (std::out_of_range ex) {
        };
    }

    return false;
}

int main(void) {
    std::vector<std::string> data = readFile("input.txt");

    len = data.at(0).size();

    for (std::string line : data) {
        s += line;
    }

    long long sum = 0;

    for (int i = 0; i < s.size(); i++) {
        int num = 0;
        while (isdigit(s.at(i))) {
            num = (num * 10) + int(s.at(i) - '0');
            i++;
        }
        if (num != 0) {
            int size = std::to_string(num).size();
            if (checkSurround(i - size, size)) {
                sum += num;
            }
        }
    }

    std::cout << sum << std::endl;

    return 0;
}

// Solution: 533784