/**
 *    author:  willy
 *    created: Sun, 02 Jan 2022 08:39:26 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  queue<long long> que;
  long long ans = 0;
  while (!que.empty() || !a.empty()) {
    long long mx = (long long) 1e18;
    if (!que.empty() && !a.empty()) {
      mx = max(que.front(), a.back());
    } else {
      if (!que.empty()) {
        mx = que.front();
      } else {
        mx = a.back();
      }
    }
    ans += 1;
    long long par = (mx >> 1);
    if (par != 0) {
      que.push(par);
    }
    while (!que.empty() && que.front() == mx) {
      que.pop();
    }
    while (!a.empty() && a.back() == mx) {
      a.pop_back();
    }
  }
  cout << ans - 1 << '\n';
  return 0;
}
