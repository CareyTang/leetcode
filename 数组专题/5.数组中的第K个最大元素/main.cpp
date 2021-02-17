#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <deque>
#include <set>
#include <map>
#include <queue>

using std::vector;
using std::string;
using std::deque;
using std::multiset;
using std::multimap;
using std::map;
using std::priority_queue;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::sort(nums.begin(),nums.end(),[](int x, int y){return x>y;});
        return nums[k-1];
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
