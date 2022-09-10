/**
 *    author:  wy
 *    created: Fri, 08 Jul 2022 07:51:41 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 200010;

int n, len;
int l, ans;

int x[N], y[N], idx[N];
deque<int> mx;
deque<int> mn;

inline bool Cmp(int i, int j) {
  if (x[i] == x[j]) {
    return y[i] < y[j];
  }
  return x[i] < x[j];
}

void Insert_mx(int id) {
  while (!mx.empty() && y[idx[mx.back()]] < y[idx[id]]) {
    mx.pop_back();
  }
  mx.push_back(id);
}

void Insert_mn(int id) {
  while (!mn.empty() && y[idx[mn.back()]] > y[idx[id]]) {
    mn.pop_back();
  }
  mn.push_back(id);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> len;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> y[i];
  }
  iota(idx, idx + n, 0);
  sort(idx, idx + n, Cmp);
  for (int i = 0; i < n; i++) {
    while (!mx.empty() && x[idx[i]] - x[idx[mx.front()]] > len) {
      mx.pop_front();
    }
    Insert_mx(i);
    while (!mn.empty() && x[idx[i]] - x[idx[mn.front()]] > len) {
      mn.pop_front();
    }
    Insert_mn(i);
    ans = max(ans, y[idx[mx.front()]] - y[idx[mn.front()]]);
  }
  cout << ans << '\n';
  debug(clock());
  return 0;
}
