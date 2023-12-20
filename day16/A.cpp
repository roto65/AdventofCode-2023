#include <bits/stdc++.h>

#include "../shared.hpp"

enum Direction {
    UP,
    LEFT,
    DOWN,
    RIGHT
};

std::vector<std::string> data, energized;
std::set<std::string> cache;

std::string stringify(Pos pos, Direction d) {
    std::stringstream ss;
    ss << pos.x << "-" << pos.y << "-" << d;
    return ss.str();
}

void shine(Pos pos, Direction d) {
    if (pos.x != -1) {
        energized.at(pos.y).at(pos.x) = '#';
    }

    std::string key = stringify(pos, d);

    if (cache.find(key) != cache.end()) {
        return;
    }
    cache.insert(key);

    Pos next(0, 0);
    switch (d) {
        case UP:
            next = Pos(pos.x, pos.y - 1);
            break;
        case LEFT:
            next = Pos(pos.x - 1, pos.y);
            break;
        case DOWN:
            next = Pos(pos.x, pos.y + 1);
            break;
        case RIGHT:
            next = Pos(pos.x + 1, pos.y);
            break;
    }

    char nextC;
    try {
        nextC = data.at(next.y).at(next.x);
    } catch (std::out_of_range ex) {
        return;
    };

    switch (nextC) {
        case '.':
            shine(next, d);
            break;
        case '\\':
            switch (d) {
                case UP:
                    shine(next, Direction::LEFT);
                    break;
                case LEFT:
                    shine(next, Direction::UP);
                    break;
                case DOWN:
                    shine(next, Direction::RIGHT);
                    break;
                case RIGHT:
                    shine(next, Direction::DOWN);
                    break;
            }
            break;
        case '/':
            switch (d) {
                case UP:
                    shine(next, Direction::RIGHT);
                    break;
                case LEFT:
                    shine(next, Direction::DOWN);
                    break;
                case DOWN:
                    shine(next, Direction::LEFT);
                    break;
                case RIGHT:
                    shine(next, Direction::UP);
                    break;
            }
            break;
        case '-':
            if (d == Direction::LEFT || d == Direction::RIGHT) {
                shine(next, d);
            } else {
                shine(next, Direction::LEFT);
                shine(next, Direction::RIGHT);
            }
            break;
        case '|':
            if (d == Direction::UP || d == Direction::DOWN) {
                shine(next, d);
            } else {
                shine(next, Direction::UP);
                shine(next, Direction::DOWN);
            }
            break;
    }
}

int main(void) {
    data = readFile("input.txt");

    energized = std::vector<std::string>(data.size(), std::string(data.at(0).size(), '.'));

    shine(Pos(-1, 0), Direction::RIGHT);

    long long sum = 0;
    for (std::string s : energized) {
        for (char c : s) {
            if (c == '#') sum++;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}

// Solution: 7939