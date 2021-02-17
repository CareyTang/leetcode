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
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0;
        int size = nums.size();
        while (right<size){
            if(nums[right]!=0){
                nums[left] = nums[right];
                ++left;
            }
            ++right;
        }
        for (int i = left; i <size ; ++i) {
            nums[i] = 0;
        }
    }
};


int main() {
    Solution sol;
    vector<int>nums{0,1,0,3,12};
    sol.moveZeroes(nums);
    return 0;
}
