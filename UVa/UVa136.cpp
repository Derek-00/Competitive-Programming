#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int coeff[] = {2, 3, 5};
  priority_queue<int, vector<int>, greater<int>> pq;
  set<int> s;
  pq.push(1);
  s.insert(1);
  for (int i = 1; i < 1500; i++) {
    int x = pq.top(); pq.pop();
    for (int l = 0; l < 3; l++) {
      int x2 = x * coeff[l];
      if (!s.count(x2)) {
        s.insert(x2);
        pq.push(x2);
      }
    }
  }
  cout << "The 1500'th ugly number is " << pq.top() << ".\n";
  return 0;
}
