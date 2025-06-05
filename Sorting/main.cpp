#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>


void countSort(std::vector<int>& arr) {
    int maxValue = *std::max_element(arr.begin() , arr.end());
    std::vector<int> result(maxValue +1 , 0);

    for (int i = 0 ;i < arr.size() ;i++) {
        result[arr[i]]++;
    }

    for (int i = 0 ;i < result.size() ;i++) {
        if (result[i] > 0) {
            for (int j = 0 ;j < result[i];j++) {
                std::cout << i << " ";
            }
        }
    }
}
// 169. Majority Element
// It takes O(N) for both
// Try to find solution that's linear time and constant stace
int majorityElement(std::vector<int>& nums) {
    std::unordered_map<int , int> mp;
    int result = 0;
    for(int i = 0 ;i < nums.size() ;i++) {
        mp[nums[i]]++;
        if(mp[nums[i]] > (nums.size() / 2))
        {
            result = nums[i];
            break;
        }
    }
    return result;
}

// time complexity O(N + M)
// space complexity O(1)  Stores counts of each character in s.
bool isAnagram(std::string s, std::string t) {
    std::unordered_map<char , int> mp;
    for(int i = 0 ;i < s.size() ;i++) {
        mp[s[i]]++;
    }

    for(int i = 0 ;i < t.size() ;i++) {
        if(mp.find(t[i]) == mp.end() || mp[t[i]] == 0)
            return false;
        mp[t[i]]--;
    }

    for (const auto & item : mp) {
        if (item.second > 0)
            return false;
    }
    return true;
}

int main(int argc , char *argv[] ) {
    std::cout << "Hello world" << std::endl;
    return 0;
}
