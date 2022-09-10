/**
 *    author:  willy
 *    created: Fri, 12 Nov 2021 16:01:26 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  const int BLOCK = (int) sqrt(n);
  vector<pair<int, int>> segs(m);
  for (int i = 0; i < m; i++) {
    cin >> segs[i].first >> segs[i].second;
    --segs[i].first; --segs[i].second;
  }
  vector<int> order(m);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    // maybe optimize??
    if (segs[i].first / BLOCK != segs[j].first / BLOCK) {
      return segs[i].first < segs[j].first;
    }
    if ((segs[i].first / BLOCK) & 1) {
      return segs[i].second < segs[j].second;
    }
    return segs[i].second > segs[j].second;
    /*
    if (segs[i].first / BLOCK != segs[j].first / BLOCK) {
      return segs[i].first / BLOCK < segs[j].first / BLOCK;
    }
    return segs[i].second < segs[j].second;
    */
  });
  vector<int> freq(n + 1);
  vector<int> cnt(n + 1);
  vector<pair<int, int>> ans(m);
  int l = 0, r = -1;
  int mx = 0;
  auto Add = [&](int id) {
    int v = s[id];
    cnt[freq[v]]--;
    freq[v]++;
    cnt[freq[v]]++;
    if (cnt[freq[v]] == 1) {
      mx = max(mx, freq[v]);
    }
  };
  auto Del = [&](int id) {
    int v = s[id];
    cnt[freq[v]]--;
    freq[v]--;
    cnt[freq[v]]++;
    if (mx == freq[v] + 1 && cnt[freq[v] + 1] == 0) {
      mx = freq[v];
    }
  };
  for (auto& i : order) {
    while (r < segs[i].second) Add(++r);
    while (r > segs[i].second) Del(r--);
    while (l > segs[i].first) Add(--l);
    while (l < segs[i].first) Del(l++);
    ans[i] = make_pair(mx, cnt[mx]);
  }
  for (int i = 0; i < m; i++) {
    if (i > 0) {
      cout << '\n';
    }
    cout << ans[i].first << " " << ans[i].second;
  }
  cout << '\n';
  return 0;
}
