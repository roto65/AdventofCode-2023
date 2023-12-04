#include <bits/stdc++.h>

#include "../shared.hpp"

constexpr int N_OF_WINNING_N = 10;

int evalCard(std::string s) {
    std::string winningNumbers = s.substr(0, N_OF_WINNING_N * 3);
    std::string myNumbers = s.substr(N_OF_WINNING_N * 3 + 2) + " ";

    int match = 0;

    for (int i = 0; i < N_OF_WINNING_N; i++) {
        std::string num = winningNumbers.substr(i * 3, 3);

        if (myNumbers.find(num) != std::string::npos) {
            match++;
        }
    }

    if (match == 0) {
        return 0;
    } else {
        return std::pow(2, match - 1);
    }
}

int main(void) {
    std::vector<std::string> data = readFile("input.txt");

    long long sum = 0;

    for (std::string card : data) {
        sum += evalCard(card.substr(10));
    }

    std::cout << sum << std::endl;

    return 0;
}

// Solution: 25571