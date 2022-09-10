/**
 *    author:  willy
 *    created: Fri, 10 Dec 2021 14:40:39 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long s = accumulate(a.begin(), a.end(), 0LL);
  long long res = 0;
  for (int i = 0; i < n; i++) {
    res += a[i] * i;
  }
  for (int i = -1; i < max(1, n / 2); i++) {
    if (i != -1) {
      res += i * (a[n - i - 1] - a[i]);
      res += (n - i - 1) * (a[i] - a[n - i - 1]);
      swap(a[i], a[n - i - 1]);
    }
    if (res % s == 0) {
      cout << i + 1 << " " << res / s << '\n';
      return 0;
    }
  }
  return 0;
}
