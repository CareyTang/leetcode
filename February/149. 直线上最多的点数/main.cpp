/*
 * @Author: your name
 * @Date: 2021-02-22 16:31:38
 * @LastEditTime: 2021-02-22 18:12:31
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\149. 直线上最多的点数\main.cpp
 */
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using std::vector;
using std::string;
using std::deque;
using std::multiset;
using std::multimap;
using std::map;
using std::unordered_map;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() < 3) {
            return points.size();
        }
        int retFinal = 0,i,j;
        for(j = 0;j<points.size();++j){
            vector<int> start = points[j];
            unordered_map<long double,int> k{};
            int repeatedNum = 0, ret = 0;
            for ( i = j+1; i < points.size(); ++i ) {
                if(points[i][0]==start[0] && points[i][1]==start[1]) {
                    repeatedNum++;
                }
                else if(points[i][0]==start[0]) {
                    if(k.find(INT32_MIN)==k.end())k[INT32_MIN]+=2;
                    else k[INT32_MIN]++;
                    ret = std::max(ret,k[INT32_MIN]);
                }
                else{
                    int dy = (points[i][1]-start[1]);
                    int dx = (points[i][0]-start[0]);
                    long double item = static_cast<long double> (dy)/dx;
                    if(k.find(item)==k.end())k[item]+=2;
                    else k[item]++;
                    ret = std::max(ret,k[item]);
                }
            }
            //如果没有重复的，ret就是真实的值
            if(repeatedNum==0)retFinal = std::max(retFinal,ret);
            //如果有个别重复的，那么返回ret+repeatedNum
            else if(repeatedNum!=(i-j-1)) retFinal = std::max(ret+repeatedNum,retFinal);
            //如果全部都是重复的，那么返回repeatNum+1
            else retFinal = std::max(retFinal,repeatedNum+1);
        }
        return  retFinal;
    }

    int gcd(int x,int y){
        int temp{};
        while (y){
            temp = x % y;
            x = y;
            y = temp;
        }
        return x;
    }
};
int main() {
    vector<vector<int>>points{{1,1},{1,1},{0,0},{3,4},{4,5},{5,6},{7,8},{8,9}};
    Solution sol;
    sol.maxPoints(points);
    return 0;
}
