#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char> (m));
    for (int i = 0; i < n; i++) {
      for (int l = 0; l < m; l++) {
        cin >> a[i][l];
      }
    }
    string s;
    for (int i = 0; i < m; i++) {
      vector<int> alpha(26);
      for (int l = 0; l < n; l++) {
        alpha[a[l][i] - 'A']++;
      }
      bool is_same = true;
      for (int k = 1; k < 26; k++) {
        if (alpha[k] != alpha[k - 1]) {
          is_same = false;
          break;
        }
      }
      if (is_same) {
        s += 'A';
      } else {
        int mx = INT_MIN;
        int idx = 0;
        for (int k = 0; k < 26; k++) {
          if (mx < alpha[k]) {
            mx = alpha[k];
            idx = k;
          }
        }
        s += (char) (idx + 'A');
      }
    }
    int counter = 0;
    for (int i = 0; i < m; i++) {
      for (int l = 0; l < n; l++) {
        if (s[i] != a[l][i]) {
          counter++;
        }
      }
    }
    cout << s << '\n' << counter << '\n';
  }
  return 0;
}
