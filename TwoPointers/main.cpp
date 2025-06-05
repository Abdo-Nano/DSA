#include <iostream>
#include <algorithm>
#include <vector>


void solve(std::string str) {
    int value{};
    for (int i = 0 ;i < str.size() ;i++) {
        std::string result;
        while (isdigit(str[i]) && i < str.size()) {
            result += str[i];
            ++i;
        }
        value = std::stoi(result);
    }


    std::cout <<  value << std::endl;
}


void sortColors(std::vector<int>& nums) {
    int left = 0;
    int right = nums.size() -1;

    while(left <= right) {
        if(nums[left] > nums[right])
            std::swap(nums[left] , nums[right]);
        if(nums[left] != 0)
            right--;
        else if(nums[right] != 2)
            left++;
        else {
            left++;
            right--;
        }
    }

}

void findDuplicateNumber(const std::vector<int>& nums) {
    //floyd’s tortoise and hare algorithm code in c++
    int slow = nums[0];
    int fast = nums[0];

    // Move slow by 1 step, fast by 2 steps until they meet
    while (true) {
        slow = nums[slow];
        fast = nums[nums[fast]];
        if (slow == fast)
            break;
    }

    // Find the start of the cycle (duplicate number)
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    std::cout << slow << std::endl;
}

std::vector<int> twoSum(std::vector<int> numbers , int target) {
    int left = 0;
    int right = numbers.size() -1;

    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if ( sum == target && left != right)
            return {left + 1 , right + 1};
        if (sum > target)
            right--;
        else
            left++;
    }
    return {};
}


int main() {
    std::vector<int> numbers{1,2,3,4};
    int target = 3;
    std::vector<int> result = twoSum(numbers , target);

    for (auto item : result)
        std::cout << item << " ";
    std::cout << std::endl;
    return 0;
}
