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
  int maxScore(vector<int> &cardPoints, int k) {
	int sum{};
	int smallest{};
	int sumAll{};
	int size = cardPoints.size();
	for (std::size_t index = 0; index < size; ++index) {
	  sum += cardPoints[index];
	  sumAll += cardPoints[index];
	  if (index==size - k - 1)smallest = sum;
	  if (index >= size - k) {
		sum -= cardPoints[index - (size - k)];
		smallest = std::min(smallest, sum);
	  }
	}
	return sumAll - smallest;
  }
};

int main() {
  vector<int> card{1, 2, 3, 4, 5, 6, 1};
  Solution sol;
  std::cout << sol.maxScore(card, 3) << std::endl;
  return 0;
}
