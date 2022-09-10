#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<bool> a;
  while (n > 1) {
    if (n & 1) {
      a.push_back(false);
    } else {
      a.push_back(true);
    }
    n /= 2;
  }
  int ans = 1;
  for (int i = (int) a.size() - 1; i >= 0; i--) {
    if (a[i]) {
      ans = ans * 2 - 1;
    } else {
      ans = ans * 2 + 1;
    }
  }
  cout << ans;
  return 0;
}
