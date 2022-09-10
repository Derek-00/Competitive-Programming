/**
 *    author:  willy
 *    created: Wed, 03 Nov 2021 12:35:20 GMT
**/
#include <iostream>
#include <vector>

using namespace std;

const long long MAX = (long long) 955049953;

long long crt(const vector<long long>& p, const vector<long long>& r) {
  long long n = 1;
  long long ans = 0;
  for (int i = 0; i < (int) p.size(); i++) {
    while (ans % p[i] != r[i]) {
      ans += n;
      if (ans >= MAX) {
        return -1;
      }
    }
    n = min(n * p[i], MAX);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<long long> p(n);
    vector<long long> r(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i] >> r[i];
    }
    long long ans = crt(p, r);
    cout << ans << '\n';
  }
  return 0;
}
