#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <unordered_map>


int lowerBound(std::vector<int> arr , int target) {
    int left = 0;
    int right = (int) arr.size() -1;
    int result = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] >=  target) {
            result = mid;
            right = mid -1;
        }
        else
            left = mid + 1;
    }
    return result;
}

int upperBound(std::vector<int> arr , int target) {
    int left = 0;
    int right = arr.size() -1;
    int result = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] <=  target) {
            result = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    return result;
}





/* ===== some important notes about this cool problem ====
 * - I liked what you did , when you broke the problem into small pieces
 * - Also when you used ChatGpt for just the  help function
 * - we used 1LL to prevent overflow of the int limit (32 bit)
 */

// is a helper function for arrange coins function
bool isComplete(int level, int coins) {
    return (1LL * level * (level + 1) / 2) <= coins;
}

int arrangeCoins(int coins) {
    int left = 1;
    int right = coins;
    int result = 0;
    while (left <= right) {
        int mid = (right + left) /2;
        if (!isComplete(mid , coins)) {
            right = mid -1;
        } else if (isComplete(mid , coins)) {
            result = std::max(mid , result);
            left = mid + 1;
        }
    }
    return result;
}


int findFirstPositiveNum(std::vector<int> & nums) {
    for (int i = 0 ;i < nums.size();i++) {
        if (nums[i] >= 0)
            return i;
    }
    return -1;
}


// this function is too long , Uncle bob will F*** U
// Try to optimize this solution + reduce the lines of code
// 977. Squares of a Sorted Array
std::vector<int> sortedSquares(std::vector<int>& nums) {
    std::vector<int> result (nums.size() , 0);
    int resultIndex = 0;
    int right = findFirstPositiveNum(nums);
    int left = (right == -1)? nums.size() -1 : right -1 ;
    while (left >= 0 && right < nums.size()) {
        if (abs(nums[left]) < nums[right]) {
            result[resultIndex] = nums[left] * nums[left];
            left--;
        } else {
            result[resultIndex] = nums[right] * nums[right];
            right++;
        }
        resultIndex++;
    }
    if (left >= 0 ) {
        for (int i = left ;i>= 0 ;i--) {
            result[resultIndex] = nums[left] * nums[left];
            resultIndex++;
        }
    } else {
        for (int i = right ;i < nums.size() ;i++){
            result[resultIndex] = nums[right] * nums[right];
            resultIndex++;
        }
    }
    return result;
}

/*
 * - Take care of limitation of int objects
 */
bool isPerfectSquare(int num) {
    long long left = 0;
    long long right = num;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long result = mid * mid;
        if (result == num)
            return true;
        else if (result < num)
            left = mid + 1;
        else
            right = mid -1;
    }

    return false;
}
/*
 * - Well done when you detected the condition , But it is not prefect
 * - By returning the right , you return the closest value to it
 */
int mySqrt(int x) {
    long long left = 0;
    long long  right = x;

    while (left <= right) {
        long long  mid = left + (right - left) / 2;
        if (mid * mid == x){
            return mid;
        }
        else if (mid * mid < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return right;
}

// not completed
int singleNonDuplicate(std::vector<int>& nums) {
    int left = 0;
    int right = nums.size() -1;
    int result = 0;

    return 0;
}

/*
 * - Well done bro
 * - You implement "If you don't challenge yourself , then you will not change" wisdom
 * - Tried a lot in the problem until you got the optimal solution
 */
int maxProfit(std::vector<int>& prices) {
    int result = 0;
    int minValue = prices[0];
    for (int i = 1;i < prices.size();i++) {
        if (prices[i] > minValue) {
            result = std::max(result , prices[i] - minValue);
        } else {
            minValue = prices[i];
        }
    }
    return result;
}

/*
 * ======== Some Important Tricks ==========
 * - sum / k >=  threshold
 * - average >= threshold
 */

int numOfSubarrays(std::vector<int>& arr, int k, int threshold) {
    int sum = 0, counter = 0;
    int target = threshold * k;

    // Calculate sum of first k elements
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }

    if (sum >= target) counter++;

    // Sliding window
    for (int right = k; right < arr.size(); right++) {
        sum += arr[right] - arr[right - k];
        if (sum >= target) counter++;
    }
    return counter;
}

int BinarySearch(std::vector<int> & arr , int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            right = mid -1;
        else
            left = mid + 1;
    }

    return - 1;
}

int rightBound(std::vector<int> & nums , int target , bool isLeft) {
    int left = 0;
    int right = nums.size() -1;

    int result = -1;
    // most right bound
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            result = mid;
            if (isLeft) {
                right = mid -1;
            } else {
                left = mid +1;
            }
        } else if (nums[mid] > target)
            right = mid -1;
        else
            left = mid +1;
    }
    return result;
}

std::vector<int> searchRange(std::vector<int> & nums , int target) {
    std::vector<int> result(2 , -1);
    int left = 0;
    int right = nums.size() -1;

    result[0] = rightBound(nums , target , true);
    result[1] = rightBound(nums , target , false);
    return result;
}

int findPivot(std::vector<int>&nums){
    int left = 0;
    int right = nums.size() -1;

    while(left < right ){
        int mid = left + (right -left) / 2;
        if(nums[mid]>nums[right])
            left = mid + 1;
        else
            right = mid;
    }

    return right;
}

void printvector(std::vector<int>& arr) {
    
    for(int i = 0 ;i < arr.size() ;i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

int search(std::vector<int>& nums, int target) {
    if (nums.empty()) return -1;  // Edge case: empty array

    int left = 0;
    int right = nums.size() - 1;
    int result = findPivot(nums);

    std::cout << result << std::endl;
    // Determine which part to search for the target
    if (target >= nums[0]) {  // Search in the left part (before pivot)
        left = 0;
        right = result - 1;
    } else {  // Search in the right part (after pivot)
        left = result;
        right = nums.size() - 1;
    }

    // Binary search in the selected part
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;  // Target not found
}

void findDuplicates(std::vector<int> & nums) {
    std::vector<int> arr(nums.size() , 0);

    for (int i = 0 ;i < nums.size() ;i++) {
        arr[nums[i-1]]++;
        // std::cout << arr[nums[nums[i-1]]]++ << std::endl;
    }

    for (int item : arr) {
        if (item == 2)
            std::cout << item << std::endl;
    }
}

bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
    int left = 0;
    int right = matrix.size() -1;

    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (matrix[mid][0] == target) {
            return true;
        }
        if (target >= matrix[mid][0] && target <= matrix[mid][matrix[mid].size() -1]) {
            break;
        }
        if (matrix[mid][0] < target)
            left = mid + 1;
        else
            right = mid -1;
    }

    std::cout << mid << std::endl;
    std::vector<int> arr = matrix[mid];

    int result = BinarySearch(arr , target);

    return result != -1;
}

int findMin(std::vector<int>& nums) {
    int left = 0;
    int right = nums.size() -1;
    int result = INT_MAX;

    while (left <= right) {
        int mid = (left + right) / 2;
        result = std::min(result , nums[mid]);

        if (nums[mid] > nums[right])
           left = mid +1;
        else
            right = mid -1;
    }

    return result;
}

void printVector(std::vector<int> & nums) {
    for (int i = 0 ;i < nums.size();i++)
        std::cout << nums[i] << " ";
    std::cout << std::endl;
}

int missingNumber(std::vector<int>& nums) {
    int n = nums.size();

    // you are sorting it in a tricky way
    for (int i = 0 ;i < n ;) {
        if (nums[i] < n && nums[i] !=i )
            std::swap(nums[i] , nums[nums[i]]);
        else
            i++;
    }
    printVector(nums);
    for (int i = 0 ;i < nums.size();i++) {
        if (nums[i] != i)
            return i;
    }

    return nums.size();
}

int KthSmallest(std::vector<std::vector<int>>& matrix , int k) {
    std::vector<int> flat;
    // Flatten the matrix
    for (const auto& row : matrix)
        flat.insert(flat.end(), row.begin(), row.end());

    // Sort the flattened vector
    std::sort(flat.begin(), flat.end());

    for (int i = 0  ;i < flat.size() ;i++) {
        std::cout << flat[i] << " ";
    }
    std::cout << std::endl;
    return flat[k-1];
}


std::vector<int> intersect(std::vector<int>& nums1 , std::vector<int>& nums2) {
    std::vector<int> result;
    std::unordered_map<int , int> mp;
    for (int item : nums1)
        mp[item]++;

    for (int i = 0 ;i < nums2.size();i++) {
        if (mp.find(nums2[i]) != mp.end()) {
            if (mp[nums2[i]] != 0) {
                result.push_back(nums2[i]);
                mp[nums2[i]]--;
            }
        }
    }
    return result;
}

int lowerBound(std::vector<int> & nums ,int index ,  int lower) {
    int left = index + 1;
    int right = nums.size() - 1;
    int result = nums.size(); // Default: no valid position found

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int sum = nums[index] + nums[mid];

        if (sum >= lower) {
            result = mid; // Update result to the smallest valid mid
            right = mid - 1; // Search left for a smaller valid position
        } else {
            left = mid + 1; // Search right
        }
    }
    return result;
}

int upperBound(std::vector<int> & nums , int index ,int upper) {
    int left = index + 1;
    int right = nums.size() - 1;
    int result = index; // Default: no valid position found (will be adjusted in loop)

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int sum = nums[index] + nums[mid];

        if (sum <= upper) {
            result = mid; // Update result to the largest valid mid
            left = mid + 1; // Search right for a larger valid position
        } else {
            right = mid - 1; // Search left
        }
    }
    return result;

}

long long countFairPair(std::vector<int>& nums , int lower , int upper) {
    long long int result = 0;
    std::sort(nums.begin() , nums.end());

    for (int i = 0 ;i < nums.size() ;i++ ) {
        int ub = upperBound(nums , i , upper);
        int lb= lowerBound(nums , i , lower);
        if (lb <= ub && lb < nums.size()) {  // Check if valid range exists
            result += (ub - lb + 1);
        }
    }

    return result;
}
int main(){
    std::cout << "Hello , world" << std::endl;
    return 0;
}
