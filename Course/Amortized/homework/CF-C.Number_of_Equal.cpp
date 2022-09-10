/**
 *    author:  willy
 *    created: Fri, 05 Nov 2021 15:20:33 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  int ptr = 0;
  long long prv = 0;
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    if (i > 0 && b[i] == b[i - 1]) {
      ans += prv;
      continue;
    }
    while (ptr < n && a[ptr] < b[i]) {
      ptr++;
    }
    int cur = ptr;
    while (cur < n && a[cur] == b[i]) {
      cur++;
    }
    prv = (long long) cur - ptr;
    ans += prv;
  }
  cout << ans << '\n';
  return 0;
}
