#include <bits/stdc++.h>

struct Pos {
    int x, y;

    Pos(const Pos& p) {
        x = p.x;
        y = p.y;
    }

    Pos(const int& X, const int& Y) {
        x = X;
        y = Y;
    }

    bool operator!=(const Pos& p) const {
        return x != p.x || y != p.y;
    }
};

std::vector<std::string> readFile(std::string path) {
    std::vector<std::string> text;

    std::ifstream file(path);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            text.push_back(line);
        }
    }

    return text;
}

std::vector<std::string> split(const std::string& s, char delim = ' ') {
    std::vector<std::string> result;
    std::stringstream ss(s);
    std::string item;

    while (getline(ss, item, delim)) {
        result.push_back(item);
    }

    return result;
}

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}