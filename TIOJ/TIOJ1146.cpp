#include <bits/stdc++.h>

using namespace std;

class matrix {
 public:
  int n;
  vector<vector<int>> m;

  matrix(int _n) : n(_n) {
    m = vector<vector<int>>(n, vector<int>(n));
  }

  matrix operator * (const matrix b) {
    matrix ans(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int l = 0; l < n; l++) {
          ans.m[i][j] += m[i][l] * b.m[l][j];
        }
      }
    }
    return ans;
  }

  void init() {
    for (int i = 0; i < n; i++) {
      m[i][i] = 1;
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // A[N][i][j] = X[N - 1][i][k] + Y[N - 1][k][j], k = 0, 1, ..., n - 1
  int n;
  while (cin >> n) {
    matrix adj(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        char s;
        cin >> s;
        adj.m[i][j] = s - '0';
      }
    }
    int a, b, k;
    cin >> a >> b >> k;
    --a; --b;
    matrix tmp(n); tmp.init();
    int ans = 0;
    for (int i = 0; i < k; i++) {
      tmp = tmp * adj;
      ans += tmp.m[a][b];
    }
    cout << ans << '\n';
  }
  return 0;
}
