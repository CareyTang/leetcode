#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <deque>
#include <set>
#include <map>
#include <queue>

using std::vector;
using std::string;
using std::deque;
using std::multiset;
using std::multimap;
using std::set;
using std::priority_queue;

class KthLargest {
 public:
  int k = {};
  priority_queue<int, vector<int>, std::greater<int>> pqueue;
  KthLargest(int k, vector<int> &nums) {
	this->k = k;
	for (int i = 0; i < nums.size(); ++i)add(nums[i]);
  }

  int add(int val) {
	pqueue.push(val);
	if (pqueue.size() > this->k)
	  pqueue.pop();
	return pqueue.top();
  }
};

int main() {
  vector<int> nums = {4, 5, 8, 2};
  KthLargest *obj = new KthLargest(3, nums);

  return 0;
}
