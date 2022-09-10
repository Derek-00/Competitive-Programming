/**
 *    author:  willy
 *    created: Fri, 26 Nov 2021 19:59:30 GMT
**/
#include <bits/stdc++.h>

using namespace std;

const int md = (int) 1e9 + 7;

inline int Add(int u, int v) {
  u += v - md;
  u += md & (u >> 31);
  return u;
}

inline int Mul(int u, int v) {
  return (long long) u * v % md;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int N = 2000;
  vector<vector<int>> C(N + 1, vector<int>(N + 1));
  C[0][0] = 1;
  for (int i = 1; i <= N; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = Add(C[i - 1][j], C[i - 1][j - 1]);
    }
  }
  int n, k;
  cin >> n >> k;
  n -= k;
  for (int i = 1; i <= k; i++) {
    cout << Mul(C[n + 1][i], C[k - 1][i - 1]) << '\n';
  }
  return 0;
}
