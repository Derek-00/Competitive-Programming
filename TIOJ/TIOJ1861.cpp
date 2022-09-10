/**
 *    author:  willy
 *    created: Thu, 26 Aug 2021 09:11:27 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n) {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      pq.push(1LL * x);
    }
    long long ans = 0;
    while ((int) pq.size() > 1) {
      int a = pq.top(); pq.pop();
      int b = pq.top(); pq.pop();
      int sum = a + b;
      ans += 1LL * sum;
      pq.push(1LL * sum);
    }
    cout << ans << '\n';
  }
  return 0;
}
