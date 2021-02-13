#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <deque>
#include <set>
#include <map>

using std::vector;
using std::string;
using std::deque;
using std::multiset;
using std::multimap;
using std::map;

class KthLargest {
public:
    int k{};
    vector<int>nums{};
    int currentKthLargest{};
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->nums = nums;
        
    }

    int add(int val) {

    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
