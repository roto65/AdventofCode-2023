#include <bits/stdc++.h>

#include "../shared.hpp"

std::vector<std::pair<int, int>> hands;

std::string adjustHex(std::string s) {
    std::replace(s.begin(), s.end(), '2', '0');
    std::replace(s.begin(), s.end(), '3', '1');
    std::replace(s.begin(), s.end(), '4', '2');
    std::replace(s.begin(), s.end(), '5', '3');
    std::replace(s.begin(), s.end(), '6', '4');
    std::replace(s.begin(), s.end(), '7', '5');
    std::replace(s.begin(), s.end(), '8', '6');
    std::replace(s.begin(), s.end(), '9', '7');
    std::replace(s.begin(), s.end(), 'T', '8');
    std::replace(s.begin(), s.end(), 'J', '9');
    std::replace(s.begin(), s.end(), 'K', 'B');
    std::replace(s.begin(), s.end(), 'A', 'C');
    std::replace(s.begin(), s.end(), 'Q', 'A');

    return s;
}

std::string sortHand(std::string s) {
    std::map<char, int> letters;

    for (char c : s) {
        try {
            letters.at(c) += 1;
        } catch (std::out_of_range ex) {
            letters.emplace(c, 1);
        }
    }

    std::priority_queue<int> q;

    for (std::pair<char, int> p : letters) {
        q.push(p.second);
    }

    switch (q.top()) {
        case 5:
            return "9" + s;
        case 4:
            return "8" + s;
        case 3:
            q.pop();
            if (q.top() == 2) {
                return "7" + s;
            } else {
                return "6" + s;
            }
        case 2:
            q.pop();
            if (q.top() == 2) {
                return "5" + s;
            } else {
                return "4" + s;
            }
        default:
            return "3" + s;
    }
}

void loadHands(std::string s) {
    std::vector<std::string> hand = split(s);

    std::pair<int, int> pair{0, stoi(hand.at(1))};

    std::stringstream ss;
    ss << std::hex << adjustHex(sortHand(hand.at(0)));
    ss >> pair.first;

    hands.push_back(pair);

    // std::cout << std::hex << pair.first << "-" << std::dec << pair.second << std::endl;
}

int main(void) {
    std::vector<std::string> data = readFile("input.txt");

    for (std::string hand : data) {
        loadHands(hand);
    }

    std::sort(hands.begin(), hands.end(), [](auto &left, auto &right) {
        return left.first < right.first;
    });

    long long sum = 0;

    for (int i = 0; i < hands.size(); i++) {
        sum += hands.at(i).second * (i + 1);
    }

    std::cout << sum << std::endl;

    return 0;
}

// Solution: 253603890