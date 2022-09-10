/**
 *    author:  willy
 *    created: Tue, 07 Dec 2021 14:20:00 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> m(n);
  for (int i = 0; i < n; i++) {
    cin >> m[i];
  }
  vector<vector<long long>> dp(2, vector<long long>(n));
  for (int rot = 0; rot < 2; rot++) {
    vector<int> st;
    for (int i = 0; i < n; i++) {
      while (!st.empty() && m[st.back()] > m[i]) {
        st.pop_back();
      }
      if (st.empty()) {
        dp[rot][i] = m[i] * (i + 1);
      } else {
        dp[rot][i] = dp[rot][st.back()] + (i - st.back()) * m[i];
      }
      st.push_back(i);
    }
    reverse(m.begin(), m.end());
  }
  reverse(dp[1].begin(), dp[1].end());
  vector<long long> p(n);
  for (int i = 0; i < n; i++) {
    p[i] = dp[0][i] + dp[1][i] - m[i];
  }
  int at = (int) (max_element(p.begin(), p.end()) - p.begin());
  const long long inf = (long long) 1e18;
  vector<long long> ans(n, inf);
  ans[at] = m[at];
  for (int i = at - 1; i >= 0; i--) {
    ans[i] = min(ans[i + 1], m[i]);
  }
  for (int i = at + 1; i < n; i++) {
    ans[i] = min(ans[i - 1], m[i]);
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << '\n';
  return 0;
}
