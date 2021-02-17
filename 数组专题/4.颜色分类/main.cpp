#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <deque>
#include <queue>
#include <set>
#include <map>

using std::vector;
using std::string;
using std::deque;
using std::multiset;
using std::multimap;
using std::map;
using std::priority_queue;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
