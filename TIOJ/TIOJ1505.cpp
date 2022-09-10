/**
 *    author:  wy
 *    created: Wed, 07 Sep 2022 13:53:38 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long res = a[0] % a[1];
    for (int i = 2; i < n; i++) {
      res = (res * a[i]) % a[1];
    }
    cout << (res == 0 ? "Asssss!!" : "zzz...") << '\n';
  }
  return 0;
}
