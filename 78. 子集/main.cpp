#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <math.h>

using std::vector;
using std::string;
using std::deque;
using std::multiset;
using std::multimap;
using std::map;
using std::unordered_set;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> ret{};
		vector<int> current{};
		dfs(nums,0,current,ret);
		return ret;
    }

    void dfs(vector<int>& nums,int index,vector<int> current,vector<vector<int>>& ret){
		if(index==nums.size()){
		    ret.push_back(current);
            return;
		}
		dfs(nums,index+1,current,ret);
		current.push_back(nums[index]);
		dfs(nums,index+1,current,ret);
	}
	
	vector<vector<int>> subsets2(vector<int>& nums) {
		vector<vector<int>> ret{};
		vector<int> current{};
		for(int i=0;i<pow(2,nums.size());++i){
		    int item = i,index = 0;
			vector<int>temp{};
			while(item){
                if(item & 0x1)temp.push_back(nums[index]);
                item=item>>1;
                ++index;
			}
			ret.push_back(temp);
			
		}
		return ret;
    }
	
};

int main() {
    Solution sol;
    vector<int> nums{1,2,3};
    sol.subsets2(nums);
	
    return 0;
}
