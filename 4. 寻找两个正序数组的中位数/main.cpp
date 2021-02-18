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

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    }
};

class Solution2 {
public:
    int countHomogenous(string s) {
        long long res{};
        long long count{};
        long long mod = 1e9+7;
        char& current = s[0];
        for(auto& item:s){
            if(item==current)++count;
            else{
                res+=count*(count+1)/2;
                count = 1;
                current = item;
            }
        }
        res=(res+count/2*(count+1));
        res %= mod;
        return res;
    }
};
int main() {
    string s(100000,'w');
    Solution2 sol2;
    std::cout<<sol2.countHomogenous(s)<<std::endl;
    return 0;
}
