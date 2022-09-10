/**
 *    author:  willy
 *    created: Sat, 31 Jul 2021 08:46:40 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x;
  vector<int> a;
  while (cin >> x) {
    a.push_back(x);
  }
  int n = (int) a.size();
  vector<int> dp(n);
  vector<int> v;
  int l = 0;
  for (int i = 0; i < n; i++) {
    auto it = lower_bound(v.begin(), v.end(), a[i]);
    if (it == v.end()) {
      v.push_back(a[i]);
      dp[i] = ++l;
    } else {
      *it = a[i];
      dp[i] = (int) (it - v.begin() + 1);
    }
  }
  cout << l << "\n-\n";
  vector<int> ans;
  for (int i = n - 1; i >= 0; i--) {
    if (dp[i] == l) {
      ans.push_back(a[i]);
      --l;
    }
  }
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}
