#include <bits/stdc++.h>

#include "../shared.hpp"

constexpr int MAX_RED = 12;
constexpr int MAX_GREEN = 13;
constexpr int MAX_BLUE = 14;

std::vector<std::pair<int, std::string>> tokenize(std::string s) {
    std::vector<std::pair<int, std::string>> vec;

    std::string delimiter = ", ";

    int pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);

        int i = token.find(" ");
        std::pair<int, std::string> p{std::stoi(token.substr(0, i)), token.substr(i + 1)};

        vec.push_back(p);
        s.erase(0, pos + delimiter.length());
    }

    int i = s.find(" ");
    std::pair<int, std::string> p{std::stoi(s.substr(0, i)), s.substr(i + 1)};
    vec.push_back(p);

    return vec;
}

bool checkGame(std::string s) {
    std::replace(s.begin(), s.end(), ';', ',');

    std::vector<std::pair<int, std::string>> tokens = tokenize(s);

    for (auto t : tokens) {
        if (t.second == "red" && t.first > MAX_RED)
            return false;
        else if (t.second == "green" && t.first > MAX_GREEN)
            return false;
        else if (t.second == "blue" && t.first > MAX_BLUE) {
            return false;
        }
    }
    return true;
}

int main(void) {
    std::vector<std::string> data = readFile("input.txt");

    long long sum = 0;
    std::string s;

    for (int i = 0; i < data.size(); i++) {
        if (i < 9) {
            s = data.at(i).substr(8);
        } else if (i < 99) {
            s = data.at(i).substr(9);
        } else {
            s = data.at(i).substr(10);
        }

        if (checkGame(s)) {
            sum += (i + 1);
        }
    }

    std::cout << sum << std::endl;

    return 0;
}

// Solution: 3035