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
    //暴力法超时
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<int> ret(puzzles.size(), 0);
        int i = 0;
        for ( const auto &pu:puzzles ) {
            char first = pu[0];
            std::set<char> puhave{pu.begin(), pu.end()};
            for ( const auto &wo:words ) {
                bool havefirst = false, havenotexist = false;
                for ( const auto &item:wo ) {
                    if ( puhave.find(item) == puhave.end())havenotexist = true;
                    else if ( item == first )havefirst = true;
                }
                if ( havefirst && !havenotexist)ret[i]++;

            }
            ++i;
        }
        return ret;
    }
};

int main() {
    vector<string> a {"aaaa","asas","able","ability","actt","actor","access"},
    b{"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"};
    Solution sol;
    sol.findNumOfValidWords(a,b);
    return 0;
}
