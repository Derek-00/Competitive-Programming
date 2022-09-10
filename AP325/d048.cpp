/**
 *    author:  wy
 *    created: Fri, 08 Jul 2022 15:01:43 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

int n;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pq.push(x);
  }
  long long ans = 0;
  while ((int) pq.size() >= 2) {
    long long a = pq.top(); pq.pop();
    long long b = pq.top(); pq.pop();
    pq.push(a + b);
    ans += (long long) (a + b);
  }
  cout << pq.top() << '\n';
  cout << ans << '\n';
  return 0;
}
