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