#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <unordered_set>
#include <unordered_map>


int prefixSum(std::vector<int> arr) {
    for (int i = 1 ;i< arr.size() ;++i) {
        arr[i] += arr[i-1];
    }

    for (int i = 0 ;i < arr.size() ;i++ )
        std::cout << arr[i] << " ";

    std::cout << std::endl;

    return 0;
}



std::vector<int> productExceptSelf(std::vector<int> nums) {
    // Count zeros first
    int zeroCount = std::count(nums.begin(), nums.end(), 0);

    // Case 1: More than one zero
    if (zeroCount > 1) {
        return std::vector<int>(nums.size(), 0);
    }

    int multi = 1;
    for (auto item : nums) {
        if (item != 0 || zeroCount == 0) { // Skip zero if there's exactly one
            multi *= item;
        }
    }

    std::vector<int> arr(nums.size());

    // Case 2: Exactly one zero
    if (zeroCount == 1) {
        for (int i = 0; i < nums.size(); i++) {
            arr[i] = (nums[i] == 0) ? multi : 0;
        }
        return arr;
    }

    // Case 3: No zeros (normal case)
    for (int i = 0; i < nums.size(); i++) {
        arr[i] = multi / nums[i];
    }

    return arr;
}

bool checkSubarraySum(std::vector<int>&nums , int k) {
    for (int i = 1 ;i < nums.size() ;i++) {
        if (nums[i] == 0 && nums[i-1] == 0)
            return true;
    }

    for (int i = 1;i < nums.size() ;i++) {
        nums[i] += nums[i-1];
    }
    for (int i = 1 ;i < nums.size() ;i++) {
        if (nums[i] % k == 0)
            return true;
    }
    return false;
}

int findMaxLength(std::vector<int> & nums) {
    int counter = 0;
    int maxLength = INT_MIN;
    std::unordered_map<int , int> mp;
    mp[0] = -1;

    for (int i = 0 ;i < nums.size() ;i++) {
        if (nums[i] == 0)
            counter--;
        else
            counter++;
        if (mp.find(counter) != mp.end()) {
            maxLength = std::max(maxLength , i - mp[counter]);
        } else
            mp[counter] = i;
    }

    return maxLength;
}

int main() {
    

    return 0;
}