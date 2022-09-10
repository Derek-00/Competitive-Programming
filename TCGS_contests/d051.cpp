/**
 *    author:  willy
 *    created: Thu, 11 Nov 2021 01:29:02 GMT
**/
#include <iostream>
#include <vector>

using namespace std;

vector<int> ra;
vector<int> rb;
vector< pair<int, int> > c;
int ans;
int xa, ya, xb, yb;
int m;

inline int dist(int xa, int ya, int xb, int yb) {
  return (xb - xa) * (xb - xa) + (yb - ya) * (yb - ya);
}

void Dfs(int id) {
  if (id == m) {
    int nra = 0;
    for (int i = 0; i < (int) ra.size(); i++) {
      nra = max(nra, ra[i]);
    }
    int nrb = 0;
    for (int i = 0; i < (int) rb.size(); i++) {
      nrb = max(nrb, rb[i]);
    }
    ans = min(ans, nra + nrb);
    return;
  }
  ra.push_back(dist(c[id].first, c[id].second, xa, ya));
  Dfs(id + 1);
  ra.pop_back();
  rb.push_back(dist(c[id].first, c[id].second, xb, yb));
  Dfs(id + 1);
  rb.pop_back();
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> xa >> ya >> xb >> yb;
    cin >> m;
    c.resize(m);
    for (int i = 0; i < m; i++) {
      cin >> c[i].first >> c[i].second;
    }
    ans = (int) 1e9;
    Dfs(0);
    cout << ans << endl;
  }
  return 0;
}
