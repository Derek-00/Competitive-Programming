/**
 *    author:  wy
 *    created: Fri, 30 Sep 2022 14:45:13 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> s(n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    sum += s[i];
  }
  vector<int> r(n);
  vector<vector<int>> idx(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> r[i];
    idx[r[i]].push_back(i);
  }
  multiset<long long> sa;
  multiset<long long> sb(s.begin(), s.end());
  long long unc = 0;
  for (int i = 0; i < n; i++) {
    for (int id : idx[i]) {
      sa.insert(s[id]);
    }
    if (sa.empty()) {
      unc += *sb.begin();
      sb.erase(sb.begin());
    } else {
      auto it = prev(sa.end());
      auto check = sb.find(*it);
      if (check == sb.end()) {
        unc -= *it;
        unc += *sb.begin();
        sb.erase(sb.begin());
      } else {
        sb.erase(check);
      }
      sa.erase(it);
    }
    cout << sum - unc << " \n"[i == n - 1];
  }
  return 0;
}
