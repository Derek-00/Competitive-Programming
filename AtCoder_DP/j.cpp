/**
 *    author:  willy
 *    created: Tue, 07 Dec 2021 07:30:47 GMT
**/
#include <bits/stdc++.h>

using namespace std;

double dp[400][400][400];

double Solve(int n, int a, int b, int c) {
  if (a == 0 && b == 0 && c == 0) {
    return dp[a][b][c] = 0;
  }
  if (dp[a][b][c] > 0) {
    return dp[a][b][c];
  }
  double ans = (double) 1.0 * n / (a + b + c);
  if (a > 0) {
    ans += (double) (1.0 * a / (a + b + c)) * Solve(n, a - 1, b, c);
  }
  if (b > 0) {
    ans += (double) (1.0 * b / (a + b + c)) * Solve(n, a + 1, b - 1, c);
  }
  if (c > 0) {
    ans += (double) (1.0 * c / (a + b + c)) * Solve(n, a, b + 1, c - 1);
  }
  return dp[a][b][c] = ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> cnt(4);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    cnt[a]++;
  }
  cout << fixed << setprecision(17) << Solve(n, cnt[1], cnt[2], cnt[3]) << '\n';
  return 0;
}
