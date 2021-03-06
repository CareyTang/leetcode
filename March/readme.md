- [[待完善]2021.3.1 395. 至少有 K 个重复字符的最长子串](#待完善202131-395-至少有-k-个重复字符的最长子串)
- [2021.3.2 304. 二维区域和检索 - 矩阵不可变](#202132-304-二维区域和检索---矩阵不可变)
- [2021.3.3 338. 比特位计数](#202133-338-比特位计数)
- [[待优化]2021.3.4 35. 搜索插入位置](#待优化202134-35-搜索插入位置)
- [[待优化]2021.3.4 300. 最长递增子序列](#待优化202134-300-最长递增子序列)
- [[未解决] 2021.3.4 354. 俄罗斯套娃信封问题](#未解决-202134-354-俄罗斯套娃信封问题)
- [[未解决] 2021.3.5 232. 用栈实现队列](#未解决-202135-232-用栈实现队列)

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

# 2021.3.3 [338. 比特位计数](https://leetcode-cn.com/problems/counting-bits/)

特别有意思的一道题目，运用到了好几个位运算的技巧，这里依次记录一下：

1. 如果我们想去掉一个二进制数字的最右边的那个1，那么我们可以使用`nums&(nums-1)`的方法；

2. 如果我们要计算1的个数，可以用以下代码：

   ```c++
   unsigned int oneNumber2(unsigned int num) {
       //注意类型为unsigned int而不是int，因为int的符号位有可能为1，可能导致错乱
   num = ((num & 0xAAAAAAAA) >> 1) + (num & 0x55555555);
   num = ((num & 0xCCCCCCCC) >> 2) + (num & 0x33333333);
   num = ((num & 0xF0F0F0F0) >> 4) + (num & 0x0F0F0F0F);
   num = ((num & 0xFF00FF00) >> 8) + (num & 0x00FF00FF);
       //如果是在16位系统上运行，那么可以不加上最后一条
   num = ((num & 0xFFFF0000) >> 16) + (num & 0x0000FFFF);
   return num;
    }
   ```

参考连接：

1. [位操作基础篇之位操作全面总结](https://blog.csdn.net/MoreWindows/article/details/7354571)

# [待优化]2021.3.4 [35. 搜索插入位置](https://leetcode-cn.com/problems/search-insert-position/)

如果只是用最简单的方法来计算的话，那么就是使用朴素的二分查找的方法，这里写了两种二分查找：

```c++
//第一种二分查找是在区间内寻找target
int binartSearch1(vector<int>&nums, int target){
  int left = 0, right = nums.size()-1, mid = 0;
  while(left<=right){
    mid = left + (right-left)/2;
    if(nums[mid]>target)
      right=mid-1;
    else if(nums[mid]<target)
      left=mid+1;
    else
      return mid;
  }
  return left;
}
//第二种查找方法是在区间内排除不是target
int binartSearch2(vector<int>& nums, int target){
  int left = 0, right = nums.size()-1, mid;
  while (left<right){
      //注意此处while的停止条件
    mid = left + (right-left)/2;
      //注意下面只有两种判断，而不像上面有三种条件
    if(nums[mid]<target)
      left = mid + 1;
    else
      right = mid;
  }
  return left;
}
```

# [待优化]2021.3.4 [300. 最长递增子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)

参考题解：[动态规划 （包含O (N log N) 解法的状态定义以及解释）](https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/dong-tai-gui-hua-er-fen-cha-zhao-tan-xin-suan-fa-p/)

# [未解决] 2021.3.4 [354. 俄罗斯套娃信封问题](https://leetcode-cn.com/problems/russian-doll-envelopes/)

# [未解决] 2021.3.5 [232. 用栈实现队列](https://leetcode-cn.com/problems/implement-queue-using-stacks/)

