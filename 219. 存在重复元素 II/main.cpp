#include <iostream>
#include <map>
#include <vector>
using std::vector;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::map<int,int> sets{};
        //用一个大小为k的set去存储nums的数据
        //set已经被装满了还没有出现重复的就说明不可能在k的窗口内找到
        //如果set还没有被装满，就发现了出现重复的了，那么就可以返回true
        for (int i = 0;i<nums.size();++i) {
            // 如果发现在map中已经有了当前下标i对应的元素,判断当前的这个数和保存在sets中的那个数之间的距离是否小于等于k
            // 如果小于等于k，说明在k大小的窗口内已经出现了，那么返回true
            if(sets.find(nums[i])!=sets.end() && i-sets[nums[i]]<=k) return true;
            //如果没找到重复的，或者说两个之间的距离大于k，那么修改对应的sets存储的下标value
            sets[nums[i]] = i;

        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> va{1,2,3,1};
    std::cout<<sol.containsNearbyDuplicate(va,3)<<std::endl;

    return 0;
}