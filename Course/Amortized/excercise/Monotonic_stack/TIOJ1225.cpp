/**
 *    author:  willy
 *    created: Sun, 07 Nov 2021 14:18:52 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> stk;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    while (!stk.empty() && stk.back() <= a[i]) {
      stk.pop_back();
      if (stk.empty()) {
        ans += a[i];
      } else {
        ans += min(a[i], stk.back());
      }
    }
    stk.push_back(a[i]);
  }
  while ((int) stk.size() > 1) {
    stk.pop_back();
    ans += stk.back();
  }
  cout << ans << '\n';
  return 0;
}
