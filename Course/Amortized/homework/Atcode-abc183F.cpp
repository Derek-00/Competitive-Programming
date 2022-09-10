/**
 *    author:  willy
 *    created: Wed, 10 Nov 2021 15:15:09 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  map<int, vector<pair<int, int>>> fds;
  vector<int> p(n + 1);
  for (int i = 1; i <= n; i++) {
    int c;
    cin >> c;
    p[i] = i;
    fds[i].emplace_back(i, c);
  }
  function<int(int)> get = [&](int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  };
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int a, b;
      cin >> a >> b;
      a = get(a);
      b = get(b);
      if (a == b) continue;
      if ((int) fds[a].size() < (int) fds[b].size()) {
        swap(a, b);
      }
      for (auto& f : fds[b]) {
        fds[a].push_back(f);
      }
      p[b] = a;
      fds[b].clear();
    } else {
      int x, y;
      cin >> x >> y;
      x = get(x);
      int ans = 0;
      for (auto& f : fds[x]) {
        if (f.second == y) {
          ans++;
        }
      }
      cout << ans << '\n';
    }
  }
  return 0;
}
