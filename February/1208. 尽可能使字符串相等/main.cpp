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
  int equalSubstring(string s, string t, int maxCost) {
	int sumCost{};
	std::size_t indexBeg{0};
	std::size_t length{0};
	for (std::size_t indexEnd = 0; indexEnd < s.size(); ++indexEnd) {
	  sumCost += std::abs(s[indexEnd] - t[indexEnd]);
	  if (sumCost > maxCost) {
		sumCost -= std::abs(s[indexBeg] - t[indexBeg]);
		++indexBeg;
	  }
//            length = (indexEnd-indexBeg+1)>length?(indexEnd-indexBeg+1):length;
//关于上行代码为什么注释掉的解释，首先在for循环中，无论怎样窗口始终都会向右扩张直到窗口最右端到达s.end()
//在for循环中，如果当前这个元素加入了窗口使sumCost>maxCost，那么窗口会平移，保持原有的大小，相当于保持了最大的窗口大小
//如果这个元素加入了窗口sumCost<=maxCost，那么窗口会向右扩张，从而窗口大小扩大
//所以，在整个过程中，即使新加入的元素cost很高，但是窗口大小没有变化，所以最后留下的是全局最优解而不是局部最优解。
	}
	return s.size() - indexBeg;
  }
};

int main() {
  Solution sol;
  string s1{"krrgw"};
  string s2{"zjxss"};
  std::cout << sol.equalSubstring(s1, s2, 19) << std::endl;
  return 0;
}