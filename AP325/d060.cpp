/**
 *    author:  wy
 *    created: Mon, 11 Jul 2022 06:38:45 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

const int N = 100010;

int n;
int sum, ans;
int m[N], s[N], t[N];
int b[N << 1], cnt[N << 1];

void Hash() {
  for (int i = 0; i < n; i++) {
    b[i * 2] = s[i];
    b[i * 2 + 1] = t[i];
  }
  int m = n + n;
  sort(b, b + m);
  m = (int) (unique(b, b + m) - b);
  for (int i = 0; i < n; i++) {
    s[i] = (int) (lower_bound(b, b + m, s[i]) - b);
    t[i] = (int) (lower_bound(b, b + m, t[i]) - b);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> m[i] >> s[i] >> t[i];
  }
  Hash();
  int mx = 0;
  for (int i = 0; i < n; i++) {
    cnt[s[i]] += m[i];
    cnt[t[i] + 1] -= m[i];
    mx = max(mx, max(s[i], t[i] + 1));
  }
  for (int i = 0; i <= mx; i++) {
    sum += cnt[i];
    ans = max(ans, sum);
  }
  cout << ans << '\n';
  return 0;
}
