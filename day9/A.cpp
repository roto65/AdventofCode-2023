#include <bits/stdc++.h>

#include "../shared.hpp"

bool isZero(std::vector<int> vec) {
    for (int n : vec) {
        if (n != 0) {
            return false;
        }
    }
    return true;
}

std::vector<int> nextSequence(std::vector<int> prev) {
    std::vector<int> tmp;

    for (int i = 1; i < prev.size(); i++) {
        tmp.push_back(prev.at(i) - prev.at(i - 1));
    }
    return tmp;
}

int evalNext(std::vector<std::string> vec) {
    std::vector<std::vector<int>> nums;
    std::vector<int> tmp;

    for (std::string s : vec) {
        tmp.push_back(stoi(s));
    }
    nums.push_back(tmp);

    while(!isZero(nums.back())) {
        nums.push_back(nextSequence(nums.back()));
    }

    tmp = nums.back();
    tmp.push_back(0);
    nums.pop_back();

    while (nums.size() != 0) {
        nums.back().push_back(tmp.back() + nums.back().back());

        tmp = nums.back();
        nums.pop_back();
    }
    return tmp.back();
}

int main(void) {
    std::vector<std::string> data = readFile("input.txt");

    long long sum = 0;

    for(int i = 0; i < data.size(); i++) {
       std::vector<std::string> nums = split(data.at(i));

       sum += evalNext(nums); 
    }

    std::cout << sum << std::endl;

    return 0;
}

// Solution: 2174807968