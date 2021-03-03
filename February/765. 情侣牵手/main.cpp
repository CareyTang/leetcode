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
  int minSwapsCouples(vector<int> &row) {
	int res{};
	for (auto it = row.begin(); it!=row.end(); it = it + 2) {
	  int &current = *it;
	  int &right = *(it + 1);
	  //如果current是偶数，那么right必然比current大一,[0,1],[2,3]
	  //如果current是奇数，那么right必然比current小一,[1,0],[3,2]
	  if ((current % 2==1 && right==current - 1) || (current % 2==0) && right==current + 1) continue;
	  //如果是奇数，就要去row里面找到current-1，然后swap
	  auto findTemp = std::find(row.begin(), row.end(), current % 2==1 ? current - 1 : current + 1);
	  std::swap(right, *findTemp);
	  ++res;
	}
	return res;
  }
};

int main() {
  Solution sol;
  vector<int> nums{0, 2, 1, 3};
  std::cout << sol.minSwapsCouples(nums) << std::endl;
  return 0;
}
