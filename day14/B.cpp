#include <bits/stdc++.h>

#include "../shared.hpp"

constexpr int CYCLES = 1'000'000'000;

void cycle(std::vector<std::string>& data) {
    int len = data.at(0).size();
    int rows = data.size();

    // North
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < len; x++) {
            if (data.at(y).at(x) != 'O') continue;

            int j = y;
            try {
                while (data.at(j - 1).at(x) == '.') {
                    data.at(j).at(x) = '.';
                    data.at(j - 1).at(x) = 'O';
                    j -= 1;
                }
            } catch (std::out_of_range ex) {
            };
        }
    }

    // West
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < len; x++) {
            if (data.at(y).at(x) != 'O') continue;

            int j = x;
            try {
                while (data.at(y).at(j - 1) == '.') {
                    data.at(y).at(j) = '.';
                    data.at(y).at(j - 1) = 'O';
                    j -= 1;
                }
            } catch (std::out_of_range ex) {
            };
        }
    }

    // South
    for (int y = rows - 1; y >= 0; y--) {
        for (int x = 0; x < len; x++) {
            if (data.at(y).at(x) != 'O') continue;

            int j = y;
            try {
                while (data.at(j + 1).at(x) == '.') {
                    data.at(j).at(x) = '.';
                    data.at(j + 1).at(x) = 'O';
                    j += 1;
                }
            } catch (std::out_of_range ex) {
            };
        }
    }

    // East
    for (int y = 0; y < rows; y++) {
        for (int x = len - 1; x >= 0; x--) {
            if (data.at(y).at(x) != 'O') continue;

            int j = x;
            try {
                while (data.at(y).at(j + 1) == '.') {
                    data.at(y).at(j) = '.';
                    data.at(y).at(j + 1) = 'O';
                    j += 1;
                }
            } catch (std::out_of_range ex) {
            };
        }
    }
}

std::string stringify(std::vector<std::string> data) {
    std::string str = "";
    for (std::string line : data) {
        str += line;
    }
    return str;
}

int main(void) {
    std::vector<std::string> data = readFile("input.txt");

    std::vector<std::vector<std::string>> cache;

    int j;

    for (int i = 0; i < CYCLES; i++) {
        j = -1;
        for (int i = 0; i < cache.size(); i++) {
            if (cache.at(i) == data) {
                j = i;
                break;
            }
        }

        cache.push_back(data);

        if (j >= 0) break;

        cycle(data);
    }

    int loopIndex = (CYCLES - (j - 1)) % (cache.size() - j - 1);
    std::string str = stringify(cache.at(j - 1 + loopIndex));

    std::reverse(str.begin(), str.end());
    int rows = data.size();

    long long sum = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str.at(i) == 'O') {
            sum += (i / rows) + 1;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}

// Solution: 91286