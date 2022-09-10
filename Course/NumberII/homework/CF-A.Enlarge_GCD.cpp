/**
 *    author:  willy
 *    created: Thu, 28 Oct 2021 16:09:31 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int all = 0;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    all = __gcd(all, a[i]);
  }
  const int N = (int) 1.5e7;
  vector<int> fact(N + 1, 0);
  for (int i = 0; i < n; i++) {
    fact[a[i] / all]++;
  }
  vector<bool> be(N + 1, true);
  be[0] = be[1] = false;
  int ans = 0;
  for (int i = 2; i <= N; i++) {
    if (be[i]) {
      int sum = 0;
      for (int j = i; j <= N; j += i) {
        be[j] = false;
        sum += fact[j];
      }
      ans = max(ans, sum);
    }
  }
  cout << (ans == 0 ? -1 : n - ans) << '\n';
  return 0;
}
