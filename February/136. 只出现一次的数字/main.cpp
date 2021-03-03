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
  int singleNumber(vector<int> &nums) {
	map<int, int> times{};
	int size = nums.size();
	for (int i = 0; i < size; ++i) {
	  times[nums[i]]++;
	}
	for (const auto &item : times) {
	  if (item.second==1)return item.first;
	}
	return 0;
  }

  int singleNumber2(vector<int> nums) {
	int res{nums[0]};
	int size = nums.size();
	for (int i = 1; i < size; ++i) {
	  res = res ^ nums[i];
	}
	return res;
  }
};

int main() {
  Solution sol;
  vector<int> nums{2, 2, 1};
  std::cout << sol.singleNumber2(nums) << std::endl;
  return 0;
}
