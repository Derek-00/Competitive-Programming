/**
 *    author:  willy
 *    created: Fri, 27 Aug 2021 11:32:33 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int K = 30;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  int Case = 0;
  while (cin >> n && n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int res = 0;
    auto Merges = [&](int l, int m, int r) {
      vector<long long> tmp;
      int i = l, j = m;
      while (i < m || j < r) {
        if (j == r || (i < m && a[i] <= a[j])) {
          tmp.push_back(a[i++]);
        } else {
          tmp.push_back(a[j++]);
          res += m - i;
        }
      }
      for (int i = l; i < r; i++) {
        a[i] = tmp[i - l];
      }
    };
    function<void(int, int)> CDQ = [&](int l, int r) {
      if (r - l <= K) {
        for (int i = l; i < r; i++) {
          for (int j = l; j < i; j++) {
            if (a[i] < a[j]) {
              ++res;
            }
          }
        }
        sort(a.begin() + l, a.begin() + r);
      } else {
        int mid = l + (r - l) / 2;
        CDQ(l, mid);
        CDQ(mid, r);
        Merges(l, mid, r);
      }
    };
    CDQ(0, n);
    cout << "Case #" << ++Case << ": " << res << '\n';
  }
  return 0;
}
