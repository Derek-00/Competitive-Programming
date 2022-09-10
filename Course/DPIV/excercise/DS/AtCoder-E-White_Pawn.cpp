/**
 *    author:  willy
 *    created: Fri, 03 Dec 2021 05:29:56 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> c(m);
  for (int i = 0; i < m; i++) {
    cin >> c[i].first >> c[i].second;
  }
  sort(c.begin(), c.end());
  set<int> s;
  s.insert(n);
  int l = 0, r = 0;
  while (l < m) {
    while (r + 1 < m && c[r + 1].first == c[l].first) {
      r += 1;
    }
    vector<int> ins;
    vector<int> del;
    for (int i = l; i <= r; i++) {
      int y = c[i].second;
      del.push_back(y);
      if (y > 0 && s.find(y - 1) != s.end()) {
        ins.push_back(y);
      }
      if (y + 1 <= n + n && s.find(y + 1) != s.end()) {
        ins.push_back(y);
      }
    }
    for (int i = 0; i < (int) del.size(); i++) {
      s.erase(del[i]);
    }
    for (int i = 0; i < (int) ins.size(); i++) {
      s.insert(ins[i]);
    }
    l = r + 1;
  }
  cout << (int) s.size() << '\n';
  return 0;
}
