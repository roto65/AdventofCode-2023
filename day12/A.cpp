#include <bits/stdc++.h>

#include "../shared.hpp"

struct Springs {
    std::vector<int> groups;
    std::vector<int> holes;
    std::string arrangement;

    Springs(std::string s) {
        std::vector<std::string> tokens = split(s);
        arrangement = tokens.at(0);

        std::vector<std::string> nums = split(tokens.at(1), ',');
        for (std::string s : nums) {
            groups.push_back(stoi(s));
        }

        for (int i = 0; i < arrangement.size(); i++) {
            if (arrangement.at(i) == '?') {
                holes.push_back(i);
            }
        }
    }

    bool validate() {
        std::string pattern = "^\\.{0,}";
        for (int i = 0; i < groups.size() - 1; i++) {
            pattern += std::string(groups.at(i), '#');
            pattern += "\\.{1,}";
        }
        pattern += std::string(groups.at(groups.size() - 1), '#');
        pattern += "\\.{0,}";

        return std::regex_match(arrangement, std::regex(pattern));
    }
};

long long evalLine(Springs springs) {
    long long partial = 0;

    for (int i = 0; i < std::pow(2,springs.holes.size()); i++) {
        std::string bits = std::bitset<18>(i).to_string().substr(18 - springs.holes.size());

        for (int j = 0; j < springs.holes.size(); j++) {
            if (bits.at(j) == '1') {
                springs.arrangement.at(springs.holes.at(j)) = '#';
            } else {
                springs.arrangement.at(springs.holes.at(j)) = '.';
            }
        }
        if (springs.validate()) partial++;
    }

    return partial;
}

int main(void) {
    std::vector<std::string> data = readFile("input.txt");

    std::vector<Springs> springsRows;
    for (std::string s : data) {
        springsRows.push_back(Springs(s));
    }

    long long sum = 0;

    for (Springs sp : springsRows) {
        sum += evalLine(sp);
    }

    std::cout << sum << std::endl;

    return 0;
}

// Solution: 7110