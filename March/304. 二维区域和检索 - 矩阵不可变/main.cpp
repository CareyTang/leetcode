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

class NumMatrix {
public:

    NumMatrix(vector<vector<int>>& matrix) {
      int row = matrix.size();
      if(row>0){
        int col = matrix[0].size();
		this->sum.resize(row+1,vector<int>(col+1,0));
		for (int i = 1; i < sum.size(); ++i) {
		  for (int j = 1; j < sum[0].size(); ++j) {
			sum[i][j] = sum[i][j-1] + sum[i-1][j] + matrix[i-1][j-1] - sum[i-1][j-1];
		  }
		}
      }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
	  return sum[row2+1][col2+1] - sum[row1][col2+1] - sum[row2+1][col1] + sum[row1][col1];
    }

private:
  vector<vector<int>> sum{};
};


int main() {
  vector<vector<int>> a{
  };
  auto* obj = new NumMatrix(a);
  int ret = obj->sumRegion(2,1,4,3);
  return 0;
}
