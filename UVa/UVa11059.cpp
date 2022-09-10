/**
 *    author:  willy
 *    created: Tue, 17 Aug 2021 02:26:01 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  int kase = 0;
  while (cin >> n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      long long val = 1;
      for (int j = i; j < n; j++) {
        val *= a[j];
        ans = max(ans, val);
      }
    }
    cout << "Case #" << ++kase << ": The maximum product is " << ans << '.' << "\n\n";
  }
  return 0;
}
