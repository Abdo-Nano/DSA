//
// Created by abdo on 5/4/25.
//

#ifndef LONGESTPALINDROMESTRING_H
#define LONGESTPALINDROMESTRING_H
#include <iostream>
#include <vector>

static std::vector<std::string> result;

void helper(const std::string &str, int index) {
    // Always add the single character as a palindrome
    result.push_back(std::string(1, str[index]));

    // Check for odd-length palindrome (like "aba")
    int left = index - 1;
    int right = index + 1;
    while (left >= 0 && right < str.size() && str[left] == str[right]) {
        result.push_back(str.substr(left, right - left + 1));
        left--;
        right++;
    }
    if (index + 1 < str.size() && str[index] == str[index + 1]) {
        result.push_back(str.substr(index, 2));
        left = index - 1;
        right = index + 2;
        while (left >= 0 && right < str.size() && str[left] == str[right]) {
            result.push_back(str.substr(left, right - left + 1));
            left--;
            right++;
        }
    }
}

void solve(std::string str) {
    for (int i = 0 ;i < str.size() ;i++) {
        helper(str , i);
    }
}

void printVect(std::vector<std::string> arr) {
    for (const auto item : arr) {
        std::cout << item <<  " ";
    }
    std::cout << std::endl;
}
#endif //LONGESTPALINDROMESTRING_H
