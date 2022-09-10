/**
 *    author:  willy
 *    created: Fri, 20 Aug 2021 10:45:37 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  stable_sort(a.begin(), a.end(), [&](int i, int j) {
    return __builtin_popcount(i) < __builtin_popcount(j);
  });
  for (int i = 0; i < n; i++) {
    cout << a[i] << " \n"[i == n - 1];
  }
  return 0;
}
