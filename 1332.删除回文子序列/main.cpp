#include <iostream>
#include <map>
#include <vector>
using std::vector;
using std::string;

class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.size()==0)return 0;
        else if(s==string(s.rbegin(),s.rend()) )return 1;
        else return 2;
    }
};

int main() {
    Solution sol;
    string s{"ababa"};
    std::cout<<sol.removePalindromeSub(s)<<std::endl;

    return 0;
}