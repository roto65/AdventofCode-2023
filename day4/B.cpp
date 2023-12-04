#include <bits/stdc++.h>

#include "../shared.hpp"

constexpr int N_OF_WINNING_N = 10;

std::vector<int> cards;

void evalCard(std::string s, int cardNum) {
    std::string winningNumbers = s.substr(0, N_OF_WINNING_N * 3);
    std::string myNumbers = s.substr(N_OF_WINNING_N * 3 + 2) + " ";

    int match = 0;

    for (int i = 0; i < N_OF_WINNING_N; i++) {
        std::string num = winningNumbers.substr(i * 3, 3);

        if (myNumbers.find(num) != std::string::npos) {
            match++;
        }
    }

    if (match == 0) return;

    for (int i = 0; i < match; i++) {
        cards.at(cardNum + i + 1) += cards.at(cardNum);
    }
}

int main(void) {
    std::vector<std::string> data = readFile("input.txt");

    cards = std::vector<int>(data.size(), 1);

    long long sum = 0;

    for (int i = 0; i < data.size(); i++) {
        evalCard(data.at(i).substr(10), i);
    }

    for (int card : cards) {
        sum += card;
    }

    std::cout << sum << std::endl;

    return 0;
}

// Solution: 8805731s