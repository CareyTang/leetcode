#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <cmath>

using std::vector;
using std::string;
using std::deque;
using std::multiset;
using std::multimap;
using std::map;
using std::unordered_set;
class Solution{
 public:
  Solution& nthfib(int num){
	for (int i = 2; i <= num; ++i) {
	  table[i] = table[i-1] + table[i-2];
	}
  }
 private:
  vector<int> table{0,1};
};
int main() {
  int num = 0;

  return 0;
}
