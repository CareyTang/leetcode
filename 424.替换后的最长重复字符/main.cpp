#include <iostream>
#include <string>
#include <deque>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        int count[26] = {0};//初始化计数数组
        int begin = 0, end = 0;
        int maxShow = 0;
        for (const auto &item : s) {
            end++;
            //每次添加新元素之后，计算现在队列中出现次数最多的元素个数
            ++count[item-'A'];
            maxShow = std::max(maxShow,count[item-'A']);
            //然后判断当前队列的长度的出现次数最多的差是否大于k
            if( (end-begin)-maxShow>k){
                //如果大于k就说明无法修改,所以需要剔除队列的头部那个，然后等待新添一个
                --count[(s[begin])-'A'];
                begin++;
            }
        }
        return end-begin;
    }
};

int main() {
    Solution sol;
    int res = sol.characterReplacement("AABABBA",1);
    std::cout<<res<<std::endl;

    return 0;
}
