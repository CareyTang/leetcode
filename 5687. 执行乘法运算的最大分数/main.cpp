/*
 * @Author: your name
 * @Date: 2021-02-21 16:54:41
 * @LastEditTime: 2021-02-22 18:20:40
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\5687. 执行乘法运算的最大分数\main.cpp
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

using std::vector;
using std::string;
using std::deque;
using std::multiset;
using std::multimap;
using std::map;
class Solution{
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers){
        int n = nums.size(), m = multipliers.size(),ret{};
        vector<vector<int>> dp(1001,vector<int>(1001,-1));
        for (size_t i = 0; i <= m; i++)
        {
            for (size_t j = 0; i+j<=m; j++)
            {
                if(i>0)dp[i][j] = std::max(dp[i][j],dp[i-1][j]+nums[i-1]*multipliers[i+j-1]);
                if(j>0)dp[i][j] = std::max(dp[i][j],dp[i][j-1]+nums[m-j]*multipliers[i+j-1]);
                
            }
            ret = std::max(ret,dp[i][m-i]);
        }
        return ret;
    }
};

int dp(int x,int y,vector<int>& aa,vector<int>& bb,vector<vector<int>>& table){
    if(x<0 || y<0)return INT32_MIN;
    else if(x==0 && y==1)return aa[aa.size()-1]*bb[0];
    else if(x==1 && y==0)return aa[0]*bb[0];
    else if(table[x][y] != -1)return table[x][y];
    else{
        int item1 = dp(x-1,y,aa,bb,table);
        if(item1==INT32_MIN);
        else item1 =  item1 + aa[x-1]*bb[x+y-1];
        int item2 = dp(x,y-1,aa,bb,table);
        if(item2==INT32_MIN);
        else item2 = item2 + aa[aa.size()-y]*bb[x+y-1];
        table[x][y] = std::max(item1,item2);
        return table[x][y];
    }
}

int main(){
    vector<int> a{-5,-3,-3,-2,7,1};
    vector<int> b{-10,-5,3,4,6};
    int max = INT32_MIN;
    vector<vector<int>>dptable(1001,vector<int>(1001,-1));
    for ( std::size_t i = 1,j = b.size()-i; i < b.size(); ++i,--j ) {
        max = std::max(max,dp(i,j,a,b,dptable));
    }
    std::cout<<max<<std::endl;
}