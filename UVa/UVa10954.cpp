/**
 *    author:  willy
 *    created: Sat, 31 Jul 2021 15:44:53 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n && n) {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; i++) {
      long long x;
      cin >> x;
      pq.push(x);
    }
    long long cost = 0;
    while ((int) pq.size() > 1) {
      long long a = pq.top(); pq.pop();
      long long b = pq.top(); pq.pop();
      cost += a + b;
      pq.push(a + b);
    }
    cout << cost << '\n';
  }
  return 0;
}
