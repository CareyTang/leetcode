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
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 0, current = nums[0], count = 0;
        while (right<nums.size()){
            if(nums[right]==current) ++count;
            else{
                current = nums[right];
                count = 1;
            }
            nums[left] = nums[right];
            if(count<=2)++left;
            ++right;
        }
        return left;
    }
};

int main() {
    Solution sol;
    vector<int>nums{1,1,1,2,2,3};
    std::cout<<sol.removeDuplicates(nums)<<std::endl;
    return 0;
}
