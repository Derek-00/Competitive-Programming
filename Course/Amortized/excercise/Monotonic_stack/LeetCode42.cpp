/**
 *    author:  willy
 *    created: Tue, 09 Nov 2021 05:41:00 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int trap(vector<int>& height) {
  vector<int> stk;
  int ans = 0;
  for (int i = 0; i < (int) height.size(); i++) {
    while (!stk.empty() && height[stk.back()] < height[i]) {
      int top = stk.back();
      stk.pop_back();
      if (stk.empty()) {
        break;
      }
      int len = i - stk.back() - 1;
      int w = min(height[i], height[stk.back()]) - height[top];
      ans += len * w;
    }
    stk.push_back(i);
  }
  return ans;
}
