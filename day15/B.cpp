#include <bits/stdc++.h>

#include "../shared.hpp"

struct Lens {
    std::string label;
    int focalLength;

    Lens(std::string s) {
        std::vector<std::string> data = split(s, '=');

        label = data.at(0);
        focalLength = stoi(data.at(1));
    }
};

std::vector<std::vector<Lens>> boxes(256, std::vector<Lens>());

int hash(std::string s) {
    int currValue = 0;

    for (char c : s) {
        if (c == '-' || c == '=') break;

        currValue += (int)c;
        currValue *= 17;
        currValue %= 256;
    }
    return currValue;
}

void insertLens(Lens newLens) {
    for (Lens& l : boxes.at(hash(newLens.label))) {
        if (l.label == newLens.label) {
            l.focalLength = newLens.focalLength;
            return;
        }
    }
    boxes.at(hash(newLens.label)).push_back(newLens);
}

void removeLens(std::string label) {
    std::vector<Lens>& box = boxes.at(hash(label));

    for (std::vector<Lens>::iterator it = box.begin(); it != box.end(); ++it) {
        if ((*it).label == label) {
            box.erase(it);
            return;
        }
    }
}

void evalCmd(std::string s) {
    if (s.find('=') != std::string::npos) {
        insertLens(Lens(s));
    } else {
        removeLens(s.substr(0, s.size() - 1));
    }
}

int main(void) {
    std::vector<std::string> data = readFile("input.txt");
    data = split(data.at(0), ',');

    long long sum = 0;

    for (std::string s : data) {
        evalCmd(s);
    }

    for (int b = 0; b < boxes.size(); b++) {
        for (int l = 0; l < boxes.at(b).size(); l++) {
            sum += (b + 1) * (l + 1) * boxes.at(b).at(l).focalLength;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}

// Solution: 279470