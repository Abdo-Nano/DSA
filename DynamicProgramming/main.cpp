#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <chrono>

std::string result = "    ";

void allSubsets(int index) {
    if (index == result.size()) {
        std::cout << result << std::endl;
        return;
    }

    result[index] = '0';
    allSubsets(index+1);

    result[index] = '1';
    allSubsets(index+1);

    result[index] = ' ';
}


void solve() {
   int n;
    std::cin >> n;

    while (--n) {
        int i;
        std::cin >> i;
        if (i % 2 == 0)
            std::cout << "even" << std::endl;
        else
            std::cout << "odd" << std::endl;
    }
}

int main() {

    std::vector<int> arr {1,2,3,4,5};

    for(int i = 0 ;i < arr.size() ;i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
    solve();
    // 1 2 3 4 5
    return 0;
}
