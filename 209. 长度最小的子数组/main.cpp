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
    int minSubArrayLen(int target, vector<int>& nums) {
        std::size_t left = 0, right = 0,length = 0;
        bool flag{true};
        int sum = 0;
        while (right<nums.size()){
            sum+=nums[right];
            while(sum>=target){
                if(flag){
                    length = right-left+1;
                    flag = false;
                }
                else length = std::min(length,right-left+1);
                sum-=nums[left];
                ++left;
            }
            ++right;
        }
        return length;
    }
};
int main() {
    Solution sol;
    vector<int>nums{2,3,1,2,4,3};
    std::cout<<sol.minSubArrayLen(7,nums)<<std::endl;
    return 0;
}
