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
using std::set;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int> numbers{nums.begin(),nums.end()};
        vector<int>res{};
        int size = nums.size();
        for (int i = 1; i < size+1; ++i) {
            if(numbers.find(i)==numbers.end())res.push_back(i);
        }
        return res;
    }
    vector<int> findDisappearedNumbers2(vector<int>& nums) {
        vector<int>res{};
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            nums[std::abs(nums[i])-1] = -1 * std::abs(nums[std::abs(nums[i])-1]);
        }
        for (int i = 0; i < size; ++i) {
            if(nums[i]>0)res.push_back(i+1);
        }
        return res;
    }

};

int main() {
    vector<int>nums{4,3,2,7,8,2,3,1};
    Solution sol;
    sol.findDisappearedNumbers2(nums);
    return 0;
}
