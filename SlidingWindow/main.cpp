#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cmath>
#include <map>


int minSubArrayLen(int target, std::vector<int>& nums) {
    int minLength = INT_MAX;
    int sum = 0;
    int left = 0;

    for (int right = 0; right < nums.size(); ++right) {
        sum += nums[right];
        while (sum >= target) {
            minLength = std::min(minLength, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }

    return (minLength == INT_MAX) ? 0 : minLength;
}


std::vector<std::string> findRepeatedDnaSequences(std::string s) {
    std::unordered_set<std::string> container;
    std::unordered_set<std::string> result;
    std::string str;

    for (int i = 0 ;i < s.size() ;i++) {
        str += s[i];
        if (i >= 10 - 1) {
            if (container.find(str) != container.end())
                result.insert(str);
            else
                container.insert(str);
            str.erase(0,1);
        }
    }

    std::vector<std::string> another (result.begin() , result.end());
    return another;
}

int longestSubstring(std::string s, int k) {
    std::unordered_map<char, int> freq;
    int maxLength = 0; // Initialize to 0 instead of INT_MIN

    for (int i = 0; i < s.size(); i++) {
        freq[s[i]]++;
        bool done = true;
        int counter = 0;

        for (const auto& item : freq) {
            if (item.second < k) {
                done = false;
            }
            counter += item.second; // Always accumulate total length
        }

        if (done) {
            maxLength = std::max(maxLength, counter);
        }
    }

    return maxLength; // No need for ternary, since we initialized to 0
}



double findMaxAverage(std::vector<int>& nums , int k) {
    double sum = 0.0;
    double maxAvg = -INFINITY; // Initialize to negative infinity to handle negative numbers

    // Compute the sum of the first window [0..k-1]
    for (int i = 0; i < k; ++i) {
        sum += nums[i];
    }
    maxAvg = sum / k; // Initialize maxAvg with the first window's average

    // Slide the window from [1..k] to [n-k..n-1]
    for (int left = 1; left <= nums.size() - k; ++left) {
        int right = left + k - 1; // Right boundary of the new window
        sum = sum - nums[left - 1] + nums[right]; // Remove leftmost, add new right element
        double currentAvg = sum / k;
        maxAvg = std::max(maxAvg, currentAvg);
    }
    return maxAvg;
}

int reverse(int number) {
    long long result = 0;

    while (number != 0) {
        int digit = number % 10;
        result = result * 10 + digit;
        if (result > INT_MAX || result < INT_MIN)
            return 0;
        number /= 10;
    }
    return result;
}

int lengthOfLongestSubstring(std::string s) {
    std::unordered_map<char , int> mp;
    int maxLength = 0;
    int right = 0;
    for (int left = 0 ; left < s.size();left++) {
        right = left+1;
        while (right < s.size()) {
           if (mp.find(s[right]) != mp.end()) {
               maxLength = std::max(maxLength , right - left);
               mp[s[right]] = right;
               left = right;
           } else {
               mp[s[right]] = right;
           }
            right++;
        }
    }
    return maxLength;
}

int longestSubString(std::string s) {
    std::unordered_set<char> set;
    int maxLength = 0;
    int left = 0;
    for(int right = 0 ;right < s.size() ;right++) {
        while(set.find(s[right]) != set.end()){
            set.erase(s[left]);
            left++;
        }
        set.insert(s[right]);
        maxLength = std::max(maxLength, right - left + 1);
    }
    return maxLength;
}


int main() {
    return 0;
}
