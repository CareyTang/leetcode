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
#include <math.h>

using std::vector;
using std::string;
using std::deque;
using std::multiset;
using std::multimap;
using std::map;
using std::unordered_set;

int binartSearch1(vector<int>&nums, int target){
  int left = 0, right = nums.size()-1, mid = 0;
  while(left<=right){
    mid = left + (right-left)/2;
    if(nums[mid]>target)
      right=mid-1;
    else if(nums[mid]<target)
      left=mid+1;
    else
      return mid;
  }
  return left;
}

int binartSearch2(vector<int>& nums, int target){
  int left = 0, right = nums.size()-1, mid;
  while (left<right){
    mid = left + (right-left)/2;
    if(nums[mid]<target)
      left = mid + 1;
    else
      right = mid;
  }
  return left;
}
int main() {
  vector<int> nums{1,3,5,6};
  int target = 2;
  std::cout<<binartSearch2(nums,target)<<std::endl;


  return 0;
}
