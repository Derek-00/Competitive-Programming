#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n) {
    vector<vector<int>> node(n);
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      node[a].push_back(b);
      node[b].push_back(a);
    }
    vector<int> distance(n);
    vector<bool> chosen(n, false);
    function<void(int)> dfs = [&](int idx) {
      for (auto i : node[idx]) {
        if (chosen[i]) continue;
        distance[i] = distance[idx] + 1;
        chosen[i] = true;
        dfs(i);
      }
    };
    chosen[0] = true;
    dfs(0);
    int mx = (int) (max_element(distance.begin(), distance.end()) - distance.begin());
    distance.clear(); distance.resize(n);
    chosen.clear(); chosen.resize(n, false);
    chosen[mx] = true;
    dfs(mx);
    cout << *max_element(distance.begin(), distance.end()) << '\n';
  }
  return 0;
}
