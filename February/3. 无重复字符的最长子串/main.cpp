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
    int lengthOfLongestSubstring(string s) {
        std::size_t left = 0,right = 0,length = 0;
        vector<int>alphabet(128,0);
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
    }
};
int main() {
    Solution sol;
    string s{"abcabcbb"};
    std::cout<<sol.lengthOfLongestSubstring(s)<<std::endl;
    return 0;
}
