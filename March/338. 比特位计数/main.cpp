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
#include <math.h>

using std::vector;
using std::string;
using std::deque;
using std::multiset;
using std::multimap;
using std::map;
using std::unordered_set;

class Solution {
 public:
  vector<int> countBits(int num) {
    vector<int>ret(num+1,0);
	for (int i = 0; i <= num; ++i) {
	  ret[i] = oneNumber2(i);
	}
	return ret;
  }
  //方法一：利用num&(num-1)可以消去最右边的二进制1实现
  int oneNumber1(int num){
    int count = 0;
	while (num!=0){
	  num &= (num-1);
	  ++count;
	}
	return count;
  }

  //方法二：利用位操作实现
  unsigned int oneNumber2(unsigned int num){
	num = ((num & 0xAAAAAAAA) >> 1) + (num & 0x55555555);
	num = ((num & 0xCCCCCCCC) >> 2) + (num & 0x33333333);
	num = ((num & 0xF0F0F0F0) >> 4) + (num & 0x0F0F0F0F);
	num = ((num & 0xFF00FF00) >> 8) + (num & 0x00FF00FF);
	num = ((num & 0xFFFF0000) >> 16) + (num & 0x0000FFFF);
	return num;
  }
};
int main() {
  Solution sol;
  int ret = sol.oneNumber2(85723);
  return 0;
}
