/**
 *    author:  willy
 *    created: Mon, 27 Dec 2021 13:35:46 GMT
**/
#include <bits/stdc++.h>

using namespace std;

class dsu {
 public:
  vector<long long> sum;
  vector<int> p;
  int n;

  dsu(const vector<long long>& _sum) : sum(_sum) {
    n = (int) sum.size();
    p.resize(n + 1);
    iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline long long Get(int x) {
    return sum[x] = sum[get(x)];
  }

  inline void unite(int x, int y) {
    x = get(x);
    y = get(y);
    long long new_sum = Get(x) + Get(y);
    sum[x] = sum[y] = new_sum;
    if (x != y) {
      p[x] = y;
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> order(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> order[i];
  }
  vector<bool> vis(n + 2, false);
  dsu d(a);
  vector<long long> ans(n + 1);
  long long mx = (int) -1e18;
  for (int i = n; i >= 1; i--) {
    vis[order[i]] = true;
    if (vis[order[i] + 1]) {
      d.unite(order[i], order[i] + 1);
    }
    if (vis[order[i] - 1]) {
      d.unite(order[i], order[i] - 1);
    }
    mx = max(mx, d.Get(order[i]));
    ans[i] = mx;
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}
