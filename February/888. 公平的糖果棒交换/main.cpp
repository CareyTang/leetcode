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
  vector<int> fairCandySwap(vector<int> &A, vector<int> &B) {

	std::sort(A.begin(), A.end());
	std::sort(B.begin(), B.end());
	int diff = (std::accumulate(A.begin(), A.end(), 0) + std::accumulate(B.begin(), B.end(), 0)) / 2
		- std::accumulate(B.begin(), B.end(), 0);
	std::size_t j = 0, i = 0;
	int sizeA = A.size();
	int sizeB = B.size();
	while (i < sizeA && j < sizeB) {
	  if (A[i] - B[j]==diff)return {A[i], B[j]};
	  else if (A[i] - B[j] > diff) ++j;
	  else ++i;
	}
	return {};
  }
};
int main() {
  Solution sol;
  vector<int> A{2};
  vector<int> B{1, 3};
  sol.fairCandySwap(A, B);
  return 0;
}
