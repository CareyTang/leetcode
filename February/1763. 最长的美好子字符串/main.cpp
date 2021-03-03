/*
 * @Author: your name
 * @Date: 2021-02-23 15:49:11
 * @LastEditTime: 2021-02-23 15:55:41
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\5668. 最长的美好子字符串\main.cpp
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
  string longestNiceSubstring(string s) {
	int size = s.length(), start = 0, length = 0;
	for (int i = 0; i < size; ++i) {
	  vector<int> upper(26, 0), lower(26, 0);
	  for (int j = i; j < size; ++j) {
		int ok = 1;
		if (s[j] <= 'z' && s[j] >= 'a')lower[s[j] - 'a'] = 1;
		else upper[s[j] - 'A'] = 1;
		for (int x = 0; x < 26; ++x) {
		  if (upper[x] ^ lower[x]) {
			ok = 0;
			break;
		  }
		}
		if (ok) {
		  if (j - i + 1 > length) {
			start = i;
			length = j - i + 1;
		  }
		}
	  }
	}
	return s.substr(start, length);
  }
};

int main() {
  string s{"YazaAay"};
  Solution sol;
  std::cout << sol.longestNiceSubstring(s) << std::endl;
}
