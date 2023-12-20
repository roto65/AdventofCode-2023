#include <bits/stdc++.h>

#include "../shared.hpp"

int main(void) {
    std::vector<std::string> data = readFile("input.txt");

    std::string str = "";
    for (std::string line : data) {
        str += line;
    }
    int len = data.at(0).size();
    int rows = data.size();

    for (int i = 0; i < str.size(); i++) {
        if (str.at(i) != 'O') continue;

        int j = i;
        try {
            while (str.at(j - len) == '.') {
                str.at(j) = '.';
                str.at(j - len) = 'O';
                j -= len;
            }
        } catch (std::out_of_range ex) {
        };
    }

    long long sum = 0;

    std::reverse(str.begin(), str.end());

    for (int i = 0; i < str.size(); i++) {
        if (str.at(i) == 'O') {
            sum += (i / rows) + 1;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}

// Solution: 105784