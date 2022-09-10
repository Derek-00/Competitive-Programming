/**
 *    author:  willy
 *    created: Sat, 06 Nov 2021 07:29:49 GMT
**/
#include <iostream>
#include <vector>

using namespace std;

bool valid(int x) {
  string res = "";
  while (x > 0) {
    res += (char) (x % 10 - '0');
    x /= 10;
  }
  for (int i = 0; i < (int) res.size(); i++) {
    if (res[i] != res[res.size() - i - 1]) {
      return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> prime;
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; i++) {
    if (is_prime[i]) {
      prime.push_back(i);
      for (int j = i * i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
  for (int i = 0; i < (int) prime.size(); i++) {
    if (valid(prime[i])) {
      cout << prime[i] << " ";
    }
  }
  cout << '\n';
  return 0;
}
