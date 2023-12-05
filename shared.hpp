#include <bits/stdc++.h>

std::vector<std::string> readFile (std::string path) {
    std::vector<std::string> text;

    std::ifstream file (path);
    if (file.is_open()) {
        std::string line;
        while(std::getline(file,line)) {
            text.push_back(line);
        }
    }

    return text;
}

std::vector<std::string> split (const std::string &s, char delim = ' ') {
    std::vector<std::string> result;
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}