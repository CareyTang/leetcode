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

class Solution {
 public:
  //先尝试用二维vector写一次看看
  vector<int> getRow(int rowIndex) {
	vector<vector<int>> nums = {};
	for (int row = 0; row < rowIndex + 1; ++row)
	  nums.push_back(vector<int>(row + 1, 1));
	for (int row = 2; row < rowIndex + 1; ++row) {
	  for (int column = 1; column < row; ++column) {
		nums[row][column] = nums[row - 1][column - 1] + nums[row - 1][column];
	  }
	}
	return nums[rowIndex];
  }

  vector<int> getRow2(int rowIndex) {
	vector<int> nums(rowIndex + 1, 1);
	for (int times = 1; times < rowIndex + 1; ++times) {
	  for (int column = times - 1; column > 0; --column) {
		nums[column] += nums[column - 1];
	  }
	}
	return nums;
  }
};

int main() {
  Solution sol;
  sol.getRow2(3);
  return 0;
}
