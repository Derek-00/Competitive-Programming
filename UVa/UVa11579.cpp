/**
 *    author:  willy
 *    created: Wed, 04 Aug 2021 11:12:27 GMT
**/
#include <bits/stdc++.h>

using namespace std;

double area(double a, double b, double c) {
  double s = (a + b + c) / 2;
  return s * (s - a) * (s - b) * (s - c);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<double> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    double ans = -1;
    for (int i = 0; i < n - 2; i++) {
      if (a[i] + a[i + 1] > a[i + 2]) {
        ans = max(ans, area(a[i], a[i + 1], a[i + 2]));
      }
    }
    if (ans == -1) {
      cout << "0.00" << '\n';
    } else {
      cout << fixed << setprecision(2) << sqrt(ans) << '\n';
    }
  }
  return 0;
}
