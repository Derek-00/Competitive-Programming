#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    map<set<int>, int> IDcache;
    vector<set<int>> Setcache;
    stack<int> s;
    auto ID = [&](set<int> x) {
      if (IDcache.count(x)) return IDcache[x];
      Setcache.push_back(x);
      return IDcache[x] = (int) (Setcache.size() - 1);
    };
    int n;
    cin >> n;
    while (n--) {
      string op;
      cin >> op;
      if (op[0] == 'P') {
        s.push(ID(set<int> ()));
      } else if (op[0] == 'D') {
        s.push(s.top());
      } else {
        set<int> x1 = Setcache[s.top()]; s.pop();
        set<int> x2 = Setcache[s.top()]; s.pop();
        set<int> x;
        if (op[0] == 'U') set_union(x1.begin(), x1.end(), x2.begin(), x2.end(), inserter(x, x.begin()));
        if (op[0] == 'I') set_intersection(x1.begin(), x1.end(), x2.begin(), x2.end(), inserter(x, x.begin()));
        if (op[0] == 'A') {
          x = x2;
          x.insert(ID(x1));
        }
        s.push(ID(x));
      }
      cout << (int) Setcache[s.top()].size() << '\n';
    }
    cout << "***\n";
  }
  return 0;
}
