/**
 *    author:  willy
 *    created: Sun, 07 Nov 2021 13:33:19 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int largestRectangleArea(vector<int>& h) {
  int n = (int) h.size();
  vector<int> stk;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    while (!stk.empty() && h[stk.back()] > h[i]) {
      int high = h[stk.back()];
      stk.pop_back();
      int width = i - (stk.empty() ? -1 : stk.back()) - 1;
      mx = max(mx, high * width);
    }
    stk.push_back(i);
  }
  while (!stk.empty()) {
    int high = h[stk.back()];
    stk.pop_back();
    int width = n - (stk.empty() ? -1 : stk.back()) - 1;
    mx = max(mx, high * width);
  }
  return mx;
}
