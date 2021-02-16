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
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size = nums.size();
        int times[size+1];
        vector<int>res{};
        for (int i = 0; i < size; ++i) {
            times[nums[i]]++;
        }
        for (int i = 1; i < size; ++i) {
            if(times[nums[i]]==0)res.push_back(i);
        }
        return res;
    }
};
int main() {
    Solution sol;
    vector<int>nums{4,3,2,7,8,2,3,1};
    sol.findDisappearedNumbers(nums);
    return 0;
}
