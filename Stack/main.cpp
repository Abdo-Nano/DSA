#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>
#include <limits.h>


std::string rstrip(const std::string &s) {
    size_t end = s.find_last_not_of(" \t\n\r\f\v");
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string splitBySpace(const std::string& input) {
    std::stringstream ss(input);
    std::string word;
    std::string result = " ";

    while (ss >> word) {
        result = word + " " + result;
    }
    result = rstrip(result);

    return result;
}

int calcArea(int left , int right , const std::vector<int> & arr) {
    int width = right - left;
    int height = std::min(arr[right] , arr[left]);
    int area = width * height;
    return area;
}

int maxArea(std::vector<int> height) {
    int left = 0;
    int right = height.size() -1;
    int maxValue = INT_MIN;

    while (left <= right) {
        maxValue = std::max(maxValue , calcArea(left , right , height));
        if (height[left] <= height[right])
            left++;
        else
            right --;
    }
    return maxValue;
}

std::string intToRoman(int num) {
    const std::vector<std::pair<int, std::string>> valueSymbols{
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
            {5, "V"},    {4, "IV"},   {1, "I"}
    };

    std::string result;

    for (const auto & [first , second] : valueSymbols) {
        while (num >= first) {
            result += second;
            num -= first;
        }
    }
    return result;
}

std::string reverseParentheses(std::string & s) {
    std::stack<std::string> stk;
    stk.push(""); // Initialize with empty string to handle top level

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            stk.push(""); // Start a new segment
        } else if (s[i] == ')') {
            std::string top = stk.top();
            stk.pop();
            reverse(top.begin(), top.end());
            stk.top() += top; // Merge with previous segment
        } else {
            stk.top() += s[i]; // Append to current segment
        }
    }
    return stk.top();
}


std::vector<std::string> splitBySlash(const std::string & path) {
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(path);

    while (std::getline(ss , token , '/'))
        tokens.push_back(token);

    return tokens;
}

std::string simplifyPath(std::string path) {
    std::vector<std::string> tokens = splitBySlash(path);
    std::stack<std::string> stk;

    for (auto token: tokens) {
        if (token == "." || token.empty())
           continue;
        if (token == "..") {
            if (!stk.empty())
                stk.pop();
        } else
            stk.push(token);
    }

    std::string result;
    while (!stk.empty()) {
        result =  "/" + stk.top()  + result  ;
        stk.pop();
    }

    return result;
}


int main() {
    std::cout << "Hello , world!" << std::endl;
    std::string path = "/home//foo/";
    std::cout << simplifyPath(path) << std::endl;
    return 0;
}
