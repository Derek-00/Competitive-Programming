/**
 *    author:  willy
 *    created: Tue, 26 Oct 2021 14:52:16 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// Mo's algorithm

vector<int> Hash(const vector<int>& a) {
  vector<int> h(a.begin(), a.end());
  sort(h.begin(), h.end());
  h.resize(unique(h.begin(), h.end()) - h.begin());
  vector<int> ret((int) a.size());
  for (int i = 0; i < (int) a.size(); i++) {
    ret[i] = (int) (lower_bound(h.begin(), h.end(), a[i]) - h.begin());
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<pair<int, int>> segs(q);
  for (int i = 0; i < q; i++) {
    cin >> segs[i].first >> segs[i].second;
    --segs[i].first; --segs[i].second;
  }
  const int sqt = (int) sqrt(n) + 1;
  vector<int> order(q);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    auto a = make_pair(segs[i].first / sqt, segs[i].second / sqt);
    auto b = make_pair(segs[j].first / sqt, segs[j].second / sqt);
    return a < b;
  });
  a = Hash(a);
  vector<int> app(n);
  vector<int> ans(q);
  int cnt = 0;
  auto Add = [&](int id) {
    if (app[a[id]]++ == 0) cnt++;
  };
  auto Sub = [&](int id) {
    if (--app[a[id]] == 0) cnt--;
  };
  int l = 0, r = -1;
  for (auto& id : order) {
    while (r < segs[id].second) Add(++r);
    while (r > segs[id].second) Sub(r--);
    while (l < segs[id].first) Sub(l++);
    while (l > segs[id].first) Add(--l);
    ans[id] = cnt;
  }
  for (auto& v : ans) {
    cout << v << '\n';
  }
  return 0;
}
