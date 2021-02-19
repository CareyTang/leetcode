# Leetcode with cpp

## author:Javy

### 目录

- [2021.2.2 424-替换后的最长重复字符](###2021.2.2 424-替换后的最长重复字符)
- [2021.2.2 面试题16.21 交换和](###2021.2.2 面试题16.21 交换和)
- [2021.2.2 219. 存在重复元素 II](###2021.2.2 219. 存在重复元素 II)
- [2021.2.2 1332. 删除回文子序列](###2021.2.2 1332. 删除回文子序列)
- [2021.2.3 480. 滑动窗口中位数](###2021.2.3 480. 滑动窗口中位数)

### 2021.2.2 424-替换后的最长重复字符

使用了`std::max`替代了`max_element`，用时4ms(98.16%)，内存6.9mb(93.17%)

**知识点：少用algorithm的算法，能用下标的尽量用下标，不要使用复杂的容器和指针**

### 2021.2.2 面试题16.21 交换和

**对于有大量数据的，如果用`vector`的话会导致超时，可以利用`set`的只保存`unique` 元素的特性进行处理，对`vector`的数据进行降维**

### 2021.2.2 219. 存在重复元素 II

**对于有大量的数据的，`set`可以对重复数据进行删减，从而减少有效数据的个数.**

但是`set`保存数据的方法是使用`Hash`算法，所以数据的保存并不会如我们所 期望的那样。所以如果我们想要使数据能够保持我们期望的顺序，可以考虑使用`map` 代替`set`，虽然`map`相比于`set`更加的复杂，多了`key-value`，但是可以利用`value`的值保存顺序，形成一个伪顺序。比如在`value`中保存我们期望的下标。

`insert(iter)`都是在当前的这个`iter`前面插入数据，如果不添加`hint`， 就会在调用`insert`函数的容器利用`Hash`算法找到插入的地方。

### 2021.2.2 1332. 删除回文子序列

脑筋急转弯的一道题，关键在于理解回文子序列这个意思，定义为：通过对原字符串中的某些字符进行删除，不改变其他字符的顺序，剩下的那些字符 依旧是回文形式，就成为回文子序列。所以说，对于只有`a和b`两种字符组成的字符串而言，只有三种情况：

1. 当目前的字符串是空，那么需要删除的次数就是0次；对此可以利用`size()`进行判断
2. 当目前的字符串本身就是回文，那么需要删除的次数就是1次；对此可以`reverse()`进行判断
3. 当目前的字符串不属于上面两种情况，那么需要删除的次数必然是2次，一次全删除`a`，一次全删除`b`。

### 2021.2.3 480. 滑动窗口中位数

待完善

### 2021.2.4 643. 子数组最大平均数 I

对于此类的滑动窗口类型的题目，关键在于怎么确定窗口滑动的条件，一般的窗口滑动题目都有共性，比如：

1. 需要对窗口内的元素进行相应的操作；
2. 需要对窗口进行平移操作，牵扯到窗口的`pop_front()`操作和`push_back()`操作，什么时候加入什么时候删除
3. 窗口到头了的边界条件判断

### 2021.2.5 [1208. 尽可能使字符串相等](https://leetcode-cn.com/problems/get-equal-substrings-within-budget/)

1. **用`std::abs()`代替`abs()`可以减少用时**
2. 窗口滑动到最后窗口的大小变化是什么样子的

### 2021.2.6 [1423. 可获得的最大点数](https://leetcode-cn.com/problems/maximum-points-you-can-obtain-from-cards/)

关键在于使用逆向思维的方法，原本是可以在头部和尾部分开取元素以获得最大点数，但是反过来剩下的就是最小的点数的组合，所以如果计算什么样的窗口可以获得最小的点数，再用全部的`sum`减去最小的点数，剩下的就是最大的点数和了。同样要使用`std::min`来代替`min`。

### 2021.2.7 [665. 非递减数列](https://leetcode-cn.com/problems/non-decreasing-array/)

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

### 2021.2.7 [888. 公平的糖果棒交换](https://leetcode-cn.com/problems/fair-candy-swap/)

难度不大，很简单的双指针比较题目。常使用`vector的push_back()`操作，但是发现很耗时间，最后使用双指针目前达到一个比较令人满意的结果。尝试后续使用`binart_search()`或者`hashmap`的方法。

### 2021.2.8  [978. 最长湍流子数组](https://leetcode-cn.com/problems/longest-turbulent-subarray/)

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

### 2021.2.9 [992. K 个不同整数的子数组](https://leetcode-cn.com/problems/subarrays-with-k-different-integers/)

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

### 2021.2.9 [209. 长度最小的子数组](https://leetcode-cn.com/problems/minimum-size-subarray-sum/)

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

### 2021.2.9 [3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)

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

### 2021.2.10 [567. 字符串的排列](https://leetcode-cn.com/problems/permutation-in-string/)

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

### [重点]2021.2.11 [703. 数据流中的第 K 大元素](https://leetcode-cn.com/problems/kth-largest-element-in-a-stream/)

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

### 2021.2.12 [119. 杨辉三角 II](https://leetcode-cn.com/problems/pascals-triangle-ii/)

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

### 2021.2.13 [136. 只出现一次的数字](https://leetcode-cn.com/problems/single-number/)

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

### 2021.2.13 [448. 找到所有数组中消失的数字](https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/)

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

### 2021.2.14 [765. 情侣牵手](https://leetcode-cn.com/problems/couples-holding-hands/)

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

### 2021.2.14 [5676. 生成交替二进制字符串的最少操作数](https://leetcode-cn.com/problems/minimum-changes-to-make-alternating-binary-string/)

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

### 2021.2.15 [485. 最大连续1的个数](https://leetcode-cn.com/problems/max-consecutive-ones/)

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

### 2021.2.16 [561. 数组拆分 I](https://leetcode-cn.com/problems/array-partition-i/)

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

### 2021.2.17 [566. 重塑矩阵](https://leetcode-cn.com/problems/reshape-the-matrix/)

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

### 2021.2.17 [4. 寻找两个正序数组的中位数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/)

1. 最简单的方法：合并两个`vector`，然后从中转换为topk的问题
2. 二分查找



### 2021.2.18 [1759. 统计同构子字符串的数目](https://leetcode-cn.com/problems/count-number-of-homogenous-substrings/)

大数乘法溢出的问题，当`count=100000`的时候，发现`count*(count+1)`总是会溢出，当两个同种类型的数据进行乘法计算的话，得出来的结果会首先保存在同类型的空间中，哪怕溢出了也会先保存在同类型的空间中，然后再copy到结果中。所以为了避免溢出的情况，优先把`count*(count+1)`计算一下，看一下大小以及用什么类型存储，然后将结果、count都设置为指定类型的数据。

### [重点]2021.2.18 [995. K 连续位的最小翻转次数](https://leetcode-cn.com/problems/minimum-number-of-k-consecutive-bit-flips/)

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

### 2021.2.18 [984. 不含 AAA 或 BBB 的字符串](https://leetcode-cn.com/problems/string-without-aaa-or-bbb/)

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

### 2021.2.19 [1004. 最大连续1的个数 III](https://leetcode-cn.com/problems/max-consecutive-ones-iii/)

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

### 2021.2.19 [66.加一](https://leetcode-cn.com/problems/plus-one/)

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

### 2021.2.19 [28. 实现 strStr()](https://leetcode-cn.com/problems/implement-strstr/)

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

### 2021.2.20 [697. 数组的度](https://leetcode-cn.com/problems/degree-of-an-array/)

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