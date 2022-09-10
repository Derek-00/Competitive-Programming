/**
 *    author:  willy
 *    created: Sun, 07 Nov 2021 11:42:43 GMT
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
  const int n = (int) nums.size();
  const int n2 = n + n;
  vector<int> stk;
  vector<int> ans(n);
  for (int i = n2 - 1; i >= 0; i--) {
    while (!stk.empty() && nums[stk.back()] <= nums[i % n]) {
      stk.pop_back();
    }
    if (stk.empty()) {
      ans[i % n] = -1;
    } else {
      ans[i % n] = nums[stk.back()];
    }
    stk.push_back(i % n);
  }
  return ans;
}
