#include <bits/stdc++.h>

#include "../shared.hpp"

enum Direction {
    UP,
    LEFT,
    DOWN,
    RIGHT,
    DEFAULT
};

Pos initialPos(0, 0);

Direction facing = DEFAULT;

void evalS(std::vector<std::string>& data) {
    for (int y = 0; y < data.size(); y++) {
        std::string line = data.at(y);

        for (int x = 0; x < line.size(); x++) {
            if (line.at(x) != 'S') continue;

            initialPos = {x, y};
            bool top = false, sx = false, bot = false, dx = false;

            try {
                if (line.at(x + 1) == '-' || line.at(x + 1) == 'J' || line.at(x + 1) == '7') dx = true;
            } catch (std::out_of_range ex) {
            };

            try {
                if (line.at(x - 1) == '-' || line.at(x - 1) == 'F' || line.at(x - 1) == 'L') sx = true;
            } catch (std::out_of_range ex) {
            };

            try {
                if (data.at(y + 1).at(x) == '|' || data.at(y + 1).at(x) == 'J' || data.at(y + 1).at(x) == 'L') bot = true;
            } catch (std::out_of_range ex) {
            };

            try {
                if (data.at(y - 1).at(x) == '|' || data.at(y - 1).at(x) == 'F' || data.at(y - 1).at(x) == '7') top = true;
            } catch (std::out_of_range ex) {
            };

            if (top && bot) {
                data.at(y).at(x) = '|';
                return;
            }
            if (sx && dx) {
                data.at(y).at(x) = '-';
                return;
            }
            if (top && dx) {
                data.at(y).at(x) = 'L';
                return;
            }
            if (top && sx) {
                data.at(y).at(x) = 'J';
                return;
            }
            if (bot && dx) {
                data.at(y).at(x) = 'F';
                return;
            }
            if (bot && sx) {
                data.at(y).at(x) = '7';
                return;
            }
        }
    }
}

int main(void) {
    std::vector<std::string> data = readFile("input.txt");

    evalS(data);
    Pos pos(initialPos);

    long long steps = 0;

    do {
        switch (data.at(pos.y).at(pos.x)) {
            case '|':
                if (facing == UP) {
                    pos.y--;
                } else {
                    pos.y++;
                }
                break;
            case '-':
                if (facing == LEFT) {
                    pos.x--;
                } else {
                    pos.x++;
                }
                break;
            case 'L':
                if (facing == DOWN) {
                    facing = RIGHT;
                    pos.x++;
                } else {
                    facing = UP;
                    pos.y--;
                }
                break;
            case 'J':
                if (facing == DOWN) {
                    facing = LEFT;
                    pos.x--;
                } else {
                    facing = UP;
                    pos.y--;
                }
                break;
            case 'F':
                if (facing == UP) {
                    facing = RIGHT;
                    pos.x++;
                } else {
                    facing = DOWN;
                    pos.y++;
                }
                break;
            case '7':
                if (facing == UP) {
                    facing = LEFT;
                    pos.x--;
                } else {
                    facing = DOWN;
                    pos.y++;
                }
        }
        steps++;

    } while (pos != initialPos);

    std::cout << steps / 2 << std::endl;

    return 0;
}

// Solution: 6815