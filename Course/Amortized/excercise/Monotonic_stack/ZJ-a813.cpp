/**
 *    author:  willy
 *    created: Mon, 08 Nov 2021 12:40:54 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  vector<pair<long long, int>> stk;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    while (!stk.empty() && stk.back().first < h[i]) {
      ans += stk.back().second;
      stk.pop_back();
    }
    if (!stk.empty() && stk.back().first == h[i]) {
      ans += stk.back().second++;
    } else {
      stk.emplace_back(h[i], 1);
    }
    if ((int) stk.size() > 1) {
      ans += 1;
    }
  }
  cout << ans + ans << '\n';
  return 0;
}
