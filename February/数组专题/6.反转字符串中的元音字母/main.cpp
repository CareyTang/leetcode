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
    bool isVowels(char& c){
        if(c=='a' || c=='e'|| c=='i'|| c=='o'|| c=='u' ||
           c=='A' || c=='E'|| c=='I'|| c=='O'|| c=='U')return true;
        else return false;
    }
    string reverseVowels(string s) {
        int left = 0, right = s.size()-1;
        while(left<right){
            while(!isVowels(s[left]) && right>left)++left;
            while(!isVowels(s[right]) && right>left)--right;
            std::swap(s[left],s[right]);
            ++left;
            --right;
        }
        return s;
    }
};
int main() {
    Solution sol;
    string s{".,"};
    std::cout<<sol.reverseVowels(s)<<std::endl;
    return 0;
}
