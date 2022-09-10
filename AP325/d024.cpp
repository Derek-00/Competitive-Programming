/**
 *    author:  willy
 *    created: Sun, 01 Aug 2021 12:12:51 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> p(n + n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i + n] = p[i];
  }
  vector<int> q(m);
  for (int i = 0; i < m; i++) {
    cin >> q[i];
  }
  vector<int> pref(n + n);
  partial_sum(p.begin(), p.end(), pref.begin());
  int at = 0;
  for (int i = 0; i < m; i++) {
    if (at != 0) {
      q[i] += pref[at - 1];
    }
    at = (int) (lower_bound(pref.begin(), pref.end(), q[i]) - pref.begin());
    at = (at + 1) % n;
  }
  cout << at << '\n';
  return 0;
}
