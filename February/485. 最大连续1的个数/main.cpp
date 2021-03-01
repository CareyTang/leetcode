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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count{};
        int maxCount{};
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            if(nums[i]==1)++count;
            else{
                maxCount = std::max(maxCount,count);
                count = 0;
            }
        }
        maxCount = std::max(maxCount,count);
        return maxCount;
    }
    //windows
    int findMaxConsecutiveOnes2(vector<int>& nums) {
        int res{};
        int left = 0, right = 0;
        int size = nums.size();
        while (right<size){
            if(nums[right++]!=1){
                left = right;
            }
            res = std::max(right-left,res);
        }
        return res;
    }
    //dp
    int findMaxConsecutiveOnes3(vector<int>& nums) {
        int maxCount{};
        int j{};
        for (int i = 0; i < nums.size(); ++i) {
            if(nums[i]==0){
                j=i+1;
            }
            maxCount = std::max(maxCount,i-j+1);
        }
        return maxCount;
    }
};
int main() {
    vector<int> nums{1,1,0,1,1,1};
    Solution sol;
    std::cout << sol.findMaxConsecutiveOnes2(nums) << std::endl;
    return 0;
}
