#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n && n) {
    queue<int> q;
    vector<int> d;
    for (int i = 1; i <= n; i++) {
      q.push(i);
    }
    while ((int) q.size() >= 2) {
      d.push_back(q.front()); q.pop();
      q.push(q.front()); q.pop();
    }
    cout << "Discarded cards:";
    for (int i = 0; i < (int) d.size(); i++) {
      cout << (i > 0 ? ", " : " ");
      cout << d[i];
    }
    cout << '\n';
    cout << "Remaining card: " << q.front() << '\n';
  }
  return 0;
}
