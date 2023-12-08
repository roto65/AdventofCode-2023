#include <bits/stdc++.h>

#include <numeric>

#include "../shared.hpp"

std::map<std::string, std::pair<std::string, std::string>> map;
std::string moves;

/*
    Cheese explanation:
    Somehow the input is made so the number of steps it takes to go from a ..A node to the ..Z
    is always the same of the path from ..Z to the same ..Z so we can just evaluate the lcm of
    the path distances to get the correct answers
*/

long long evalPath(std::string curr) {
    long long steps = 0;

    for (int i = 0; i < moves.size(); i++) {
        if (moves.at(i) == 'L') {
            curr = map.at(curr).first;
        } else {
            curr = map.at(curr).second;
        }

        steps++;
        if (i == moves.size() - 1) {
            i = -1;
        }

        if (curr.at(2) == 'Z') break;
    }

    return steps;
}

int main(void) {
    std::vector<std::string> data = readFile("input.txt");

    moves = data.at(0);
    std::vector<std::string> currNodes;

    for (int i = 2; i < data.size(); i++) {
        map.insert({data.at(i).substr(0, 3), {data.at(i).substr(7, 3), data.at(i).substr(12, 3)}});

        if (data.at(i).at(2) == 'A') {
            currNodes.push_back(data.at(i).substr(0, 3));
        }
    }

    long long res = 1;

    for (std::string s : currNodes) {
        res = lcm(res, evalPath(s));
    }

    std::cout << res << std::endl;

    return 0;
}

// Solution: 14631604759649