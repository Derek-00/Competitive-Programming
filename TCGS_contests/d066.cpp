/**
 *    author:  willy
 *    created: Sat, 06 Nov 2021 08:00:11 GMT
**/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class dsu {
 public:
  vector<int> p;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    for (int i = 0; i < n; i++) {
      p[i] = i;
    }
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

struct edge {
  int from;
  int to;
  int cost;

  edge(int from, int to, int cost) : from(from), to(to), cost(cost) {
  }

  inline bool operator < (const edge& other) const {
    return cost < other.cost;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  map<string, int> mp;
  vector<string> names;
  int id = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    mp[s] = id++;
    names.push_back(s);
  }
  vector<edge> edges;
  for (int i = 0; i < m; i++) {
    string a, b;
    int w;
    cin >> a >> b >> w;
    int u = mp[a], v = mp[b];
    edges.push_back(edge(u, v, w));
  }
  sort(edges.begin(), edges.end());
  vector<pair<int, int> > ans;
  dsu d(n);
  int cost = 0;
  for (int i = 0; i < m; i++) {
    edge& e = edges[i];
    if (d.unite(e.from, e.to)) {
      ans.push_back(make_pair(min(e.from, e.to), max(e.from, e.to)));
      cost += e.cost;
    }
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << '(' << names[ans[i].first] << " " << names[ans[i].second] << ')';
  }
  cout << '\n';
  cout << cost << '\n';
  return 0;
}
