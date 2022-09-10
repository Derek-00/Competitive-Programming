#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  int kase = 0;
  map<int, int> team;
  while (cin >> t && t) {
    cout << "Scenario #" << ++kase << '\n';
    for (int i = 0; i < t; i++) {
      int n;
      cin >> n;
      while (n--) {
        int x;
        cin >> x;
        team[x] = i; // to know that x is at which team.
      }
    }
    queue<int> q; // team queue
    vector<queue<int>> q2(t); // the numbers queue in team queue
    while (true) {
      string cmd;
      cin >> cmd;
      if (cmd[0] == 'S') break;
      if (cmd[0] == 'D') {
        int t = q.front();
        cout << q2[t].front() << '\n';
        q2[t].pop();
        if (q2[t].empty()) q.pop();
      } else if (cmd[0] == 'E') {
        int x;
        cin >> x;
        int t = team[x];
        if (q2[t].empty()) q.push(t);
        q2[t].push(x);
      }
    }
    cout << '\n';
  }
  return 0;
}
