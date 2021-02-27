- [2021.2.2 424-替换后的最长重复字符](#202122-424-替换后的最长重复字符)
- [2021.2.2 面试题16.21 交换和](#202122-面试题1621-交换和)
- [2021.2.2 219. 存在重复元素 II](#202122-219-存在重复元素-ii)
- [2021.2.2 1332. 删除回文子序列](#202122-1332-删除回文子序列)
- [2021.2.3 480. 滑动窗口中位数](#202123-480-滑动窗口中位数)
- [2021.2.4 643. 子数组最大平均数 I](#202124-643-子数组最大平均数-i)
- [2021.2.5 1208. 尽可能使字符串相等](#202125-1208-尽可能使字符串相等)
- [2021.2.6 1423. 可获得的最大点数](#202126-1423-可获得的最大点数)
- [2021.2.7 665. 非递减数列](#202127-665-非递减数列)
- [2021.2.7 888. 公平的糖果棒交换](#202127-888-公平的糖果棒交换)
- [2021.2.8  978. 最长湍流子数组](#202128--978-最长湍流子数组)
- [2021.2.9 992. K 个不同整数的子数组](#202129-992-k-个不同整数的子数组)
- [2021.2.9 209. 长度最小的子数组](#202129-209-长度最小的子数组)
- [2021.2.10 567. 字符串的排列](#2021210-567-字符串的排列)
- [[重点]2021.2.11 703. 数据流中的第 K 大元素](#重点2021211-703-数据流中的第-k-大元素)
- [2021.2.12 119. 杨辉三角 II](#2021212-119-杨辉三角-ii)
- [2021.2.13 136. 只出现一次的数字](#2021213-136-只出现一次的数字)
- [2021.2.13 448. 找到所有数组中消失的数字](#2021213-448-找到所有数组中消失的数字)
- [2021.2.14 765. 情侣牵手](#2021214-765-情侣牵手)
- [2021.2.14 5676. 生成交替二进制字符串的最少操作数](#2021214-5676-生成交替二进制字符串的最少操作数)
- [2021.2.15 485. 最大连续1的个数](#2021215-485-最大连续1的个数)
- [2021.2.16 561. 数组拆分 I](#2021216-561-数组拆分-i)
- [2021.2.17 566. 重塑矩阵](#2021217-566-重塑矩阵)
- [2021.2.17 4. 寻找两个正序数组的中位数](#2021217-4-寻找两个正序数组的中位数)
- [2021.2.18 1759. 统计同构子字符串的数目](#2021218-1759-统计同构子字符串的数目)
- [[重点]2021.2.18 995. K 连续位的最小翻转次数](#重点2021218-995-k-连续位的最小翻转次数)
- [2021.2.18 984. 不含 AAA 或 BBB 的字符串](#2021218-984-不含-aaa-或-bbb-的字符串)
- [2021.2.19 1004. 最大连续1的个数 III](#2021219-1004-最大连续1的个数-iii)
- [2021.2.19 66.加一](#2021219-66加一)
- [2021.2.19 28. 实现 strStr()](#2021219-28-实现-strstr)
- [2021.2.20 697. 数组的度](#2021220-697-数组的度)
- [2021.2.21 1438. 绝对差不超过限制的最长连续子数组](#2021221-1438-绝对差不超过限制的最长连续子数组)
- [[重点,动态规划]2021.2.21 5687. 执行乘法运算的最大分数](#重点动态规划2021221-5687-执行乘法运算的最大分数)
- [2021.2.22 149. 直线上最多的点数](#2021222-149-直线上最多的点数)
- [2021.2.23 1052. 爱生气的书店老板](#2021223-1052-爱生气的书店老板)
- [2021.2.23 1763. 最长的美好子字符串](#2021223-1763-最长的美好子字符串)
- [2021.2.24 4. 寻找两个正序数组的中位数](#2021224-4-寻找两个正序数组的中位数)
# 2021.2.2 424-替换后的最长重复字符

使用了`std::max`替代了`max_element`，用时4ms(98.16%)，内存6.9mb(93.17%)

**知识点：少用algorithm的算法，能用下标的尽量用下标，不要使用复杂的容器和指针**

# 2021.2.2 面试题16.21 交换和

**对于有大量数据的，如果用`vector`的话会导致超时，可以利用`set`的只保存`unique` 元素的特性进行处理，对`vector`的数据进行降维**

# 2021.2.2 219. 存在重复元素 II

**对于有大量的数据的，`set`可以对重复数据进行删减，从而减少有效数据的个数.**

但是`set`保存数据的方法是使用`Hash`算法，所以数据的保存并不会如我们所 期望的那样。所以如果我们想要使数据能够保持我们期望的顺序，可以考虑使用`map` 代替`set`，虽然`map`相比于`set`更加的复杂，多了`key-value`，但是可以利用`value`的值保存顺序，形成一个伪顺序。比如在`value`中保存我们期望的下标。

`insert(iter)`都是在当前的这个`iter`前面插入数据，如果不添加`hint`， 就会在调用`insert`函数的容器利用`Hash`算法找到插入的地方。

# 2021.2.2 1332. 删除回文子序列

脑筋急转弯的一道题，关键在于理解回文子序列这个意思，定义为：通过对原字符串中的某些字符进行删除，不改变其他字符的顺序，剩下的那些字符 依旧是回文形式，就成为回文子序列。所以说，对于只有`a和b`两种字符组成的字符串而言，只有三种情况：

1. 当目前的字符串是空，那么需要删除的次数就是0次；对此可以利用`size()`进行判断
2. 当目前的字符串本身就是回文，那么需要删除的次数就是1次；对此可以`reverse()`进行判断
3. 当目前的字符串不属于上面两种情况，那么需要删除的次数必然是2次，一次全删除`a`，一次全删除`b`。

# 2021.2.3 480. 滑动窗口中位数

待完善

# 2021.2.4 643. 子数组最大平均数 I

对于此类的滑动窗口类型的题目，关键在于怎么确定窗口滑动的条件，一般的窗口滑动题目都有共性，比如：

1. 需要对窗口内的元素进行相应的操作；
2. 需要对窗口进行平移操作，牵扯到窗口的`pop_front()`操作和`push_back()`操作，什么时候加入什么时候删除
3. 窗口到头了的边界条件判断

# 2021.2.5 [1208. 尽可能使字符串相等](https://leetcode-cn.com/problems/get-equal-substrings-within-budget/)

1. **用`std::abs()`代替`abs()`可以减少用时**
2. 窗口滑动到最后窗口的大小变化是什么样子的

# 2021.2.6 [1423. 可获得的最大点数](https://leetcode-cn.com/problems/maximum-points-you-can-obtain-from-cards/)

关键在于使用逆向思维的方法，原本是可以在头部和尾部分开取元素以获得最大点数，但是反过来剩下的就是最小的点数的组合，所以如果计算什么样的窗口可以获得最小的点数，再用全部的`sum`减去最小的点数，剩下的就是最大的点数和了。同样要使用`std::min`来代替`min`。

# 2021.2.7 [665. 非递减数列](https://leetcode-cn.com/problems/non-decreasing-array/)

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

# 2021.2.7 [888. 公平的糖果棒交换](https://leetcode-cn.com/problems/fair-candy-swap/)

难度不大，很简单的双指针比较题目。常使用`vector的push_back()`操作，但是发现很耗时间，最后使用双指针目前达到一个比较令人满意的结果。尝试后续使用`binart_search()`或者`hashmap`的方法。

# 2021.2.8  [978. 最长湍流子数组](https://leetcode-cn.com/problems/longest-turbulent-subarray/)

**使用了动态规划算法。**

先复习一下动态规划算法(https://www.zhihu.com/question/39948290/answer/883302989)

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

# 2021.2.9 [992. K 个不同整数的子数组](https://leetcode-cn.com/problems/subarrays-with-k-different-integers/)

给定一个正整数数组 `A`，如果 `A` 的某个子数组中不同整数的个数**恰好**为 `K`，则称 `A` 的这个连续、不一定独立的子数组为好子数组。

对于这个题目，我的第一个想法就是滑动窗口法，因为这个题目要求对数组中的每个元素进行遍历，并且检查这个元素是否符合题目中给定的规则，所以用滑动窗口法可以很好的解决这个问题。

伪代码差不多就是下面这个样子的：

```c++
int left = 0, right = 0;
while(遍历A){
    if(left~right满足要求)++right;
    else{
        ++left直到满足要求;
        right = left;
    }
}
```

这样子相当于在左边不变的前提下依次寻找子数组，然后当不符合条件了就修改窗口左边界直至再次符合要求，然后重置窗口重新开始接下来的步骤；相当于最坏的情况，每个元素都要进行一次遍历，所以复杂度为O(n<sup>2</sup>)。

所以考虑使用一个更加有效的方法，看看能不能不需要回溯。

**首先讨论子问题一：求 A 中由 K 个不同整数组成的最长子数组的长度**，标准的使用滑动窗口的算法，代码如下：

```c++
int func1(vector<int>&A,int K){
    std::size_t left = 0, right = 0;
    //原本是使用map<int,int>记录当前整数出现的次数的，但是map占用的空间以及之后的erase()用时比较久，考虑使用vector代替
    //map<int,int>times{};
    vector<int>times(20000,0);
    int unique{};//记录出现的不同整数的个数
    std::size_t res{};//最后返回的值
    while (right<A.size()){
        if(times[A[right]]==0)unique++;//如果当前的这个元素没有出现过，unique++表示不同的整数个数+1
        times[A[right]]+=1;//然后记录这个整数出现的次数
        while(unique>K){//当已经出现了>K个不同的整数时
            times[A[left]]-=1;//删除最早进来的那个整数，这里将这个整数的次数-1，这个整数就是窗口的左边界
            if(times[A[left]]==0){//如果此时这个数没有出现了，那么unique--表示少了一个整数的出现
                unique--;
            }
            left++;//最后滑动窗口左边界直至满足条件
        }
        res = std::max(res,right-left+1);//每次滑动了窗口之后就比较一次当前的窗口长度
        right++;//最后滑动窗口右边界
    }
    return res;
}
```

**然后讨论子问题二：求A 中由最多 K 个不同整数组成的子数组的个数**，和func1()不一样，这里求的是个数，在func1()中，我们可以计算出最长的数组的长度。 现在思考一下窗口内最多K个不同整数组成的子数组的个数和窗口之间的关系，以{1,2,1,2,3}为例：

```c++
 {1}的子数组个数为1；
 {1,2}的子数组的个数为{1}，{1,2}，{2}，个数为3个，和{1}相比增加了{1，2}，{2}两个以当前2结尾的子数组
 {1,2,1}的子数组的个数为{1}，{1,2}，{1,2,1}，{2}，{2,1}，{1}，个数为6，相比于{1,2}增加了以1结尾的3个子数组
 ……
  所以可以总结，每一次形成了新的窗口之后，相比于滑动前的窗口，会增加size个数组，也就是right-left+1个
```

 所以可以总结，每一次形成了新的窗口之后，相比于滑动前的窗口，会增加size个数组，也就是right-left+1个

```c++
int func2(vector<int>&A,int K){
    std::size_t left = 0, right = 0;
    //map<int,int>times{};
    vector<int>times(20000,0);
    int unique{};
    std::size_t res{};
    while (right<A.size()){
        if(times[A[right]]==0)unique++;
        times[A[right]]+=1;
        while(unique>K){
            times[A[left]]-=1;
            if(times[A[left]]==0){
                unique--;
            }
            left++;
        }
        res += right-left+1;
        right++;
    }
    return res;
}
```

最后回到问题本身，求**恰好**K个不同的整数组成的子数组的个数，可以理解为最多K个不同的整数组成的子数组的个数-最多(K-1)个不同的整数组成的子数组的个数。

```c++
return func2(A,K)-func2(A,K-1);
```

# 2021.2.9 [209. 长度最小的子数组](https://leetcode-cn.com/problems/minimum-size-subarray-sum/)

标准的使用滑动窗口法，窗口移动的规则为：

```c++
//当当前窗口内的和sum<target的时候，让窗口向右扩展，当sum>=target的时候，收缩窗口直到窗口的和sum重新小于target，
//在收缩窗口的过程中不断记录sum>=target时的最短的长度。
while (right<nums.size()){
            sum+=nums[right];
            while(sum>=target){
                if(flag){
                    length = right-left+1;
                    flag = false;
                }
                else length = std::min(length,right-left+1);
                sum-=nums[left];
                ++left;
            }
            ++right;
        }
```

2021.2.9 [3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)

标准的使用滑动窗口法，窗口移动的规则为：

```c++
//当当前窗口内没有重复字符的时候，窗口向右扩展，当有重复字符的时候，窗口收缩直到没有重复字符为止
//每次窗口变化之后都要计算length
int alphabet[128] = {0};//初始化一个ascii码数组存放字符出现次数
while (right<s.size()){
            alphabet[(int)s[right]]++;
            while (alphabet[(int)s[right]]>1){
                alphabet[s[left]]--;
                left++;
            }
            right++;
            length = std::max(length,right-left);
        }
        return length;
```

# 2021.2.10 [567. 字符串的排列](https://leetcode-cn.com/problems/permutation-in-string/)

一般进行这样的匹配的题目，通常的做法是初始化一个用来存储一共会出现的字符的次数的数组或者map，`map可以设计成{出现的字符:出现的次数}`这样的结构，但是map的操作比较费内存和时间，用数组替代可能更好一点。**对于这类匹配的题目，关键要搞清楚什么时候应该对窗口大小进行修改。**

题目中的要求是判断 **s2** 是否包含 **s1** 的排列，所以首先初始化一个s1可能出现的所有元素的数组，然后通过遍历s2不断修改s1中的值，判断是否满足要求。

```c++
//所以首先初始化s1数组，由于s1都是小写字母组成的，所以可以用length=26的数组存储，并且对于s1中出现了的字母初始化为1
int alphabet[26] = (26,0);
std::size_t size1 = s1.size(), size2 = s2.size();
for(std::size_t i = 0;i<size1;i++)
    alphabet[s1[i]-'a']--;
//然后遍历s2中的字符，对每一个字符都计数+1，然后对于这个字符如果当前的计数>0，就说明这个字符不在s1中或者已经超出了s1中出现的次数
//所以如果发生了这样的情况，就计数--；最后判断是否right-left==size2
std::size_t left = 0, right = 0;
while(right < size2){
    alphabet[s2[right]-'a']++;
    while(alphabet[s2[right]-'a']>0){
        alphabet[s2[left]-'a']--;
        left++;
    }
    right++;
    if(right-left==size1) return true;
}
else return false;
```

# [重点]2021.2.11 [703. 数据流中的第 K 大元素](https://leetcode-cn.com/problems/kth-largest-element-in-a-stream/)

想法是在初始化`KthLargest`的时候就直接先找出前K大的所有元素，放在一个`set`或者一个`vector`里面，所以这个问题就转换成了设计一个合理的容器出来，**后来发现有一个叫做`priority_queue`的容器可以完美的解决这个问题(https://en.cppreference.com/w/cpp/container/priority_queue)，关于`priority_queue`的实现可以看数据结构的`heap`相关。**

```c++
int k = {};
priority_queue<int,vector<int>,std::greater<int>> pqueue;
KthLargest(int k, vector<int>& nums) {
	this->k = k;
	for(int i = 0; i <nums.size();++i)add(nums[i]);
}

int add(int val) {
	pqueue.push(val);
	if(pqueue.size()> this->k)
		pqueue.pop();
	return pqueue.top();
}
//执行用时：56 ms, 在所有 C++ 提交中击败了58.28%的用户
//内存消耗：19.4 MB, 在所有 C++ 提交中击败了69.98%的用户
```

# 2021.2.12 [119. 杨辉三角 II](https://leetcode-cn.com/problems/pascals-triangle-ii/)

由于杨辉三角只和当前这一行以及上一行油有关，可以设计一个二维的`vector`存储元素

```c++
//注意几个细节问题：
//1.由于数组的下标为0开始，但是杨辉三角下标从1开始，所以初始化的时候要到rowIndex+1才停止
//2.第一行和第二行都不需要进行修改，直接跳过，同时可以避免第二行计算的时候发生越界
vector<int> getRow(int rowIndex) {
    vector<vector<int>> nums = {};
    for(int row = 0;row<rowIndex+1;++row)
        nums.push_back(vector<int>(row+1,1));
    for(int row = 2;row<rowIndex+1;++row){
        for(int column = 1;column<row;++column){
            nums[row][column] = nums[row-1][column-1] + nums[row-1][column];
        }
    }
    return nums[rowIndex];
```

还有第二个思路，就是设置一个简单的一维`vector`存储数据

```c++
//同样初始化的时候设置成rowIndex+1个1
//由于在二维数组中，每次我们都是利用nums[row][column] = nums[row-1][column-1] + nums[row-1][column]修改row行数据
//在一维数组中，由于修改nums[column]的数据需要用到nums[column-1]的值，所以如果从左往右修改会因为当前修改的column-1的值影响
//后面的column的值，所以从右往左修改。
vector<int> getRow2(int rowIndex){
    vector<int> nums(rowIndex+1,1);
    for(int times = 1;times<rowIndex+1;++times){
        for(int column = times-1;column>0;--column){
            nums[column] += nums[column-1];
        }
    }
    return nums;
}
```

# 2021.2.13 [136. 只出现一次的数字](https://leetcode-cn.com/problems/single-number/)

很神奇，利用了**异或**的性质。

```c++
A^A=0;0^A=A;
//如果对一个数组遍历异或，那么由于数组中的出现了两次的数经过异或操作之后为0，所以最后剩下的就是只出现了一次的那个数
int singleNumber2(vector<int>nums)  {
    int res{nums[0]};
    int size = nums.size();
    for (int i = 1; i < size; ++i) {
        res = res ^ nums[i];
    }
    return res;
}
```

# 2021.2.13 [448. 找到所有数组中消失的数字](https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/)

首先注意题目中的两个关键点：

1. 数组长度为n
2. 数组中的元素值都在1~n内

考虑到可能会出现大量重复的元素，所以**首先使用`set`降重**，然后遍历set寻找哪个1~n的元素不在`set`中

```c++
 vector<int> findDisappearedNumbers(vector<int>& nums) {
     set<int> numbers{nums.begin(),nums.end()};
     vector<int>res{};
     int size = nums.size();
     for (int i = 1; i < size+1; ++i) {
         if(numbers.find(i)==numbers.end())res.push_back(i);
     }
     return res;
 }
//执行用时：160 ms, 在所有 C++ 提交中击败了14.53%的用户
//内存消耗：44.1 MB, 在所有 C++ 提交中击败了7.00%的用户
//主要是在find中需要遍历numbers，所以相当于这个时间复杂度为size*numbers/2
//所以优化的地方在于，能不能不需要用set的find实现寻找元素是否出现这个功能，关键在于能不能摆脱set容器
```

现在考虑如何不借助`set`实现记录出现的次数的功能，以`{4,3,2,7,8,2,3,1}`为例，长度为8，所以会出现的数字为1~8，映射成下标0-7，所以假设一个数字出现了一次，那么我们就令这个数字-1为下标，这个下标对应的数字乘以-1，那么最后没有出现的数字-1作为下标对应的数字自然就是正数，这样子就可以利用正负数区分开来。

```c++
for(int i = 0;i<nums.size();++i){
    nums[abs(nums[i])-1] *= -1;
}
```

但是由于数组中有些数字会出现2次，那么连续乘以两次-1之后又成为了正数，就不符合我们的期望了，所以对于一个已经是负数的数，就不应该再乘以-1。

```c++
for(int i = 0;i<nums.size();++i){
	if(nums[abs(nums[i])-1] < 0) continue;
    nums[abs(nums[i])-1] *= -1;
}
```

或者从另一个角度来看，可以无论怎么样都对这个数的绝对值乘以-1，这样就不会发生负数变为正数的情况。

```c++
for(int i=0;i<nunms.size();++i){
	nums[abs(nums[i])-1] = -1 * abs(nums[abs(nums[i])-1]);
}
```

# 2021.2.14 [765. 情侣牵手](https://leetcode-cn.com/problems/couples-holding-hands/)

1. 首先，题目给定了N对couples，那么一定是可以完成配对的；
2. couples的初始化位置不对，需要还原成couples的正确位置

```c++
/*
总是假设下标为偶数的人所在位置一定是正确的，那么如果couples位置正确，就有两种可能
1. [1,2],[3,4]……奇数的比偶数的+1
2. [2,1],[4,3]……偶数的比奇数的-1
如果不满足这两种情况，就需要去寻找2N中寻找正确的数值，然后swap
*/
int res{};
for (auto it = row.begin();it!=row.end();it=it+2) {
    int& current = *it;
    int& right = *(it+1);
    //如果current是偶数，那么right必然比current大一,[0,1],[2,3]
    //如果current是奇数，那么right必然比current小一,[1,0],[3,2]
    if( (current%2==1 && right==current-1) || (current%2==0)&&right==current+1) continue;
    //如果是奇数，就要去row里面找到current-1，然后swap，如果是偶数，就去row里面找current+1，然后swap
    auto findTemp = std::find(row.begin(),row.end(),current%2==1?current-1:current+1);
    std::swap(right,*findTemp);
    ++res;
}
return res;
```

# 2021.2.14 [5676. 生成交替二进制字符串的最少操作数](https://leetcode-cn.com/problems/minimum-changes-to-make-alternating-binary-string/)

这个题目对应的交替二进制字符串只有两种情况，一种是`01010101……`，一种是`10101010……`

前者下标偶数对应0，下标奇数对应1；后者下标偶数对应1，下标奇数对应1；'0'的ascii码值为48，'1'的ascii码值为49所以只要遍历整个字符串看看是前者的情况多还是后者的情况多就知道答案了。

```c++
int minOperations(string s) {
	int size = s.size();
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < size;++i) {
        //符合前者，++cnt1
		if( (i%2==0&&s[i]!='0') || (i%2==1&&s[i]!='1') )++cnt1;
        //符合后者，++cnt2
		else if( (i%2==0&&s[i]!='1') || (i%2==1&&s[i]!='0') )++cnt2;
	}
    //最后整个字符串里面有cnt1个前者，cnt2个后者，那么需要把少的那个改成另一种，所以一共需要改std::min(cnt1,cnt2)次
	return std::min(cnt1,cnt2);
}
```

# 2021.2.15 [485. 最大连续1的个数](https://leetcode-cn.com/problems/max-consecutive-ones/)

1. 通过遍历数组，如果是1，就count++，如果不是1，就比较一次当前的count和之前的maxcount谁更大，最后遍历完了之后再比较一次

```c++
int findMaxConsecutiveOnes(vector<int>& nums) {
    int count{};
    int maxCount{};
    int size = nums.size();
    for (int i = 0; i < size; ++i) {
        if(nums[i]==1)++count;
        else{
            maxCount = std::max(maxCount,count);
            count = 0;
        }
    }
    maxCount = std::max(maxCount,count);
    return maxCount;
}
```

2. 滑动窗口法，如果right值为1，那么窗口扩大，如果不是1，那么就窗口缩小令left=right+1，并且伴随--count。

```c++
int findMaxConsecutiveOnes2(vector<int>& nums) {
    int res{};
    int left = 0, right = 0;
    int size = nums.size();
    while (right<size){
        if(nums[right++]!=1){
            left = right;
        }
        res = max(right-left,res);
        ++right;
    }
    return res;
}
```

**发现把`std::max`改成`max`后用时和内存都有所下降，推测原因如下：因为`std::max`定义为`template`编程，适用于所有的数据类型，所以`std::max`相比`max`具有普适性，但是同样由于这个原因，用时可能会更久，所以如果是同样的数据类型，用`max`可能更好一点**

# 2021.2.16 [561. 数组拆分 I](https://leetcode-cn.com/problems/array-partition-i/)

观测题目中给的数据，如果分拆后的数组的和有最大值的话，必须要对数组进行排序，然后令数组每两个组成一个新的小数组

```c++
int arrayPairSum(vector<int>& nums) {
    std::sort(nums.begin(),nums.end());
    int size = nums.size();
    int res{};
    for (int i = 0; i < size; i+=2) {
        res += nums[i];
    }
    return res;
}
```

# 2021.2.17 [566. 重塑矩阵](https://leetcode-cn.com/problems/reshape-the-matrix/)

实现matlab的`reshape()`函数，两个知识点：

1. 将原数组降维成一维数组，从一维数组重建二维数组，使用一个index作为变量遍历数组，关键在于怎么从index得出数组的行列，每一行有column个元素，所以index%column表示当前行的第几个元素，而index/column表示第几行
2. 二维vector的初始化以及元素访问，二维的vector相当于其中每个变量都是一个vector，所以定义一个这样的变量为`vector<vector<int>>nums{{1,2},{3,4}}`，访问为两个`[]`访问，比如`nums[0][1]`可以访问第一行vector里面的第二个元素

```c++
vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    std::size_t row = nums.size(), column = nums[0].size();
    vector<vector<int>>res(r,vector<int>(c,0));\
    std::size_t index{};
    if(row*column!=r*c)return nums;
    else{
        while (index<row*column) {
            res[index / c][index % c] = nums[index / column][index % column];
            ++index;
        }
        return res;
    }
}
```

# 2021.2.17 [4. 寻找两个正序数组的中位数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/)

1. 最简单的方法：合并两个`vector`，然后从中转换为topk的问题
2. 二分查找



# 2021.2.18 [1759. 统计同构子字符串的数目](https://leetcode-cn.com/problems/count-number-of-homogenous-substrings/)

大数乘法溢出的问题，当`count=100000`的时候，发现`count*(count+1)`总是会溢出，当两个同种类型的数据进行乘法计算的话，得出来的结果会首先保存在同类型的空间中，哪怕溢出了也会先保存在同类型的空间中，然后再copy到结果中。所以为了避免溢出的情况，优先把`count*(count+1)`计算一下，看一下大小以及用什么类型存储，然后将结果、count都设置为指定类型的数据。

# [重点]2021.2.18 [995. K 连续位的最小翻转次数](https://leetcode-cn.com/problems/minimum-number-of-k-consecutive-bit-flips/)

1. [差分数组](https://blog.csdn.net/JingleLiA/article/details/108730954)的应用，对于这样的有可能是大规模数据的数组，要对数组中的区间进行频繁修改，如果一直修改的复杂度是`O(n*k)`，但是如果是改用差分数组的复杂度为常数`O(k)`。而差分数组的修改在于`diff[i]++,diff[i+k]--`
2. 用`int`实现二进制的加减法，使用异或`^`符号，比如`int 1+1 = 0, 1+0=1,0+0=0`，恰好符合异或算法

遍历整个`vector`，只有当`当前的元素为0，当前元素在之前累计修改次数为偶数次或当前元素为1，当前元素在之前累计修改次数为奇数次`才需要修改。

并且注意边界条件，当`当前元素需要被翻转，但是当前元素下标+K>size`的时候，就说明接下来不能一次翻转K个元素，这个时候就应该退出。

```c++
int minKBitFlips(vector<int>& A, int K) {
    int count = 0, sum = 0;
    //新建一个vector作为差分数组存储当前元素和前一个元素翻转次数的差
    vector<int>diff(A.size()+1,0);
    for (int i = 0; i < A.size(); ++i) {
        //用sum存储当前这个元素截止之前的修改次数，因为差分数组的特性，必须累加才知道当前元素的实际的值
        sum ^= diff[i];
        //如果当前元素需要修改
        if(sum==A[i]){
            //如果后续的元素不满足一次翻转k个元素，退出
            if(i+K>A.size())return -1;
            //因为当前元素需要修改，所以用diff记录下来，用异或实现二进制的加法，因为修改了两次和修改了零次是一样的
            diff[i] ^= 1;
            //因为当前元素需要修改，而sum没有记录这个时候的改变，所以sum也需要二进制的加法。
            sum ^= 1;
            diff[i+K] ^= 1;
            //记录一共修改的次数
            count++;
        }
    }
    return count;
}
```

注意到我们使用`diff`这个差分数组和`sum`一起构成了当前元素到目前被翻转的次数，可不可以直接在`A`上记录当前元素被翻转的次数？由于一个元素只有翻转0次和翻转1次两种情况，所以如果一个元素翻转了，那么我们就对这个元素加上一个特定的值`val`表示这个元素发生了翻转，再次发生翻转就减去这个特定的值`val`。

由于翻转次数`flip`只能为0或1，当元素为0，`flip`为0时，需要翻转；当元素为1，`flip`为1时，需要翻转，所以总结就是：当`flip==A[i]`时，需要翻转。

同时考虑到在`diff`差分数组中，如果某个元素发生了翻转，那么不仅`diff[i]^=1`，还需要`diff[i+K]^=1`，所以当我们遍历到`i+K`的时候，我们要检查一下`i`是否发生了翻转，如果发生了翻转，那么`flip^=1`

```c++
int minKBitFlips2(vector<int>& A, int K) {
    int count = 0, sum = 0, flip = 0, val = 2;
    for (int i = 0; i < A.size(); ++i) {
        if (i >= K && A[i - K] >= val) {
            flip ^= 1;
            A[i - K] -= val;
        }
        if (flip == A[i]) {
            if (i + K > A.size())return -1;
            count++;
            A[i] += val;
            flip ^= 1;
        }
    }
    return count;
}
```

# 2021.2.18 [984. 不含 AAA 或 BBB 的字符串](https://leetcode-cn.com/problems/string-without-aaa-or-bbb/)

从个数多的开始填入，满足下列要求：

1. 当a的个数大于b的个数并且此时没有连续填入两个a，或者此时连续填入两个b，填入a
2. 当b的个数大于a的个数并且此时没有连续填入两个b，或者此时连续填入两个a，填入b

```c++
string strWithout3a3b(int a, int b) {
    string item{};
    int countA = 0, countB = 0;
    while (a!=0 || b!=0){
        //当a的个数大于b的个数且连续填入小于两个a，或者此时已经连续填入两个b了
        if((a>b && countA<2) || (countB==2)){
            item.push_back('a');
            a--;
            countA++;
            countB = 0;
        }else{
            item.push_back('b');
            b--;
            countB++;
            countA = 0;
        }
    }
    return item;
```

# 2021.2.19 [1004. 最大连续1的个数 III](https://leetcode-cn.com/problems/max-consecutive-ones-iii/)

典型的滑动窗口法，首先确定我们需要寻找的条件

1. 要求最多可以变动`K`次，所以用`count0`来记录截止目前变动的次数；
2. 每当遇到了0时，检查一下当前`count0`是否大于`K`，如果小于`K`，那么可以当做无事发生，窗口继续向右滑动；如果大于`K`，就说明此时不能再变化了，所以要收缩窗口直到窗口中0的个数重新小于`K`，并且由于最后窗口滑动到的那个0并没有被`count0`记录，所以最后还要补上。

```c++
int longestOnes(vector<int>& A, int K) {
    int left = 0, right = 0, ret = 0, count0 = 0;
    while(right<A.size()){
        //如果当前元素为0
        if(A[right]==0){
            //如果窗口内0的次数小于K，++count0记录下来，正常滑动窗口
            if(count0<K)++count0;
            //如果此时窗口内0的次数>=K，那么就要收缩窗口直到窗口内0的个数重新小于K
            else{
                while(count0>=K){
                    if(A[left]==0)--count0;
                    ++left;
                }
                //并且由于最后的这个0并没有被记录下来，所以最后要把这个0出现的次数加上去
                ++count0;
            }
        }
        ++right;
        ret = std::max(ret,right-left);
    }
    return ret;
}
```
还可以进一步化简

```c++
int longestOnes(vector<int>& A, int K) {
    int left = 0, right = 0, ret = 0, count0 = 0;
    while(right<A.size()){
        //只要当前元素为0，就记录下来窗口内0的个数
        if(A[right]==0)++count0;
        //直到窗口内0的个数重新不大于K，也就是说窗口内最多K个0
        while(count0>K){
            //收缩窗口
            if(A[left]==0)--count0;
            ++left;
        }
        ++right;
        //关于到底最后窗口的长度到底是right-left+1还是right-left，取决于最后计算前right停下来的地方
        //如果刚把当前right的元素完成遍历，此时窗口长度为right-left+1
        //如果此时right++，表示扩大窗口了，那么就是right-left
        ret = std::max(ret,right-left);
    }
    return ret;
}
```

模板如下：

```python
def findSubArray(nums):
    N = len(nums) # 数组/字符串长度
    left, right = 0, 0 # 双指针，表示当前遍历的区间[left, right]，闭区间
    sums = 0 # 用于统计 子数组/子区间 是否有效，根据题目可能会改成求和/计数
    res = 0 # 保存最大的满足题目要求的 子数组/子串 长度
    while right < N: # 当右边的指针没有搜索到 数组/字符串 的结尾
        sums += nums[right] # 增加当前右边指针的数字/字符的求和/计数
        while 区间[left, right]不符合题意：# 此时需要一直移动左指针，直至找到一个符合题意的区间
            sums -= nums[left] # 移动左指针前需要从counter中减少left位置字符的求和/计数
            left += 1 # 真正的移动左指针，注意不能跟上面一行代码写反
        # 到 while 结束时，我们找到了一个符合题意要求的 子数组/子串
        res = max(res, right - left + 1) # 需要更新结果
        right += 1 # 移动右指针，去探索新的区间
    return res
```

# 2021.2.19 [66.加一](https://leetcode-cn.com/problems/plus-one/)

很有意思的一道题目，正常想法如下：

```c++
vector<int> plusOne(vector<int>& digits) {
        int cflag = 0;
        //首先处理最后一位数
        if(++digits[digits.size()-1]==10){
            digits[digits.size()-1] = 0;
            cflag = 1;
        }
        //开始处理其他的数
        int index = digits.size()-2;
        while(cflag!=0 && index!=-1){
            --cflag;
            if(++digits[index]==10){
                digits[index] = 0;
                ++cflag;
            }
            --index;
        }
        if(cflag)digits.insert(digits.begin(),1);
        return digits;
}

```

但是仔细分析一下，如果当前的这个值++后没有变成10，那么就说明没有发生进位，可以直接返回digitals了，但是如果发生了进位了，那么就继续循环遍历，如果遍历完了还没退出，就说明是999这样的情况，那么就应该最后insert

```c++
    vector<int> plusOne(vector<int>& digits) {
        for(int index = digits.size()-1;index>=0;--index){
            ++digits[index];
            digits[index] %= 10;
            if(digits[index]!=0) return digits;
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
```

# 2021.2.19 [28. 实现 strStr()](https://leetcode-cn.com/problems/implement-strstr/)

很有意思的一个题目，有很多边界条件

```c++
class Solution {
public:
    int strStr(string haystack, string needle) {
        int ph = 0, pn = 0,ret = haystack.size();
        //h="",n="aba"
        if(haystack.size()==0 && needle.size()!=0)return -1;
        //h="aba",n=""
        else if(needle.size()==0 && haystack.size()!=0)return 0;
        //h="",n=""
        else if(needle.size()==0 && haystack.size()==0)return 0;
        for(;ph<haystack.size();++ph){
            if(haystack[ph]==needle[pn]){
                ret = min(ret,ph);
                if(pn==needle.size()-1)return ret;
                ++pn;
            }else{
                ret = haystack.size();
                ph = ph-pn;//因为接下来ph还需要++，所以这里就不+1了
                pn = 0;
                
            }
        }
        return -1;
    }
};
```

# 2021.2.20 [697. 数组的度](https://leetcode-cn.com/problems/degree-of-an-array/)

```c++
int findShortestSubArray(vector<int>& nums) {
    //首先我们需要存储的数据有，出现的元素，出现的次数，第一次出现的下标，最后一次出现的下标
    //所以可以用一个map来存储，key为元素值
    //value设置为一个vector，vector的size为3，0是次数，1是第一次下标，2是最后一次下标
    map<int,vector<int>> counts{};
    int ret = nums.size(),max{};
    //然后第一次遍历，如果之前这个数据不在map里面，新添一个到map中，如果已经有了，map修改最后一次出现的下标
    for(int i = 0; i < nums.size();++i){
        if(counts.find(nums[i])==counts.end())counts[nums[i]] = {1,i,i};
        else{
            counts[nums[i]][0]++;
            counts[nums[i]][2] = i;
        }
    }
    //然后再遍历一次，如果当前元素出现的次数之前已经有前例了，那么就计算距离更新ret
    //并且每次都要保存最短的距离
    for(const auto& item:counts){
        if(item.second[0]==max){
            max = item.second[0];
            ret = std::min(item.second[2] - item.second[1]+1,ret);
        }else if(item.second[0]>max){
            //如果出现的次数更大了，那么就重新计算距离
            //由于需要保存最短的距离，所以ret必须清零避免之前次数较少的影响，这里将ret设置为nums的size初始化
            ret = nums.size();
            max = item.second[0];
            ret = std::min(item.second[2] - item.second[1]+1,ret);
        }
    }
    return ret;
}
```

可以优化的地方：

1. `map`改用`unordered_map`，因为`unordered_map`使用`hash`表而map使用的是红黑树，`unordered_map`的查找为O(1)
2. `map`中的`value`从`vector`改成数组降低内存消耗

```c++
int findShortestSubArray(vector<int>& nums) {
    unordered_map<int,int*> counts{};
    int ret = nums.size(),degree{};
    for(int i = 0; i < nums.size();++i) {
        if ( counts.find(nums[i]) == counts.end()) {
            int* temp = new int[3];
            temp[0] = 1;
            temp[1] = i;
            temp[2] = i;
            counts[nums[i]] = temp;
        }else {
            counts[nums[i]][0]++;
            counts[nums[i]][2] = i;
        }
        degree = std::max(degree,counts[nums[i]][0]);
    }
    for(const auto& item:counts) {
        if (item.second[0] == degree) {
            ret = std::min(item.second[2] - item.second[1] + 1, ret);
        }
        else delete item.second;
    }
    return ret;
}
```

# 2021.2.21 [1438. 绝对差不超过限制的最长连续子数组](https://leetcode-cn.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/)

分析可以使用滑动窗口的方法实现，但是关键在于怎么在窗口内部求出哪个是最小的元素哪个是最大的元素，因为每次收缩窗口之后都要重新求出最大值和最小值，所以为了方便处理可以认为窗口内部是`sorted`的，并且由于有重复的元素，所以使用`multiset`实现。

```c++
int longestSubarray(vector<int>& nums, int limit) {
        int ret = 0, left = 0, right = left;
        multiset<int> windows{};
        while(right!=nums.size()){
            //每次扩张之后加入新的元素到窗口中
            windows.insert(nums[right]);
            //由于窗口使排序好了的，所以begin就是最小的，rbegin就是最大的
            while(*(windows.rbegin())-*windows.begin() > limit){
                //如果这个时候窗口不符合要求，就收缩窗口直到符合要求
                //收缩的时候不断的抹去窗口丢掉的那个元素
                windows.erase(windows.find(nums[left]));
                ++left;
            }
            ret = std::max(ret,right-left+1);
            ++right;
        }
        return ret;
    }
```

**如果要访问最后一个元素，由于`end`访问的是尾后元素，所以不太合适，换成`rbegin`可以很好的解决这个问题**

可以优化的点：关键在于怎么每次更新之后获取`windows`内部的最大值和最小值，用`multiset`的`insert`和`find`还有`erase`几个操作的确有点费时间内存

# [重点,动态规划]2021.2.21 [5687. 执行乘法运算的最大分数](https://leetcode-cn.com/problems/maximum-score-from-performing-multiplication-operations/)

首先先暴力求解，找到状态转移方程。假设从`nums`左边取出`i`个元素，右边取出`j`个元素，那么如果我想知道在这种情况下怎样才能得到最优解，可以转换为两个子方程

1. 从`nums`左边取`i-1`个元素，右边取出`j`个元素，然后再从左边取出1个元素,这时左边这个元素的坐标为`mul[i-1]`；
2. 从`nums`左边取`i`个元素，右边取出`j-1`个元素，然后再从右边取出1个元素，这时右边这个元素的坐标为`mul[nums.size()-j]`；

然后找到这两个中最大的那一个就是当前的最优解。

注意特殊情况：

1. 如果求左边取出0个，右边取出x(x>1)个，那么就是进入左边取出-1个的方程，这里通过取出个数是否小于0判断，如果小于0，就返回INIT_MIN；
2. 左边取出0个，右边取出1个，那么直接放回边界条件`nums[nums.size()-1]*mul[0]`
3. 左边取出1个，右边取出0个，那么直接放回边界条件`nums[0]*mul[0]`
4. 如果返回的值是INIT_MIN，也就是说子状态越界了，那么不管他，因为最后进行`std::max`比较的时候会忽略的。

```c++
int dp(int x,int y,vector<int>& aa,vector<int>& bb,vector<vector<int>>& table){
    if(x<0 || y<0)return INT32_MIN;
    else if(x==0 && y==1)return aa[aa.size()-1]*bb[0];
    else if(x==1 && y==0)return aa[0]*bb[0];
    else if(table[x][y] != -1)return table[x][y];
    else{
        int item1 = dp(x-1,y,aa,bb,table);
        if(item1==INT32_MIN);
        else item1 =  item1 + aa[x-1]*bb[x+y-1];
        int item2 = dp(x,y-1,aa,bb,table);
        if(item2==INT32_MIN);
        else item2 = item2 + aa[aa.size()-y]*bb[x+y-1];
        table[x][y] = std::max(item1,item2);
        return table[x][y];
    }
}

int main(){
    vector<int> a{-5,-3,-3,-2,7,1};
    vector<int> b{-10,-5,3,4,6};
    int max = INT32_MIN;
    //把vector改成数组后内存消耗会得到很大的提升！！！
    vector<vector<int>>dptable(1001,vector<int>(1001,-1));
    for ( std::size_t i = 1,j = b.size()-i; i < b.size(); ++i,--j ) {
        max = std::max(max,dp(i,j,a,b,dptable));
    }
    std::cout<<max<<std::endl;
}
```

在main函数里面相当于计算了当左边取出1个，右边取出m-1个元素时的最优解；然后左边2个……这样的遍历过程，是从顶向下的计算方法，所以需要用到递归，因为需要保存顶层的数据，但是反过来，为了求得顶层，我们必须先递归到底层先计算出底层的数据，所以可以优化成先计算底层的数据，然后由底向上计算。

比如：在计算左边取出1个右边取出4个的最优解，我们要先计算左边取出1个右边取出3个和左边取出0个右边取出4个的子方程，因此我们可以先计算最底层左边取出0个右边取出1个，左边取出1个右边取出0个，然后依次向上。

```c++
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int dp[1005][1005];
        int n=nums.size(),m=multipliers.size(),ans=-2e9;
        for(int i=0;i<=m;i++)for(int j=0;j<=m;j++)dp[i][j]=-2e9;
        
        dp[0][0]=0;
        for(int i=0;i<=m;i++){
            for(int j=0;i+j<=m;j++){
                if(i>0)dp[i][j]=max(dp[i][j],dp[i-1][j]+nums[i-1]*multipliers[i+j-1]);
                if(j>0)dp[i][j]=max(dp[i][j],dp[i][j-1]+nums[n-j]*multipliers[i+j-1]);
            }
            ans=max(ans,dp[i][m-i]);
        }
        return ans;
    }
};
```

# 2021.2.22 [149. 直线上最多的点数](https://leetcode-cn.com/problems/max-points-on-a-line/)

每个点依次遍历，求这个点和其他的点的斜率，并且将斜率存到一个map里面，map中value最大的就是出现次数最多的线。

几个关键点：

1. 有重复的点要处理；
2. LeetCode中有一个测试案例需要用`long double`才行

```c++
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() < 3) {
            return points.size();
        }
        int retFinal = 0,i,j;
        for(j = 0;j<points.size();++j){
            vector<int> start = points[j];
            unordered_map<long double,int> k{};
            int repeatedNum = 0, ret = 0;
            for ( i = j+1; i < points.size(); ++i ) {
                if(points[i][0]==start[0] && points[i][1]==start[1]) {
                    repeatedNum++;
                }
                else if(points[i][0]==start[0]) {
                    if(k.find(INT32_MIN)==k.end())k[INT32_MIN]+=2;
                    else k[INT32_MIN]++;
                    ret = std::max(ret,k[INT32_MIN]);
                }
                else{
                    int dy = (points[i][1]-start[1]);
                    int dx = (points[i][0]-start[0]);
                    long double item = static_cast<long double> (dy)/dx;
                    if(k.find(item)==k.end())k[item]+=2;
                    else k[item]++;
                    ret = std::max(ret,k[item]);
                }
            }
            //如果没有重复的，ret就是真实的值
            if(repeatedNum==0)retFinal = std::max(retFinal,ret);
            //如果有个别重复的，那么返回ret+repeatedNum
            else if(repeatedNum!=(i-j-1)) retFinal = std::max(ret+repeatedNum,retFinal);
            //如果全部都是重复的，那么返回repeatNum+1
            else retFinal = std::max(retFinal,repeatedNum+1);
        }
        return  retFinal;
    }
};
```

# 2021.2.23 [1052. 爱生气的书店老板](https://leetcode-cn.com/problems/grumpy-bookstore-owner/)

通过建立一个长度为`X`的窗口滑动，那么一共满意的`customers`就是窗口内所有的`customers`+窗口外所有的满意的。

所以最初的想法是通过暴力计算的方法，两个`for`循环，第一个`for`循环记录窗口开始的位置，第二个`for`循环遍历每个顾客是否满意。

```c++
int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int ret = INT32_MIN;
        for(int start = 0; start <= customers.size()-X;++start){
            int end = start + X - 1, temp = 0;
            for(int i = 0;i<customers.size();++i){
                if(i>=start && i<=end)temp+=customers[i];
                else{
                    if(grumpy[i]==0)temp+=customers[i];
                }
            }
            ret = max(ret,temp);
        }
        return ret;
    }
```

但是会发现这样超时了，因为每次计算窗口外面的满意的人的时候都有大量的重复计算，可以进行简化。

观察第二个`for`循环内，我们每次都要从头到尾遍历所有本来就满意的顾客，那我们可以最初初始化的时候就将提前遍历一次，将所有满意的顾客都存下来，**然后在窗口内只要计算那些原本不满意的就行了。这样题目就变成计算窗口内不满意顾客最多的人数。**

这样就可以通过滑动窗口法，但是这里的滑动窗口的长度是固定的，那么什么时候窗口应该滑动呢？也就是当窗口的长度等于X的时候，我们就该移动窗口了。

```c++
int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
    int ret = INT32_MIN,size = grumpy.size(),happy{};
    int start = 0, end = 0;
    //遍历获取本来就满意的顾客
    for(int i = 0; i<size; ++i)happy+=(1-grumpy[i])*customers[i];
    //开始滑动窗口
    while(end<size){
        //一但窗口长度等于X了，就说明此时我们需要平移窗口了，此时收缩最左边的start，减去start对应的happy的值
        //然后扩张end，加上end对应的happy的值，这样一收缩一扩展就完成了平移。
        //注意这里的比较是end-start==X，因为我是先收缩再扩张，里面已经有X个元素，收缩后X-1个，扩张回来
        if(end-start==X){
            happy-=grumpy[start]*customers[start];
            ++start;
        }
       	//当窗口还不够长的时候，向右滑动扩张，因为我们只需要获取grumpy[end]=1
        //也就是不开心的顾客，老板让他开心了所以要加到总和里面去
        happy+=grumpy[end]*customers[end];
        ++end;
        ret = std::max(ret,happy);
    }
    return ret;
}
```

# 2021.2.23 [1763. 最长的美好子字符串](https://leetcode-cn.com/problems/longest-nice-substring/)

最简单的做法就是暴力遍历，每次遇到一个字符，就将这个字符出现的次数存到对应的数组里面去，如果是大写就存入到`upper`，小写就存入到`lower`。然后再遍历`lower`和`upper`，如果两个数组对应的元素都为1，那就表示这个到现在为止字符串中既有大写的也有小写的，满足要求，而一但出现两个数组不想等了，那就说明不满足要求了。对于这样的相等与不相等的，可以使用异或进行判断。

```c++
string longestNiceSubstring(string s) {
    int size = s.length(),start=0,length=0;
    for(int i = 0; i < size; ++i){
        //用vector存储，关键在于每次遍历完了之后都要清零，用数组清零需要遍历，不太方便
        vector<int> upper(26,0),lower(26,0);
        for(int j = i; j < size; ++j){
            //遍历向lower和upper添加是否出现
            if(s[j]<='z' && s[j]>='a')lower[s[j]-'a']=1;
            else upper[s[j]-'A']=1;
            
            //遍历lower和upper看是否符合要求
            int ok=1;
            for(int x=0;x<26;++x){
                //只要有一个字母不符合要求，就可以结束循环了
                if(upper[x] ^ lower[x]){
                    ok=0;
                    break;
                }
            }
            if(ok){
                if(j-i+1>length){
                    start=i;
                    length=j-i+1;
                }
            }
        }
    }
    return s.substr(start,length);
}
```

# 2021.2.24 [4. 寻找两个正序数组的中位数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/)

朴素的做法就是用两个指针寻找中位数，但是要注意遍历的时候的停止条件，以及一些特殊情况。

中位数的判断：如果一共奇数个数(`size`)，那么中位数就是第`size/2`个数；如果一共偶数个数，那么中位数就是第`size/2-1`和`size/2`个数。所以我们如果从下标为0开始遍历，那么一共需要遍历`size/2+1`次。考虑到偶数的时候需要两个数据，所以设置一个left存储上次遍历时的数据，right记录这次的数据。

1. 假如有数组是空的，那么就直接返回另一个数组的中位数；
2. 如果两个数组都不是空的，那么依次遍历，当两个下标都没越界的时候，比较两个下标对应的数，把小的那个++，只要有一个下标越界了，但是整体遍历还没有结束，那就++另一个下标

所以代码为：

```c++
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    std::size_t size = nums1.size()+nums2.size(),size1 = nums1.size(),size2 = nums2.size();
    int count = 0,left = INT32_MIN, right = INT32_MIN;
    int index1 = 0, index2 = 0;
    //如果有空数组的处理
    if(nums1.empty())return (static_cast<double>(nums2[(size2-1)/2]+nums2[size2/2])/2);
    else if(nums2.empty())return (static_cast<double>(nums1[(size1-1)/2]+nums1[size1/2])/2);
    //开始遍历
    while(count<size/2+1){
        //存储上次记录的数据，必须放在right赋值的前面，否则left会被当次数据覆盖
        left = right;
        if( (index2<nums2.size()&&index1<nums1.size()&&nums1[index1]<=nums2[index2]) || index2>=nums2.size() ){
            right = nums1[index1];
            ++index1;
        }else if((index2<nums2.size()&&index1<nums1.size()&&nums1[index1]>nums2[index2]) || index1>=nums1.size()){
            right = nums2[index2];
            ++index2;
        }
        ++count;
    }
    return size%2==1?right: (static_cast<double>(right)+left)/2;
}
```

# 2021.2.27 [1178. 猜字谜](https://leetcode-cn.com/problems/number-of-valid-words-for-each-puzzle/)

# 2021.2.27 [78. 子集](https://leetcode-cn.com/problems/subsets/)

很有意思的一道题，也是很考验技术的一道题。有两个方法，一个递归，一个数学方法。

1. 递归

   ![E2C55933-0D86-4F8E-82B9-430682B5B099.png](https://pic.leetcode-cn.com/1613704529-qfwaRN-E2C55933-0D86-4F8E-82B9-430682B5B099.png)

   从这个图片可以看出来，我们依次遍历整个`nums`，每次选择从`nums`中放入或者不放一个数，因此`nums.size()`就是一共要进行多少次抉择，这里`nums=3`，所以一共要进行2^3=8次抉择，所以最后会有8个子集。

   根据这张图，我们可以看出，如果要实现这样一个抉择，我们需要使用递归的方法，因此这里我们先假设一个函数`void dfs()`，我们来看看这个函数需要什么。

   1. 函数需要`nums`，以及当前需要进行抉择的那个数字，这里我们选择使用这个数字的下标`index`；
   2. 函数需要一个返回的值，考虑到我们到最底层才返回，不能每次都返回，我们可以用一个公共空间存储，所以我们设置一个`vector<vector<int>>& ret`作为最后的返回的结果；
   3. 每次我们做抉择的时候，我们都需要在上次抉择完了的基础上继续做抉择，所以我们需要一个存储上次抉择完的结果的变量，也是一个`vector<int> current` 。

   所以我们可以设置这个函数为`void dfs(vector<int>& nums,int index,vector<int> current,vector<vector<int>>& ret)`，再观察退出条件，我们只需要存储最底层的数据，因此只要到达最底层了我们就向`ret`里面添加一次结果，判断底层的条件为：`index?=nums.size()`，当我们做最后一次抉择时，`index=2`，做完之后`index=index+1=3`，这个时候恰好等于`nums.size()`。

   抉择的设置：当我们需要进行抉择的时候，我们有两个选择：

   1. 不加入当前`index`的元素，直接`index++`进入下一个抉择；
   2. 加入当前元素，也就是`current.push_back(nums[index])`，然后`index++`进入下一个抉择。

   所以代码可以写成：

   ```c++
   vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> ret{};
      vector<int> current{};
      dfs(nums,0,current,ret);
      return ret;
      }
   
      void dfs(vector<int>& nums,int index,vector<int> current,vector<vector<int>>& ret){
      if(index==nums.size()){
          ret.push_back(current);
              return;
      }
      dfs(nums,index+1,current,ret);
      current.push_back(nums[index]);
      dfs(nums,index+1,current,ret);
   }
   ```

最后的效率为下图，不太理想，因为调用了递归，需要大量的空间，并且计算量太复杂了。![image-20210227205203131](C:\Users\jiawei tang\AppData\Roaming\Typora\typora-user-images\image-20210227205203131.png)

2. 注意上面的递归的方法，我们一共进行了2^3=8次抉择，每次往`ret`里面加入一个数据，这里我们思考一下`0~7`这8个数的二进制，也就是`000~111`，如果我们用某一位为1表示子集中含有该下标对应的数字，那么`101`表示子集为`{3,1}`。所以我们只需要遍历`000~111`这8种情况就行了。

   由于每次我们只需要检查一位是否为1，所以我们用`bit masks`，然后每次令被检查的数向右移一位，然后再次检查即可。

   所以代码为：

   ```c++
   vector<vector<int>> subsets2(vector<int>& nums) {
   	vector<vector<int>> ret{};
   	vector<int> current{};
       //一共2^n种情况
   	for(int i=0;i<std::pow(2,nums.size());++i){
           //用item保存当前的i值，防止因为后续操作改变i导致死循环
   	    int item = i,index = 0;
           //如果什么都不加入，就是空子集
   		vector<int>temp{};
           //只要item还存在就要继续，直到item==0
   		while(item){
               //对item的最低位进行判断，如果最低位存在，就加入index对应的数
               if(item & 0x1)temp.push_back(nums[index]);
               //然后item>>1，同时index++表示我们打算取下一个数
               item=item>>1;
               ++index;
   		}
   		ret.push_back(temp);
   		
   	}
   	return ret;
   }
   ```

效果为下图，很理想。![image-20210227210718360](C:\Users\jiawei tang\AppData\Roaming\Typora\typora-user-images\image-20210227210718360.png)





# 2021.2.27 [395. 至少有 K 个重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/)

