/**
 *    author:  willy
 *    created: Thu, 26 Aug 2021 14:09:17 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }
  vector<long long> stk;
  vector<long long> R(n + 1);
  for (int i = n; i >= 0; i--) {
    while (!stk.empty() && a[i] <= a[stk.back()]) {
      stk.pop_back();
    }
    R[i] = (stk.empty() ? n : stk.back() - 1) - i;
    stk.push_back(i);
  }
  long long sum = accumulate(R.begin(), R.end(), 0);
  cout << n * (n + 1) / 2 - sum << '\n';
  return 0;
}
