/*
 * @Author: your name
 * @Date: 2021-02-25 19:48:36
 * @LastEditTime: 2021-02-25 20:01:22
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\数组专题\8.有效的数独\main.cpp
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
  bool isValidSudoku(vector<vector<char>> &board) {
	int rowOk[9][9] = {0};
	int barOk[9][9] = {0};
	int columnOk[9][9] = {0};
	int index = 0;
	for (int i = 0; i < 9; ++i) {
	  for (int j = 0; j < 9; ++j) {
		if (board[i][j]=='.')continue;
		else {
		  index = board[i][j] - '0' - 1;
		  columnOk[i][index]++;
		  rowOk[j][index]++;
		  barOk[i / 3 * 3 + j / 3][index]++;
		}
		if (columnOk[i][index] > 1 || rowOk[j][index] > 1 || barOk[i / 3 * 3 + j / 3][index] > 1)
		  return false;
	  }
	}
	return true;
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
