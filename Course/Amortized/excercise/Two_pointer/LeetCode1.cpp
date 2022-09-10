/**
 *    author:  willy
 *    created: Sat, 06 Nov 2021 05:42:24 GMT
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& a, int target) {
  const int n = (int) a.size();
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return a[i] < a[j];
  });
  int l = 0, r = n - 1;
  while (l < r) {
    if (a[order[l]] + a[order[r]] == target) {
      return {order[l], order[r]};
    } else {
      if (a[order[l]] + a[order[r]] > target) {
        --r;
      } else {
        ++l;
      }
    }
  }
  assert(false);
  return vector<int>();
}
