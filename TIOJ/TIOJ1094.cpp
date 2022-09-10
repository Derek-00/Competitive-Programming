/**
 *    author:  willy
 *    created: Thu, 26 Aug 2021 10:30:54 GMT
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n && n) {
    vector<int> bs(N, 0);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      for (int i = N - 1; i >= 0; i--) {
        if (x & (1 << i)) {
          if (bs[i] != 0) {
            x ^= bs[i];
          } else {
            bs[i] = x;
            break;
          }
        }
      }
    }
    int res = 0;
    for (int i = N - 1; i >= 0; i--) {
      if ((res ^ bs[i]) & (1 << i)) {
        res ^= bs[i];
      }
    }
    cout << res << '\n';
  }
  return 0;
}
