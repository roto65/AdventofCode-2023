#include <bits/stdc++.h>

#include "../shared.hpp"

struct Springs {
    std::vector<int> groups;
    std::string arrangement;

    Springs(std::string s) {
        std::vector<std::string> tokens = split(s);
        arrangement = tokens.at(0) + '?' + tokens.at(0) + '?' + tokens.at(0) + '?' + tokens.at(0) + '?' + tokens.at(0);

        std::vector<std::string> nums = split(tokens.at(1), ',');
        for (int i = 0; i < 5; i++) {
            for (std::string s : nums) {
                groups.push_back(stoi(s));
            }
        }
    }

    Springs(std::string arr, std::vector<int> groups) {
        this->arrangement = arr;
        this->groups = groups;
    }

    std::string getKey() {
        std::stringstream key;
        key << arrangement;

        for (int x : groups) {
            key << x;
        }

        return key.str();
    }
};

std::map<std::string, int> cache;

long long evalLine(std::string arr, std::vector<int> groups) {
    if (arr == "") {
        return groups.empty() ? 1 : 0;
    }

    if (groups.empty()) {
        return arr.find('#') != std::string::npos ? 1 : 0;
    }

    std::string key = Springs(arr, groups).getKey();

    if (cache.find(key) != cache.end()) {
        return cache.at(key);
    }

    long long res = 0;

    if (arr.at(0) != '#') {
        res += evalLine(arr.substr(1), groups);
    }

    if (arr.at(0) != '.') {
        if (groups.at(0) <= arr.size() && arr.substr(0, groups.at(0)).find('.') == std::string::npos && (groups.at(0) == arr.size() || arr.at(groups.at(0)) != '#')) {
            try {
                res += evalLine(arr.substr(groups.at(0) + 1), std::vector<int>(groups.begin() + 1, groups.end()));
            } catch (std::out_of_range ex) {
                res += groups.size() > 1 ? 1 : 0;
            }
        }
    }

    cache.insert({key, res});

    return res;
}

int main(void) {
    std::vector<std::string> data = readFile("input.txt");

    std::vector<Springs> springsRows;
    for (std::string s : data) {
        springsRows.push_back(Springs(s));
    }

    long long sum = 0;

    for (Springs sp : springsRows) {
        sum += evalLine(sp.arrangement, sp.groups);
    }

    std::cout << sum << std::endl;

    return 0;
}

// Solution: 1566786613613