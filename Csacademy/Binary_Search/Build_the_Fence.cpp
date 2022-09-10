/**
 *    author:  willy
 *    created: Sat, 01 Jan 2022 09:42:40 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  auto Can = [&](int x) {
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += a[i] / x;
      if (cnt >= k) {
        return true;
      }
    }
    return false;
  };
  int low = 0, high = *max_element(a.begin(), a.end());
  while (low < high) {
    int mid = (low + high + 1) >> 1;
    if (Can(mid)) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }
  cout << low << '\n';
  return 0;
}
