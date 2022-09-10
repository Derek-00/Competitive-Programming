/**
 *    author:  willy
 *    created: Thu, 28 Oct 2021 15:57:22 GMT
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
    vector<long long> a(n);
    vector<int> pos(n << 1 | 1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      pos[a[i]] = i + 1;
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (a[i] * a[j] >= n * 2) {
          break;
        }
        if (a[i] * a[j] == pos[a[i]] + pos[a[j]]) {
          ans++;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
