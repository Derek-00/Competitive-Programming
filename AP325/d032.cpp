/**
 *    author:  wy
 *    created: Fri, 08 Jul 2022 06:51:13 GMT
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
  int n, l;
  cin >> n >> l;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  deque<int> mx = {0};
  deque<int> mn = {0};
  auto Insert_mx = [&](int id) {
    while (!mx.empty() && a[mx.back()] < a[id]) {
      mx.pop_back();
    }
    mx.push_back(id);
  };
  auto Insert_mn = [&](int id) {
    while (!mn.empty() && a[mn.back()] > a[id]) {
      mn.pop_back();
    }
    mn.push_back(id);
  };
  int ans = (int) -1e9;
  for (int i = 1; i < n; i++) {
    while (mx.front() <= i - l) {
      mx.pop_front();
    }
    Insert_mx(i);
    while (mn.front() <= i - l) {
      mn.pop_front();
    }
    Insert_mn(i);
    ans = max(ans, a[mx.front()] - a[mn.front()]);
  }
  cout << ans << '\n';
  return 0;
}
