/**
 *    author:  willy
 *    created: Mon, 13 Dec 2021 08:38:26 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, r;
  cin >> n >> r;
  string s;
  cin >> s;
  auto Get = [&](string s) {
    int x = 0;
    for (auto& c : s) {
      x += (int) (c - '0');
    }
    while (x >= 10) {
      int nx = 0;
      while (x > 0) {
        nx += x % 10;
        x /= 10;
      }
      swap(x, nx);
    }
    return x;
  };
  auto its = [&](int x) {
    stringstream ss;
    string res;
    ss << x;
    ss >> res;
    return res;
  };
  vector<string> ans;
  for (int i = 0; i <= (int) s.size(); i++) {
    for (int j = 0; j < 10; j++) {
      string res = s.substr(0, i) + its(j) + s.substr(i);
      auto new_root = Get(res);
      if (new_root == r) {
        ans.push_back(res);
      }
    }
  }
  sort(ans.begin(), ans.end());
  ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
  for (int i = 1; i < (int) ans.size() - 1; i++) {
    if (i > 1) {
      cout << '\n';
    }
    cout << ans[i];
  }
  cout << '\n';
  return 0;
}
