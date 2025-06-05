#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>
#include <unordered_map>
#include <ranges>


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

int romanToInt(const std::string & s) {
    std::unordered_map<char, int> sybmolsValues {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };


    int result = 0;

    for (int i = 0 ;i < s.size() ;i++ ) {
        if (i < s.size()  && sybmolsValues[s[i]] < sybmolsValues[s[i+1]])
            result -= sybmolsValues[s[i]];
        else
            result += sybmolsValues[s[i]];
    }
    return result;

};


class Test {
private:
    int size;
    std::queue<int> q;

public:
    Test(int size) :  size(size) {}
};




class LRUCache {
    std::unordered_map<int, int> mp;
    std::deque<int> dq;
    int size;
    int length;

public:
    LRUCache(int capacity) : size(capacity), length(0) {}

    int get(int key) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            // Move the accessed key to front
            dq.erase(std::remove(dq.begin(), dq.end(), key), dq.end());
            dq.push_front(key);
            return it->second;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // Key exists, update value and move to front
            mp[key] = value;
            dq.erase(std::remove(dq.begin(), dq.end(), key), dq.end());
            dq.push_front(key);
            return;
        }

        if (length == size) {
            mp.erase(dq.back());
            dq.pop_back();
        } else {
            length++;
        }
        mp[key] = value;
        dq.push_front(key);
    }
};
int main() {
    std::list<int> list {1,2,3,4,5};

    std::cout << "Hello , world" << std::endl;

    return 0;
}
