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

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        int size = nums.size();
        int res{};
        for (int i = 0; i < size; i+=2) {
            res += nums[i];
        }
        return res;
    }
};


int main() {
    Solution sol;
    vector<int>nums{6,2,6,5,1,2};
    std::cout<<sol.arrayPairSum(nums)<<std::endl;
    return 0;
}
