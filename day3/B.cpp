#include <bits/stdc++.h>

#include "../shared.hpp"

int len;
std::string s;

std::map<int, int> values;

int checkSurround(int i) {
    std::set<int> factors;

    try {
        if (isdigit(s.at(i - 1))) {
            factors.insert(values.at(i - 1));
        }
    } catch (std::out_of_range ex) {
    };

    try {
        if (isdigit(s.at(i + 1))) {
            factors.insert(values.at(i + 1));
        }
    } catch (std::out_of_range ex) {
    };

    try {
        if (isdigit(s.at(i - len))) {
            factors.insert(values.at(i - len));
        } else {
            try {
                if (isdigit(s.at(i - len - 1))) {
                    factors.insert(values.at(i - len - 1));
                }
            } catch (std::out_of_range ex) {
            };

            try {
                if (isdigit(s.at(i - len + 1))) {
                    factors.insert(values.at(i - len + 1));
                }
            } catch (std::out_of_range ex) {
            };
        }
    } catch (std::out_of_range ex) {
    };

    try {
        if (isdigit(s.at(i + len))) {
            factors.insert(values.at(i + len));
        } else {
            try {
                if (isdigit(s.at(i + len - 1))) {
                    factors.insert(values.at(i + len - 1));
                }
            } catch (std::out_of_range ex) {
            };

            try {
                if (isdigit(s.at(i + len + 1))) {
                    factors.insert(values.at(i + len + 1));
                }
            } catch (std::out_of_range ex) {
            };
        }
    } catch (std::out_of_range ex) {
    };

    if (factors.size() == 2) {
        int res = 1;
        for (std::set<int>::iterator it = factors.begin(); it != factors.end(); ++it) {
            res *= *it;
        }

        return res;
    }

    return 0;
}

int main(void) {
    std::vector<std::string> data = readFile("input.txt");

    len = data.at(0).size();

    for (std::string line : data) {
        s += line;
    }

    long long sum = 0;

    for (int i = 0; i < s.size(); i++) {
        int num = 0;
        while (isdigit(s.at(i))) {
            num = (num * 10) + int(s.at(i) - '0');
            i++;
        }
        if (num != 0) {
            int size = std::to_string(num).size();

            for (int j = i; j > i - size; j--) {
                values.insert({j - 1, num});
            }
        }
    }

    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == '*') {
            sum += checkSurround(i);
        }
    }

    std::cout << sum << std::endl;

    return 0;
}

// Solution: 78826761