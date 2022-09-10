/**
 *    author:  willy
 *    created: Fri, 12 Nov 2021 06:28:20 GMT
**/
#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 5;

int p[N];
int val[N], add[N];
vector<int> group[N];

inline int get(int x) {
  return (x == p[x] ? x : (p[x] = get(p[x])));
}

void unite(int x, int y) {
  x = get(x);
  y = get(y);
  if (x != y) {
    if ((int) group[x].size() < (int) group[y].size()) {
      swap(x, y);
    }
    for (auto& v : group[y]) {
      val[v] += add[y] - add[x];
      group[x].push_back(v);
    }
    group[y].clear();
    p[y] = x;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    group[i].push_back(i);
    p[i] = i;
  }
  while (m--) {
    string s;
    cin >> s;
    if (s[0] == 'j') {
      int x, y;
      cin >> x >> y;
      --x; --y;
      unite(x, y);
    }
    if (s[0] == 'a') {
      int x, v;
      cin >> x >> v;
      --x;
      x = get(x);
      add[x] += v;
    }
    if (s[0] == 'g') {
      int x;
      cin >> x;
      --x;
      int p = get(x);
      cout << val[x] + add[p] << '\n';
    }
  }
  return 0;
}
