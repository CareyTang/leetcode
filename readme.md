# Leetcode with cpp

## author:Javy

### 2021.2.2 424-替换后的最长重复字符(https://leetcode-cn.com/problems/longest-repeating-character-replacement/)

使用了`std::max`替代了`max_element`，用时4ms(98.16%)，内存6.9mb(93.17%)

知识点：少用algorithm的算法，能用下标的尽量用下标，不要使用复杂的容器和指针

### 2021.2.2 面试题16.21 交换和(https://leetcode-cn.com/problems/sum-swap-lcci/)

对于有大量数据的，如果用`vector`的话会导致超时，可以利用`set`的只保存`unique` 元素的特性进行处理，对`vector`的数据进行降维

### 2021.2.2 219. 存在重复元素 II(https://leetcode-cn.com/problems/contains-duplicate-ii/)

对于有大量的数据的，`set`可以对重复数据进行删减，从而减少有效数据的个数. 但是`set`保存数据的方法是使用`Hash`算法，所以数据的保存并不会如我们所 期望的那样。所以如果我们想要使数据能够保持我们期望的顺序，可以考虑使用`map` 代替`set`，虽然`map`相比于`set`更加的复杂，多了`key-value`，但是可以利用`value`的值保存顺序，形成一个伪顺序。比如在`value`中保存我们期望的下标。

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

1. 用`std::abs()`代替`abs()`可以减少用时，猜测是前者优化的更好
2. 窗口滑动到最后窗口的大小变化是什么样子的

### 2021.2.6 1423. 可获得的最大点数(https://leetcode-cn.com/problems/maximum-points-you-can-obtain-from-cards/)

关键在于使用逆向思维的方法，原本是可以在头部和尾部分开取元素以获得最大点数，但是反过来剩下的就是最小的点数的组合，所以如果计算什么样的窗口可以获得最小的点数，再用全部的`sum`减去最小的点数，剩下的就是最大的点数和了。同样要使用`std::min`来代替`min`。

### 2021.2.7 665. 非递减数列(https://leetcode-cn.com/problems/non-decreasing-array/)

