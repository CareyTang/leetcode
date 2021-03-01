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
    int maxTurbulenceSize(vector<int>& arr) {
        int res = 1, up = 1, down = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i - 1] < arr[i]) {
                up = down + 1;
                down = 1;
            } else if (arr[i - 1] > arr[i]) {
                down = up + 1;
                up = 1;
            } else {
                up = 1;
                down = 1;
            }
            res = std::max(res, std::max(up, down));
        }
        return res;
    }
};
int main() {
    Solution sol;
    vector<int> arr{9,4,2,10,7,8,8,1,9};
    std::cout<<sol.maxTurbulenceSize(arr)<<std::endl;
    return 0;
}
