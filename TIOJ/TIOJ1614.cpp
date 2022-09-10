/**
 *    author:  willy
 *    created: Fri, 13 Aug 2021 10:26:28 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(b.begin(), b.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int at = (int) (lower_bound(b.begin(), b.end(), a[i]) - b.begin());
    if (a[i] != b[at] && (at % 2 == 0)) {
      ++ans;
    }
  }
  cout << ans << '\n';
  return 0;
}
