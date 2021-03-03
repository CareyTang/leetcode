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
  int closestCost(vector<int> &baseCosts, vector<int> &toppingCosts, int target) {
	for (const auto &baseCost : baseCosts) {
	  int current = baseCost;
	  dfs(toppingCosts, current, 0, target);
	}
	return ret;
  }

  Solution &dfs(vector<int> &top, int current, int index, int &target) {
	if (index==top.size()) {
	  if (abs(current - target) < diff) {
		diff = abs(current - target);
		ret = current;
	  }
	  return *this;
	}
	dfs(top, current, index + 1, target);
	dfs(top, current + top[index], index + 1, target);
	dfs(top, current + top[index] * 2, index + 1, target);
	return *this;
  }

 private:
  int ret = 0;
  int diff = INT32_MAX;
};
int main() {
  Solution sol;
  vector<int> a{2, 3}, b{4, 5, 100};
  int t{18};
  std::cout << sol.closestCost(a, b, t) << std::endl;
  return 0;
}
