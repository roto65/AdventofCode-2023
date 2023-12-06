#include <bits/stdc++.h>

#include "../shared.hpp"

int evalRecords(int time, int distance) {
    int records = 0;

    for (int i = 1; i <= time; i++) {
        if (i * (time - i) > distance) {
            records++;
        }
    }

    return records;
}

int main(void) {
    std::vector<std::string> data = readFile("input.txt");

    std::vector<std::string> time = split(std::regex_replace(data.at(0).substr(5), std::regex("\\s+"), " "));
    if (time.at(0) == "") {
        time.erase(time.begin());
    }

    std::vector<std::string> distance = split(std::regex_replace(data.at(1).substr(9), std::regex("\\s+"), " "));
    if (distance.at(0) == "") {
        distance.erase(distance.begin());
    }

    long long prod = 1;

    for (int i = 0; i < time.size(); i++) {
        prod *= evalRecords(stoi(time.at(i)), stoi(distance.at(i)));
    }

    std::cout << prod << std::endl;

    return 0;
}

// Solution: 219849