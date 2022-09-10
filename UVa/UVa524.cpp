/**
 *    author:  willy
 *    created: Thu, 19 Aug 2021 14:40:30 GMT
**/
#include <bits/stdc++.h>

using namespace std;

const int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

bool is_prime(int x) {
  for (const auto p : prime) {
    if (x == p) {
      return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  int Case = 0;
  while (cin >> n) {
    vector<int> a(1, 1);
    vector<bool> vis(n + 1);
    vis[1] = true;
    function<void(int)> dfs = [&](int sz) {
      if (sz == n && is_prime(a[0] + a.back())) {
        for (int i = 0; i < n; i++) {
          cout << a[i] << " \n"[i == n - 1];
        }
        return;
      }
      for (int i = 2; i <= n; i++) {
        if (!vis[i] && is_prime(a.back() + i)) {
          a.push_back(i);
          vis[i] = true;
          dfs(sz + 1);
          a.pop_back();
          vis[i] = false;
        }
      }
    };
    if (Case > 0) {
      cout << '\n';
    }
    cout << "Case " << ++Case << ":\n";
    dfs(1);
  }
  return 0;
}
