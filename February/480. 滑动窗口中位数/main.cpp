#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
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
  vector<double> medianSlidingWindow(vector<int> &nums, int k) {
	vector<double> res{};
	multiset<int> windows{};
	std::size_t i = 0;
	while (i < nums.size()) {
	  windows.emplace(nums[i]);
	  if (i >= k)
		windows.erase(windows.find(nums[i - k]));
	  auto it = windows.begin();
	  if (windows.size() >= k) {
		if (k & 1) {
		  std::advance(it, k / 2);
		  res.push_back(*(it));
		} else {
		  std::advance(it, k / 2);
		  double temp1 = *(it);
		  double temp2 = *(--it);
		  res.push_back((temp1 + temp2) / 2);
		}
	  }
	  ++i;
	}
	return res;
  }
};

int main() {
  Solution sol;
  vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
  sol.medianSlidingWindow(nums, 3);
  return 0;
}