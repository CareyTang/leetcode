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

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int alphabet[26] = {0};
        std::size_t size1 = s1.size(), size2 = s2.size();
        for(std::size_t i = 0;i<size1;i++)
            alphabet[s1[i]-'a']--;
        std::size_t left = 0, right = 0;
        while(right < size2){
            alphabet[s2[right]-'a']++;
            while(alphabet[s2[right]-'a']>0){
                alphabet[s2[left]-'a']--;
                left++;
            }
            if(right-left==size1) return true;
        }
        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    int alphabet[26] = {0};
    return 0;
}
