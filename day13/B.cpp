#include <bits/stdc++.h>

#include "../shared.hpp"

std::vector<std::vector<std::string>> grids;
std::vector<std::vector<std::string>> transposed;

int countDifference(std::string s1, std::string s2) {
    int count = 0;

    for (int i = 0; i < s1.size(); i++) {
        if (s1.at(i) != s2.at(i)) count++;
    }
    return count;
}

std::vector<std::string> transpose(std::vector<std::string> grid) {
    std::vector<std::string> transpGrid;
    std::string tmp;

    for (int i = 0; i < grid.at(0).size(); i++) {
        for (std::string line : grid) {
            tmp.push_back(line.at(i));
        }
        transpGrid.push_back(tmp);
        tmp.clear();
    }

    return transpGrid;
}

int evalSimm(std::vector<std::string> grid) {
    for (int split = 1; split < grid.size(); split++) {
        int len = std::min(split, (int)grid.size() - split);

        int smudge = 0;
        for (int i = 0; i < len; i++) {
            smudge += countDifference(grid.at(split - 1 - i), grid.at(split + i));
        }
        if (smudge == 1) {
            return split;
        }
    }
    return 0;
}

int main(void) {
    std::vector<std::string> data = readFile("input.txt");

    std::vector<std::string> tmp;
    for (std::string s : data) {
        if (s != "") {
            tmp.push_back(s);
        } else {
            grids.push_back(tmp);
            tmp.clear();
        }
    }
    grids.push_back(tmp);

    long long sum = 0;

    for (std::vector<std::string> grid : grids) {
        int rows = evalSimm(grid);
        sum += rows * 100;
        transposed.push_back(transpose(grid));
    }

    for (std::vector<std::string> grid : transposed) {
        sum += evalSimm(grid);
    }

    std::cout << sum << std::endl;

    return 0;
}

// Solution: 32728