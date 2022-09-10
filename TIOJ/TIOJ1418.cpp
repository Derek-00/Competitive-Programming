/**
 *    author:  willy
 *    created: Wed, 13 Oct 2021 14:43:41 GMT
**/
#include <bits/stdc++.h>

using namespace std;

const int inf = (int) 1e9;

const int N = 22;
const int B = 1 << N;

int n;
int dp[B];
int cost[N][N];

int Dfs(int bs) {
  if (dp[bs] != -1) {
    return dp[bs];
  }
  int ret = inf;
  int a = __builtin_ctz(bs);
  for (int b = a + 1; b < n; b++) {
    if (!(bs & (1 << b))) continue;
    for (int c = b + 1; c < n; c++) {
      if (!(bs & (1 << c))) continue;
      int w = cost[a][b] + cost[b][c] + cost[c][a];
      ret = min(ret, Dfs(bs ^ (1 << a) ^ (1 << b) ^ (1 << c)) + w);
    }
  }
  return dp[bs] = ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> cost[i][j];
      }
    }
    const int lt = 1 << n;
    for (int i = 1; i < lt; i++) {
      dp[i] = -1;
    }
    cout << Dfs(lt - 1) << '\n';
  }
  return 0;
}
