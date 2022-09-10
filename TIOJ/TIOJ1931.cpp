/**
 *    author:  willy
 *    created: Tue, 10 Aug 2021 15:48:28 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    long long ans = 0;
    for (int i = 1; i < n; i += 2) {
      ans += 4LL * a[i];
    }
    cout << ans << '\n';
  }
  return 0;
}
