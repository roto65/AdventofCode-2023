#include <bits/stdc++.h>

#include "../shared.hpp"

constexpr int EXPANSION = 999'999;

int main(void) {
    std::vector<std::string> data = readFile("input.txt");

    std::vector<Pos> galaxies;
    std::set<int> nonEmptyCols;
    std::vector<int> emptyCols;

    for (int y = 0; y < data.size(); y++) {
        if (data.at(y).find('#') == std::string::npos) {
            for (int z = 0; z < EXPANSION; z++) {
                data.insert(data.begin() + y, std::string(data.at(0).size(), '.'));
                y++;
            }
        }

        for (int x = 0; x < data.at(0).size(); x++) {
            if (data.at(y).at(x) == '#') {
                galaxies.push_back(Pos(x, y));
                nonEmptyCols.insert(x);
            }
        }
    }

    for (int i = 0; i < data.at(0).size(); i++) {
        if (nonEmptyCols.find(i) == nonEmptyCols.end()) {
            emptyCols.push_back(i);
        }
    }

    for (int x : emptyCols) {
        for (Pos& gal : galaxies) {
            if (gal.x > x) {
                gal.x += EXPANSION;
            }
        }

        for (int& col : emptyCols) {
            if (col > x) {
                col += EXPANSION;
            }
        }
    }

    long long sum = 0;

    for (int i = 0; i < galaxies.size(); i++) {
        for (int j = i + 1; j < galaxies.size(); j++) {
            sum += std::abs(galaxies.at(i).x - galaxies.at(j).x);
            sum += std::abs(galaxies.at(i).y - galaxies.at(j).y);
        }
    }

    std::cout << sum << std::endl;

    return 0;
}

// Solution: