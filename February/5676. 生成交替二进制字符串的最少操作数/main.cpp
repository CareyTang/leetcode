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
    int minOperations(string s) {
        int size = s.size();
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < size;++i) {
            if( (i%2==0&&s[i]!='0') || (i%2==1&&s[i]!='1') )++cnt1;
            else if( (i%2==0&&s[i]!='1') || (i%2==1&&s[i]!='0') )++cnt2;
        }
        return std::min(cnt1,cnt2);
    }
};

int main() {
    string s = "110010";
    Solution solution;
    std::cout<<solution.minOperations(s)<<std::endl;
    return 0;
}
