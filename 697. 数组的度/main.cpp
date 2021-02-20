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


class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,vector<int>> counts{};
        int ret = nums.size(),degree{};
        for(int i = 0; i < nums.size();++i){
            if(counts.find(nums[i])==counts.end())counts[nums[i]] = {1,i,i};
            else{
                counts[nums[i]][0]++;
                counts[nums[i]][2] = i;
            }
            degree = std::max(degree,counts[nums[i]][0]);
        }
        for(const auto& item:counts) {
            if (item.second[0] == degree) {
                ret = std::min(item.second[2] - item.second[1] + 1, ret);
            }
        }
        return ret;
    }
};


int main() {
    vector<int>nums{1,3,2,2,3,1};
    Solution sol;
    sol.findShortestSubArray(nums);
    return 0;
}
