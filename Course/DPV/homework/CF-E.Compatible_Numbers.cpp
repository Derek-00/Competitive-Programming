/**
 *    author:  willy
 *    created: Mon, 13 Dec 2021 12:57:40 GMT
**/
#include <bits/stdc++.h>

using namespace std;

const int MAX = 22;
const int ALL = 1 << MAX;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> dp(ALL, -1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    dp[a[i]] = a[i];
  }
  for (int i = 0; i < MAX; i++) {
    for (int b = 0; b < ALL; b++) {
      if (b & (1 << i) && dp[b] == -1) {
        dp[b] = dp[b ^ (1 << i)];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    int flip = (a[i] ^ (ALL - 1));
    cout << dp[flip];
  }
  cout << '\n';
  return 0;
}
