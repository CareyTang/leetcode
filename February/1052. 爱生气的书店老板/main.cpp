/*
 * @Author: your name
 * @Date: 2021-02-23 10:59:35
 * @LastEditTime: 2021-02-23 11:34:40
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\1052. 爱生气的书店老板\main.cpp
 */
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
  int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X) {
	int ret = INT32_MIN, size = grumpy.size(), happy{};
	int start = 0, end = 0;
	for (int i = 0; i < size; ++i)happy += (1 - grumpy[i]) * customers[i];
	while (end < size) {
	  if (end - start==X - 1) {
		happy -= grumpy[start] * customers[start];
		++start;
	  }
	  happy += grumpy[end] * customers[end];
	  ++end;
	  ret = std::max(ret, happy);
	}
	return ret;
  }
};
int main() {
  vector<int> a{1, 0, 1, 2, 1, 1, 7, 5}, b{0, 1, 0, 1, 0, 1, 0, 1};
  Solution sol;
  sol.maxSatisfied(a, b, 3);
  return 0;
}
