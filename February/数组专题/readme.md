### 移动零

首先把所有不是0的元素都提前，然后把后面空出来的都补零

```c++
void moveZeroes(vector<int>& nums) {
    int left = 0, right = 0;
    int size = nums.size();
    while (right<size){
        if(nums[right]!=0){
            nums[left] = nums[right];
            ++left;
        }
        ++right;
    }
    for (int i = left; i <size ; ++i) {
        nums[i] = 0;
    }
}
```

### 移除元素

同样用一个`left`和`right`，如果当前的值不等于`val`，就替换，并且`++left`找到下一个需要被替换的地方

```c++
int removeElement(vector<int>& nums, int val) {
    int left = 0, right = 0, count = 0,size = nums.size();
    while (right<size){
        if(nums[right]!=val){
            nums[left] = nums[right];
            ++left;
            ++count;
        }
        ++right;
    }
    return count;
}
```

### 删除排序数组中的重复项

明确一下规则，当遇到了不同的数字的时候，就要发生交换，交换后`left++`，如果是相同的数字，那么`right++`

注意边界条件：由于需要`right-1`，所以right得从1开始，所以如果数组只有0或者1个元素，直接返回`size`

```c++
int removeDuplicates(vector<int>& nums) {
    if(nums.size()==0 || nums.size()==1) return nums.size();
    int left = 1, right = 1;
    while(right<nums.size()){
        if(nums[right]!=nums[right-1]){
            nums[left] = nums[right];
            ++left;
        }
        ++right;
    }
    return left;
}
```

### 删除排序数组中的重复项 II

同样用一个`left`和`right`，遍历`nums`，用一个`count`记录这个数出现了多少次，用`current`表示当前记录的数

如果`count<=2`，就说明不需要替换，`++left`，如果`count>2`，就说明需要开始替换了，`left`不动，

如果当前的元素不为`current`，说明出现了新的数，`count=0`，`current`更新。

```c++
int removeDuplicates(vector<int>& nums) {
    int left = 0, right = 0, current = nums[0], count = 0;
    while (right<nums.size()){
        if(nums[right]==current) ++count;
        else{
            current = nums[right];
            count = 1;
        }
        nums[left] = nums[right];//这个地方可不可以再优化一下？
        if(count<=2)++left;
        ++right;
    }
    return left;
}
```

### 颜色分类

要求能够一次遍历就能够完成算法，直接`sort()`

### 数组中的第K个最大元素

```c++
//用lambda写一个compare
std::sort(nums.begin(),nums.end(),[](int x, int y){return x>y;});
return nums[k-1];
```

### 反转字符串中的元音字母

双指针，注意什么时候退出，当`left>right`的时候就不应该`swap`

```c++
bool isVowels(char& c){
    if(c=='a' || c=='e'|| c=='i'|| c=='o'|| c=='u' ||
       c=='A' || c=='E'|| c=='I'|| c=='O'|| c=='U')return true;
    else return false;
}
string reverseVowels(string s) {
    int left = 0, right = s.size()-1;
    while(left<right){
        //括号里面的right>left非常重要，以"hello"为例，正常反转之后为"holle"
        //随着遍历，如果不加right>left的话，最后有可能会出现left->e,right->o，那么此时又会发生一次反转，回复原样
        //所以为了避免这样的情况，应当避免left增加到while循环结束的条件，所以加上right>left
        //如果不加入right>left而是改用在swap之前加入if(right>left)，那么有可能发生下标越界的情况，这也是需要避免的
        //所以最好的方法还是在while中加入right>left
        while(!isVowels(s[left]) && right>left)++left;
        while(!isVowels(s[right]) && right>left)--right;
        std::swap(s[left],s[right]);
        ++left;
        --right;
    }
    return s;
}
```

### [重点]盛最多水的容器

判断容积的时候，因为只有短板才有影响，所以移动指针应该移动短板，因为移动长板时，有：

1. 如果长板变得比短板还短，那么容积显然减少。
2. 如果长板变得比短板长或相等，因为短板依旧未变。但距离减少，所以容积依旧减少。

所以左右指针对撞，移动左右指针height中较矮的那一个

```c++
int maxArea(vector<int>& height) {
    std::size_t left = 0, right = height.size()-1;
    int maxTemp{},max{};
    while (left<right){
        maxTemp = std::min(height[left],height[right])*(right-left);
        if(height[left]>height[right])--right;
        else ++left;
        max = std::max(max,maxTemp);
    }
    return max;
}
```

### 买卖股票的最佳时机II

很有意思的一道题目，首先买卖股票的核心是：相邻两天，低吸高抛。其次，如果股价连续上涨，那么多天连续交易的收入等同于区间交易的收入，但是只要股价存在下降，那么那一天就不应该操作。

如果遇到这种情况可以特殊解释：第一天买入第二天卖出，第二天又买入第三天又卖出。这里第二天卖出的同时买入，其实相当于什么都没做。也就是说，相当于第一天买入，第三天再卖出。但是计算的时候，利润可以用第一次和第二次的利润直接相加的。

```c++
int maxProfit(vector<int>& prices) {
        int buy = 0, sell = 1, income = 0;
        if(prices.size()==1)return 0;
        while(sell<prices.size()){
            if(prices[buy]<prices[sell]) income += prices[sell]-prices[buy];
            ++sell;
            ++buy;
        }
        return income;
    }
```

