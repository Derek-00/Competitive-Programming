/**
 *    author:  willy
 *    created: Fri, 05 Nov 2021 15:35:51 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long s;
  cin >> n >> s;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int l = 0;
  long long sum = 0;
  int mx = 0;
  for (int r = 0; r < n; r++) {
    sum += a[r];
    while (sum > s) {
      sum -= a[l++];
    }
    mx = max(mx, r - l + 1);
  }
  cout << mx << '\n';
  return 0;
}
