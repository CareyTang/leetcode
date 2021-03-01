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
using std::set;

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int ret = 0, diff = INT32_MAX;
        for ( const auto &baseCost : baseCosts ) {
            int current = baseCost;
            dfs(toppingCosts, current, 0, ret, target,diff);

        }
        return ret;
    }

    void dfs(vector<int> &top, int current, int index, int &ret, int& target, int& diff) {
        if(index==top.size()){
            if(abs(current-target)<diff){
                diff = abs(current-target);
                ret = current;
            }
            return;
        }
        dfs(top, current, index + 1, ret, target,diff);
        dfs(top, current + top[index], index + 1, ret, target,diff);
        dfs(top, current + top[index] * 2, index + 1, ret,target,diff);
    }
};
int main() {
    Solution sol;
    vector<int> a{10},b{1};
    int t{1};
    sol.closestCost(a,b,t);
    return 0;
}
