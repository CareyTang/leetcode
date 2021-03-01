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
    int maxArea(vector<int>& height) {
        std::size_t left = 0, right = height.size()-1;
        int maxTemp{},max{};
        while (left<right){
            maxTemp = std::min(height[left],height[right])*(right-left);
            if(height[left]>height[right])--right;
            else ++left;
            max = std::max(max,maxTemp);
        }
        return max;
    }
};

int main() {
    vector<int>height{4,3,2,1,4};
    Solution sol;
    std::cout<<sol.maxArea(height)<<std::endl;
    return 0;
}
