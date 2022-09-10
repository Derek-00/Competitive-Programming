/**
 *    author:  willy
 *    created: Mon, 18 Oct 2021 02:00:11 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://leetcode.com/problems/student-attendance-record-ii/

const int abt = 2;
const int lt = 3;
const int md = (int) 1e9 + 7;

int dp[(int) 1e5 + 10][2][3];

int checkRecord(int n) {
  memset(dp, -1, sizeof(dp));
  function<int(int, int, int)> Solve = [&](int n, int a, int l) {
    if (n == 0) {
      return 1;
    }
    if (dp[n][a][l] != -1) {
      return dp[n][a][l];
    }
    int ret = 0;
    ret += Solve(n - 1, a, lt - 1) % md;
    if (a != 0) {
      ret += Solve(n - 1, a - 1, lt - 1) % md;
      ret %= md;
    }
    if (l != 0) {
      ret += Solve(n - 1, a, l - 1) % md;
      ret %= md;
    }
    return dp[n][a][l] = ret;
  };
  return Solve(n, abt - 1, lt - 1);
}
