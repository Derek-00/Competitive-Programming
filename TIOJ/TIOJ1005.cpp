#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n && n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int total = n * (n - 1) / 2;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (__gcd(a[i], a[j]) == 1) ++cnt;
      }
    }
    if (cnt == 0) {
      cout << "No estimate for this data set.\n";
      continue;
    }
    int ans = 6 * total;
    cout << fixed << setprecision(6) << sqrt(ans * 1.0 / cnt) << '\n';
  }
  return 0;
}
