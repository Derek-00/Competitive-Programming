/**
 *    author:  willy
 *    created: Thu, 16 Dec 2021 13:31:26 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> cnt(n + 1, 0);
  long long has = 0;
  int l = 0, r = 0;
  auto Get = [&](int ll, int rr) {
    while (l > ll) {
      --l;
      has += (long long) cnt[a[l]]++;
    }
    while (r < rr) {
      has += (long long) cnt[a[r]]++;
      ++r;
    }
    while (l < ll) {
      has -= (long long) --cnt[a[l]];
      ++l;
    }
    while (r > rr) {
      --r;
      has -= (long long) --cnt[a[r]];
    }
    return has;
  };
  const long long inf = (long long) 1e18;
  vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, inf));
  dp[0][0] = 0;
  function<void(int, int, int, int, int)> dfs = [&](int k, int l, int r, int ll, int rr) {
    if (l >= r) {
      return;
    }
    int mid = (l + r) >> 1;
    int best = -1;
    for (int i = ll; i < min(mid, rr); i++) {
      long long cost = Get(i, mid);
      if (dp[k][mid] > dp[k - 1][i] + cost) {
        dp[k][mid] = dp[k - 1][i] + cost;
        best = i;
      }
    }
    dfs(k, l, mid, ll, best + 1);
    dfs(k, mid + 1, r, best, rr);
  };
  for (int i = 1; i <= k; i++) {
    l = r = 0; has = 0LL;
    fill(cnt.begin(), cnt.end(), 0);
    dfs(i, i, n + 1, 0, n + 1);
  }
  cout << dp[k][n] << '\n';
  return 0;
}
