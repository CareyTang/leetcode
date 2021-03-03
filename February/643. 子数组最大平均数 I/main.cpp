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
  double findMaxAverage(vector<int> &nums, int k) {
	deque<int> windows{};
	double tempMax{};
	double max{};
	bool flag{true};
	for (std::size_t i = 0; i < nums.size(); ++i) {
	  tempMax += nums[i];
	  if (i > k - 1)tempMax -= nums[i - k];
	  if (i >= k - 1) {
		if (flag) {
		  max = tempMax;
		  flag = false;
		} else
		  max = tempMax > max ? tempMax : max;
	  }
	}
	return max / k;
  }
};

int main() {
  Solution sol;
  vector<int> num{1, 12, -5, -6, 50, 3};
  std::cout << sol.findMaxAverage(num, 4) << std::endl;
  return 0;
}