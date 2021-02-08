# Leetcode with cpp

## author:Javy

### 2021.2.2 424-替换后的最长重复字符(https://leetcode-cn.com/problems/longest-repeating-character-replacement/)

使用了`std::max`替代了`max_element`，用时4ms(98.16%)，内存6.9mb(93.17%)

**知识点：少用algorithm的算法，能用下标的尽量用下标，不要使用复杂的容器和指针**

### 2021.2.2 面试题16.21 交换和(https://leetcode-cn.com/problems/sum-swap-lcci/)

**对于有大量数据的，如果用`vector`的话会导致超时，可以利用`set`的只保存`unique` 元素的特性进行处理，对`vector`的数据进行降维**

### 2021.2.2 219. 存在重复元素 II(https://leetcode-cn.com/problems/contains-duplicate-ii/)

**对于有大量的数据的，`set`可以对重复数据进行删减，从而减少有效数据的个数.**

但是`set`保存数据的方法是使用`Hash`算法，所以数据的保存并不会如我们所 期望的那样。所以如果我们想要使数据能够保持我们期望的顺序，可以考虑使用`map` 代替`set`，虽然`map`相比于`set`更加的复杂，多了`key-value`，但是可以利用`value`的值保存顺序，形成一个伪顺序。比如在`value`中保存我们期望的下标。

`insert(iter)`都是在当前的这个`iter`前面插入数据，如果不添加`hint`， 就会在调用`insert`函数的容器利用`Hash`算法找到插入的地方。

### 2021.2.2 1332. 删除回文子序列（https://leetcode-cn.com/problems/remove-palindromic-subsequences/)

脑筋急转弯的一道题，关键在于理解回文子序列这个意思，定义为：通过对原字符串中的某些字符进行删除，不改变其他字符的顺序，剩下的那些字符 依旧是回文形式，就成为回文子序列。所以说，对于只有`a和b`两种字符组成的字符串而言，只有三种情况：

1. 当目前的字符串是空，那么需要删除的次数就是0次；对此可以利用`size()`进行判断
2. 当目前的字符串本身就是回文，那么需要删除的次数就是1次；对此可以`reverse()`进行判断
3. 当目前的字符串不属于上面两种情况，那么需要删除的次数必然是2次，一次全删除`a`，一次全删除`b`。

### 2021.2.3 480. 滑动窗口中位数(https://leetcode-cn.com/problems/sliding-window-median/)

待完善

### 2021.2.4 643. 子数组最大平均数 I(https://leetcode-cn.com/problems/maximum-average-subarray-i/)

对于此类的滑动窗口类型的题目，关键在于怎么确定窗口滑动的条件，一般的窗口滑动题目都有共性，比如：

1. 需要对窗口内的元素进行相应的操作；
2. 需要对窗口进行平移操作，牵扯到窗口的`pop_front()`操作和`push_back()`操作，什么时候加入什么时候删除
3. 窗口到头了的边界条件判断

### 2021.2.5 1208. 尽可能使字符串相等(https://leetcode-cn.com/problems/get-equal-substrings-within-budget/)

1. **用`std::abs()`代替`abs()`可以减少用时，猜测是前者优化的更好**
2. 窗口滑动到最后窗口的大小变化是什么样子的

### 2021.2.6 1423. 可获得的最大点数(https://leetcode-cn.com/problems/maximum-points-you-can-obtain-from-cards/)

关键在于使用逆向思维的方法，原本是可以在头部和尾部分开取元素以获得最大点数，但是反过来剩下的就是最小的点数的组合，所以如果计算什么样的窗口可以获得最小的点数，再用全部的`sum`减去最小的点数，剩下的就是最大的点数和了。同样要使用`std::min`来代替`min`。

### 2021.2.7 665. 非递减数列(https://leetcode-cn.com/problems/non-decreasing-array/)

虽然是一个`easy`题，但是确实学到了很多东西。总结一下：

1. 首先，对于一个非递减数列，如果到当前下标`index`为止，整个数列都是上升趋势的，那么不管他，因为目前来看依旧符合要求；
2. 如果开始当前下标`index`和前一个`index-1`相比，有下降趋势，那么此时必须要发生修改了，用`count`记录修改次数
   1. 比如`{3,4,2,5}`，如果当前的`index(2)`下标大于`index-2(3)`，那么此时很容易想到，应该把`index`对应的值修改成`index-1`对应的值，修改后就是`{3,4,4,5}`；
   2. 但是也有特例，比如测试用例`{4,2,3}`，此时都没有`index-2`，所以应该修改`index-1`为`index`；
   3. 比如`{2,4,3,5}`，当前的`index(3)`大于`index-2(2)`，那么此时应该修改`index-1`为`index`的值，修改后就是`{2,2,3,5}`

​	3. 所以综上总结，一共就两种情况：

```
if(index==1||nums[index]>=nums[index-2]) nums[index-1] = nums[index];
else nums[index] = nums[index-1];
```

并且每次发生了修改之后都需要`++count`，然后最后判断`count<=1`，通过判断修改的次数是否超过了1，如果超过了，就说明不合格。

### 2021.2.7 888. 公平的糖果棒交换(https://leetcode-cn.com/problems/fair-candy-swap/)

难度不大，很简单的双指针比较题目。常使用`vector的push_back()`操作，但是发现很耗时间，最后使用双指针目前达到一个比较令人满意的结果。尝试后续使用`binart_search()`或者`hashmap`的方法。

### 2021.2.8 978. 最长湍流子数组(https://leetcode-cn.com/problems/longest-turbulent-subarray/)

**使用了动态规划算法。**

先复习一下动态规划算法(https://www.zhihu.com/question/39948290/answer/883302989)。

动态规划算法分为三个子目标：

1. 建立状态转移方程，也就是根据`f(1)~f(n-1)`的方程得出`f(n)`的公式
2. 缓存并复用以减少每次计算方程的计算量，计算`f(n)`时可以直接使用`f(n-1)`的值
3. 按照从小到大的顺序

所以联系最长湍流子数组这道题，说白了就是找数组中满足`↗ ↘ ↗ ↘`或者`↘ ↗ ↘ ↗`规律的最长的子数组的长度，现在如果使用动态规划算法，首先应该建立状态转移方程。

1. 只要不是空数组，那么必然存在至少`1`个满足规律的子数组(本身)，而如果`index=2`满足要求，那么有两种情况：要不`index=1<index=2`，形成`↗`趋势；要不`index=1>index=2`，形成`↘`趋势；

2. 而`index=3`如果满足最长的条件，那么前面俩必然满足湍流子数组的条件，然后根据对应情况在对应的湍流子数组长度上+1。也就是说，如果前两个满足`↗ ↘`的规律，那么`index=3和index=2`就应该满足`↘ ↗`的规律；同理，如果前两个满足 `↘↗`的规律，那么`index=3和index=2`就应该满足 `↗↘`的规律；

3. 所以综上，我们需要两个变量来记录分别对应两种规律的情况下，当前的`index`对应的湍流子数组长度的值，这里我们使用`up`和`down`两个变量进行记录；`up`表示` ↗`规律，`down`表示` ↘`规律。`up[index]`表示截止到`index`为止，前面的最长的湍流子数组的长度，`down[index]`同理。

4. 对应`index`而言，如果`arr[index-1]<arr[index]`，即满足`↗`规律，那么对于`index-1`就应该满足`↘`规律，即`arr[index-2]>arr[index-1]`，那么就可以`up[index]=down[index-1]+1`，即使后者不满足，也可以`up[index]=down[index-1]+1`，因为至少有了`index-1,index`两个变量。

5. 所以我们可以初始化`up=down=1`，代码如下：

   ```c++
   for (int i = 1; i < arr.size(); i++) {
       if (arr[i - 1] < arr[i]) {
           up = down + 1;
           down = 1;
       } else if (arr[i - 1] > arr[i]) {
           down = up + 1;
           up = 1;
       } else {
           up = 1;
           down = 1;
       }
       res = std::max(res, std::max(up, down));
   }
   ```

