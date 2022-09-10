/**
 *    author:  willy
 *    created: Fri, 13 Aug 2021 13:34:25 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n && n) {
    map<int, array<vector<int>, 2>> mp;
    multiset<int> ms = {0};
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
      int l, h, r;
      cin >> l >> h >> r;
      mp[l][0].push_back(h);
      mp[r][1].push_back(h);
    }
    for (const auto &v : mp) {
      int p = v.first;
      const auto &in = v.second[0];
      const auto &out = v.second[1];
      for (int h : in) {
        ms.insert(h);
      }
      for (int h : out) {
        ms.erase(ms.find(h));
      }
      int h = *prev(ms.end());
      if (ans.empty() || ans.back().second != h) {
        ans.emplace_back(p, h);
      }
    }
    for (int i = 0; i < (int) ans.size(); i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << ans[i].first << " " << ans[i].second;
    }
    cout << '\n';
  }
  return 0;
}
