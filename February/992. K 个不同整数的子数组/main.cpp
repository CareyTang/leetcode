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

//求 A 中由 K 个不同整数组成的最长子数组的长度
int func1(vector<int> &A, int K) {
  std::size_t left = 0, right = 0;
  //原本是使用map<int,int>记录当前整数出现的次数的，但是目前看起来好像map占用的空间以及之后的erase()用时比较久，考虑使用vector代替
  //map<int,int>times{};
  vector<int> times(20000, 0);
  int unique{};
  std::size_t res{};
  while (right < A.size()) {
	if (times[A[right]]==0)unique++;
	times[A[right]] += 1;
	while (unique > K) {
	  times[A[left]] -= 1;
	  if (times[A[left]]==0) {
		unique--;
	  }
	  left++;
	}
	res = std::max(res, right - left + 1);
	right++;
  }
  return res;
}

/*A 中由最多 K 个不同整数组成的子数组的个数
和func1()不一样，这里求的是个数，在func1()中，我们可以计算出最长的数组的长度。
 现在思考一下窗口内最多K个不同整数组成的子数组的个数和窗口之间的关系，以{1,2,1,2,3}为例
 {1}的子数组个数为1；
 {1,2}的子数组的个数为{1}，{1,2}，{2}，个数为3个，和{1}相比增加了{1，2}，{2}两个以当前2结尾的子数组
 {1,2,1}的子数组的个数为{1}，{1,2}，{1,2,1}，{2}，{2,1}，{1}，个数为6，相比于{1,2}增加了以1结尾的3个子数组
 ……
 所以可以总结，每一次形成了新的窗口之后，相比于滑动前的窗口，会增加size个数组，也就是right-left+1个
*/
int func2(vector<int> &A, int K) {
  std::size_t left = 0, right = 0;
  //map<int,int>times{};
  vector<int> times(20000, 0);
  int unique{};
  std::size_t res{};
  while (right < A.size()) {
	if (times[A[right]]==0)unique++;
	times[A[right]] += 1;
	while (unique > K) {
	  times[A[left]] -= 1;
	  if (times[A[left]]==0) {
		unique--;
	  }
	  left++;
	}
	res += right - left + 1;
	right++;
  }
  return res;
}
/*
 * 题目要求的是 恰好K个不同的整数组成的子数组的个数，可以理解为最多K个不同的整数组成的子数组的个数-最多(K-1)个不同的整数组成的子数组的个数
 */
class Solution {
 public:
  int subarraysWithKDistinct(vector<int> &A, int K) {
	return func2(A, K) - func2(A, K - 1);
  }
};

int main() {
  vector<int> nums{1, 2, 1, 2, 3};
  Solution sol;
  std::cout << func2(nums, 1) << std::endl;
  std::cout << sol.subarraysWithKDistinct(nums, 2) << std::endl;
  return 0;
}
