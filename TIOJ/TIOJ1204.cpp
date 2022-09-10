/**
 *    author:  willy
 *    created: Thu, 12 Aug 2021 09:55:57 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n && n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> ans;
    function<void(int, int)> dfs = [&](int l, int r) {
      if (l >= r) {
        return;
      }
      int id = (int) (min_element(a.begin() + l, a.begin() + r) - a.begin());
      ans.push_back(a[id]);
      dfs(l, id);
      dfs(id + 1, r);
    };
    dfs(0, n);
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " \n"[i == n - 1];
    }
  }
  return 0;
}
