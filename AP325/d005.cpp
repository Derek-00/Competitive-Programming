/**
 *    author:  wy
 *    created: Mon, 04 Jul 2022 07:40:55 GMT
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
  string s;
  cin >> s;
  int n;
  cin >> n;
  int id = 0;
  function<long long(int)> Solve = [&](long long e) {
    if (s[id] == '0' || s[id] == '1') {
      return (s[id++] == '1' ? e * e : 0);
    }
    e >>= 1;
    id += 1;
    long long ans = 0;
    for (int i = 0; i < 4; i++) {
      ans += Solve(e);
    }
    return ans;
  };
  cout << Solve(n) << '\n';
  return 0;
}
