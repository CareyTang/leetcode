/*
 * @Author: your name
 * @Date: 2021-02-25 23:39:02
 * @LastEditTime: 2021-02-27 00:35:20
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\1178. 猜字谜\main.cpp
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
  //暴力法超时
/* 	
     vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
         vector<int> ret(puzzles.size(), 0);
         int i = 0;
         for ( const auto &pu:puzzles ) {
             char first = pu[0];
             std::set<char> puhave{pu.begin(), pu.end()};
             for ( const auto &wo:words ) {
                 bool havefirst = false, havenotexist = false;
                 for ( const auto &item:wo ) {
                     if ( puhave.find(item) == puhave.end())havenotexist = true;
                     else if ( item == first )havefirst = true;
                 }
                 if ( havefirst && !havenotexist)ret[i]++;

             }
             ++i;
         }
         return ret;
     }
 */
  vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles) {
	map<int, int> wordCounts{};
	vector<int> puzzleCount(puzzles.size(), 0), ret(puzzles.size(), 0);
	int i = 0;
	for (const auto &word:words) {
	  int temp = 0;
	  for (const auto &c : word) {
		temp |= 1 << (c - 'a');
	  }
	  wordCounts[temp]++;
	}
	for (const auto &puzzle:puzzles) {
	  int first = 1 << (puzzle[0] - 'a');
	  for (const auto &c : puzzle)puzzleCount[i] |= 1 << (c - 'a');
	  int ori = puzzleCount[i];
	  //现在的puzzleCount[i]就是含有的所有子集的，我们要从中筛选出有first的子集
	  while (puzzleCount[i] > 0) {
		if (puzzleCount[i] & first) {
		  auto iter = wordCounts.find(puzzleCount[i]);
		  if (iter!=wordCounts.end())ret[i] += iter->second;
		}
		puzzleCount[i] = (puzzleCount[i] - 1) & ori;
	  }
	  ++i;
	}
	return ret;
  }

};

int main() {
  vector<string> a{"aaaa", "asas", "able", "ability", "actt", "actor", "access"},
	  b{"gaswxyz"};
  Solution sol;
  sol.findNumOfValidWords(a, b);
  return 0;
}
