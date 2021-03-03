/*
 * @Author: your name
 * @Date: 2021-02-17 23:09:29
 * @LastEditTime: 2021-02-24 22:32:23
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\4. 寻找两个正序数组的中位数\main.cpp
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
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
	std::size_t size = nums1.size() + nums2.size(), size1 = nums1.size(), size2 = nums2.size();
	int count = 0, left = INT32_MIN, right = INT32_MIN;
	int index1 = 0, index2 = 0;
	if (nums1.empty())return (static_cast<double>(nums2[(size2 - 1) / 2] + nums2[size2 / 2]) / 2);
	else if (nums2.empty())return (static_cast<double>(nums1[(size1 - 1) / 2] + nums1[size1 / 2]) / 2);
	while (count < size / 2 + 1) {
	  left = right;
	  if ((index2 < nums2.size() && index1 < nums1.size() && nums1[index1] <= nums2[index2])
		  || index2 >= nums2.size()) {
		right = nums1[index1];
		++index1;
	  } else if ((index2 < nums2.size() && index1 < nums1.size() && nums1[index1] > nums2[index2])
		  || index1 >= nums1.size()) {
		right = nums2[index2];
		++index2;
	  }
	  ++count;
	}
	return size % 2==1 ? right : (static_cast<double>(right) + left) / 2;
  }
};

int main() {
  Solution sol;
  vector<int> num1{1, 2}, num2{3, 4};
  auto ret = sol.findMedianSortedArrays(num1, num2);
  return 0;
}
