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

class Solution2{
public:
    int longestOnes(vector<int>& A, int K) {
        int left = 0, right = 0, ret = 0, count0 = 0;
        while(right<A.size()){
            if(A[right]==0)++count0;
            while(count0>K){
                if(A[left]==0)--count0;
                ++left;
            }
            ++right;
            ret = std::max(ret,right-left);
        }
        return ret;
    }
};
int main() {
    Solution2 sol2;
    vector<int>nums{1,1,1,0,0,0,1,1,1,1,0};
    std::cout<<sol2.longestOnes(nums,2)<<std::endl;
    return 0;
}
