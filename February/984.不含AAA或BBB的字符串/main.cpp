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
  string strWithout3a3b(int a, int b) {
	string item{};
	int countA = 0, countB = 0;
	while (a!=0 || b!=0) {
	  //当a的个数大于b的个数且连续填入小于两个a，或者此时已经连续填入两个b了
	  if ((a > b && countA < 2) || (countB==2)) {
		item.push_back('a');
		a--;
		countA++;
		countB = 0;
	  } else {
		item.push_back('b');
		b--;
		countB++;
		countA = 0;
	  }
	}
	return item;
  }
};

int main() {
  Solution sol;
  std::cout << sol.strWithout3a3b(4, 1) << std::endl;
  return 0;
}
