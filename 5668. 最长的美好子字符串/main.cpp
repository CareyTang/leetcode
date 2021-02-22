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
    string longestNiceSubstring(string s) {
        int length = 0, size = s.size(), ok = 0, index = 0;
        int start = 0, end = 0;
        int upper[26] = {0},lower[26] = {};
        int i = 0, j = 0;
        for(i = 0; i < size; ++i){
            for( j = i; j< size; ++j){
                ok = 0;
                if(s[j]>='a' && s[j]<='z'){
                    index = s[j]-'a';
                    lower[index]++;
                }
                else if(s[j]>='A' && s[j]<='Z'){
                    index = s[j]-'A';
                    upper[index]++;
                }
                for ( int k = 0; k < 26; ++k ) {
                    if(upper[k]>0&&lower[k]>0)ok++;
                    else if((upper[k]>0&&lower[k]==0) ||(upper[k])==0&&lower[k]>0)ok--;
                }
                if(ok<=-2)j = size;
                else if(ok>0 && j-i+1>length){
                    start = i;
                    end = j;
                    length = end-start+1;
                }
            }
            for ( int k = 0; k < 26; ++k ) {
                upper[k] = 0;
                lower[k] = 0;
            }
            ok = 0;
        }
        return s.substr(start,length);
    }
};

int main() {
    string s{"YazaAay"};
    Solution sol;
    std::cout<<sol.longestNiceSubstring(s)<<std::endl;
}
