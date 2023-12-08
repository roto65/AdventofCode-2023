#include <bits/stdc++.h>

#include "../shared.hpp"

std::map<std::string, std::pair<std::string, std::string>> map;

int main(void) {
    std::vector<std::string> data = readFile("input.txt");

    std::string moves = data.at(0);

    for (int i = 2; i < data.size(); i++) {
        map.insert({data.at(i).substr(0, 3), {data.at(i).substr(7, 3), data.at(i).substr(12, 3)}});
    }

    long long steps = 0;

    std::string curr = "AAA";

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

        if (curr == "ZZZ") break;
    }

    std::cout << steps << std::endl;

    return 0;
}

// Solution: 17263