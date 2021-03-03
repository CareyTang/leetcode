<!--
 * @Author: your name
 * @Date: 2021-03-01 10:33:43
 * @LastEditTime: 2021-03-02 11:08:57
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\March\readme.md
-->

- [[待完善]2021.3.1 395. 至少有 K 个重复字符的最长子串](#待完善202131-395-至少有-k-个重复字符的最长子串)
- [2021.3.2 304. 二维区域和检索 - 矩阵不可变](#202132-304-二维区域和检索---矩阵不可变)

# [待完善]2021.3.1 [395. 至少有 K 个重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/)

# 2021.3.2 [304. 二维区域和检索 - 矩阵不可变](https://leetcode-cn.com/problems/range-sum-query-2d-immutable/)

依旧是前缀和的解法，当前的结果取决于之前的结果加上目前的选择。题解写的比我想的详细多了，可以参考下面两篇题解。

1. [二维区域和检索 - 矩阵不可变](https://leetcode-cn.com/problems/range-sum-query-2d-immutable/solution/er-wei-qu-yu-he-jian-suo-ju-zhen-bu-ke-b-2z5n/)
2. [如何求二维的前缀和，以及用前缀和求子矩形的面积](https://leetcode-cn.com/problems/range-sum-query-2d-immutable/solution/ru-he-qiu-er-wei-de-qian-zhui-he-yi-ji-y-6c21/)

但是要注意一个边界条件，当我们构造一个空的矩阵的时候，注意此时的`row和col`。

```c++
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
```



