#include <bits/stdc++.h>

#include "../shared.hpp"

enum Direction {
    UP,
    LEFT,
    DOWN,
    RIGHT,
    DEFAULT
};

Pos initialPos (0, 0);

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

char lastWindingDirection = '.';
int lastWindingY = -1;

void assignWinding(std::vector<std::string>& windings, Pos pos, char newWinding) {
    if (pos.y != lastWindingY || lastWindingDirection != newWinding) {
        windings.at(pos.y).at(pos.x) = newWinding;
        lastWindingY = pos.y;
        lastWindingDirection = newWinding;
        return;
    }

    windings.at(pos.y).at(pos.x) = '-';
}

int main(void) {
    std::vector<std::string> data = readFile("input.txt");

    evalS(data);
    Pos pos (initialPos);

    std::vector<std::string> windings(data.size(), std::string(data.at(0).size(), '.'));

    do {
        switch (data.at(pos.y).at(pos.x)) {
            case '|':
                if (facing == UP) {
                    assignWinding(windings, pos, 'U');
                    pos.y--;
                } else {
                    assignWinding(windings, pos, 'D');
                    pos.y++;
                }
                break;
            case '-':
                windings.at(pos.y).at(pos.x) = '-';
                if (facing == LEFT) {
                    pos.x--;
                } else {
                    pos.x++;
                }
                break;
            case 'L':
                if (facing == DOWN) {
                    facing = RIGHT;
                    assignWinding(windings, pos, 'D');
                    pos.x++;
                } else {
                    facing = UP;
                    assignWinding(windings, pos, 'U');
                    pos.y--;
                }
                break;
            case 'J':
                if (facing == DOWN) {
                    facing = LEFT;
                    assignWinding(windings, pos, 'D');
                    pos.x--;
                } else {
                    facing = UP;
                    assignWinding(windings, pos, 'U');
                    pos.y--;
                }
                break;
            case 'F':
                if (facing == UP) {
                    facing = RIGHT;
                    assignWinding(windings, pos, 'U');
                    pos.x++;
                } else {
                    facing = DOWN;
                    assignWinding(windings, pos, 'D');
                    pos.y++;
                }
                break;
            case '7':
                if (facing == UP) {
                    facing = LEFT;
                    assignWinding(windings, pos, 'U');
                    pos.x--;
                } else {
                    facing = DOWN;
                    assignWinding(windings, pos, 'D');
                    pos.y++;
                }
        }
    } while (pos != initialPos);

    long long internal = 0;

    for (std::string line : windings) {
        int partialWinding = 0;
        for (char c : line) {
            switch (c) {
                case 'U':
                    partialWinding++;
                    break;
                case 'D':
                    partialWinding--;
                    break;
                case '.':
                    if (partialWinding != 0) internal++;
                    break;
                default:
                    break;
            }
        }
    }

    std::cout << internal << std::endl;

    return 0;
}

// Solution: 269