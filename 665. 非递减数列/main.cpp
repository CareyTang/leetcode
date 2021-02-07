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
    bool checkPossibility(vector<int>& nums) {
        std::size_t size = nums.size();
        int count = 0;
        for(std::size_t index = 1;index<size-1;++index){
            if(nums[index]<nums[index-1]){
                if(index==1||nums[index]>=nums[index-2]) nums[index-1] = nums[index];
                else nums[index] = nums[index-1];
                ++count;
            }
        }
        return count&1;
    }
};

int main() {
    Solution sol;
    vector<int>nums{4,2,3};
    std::cout<<sol.checkPossibility(nums)<<std::endl;
    return 0;
}
