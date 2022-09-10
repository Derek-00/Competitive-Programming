/**
 *    author:  willy
 *    created: Tue, 16 Nov 2021 05:38:28 GMT
**/
#include <bits/stdc++.h>

using namespace std;

inline int id(char s) {
  if (s == '+') return 0;
  if (s == '-') return 1;
  if (s == '*') return 2;
  if (s == '/') return 3;
}

int main() {
  string s;
  getline(cin, s);
  stringstream ss(s);
  double x;
  vector<double> a;
  while (ss >> x) {
    a.push_back(x);
  }
  vector<int> cnt(4);
  for (int i = 0; i < (int) a.size() - 1; i++) {
    char s;
    cin >> s;
    cnt[id(s)]++;
  }
  const double inf = (double) 1e30;
  double ans = -inf;
  function<void(int, double, double)> Dfs = [&](int id, double prv, double cur) {
    if (id == (int) a.size() - 1) {
      ans = max(ans, prv + cur);
      return;
    }
    for (int i = 0; i < 4; i++) {
      if (cnt[i] > 0) {
        --cnt[i];
        if (i == 0) Dfs(id + 1, prv + cur, a[id + 1]);
        if (i == 1) Dfs(id + 1, prv + cur, -a[id + 1]);
        if (i == 2) Dfs(id + 1, prv, cur * a[id + 1]);
        if (i == 3) Dfs(id + 1, prv, cur / a[id + 1]);
        ++cnt[i];
      }
    }
  };
  Dfs(0, 0, a[0]);
  cout << fixed << setprecision(2) << ans << '\n';
  return 0;
}
