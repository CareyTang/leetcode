#include <iostream>
#include <numeric>
#include <vector>
#include <set>

using std::vector;

class Solution {
 public:
  vector<int> findSwapValues(vector<int> &array1, vector<int> &array2) {
	int sum1 = std::accumulate(array1.cbegin(), array1.cend(), 0);
	int sum2 = std::accumulate(array2.cbegin(), array2.cend(), 0);
	std::set<int> set1(array1.begin(), array1.end());
	std::set<int> set2(array2.begin(), array2.end());
	if ((sum1 + sum2) % 2!=0) return vector < int > {};
	int less = sum1 - (sum1 + sum2) / 2;
	for (const auto &item1 : set1) {
	  for (const auto &item2 : set2) {
		if (item1 - item2==less) return vector < int > {item1, item2};
	  }
	}
	return vector < int > {};
  }
};

int main() {
  Solution sol;
  vector<int> arr1{519, 886, 282, 382, 662, 4718, 258, 719, 494, 795};
  vector<int> arr2{52, 20, 78, 50, 38, 96, 81, 20};
  vector<int> ans = sol.findSwapValues(arr1, arr2);
  return 0;
}
