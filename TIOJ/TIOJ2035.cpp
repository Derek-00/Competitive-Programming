/**
 *    author:  willy
 *    created: Wed, 25 Aug 2021 16:03:07 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int to_digit(int x, int k) {
  int res = 0;
  int sq = 1;
  string s = to_string(x);
  reverse(s.begin(), s.end());
  for (int i = 0; i < (int) s.size(); i++) {
    res += (s[i] - '0') * sq;
    sq *= k;
  }
  return res;
}

int power(int x, int k) {
  int res = 1;
  while (k > 0) {
    if (k & 1) {
      res *= x;
    }
    x *= x;
    k >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int b, n;
  cin >> b >> n;
  int digit = to_digit(n, b);
  int d = (int) to_string(n).size();
  int after = 0;
  while (n > 0) {
    int tmp = n % 10;
    after += power(tmp, d);
    n /= 10;
  }
  cout << (after == digit ? "YES" : "NO") << '\n';
  return 0;
}
