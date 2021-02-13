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
    bool checkInclusion(string s1, string s2) {
        vector<int>alphabet(26);
        std::size_t left = 0,right = 0;
        std::size_t size1 = s1.size();
        std::size_t size2 = s2.size();
        for (int i = 0; i < size1; ++i) {
            alphabet[s1[i]-'a']--;
        }
        while (right<size2){
            alphabet[s2[right]-'a']++;
            while(alphabet[s2[right]-'a']>0){
                alphabet[s2[left]-'a']--;
                ++left;
            }
            if(right-left+1==size1)
                return true;
            right++;
        }
        return false;
    }
};
int main() {
    Solution sol;
    string s1 = {"ab"};
    string s2 = {"eidbaooo"};
    sol.checkInclusion(s1,s2);
    return 0;
}
