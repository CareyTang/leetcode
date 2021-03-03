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
  int minKBitFlips(vector<int> &A, int K) {
	int count = 0, sum = 0;
	vector<int> diff(A.size() + 1, 0);
	for (int i = 0; i < A.size(); ++i) {
	  sum ^= diff[i];
	  if (sum==A[i]) {
		if (i + K > A.size())return -1;
		sum ^= 1;
		diff[i + K] ^= 1;
		count++;
	  }
	}
	return count;
  }
  int minKBitFlips2(vector<int> &A, int K) {
	int count = 0, sum = 0, flip = 0, val = 2;
	for (int i = 0; i < A.size(); ++i) {
	  if (i >= K && A[i - K] >= val) {
		flip ^= 1;
		A[i - K] -= val;
	  }
	  if (flip==A[i]) {
		if (i + K > A.size())return -1;
		count++;
		A[i] += val;
		flip ^= 1;
	  }
	}
	return count;
  }
};

int main() {
  vector<int> nums{0, 1, 1, 1, 0, 0};
  Solution sol;
  std::cout << sol.minKBitFlips(nums, 3) << std::endl;
  return 0;
}
