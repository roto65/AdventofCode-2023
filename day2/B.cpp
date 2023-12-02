#include <bits/stdc++.h>

#include "../shared.hpp"

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

int evalPower(std::string s) {
    std::replace(s.begin(), s.end(), ';', ',');

    std::vector<std::pair<int, std::string>> tokens = tokenize(s);

    int red = 0, green = 0, blue = 0;

    for (auto t : tokens) {
        if (t.second == "red")
            red = std::max(red, t.first);
        else if (t.second == "green")
            green = std::max(green, t.first);
        else if (t.second == "blue") {
            blue = std::max(blue, t.first);
        }
    }
    return red * green * blue;
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

        sum += evalPower(s);
    }

    std::cout << sum << std::endl;

    return 0;
}

// Solution: 66027