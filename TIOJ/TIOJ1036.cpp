/**
 *    author:  willy
 *    created: Sun, 29 Aug 2021 13:12:49 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 10000000;

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> prime;
  vector<bool> is_prime(N + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= N; i++) {
    if (is_prime[i]) {
      prime.push_back(i);
      for (int j = i * i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    cout << (int) (upper_bound(prime.begin(), prime.end(), n) - prime.begin()) << '\n';
  }
  return 0;
}
