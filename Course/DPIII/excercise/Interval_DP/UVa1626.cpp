/**
 *    author:  willy
 *    created: Sat, 09 Oct 2021 14:20:35 GMT
**/
#include <bits/stdc++.h>

using namespace std;

// problem URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=825&page=show_problem&problem=4501

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  string foo = "";
  getline(cin, foo);
  while (tt--) {
    getline(cin, foo);
    string s;
    getline(cin, s);
    int n = (int) s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n; i++) {
      dp[i][i] = 1;
      dp[i + 1][i] = 0;
    }
    auto match = [&](char l, char r) {
      return ((l == '(' && r == ')') || (l == '[' && r == ']'));
    };
    const int MAX = 12345;
    for (int l = n - 2; l >= 0; l--) {
      for (int r = l + 1; r < n; r++) {
        dp[l][r] = (match(s[l], s[r]) ? dp[l + 1][r - 1] : MAX);
        for (int k = l; k < r; k++) {
          dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
        }
      }
    }
    function<void(int, int)> print = [&](int l, int r) {
      if (l > r) {
        return;
      }
      if (l == r) {
        cout << (s[l] == '(' || s[l] == ')' ? "()" : "[]");
        return;
      }
      if (match(s[l], s[r]) && dp[l + 1][r - 1] == dp[l][r]) {
        cout << s[l];
        print(l + 1, r - 1);
        cout << s[r];
      } else {
        for (int k = l; k < r; k++) {
          if (dp[l][k] + dp[k + 1][r] == dp[l][r]) {
            print(l, k);
            print(k + 1, r);
            break;
          }
        }
      }
    };
    print(0, n - 1);
    cout << '\n';
    if (tt) {
      cout << '\n';
    }
  }
  return 0;
}
