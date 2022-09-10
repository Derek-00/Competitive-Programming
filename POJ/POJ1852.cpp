/**
 *    author:  willy
 *    created: Sun, 01 Aug 2021 09:52:11 GMT
**/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int l, n;
    cin >> l >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int mx = -1, mn = -1;
    for (int i = 0; i < n; i++) {
      mx = max(mx, max(a[i], l - a[i]));
      mn = max(mn, min(a[i], l - a[i]));
    }
    cout << mn << " " << mx << '\n';
  }
  return 0;
}
