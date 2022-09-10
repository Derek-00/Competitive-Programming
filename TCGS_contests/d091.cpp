/**
 *    author:  willy
 *    created: Tue, 09 Nov 2021 14:12:33 GMT
**/
#include <iostream>

using namespace std;

int n;
int mn, val;
int cnt[7];
int neg[7];

void dfs(int id, int diff, int times) {
  if (id > 6) {
    if (abs(diff) == val) {
      mn = min(mn, times);
    }
    if (abs(diff) < val) {
      val = abs(diff);
      mn = times;
    }
    return;
  }
  for (int i = 0; i <= cnt[id]; i++) {
    int ndiff = id * (cnt[id] - 2 * i);
    int nt = abs(i - neg[id]);
    dfs(id + 1, diff + ndiff, times + nt);
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int u, d;
    cin >> u >> d;
    int diff = abs(u - d);
    if (diff == 0) continue;
    cnt[diff]++;
    if (u < d) {
      neg[diff]++;
    }
  }
  mn = (int) 1e9;
  val = (int) 1e9;
  dfs(1, 0, 0);
  cout << mn << endl;
  cout << val << endl;
  return 0;
}
