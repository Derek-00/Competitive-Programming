/**
 *    author:  willy
 *    created: Sun, 15 Aug 2021 12:49:44 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  int now = 0;
  vector<int> stk;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    while (now < x) {
      stk.push_back(++now);
    }
    auto it = find(stk.begin(), stk.end(), x);
    int dist = stk.end() - it;
    if (dist > m + 1) {
      cout << "no" << '\n';
      return 0;
    } else {
      stk.erase(it);
    }
  }
  cout << "yes" << '\n';
  return 0;
}
