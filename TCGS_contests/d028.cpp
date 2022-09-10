/**
 *    author:  willy
 *    created: Sat, 06 Nov 2021 15:38:14 GMT
**/
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

const int N = 100;

bool vis[N][N];
queue< pair<int, int> > que;
pair<int, int> from[N][N];
vector< pair<int, int> > ans;

void init() {
  memset(vis, false, sizeof(vis));
  memset(from, -1, sizeof(from));
  que.push(make_pair(0, 0));
}

void print(int l, int r) {
  pair<int, int> prv = from[l][r];
  if (l == 0 && r == 0) {
    ans.push_back(make_pair(l, r));
  } else {
    print(prv.first, prv.second);
    ans.push_back(make_pair(l, r));
  }
}

bool bfs(int a, int b, int c) {
  init();
  while (!que.empty()) {
    int l = que.front().first;
    int r = que.front().second;
    que.pop();
    vis[l][r] = true;
    if (l == c || r == c) {
      print(l, r);
      return true;
    }
    if (l != a) {
      if (!vis[a][r]) {
        que.push(make_pair(a, r));
        from[a][r] = make_pair(l, r);
      }
    }
    if (l != 0) {
      int amount = min(l, b - r);
      int nl = l - amount;
      int nr = r + amount;
      if (!vis[nl][nr]) {
        que.push(make_pair(nl, nr));
        from[nl][nr] = make_pair(l, r);
      }
    }
    if (r != 0) {
      if (!vis[l][0]) {
        que.push(make_pair(l, 0));
        from[l][0] = make_pair(l, r);
      }
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  if (!bfs(a, b, c)) {
    cout << "NO" << '\n';
    return 0;
  }
  for (int i = 0; i < (int) ans.size(); i++) {
    if (i > 0) {
      cout << "->";
    }
    cout << '(' << ans[i].first << ',' << ans[i].second << ')';
  }
  cout << '\n';
  return 0;
}
