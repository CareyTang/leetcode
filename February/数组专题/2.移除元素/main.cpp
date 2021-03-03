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
  int removeElement(vector<int> &nums, int val) {
	int left = 0, right = 0, count = 0, size = nums.size();
	while (right < size) {
	  if (nums[right]!=val) {
		nums[left] = nums[right];
		++left;
		++count;
	  }
	  ++right;
	}
	return count;
  }
};

int main() {
  Solution sol;
  vector<int> nums{0, 1, 2, 2, 3, 0, 4, 2};
  std::cout << sol.removeElement(nums, 2) << std::endl;
  return 0;
}
