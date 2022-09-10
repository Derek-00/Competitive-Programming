/**
 *    author:  willy
 *    created: Tue, 07 Dec 2021 02:45:25 GMT
**/
#include <bits/stdc++.h>

using namespace std;

const int md = (int) 1e9 + 7;

inline int add(int a, int b) {
  a += b;
  if (a >= md) a -= md;
  return a;
}

inline int sub(int a, int b) {
  a -= b;
  if (a < 0) a += md;
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> dp(k + 1);
  for (int i = 0; i <= a[0]; i++) {
    dp[i] = 1;
  }
  vector<int> pref(k + 1);
  pref[0] = dp[0];
  for (int i = 1; i <= k; i++) {
    pref[i] = add(pref[i - 1], dp[i]);
  }
  for (int i = 1; i < n; i++) {
    vector<int> new_dp(k + 1);
    for (int j = 0; j <= k; j++) {
      new_dp[j] = add(new_dp[j], sub(pref[j], (j - a[i] <= 0 ? 0 : pref[j - a[i] - 1])));
    }
    vector<int> new_pref(k + 1);
    new_pref[0] = new_dp[0];
    for (int j = 1; j <= k; j++) {
      new_pref[j] = add(new_pref[j - 1], new_dp[j]);
    }
    swap(pref, new_pref);
    swap(dp, new_dp);
  }
  cout << dp[k] << '\n';
  return 0;
}
