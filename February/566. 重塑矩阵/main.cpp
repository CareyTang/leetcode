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
  vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
	std::size_t row = nums.size(), column = nums[0].size();
	vector<vector<int>> res(r, vector<int>(c, 0));\
        std::size_t index{};
	if (row * column!=r * c)return nums;
	else {
	  while (index < row * column) {
		res[index / c][index % c] = nums[index / column][index % column];
		++index;
	  }
	  return res;
	}
  }
};

int main() {
  vector<vector<int>> nums{{1, 2}, {3, 4}, {5, 6}};
  Solution sol;
  sol.matrixReshape(nums, 2, 3);
  return 0;
}
