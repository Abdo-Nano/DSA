
// Created by nano on 11/15/24.
//

#pragma once

#ifndef PROBLEMS_H
#define PROBLEMS_H


#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;



bool hasDuplicate(vector<int>& nums) {
    // time and space complexity is O(n)
    unordered_set<int> result;
    for(const int & item : nums) {
        if(result.contains(item))
            return true;
        result.insert(item);
    }
    return false;
}


bool isAnagram(string s, string t) {
    /* simple algorithm
     *  time and space complexity are both O(n)
     * - first check if their len are equal or not
     * - dec a hash table for each of them
     * - store the characters of the string , and it's number
     * - compare two hash tables to each other
     */
    if (s.length() != t.length()) {
        return false;
    }

    unordered_map<char, int> countS;
    unordered_map<char, int> countT;
    for (int i = 0; i < s.length(); i++) {
        countS[s[i]]++;
        countT[t[i]]++;
    }
    return countS == countT;
}


vector<int> twoSum(vector<int>& nums, int target) {
    /* = the algorithm
     * -- time and space complexity are both O(n)
     * - store the values in hash table with their indices
     * - loop through the array and get the abs value
     * - look for the abs value except the current value
     * - return the index of current value and the hash table value
     */

    vector<int> result;
    unordered_map<int , int> container; // value -> index
    for(int i = 0 ;i < nums.size();i++)
       container[nums[i]] = i;

    for(int i = 0 ; i < nums.size();i++) {
        int absValue = target - nums[i];
        if(container.find(absValue) != container.end() && container[absValue] != i) {
           return {i , container[absValue]};
        }
    }
}

// come here again
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*
         * - fucking time and space complexity
         * - dec a hash table / val -> vector of anagrams
         * - if it's empty insert it
         * - if not , then check if it anagram with other or not
         *     - if anagram , then push it
         *     - else insert it to the hash table
         * - dec a result vector and push to it the values of the hash table
         * - return the result
         */
        unordered_map<string, vector<string>> container;

        for (const auto& str : strs) {
            bool found = false;

            for (auto& item : container) {
                if (isAnagram(item.first, str)) {
                    item.second.push_back(str);
                    found = true;
                    break; // Stop checking after finding a match
                }
            }

            // If no matching anagram group is found, insert as a new group
            if (!found) {
                container.insert({str, {str}});
            }
        }

        vector<vector<string>> result;
        for (const auto& item : container) {
            result.push_back(item.second);
        }
        return result;
}



void print()
{

    cout << "hello world" << endl;

}
#endif //PROBLEMS_H
