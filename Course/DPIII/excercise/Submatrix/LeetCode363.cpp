/**
 *    author:  willy
 *    created: Wed, 13 Oct 2021 12:07:52 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/

const int inf = (int) 1e9;

int Solve(const vector<int>& a, int k) {
  const int n = (int) a.size();
  int mx = -inf;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += a[j];
      if (sum <= k) {
        mx = max(mx, sum);
      }
    }
  }
  return mx;
}

int maxSumSubmatrix(vector<vector<int>>& matrix, int K) {
  const int n = (int) matrix.size();
  const int m = (int) matrix[0].size();
  int ans = -inf;
  for (int i = 0; i < n; i++) {
    vector<int> a(m);
    for (int j = i; j < n; j++) {
      for (int k = 0; k < m; k++) {
        a[k] += matrix[j][k];
      }
      ans = max(ans, Solve(a, K));
    }
  }
  return ans;
}
