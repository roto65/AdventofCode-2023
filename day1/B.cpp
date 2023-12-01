#include <bits/stdc++.h>

#include "../shared.hpp"

std::vector<std::pair<std::string, int>> numbers{{"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};
std::vector<std::pair<std::string, int>> srebmun{{"eno", 1}, {"owt", 2}, {"eerht", 3}, {"ruof", 4}, {"evif", 5}, {"xis", 6}, {"neves", 7}, {"thgie", 8}, {"enin", 9}};

int evalValue(std::string& s) {
    int value = 0;

    // Evaluate the first digit

    int lettImin = s.size(), minValue = 0;

    for (std::pair<std::string, int> num : numbers) {
        int i = s.find(num.first);

        if (i != std::string::npos) {
            if (i < lettImin) {
                lettImin = i;
                minValue = num.second;
            }
        }
    }

    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s.at(i))) {
            if (lettImin > i) {
                value += 10 * int(s.at(i) - '0');
            } else {
                value += 10 * minValue;
            }
            break;
        }
    }

    // Evaluate the second digit

    reverse(s.begin(), s.end());

    int lettImax = s.size(), maxValue = 0;

    for (std::pair<std::string, int> num : srebmun) {
        int i = s.find(num.first);

        if (i != std::string::npos) {
            if (i < lettImax) {
                lettImax = i;
                maxValue = num.second;
            }
        }
    }

    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s.at(i))) {
            if (lettImax > i) {
                value += int(s.at(i) - '0');
            } else {
                value += maxValue;
            }
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

// Solution: 54518