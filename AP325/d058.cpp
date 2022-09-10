/**
 *    author:  wy
 *    created: Mon, 11 Jul 2022 05:58:32 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = (int) 1e5;

int n;
long long t[N], d[N];
int id[N];
long long times;

inline bool Cmp(int i, int j) {
  return d[i] < d[j];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> t[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> d[i];
    }
    iota(id, id + n, 0);
    sort(id, id + n, Cmp);
    times = 0;
    bool can = true;
    for (int i = 0; i < n; i++) {
      times += t[id[i]];
      if (times > d[id[i]]) {
        can = false;
        break;
      }
    }
    cout << (can ? "yes" : "no") << '\n';
  }
  return 0;
}
