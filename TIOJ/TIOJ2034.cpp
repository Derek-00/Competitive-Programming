/**
 *    author:  willy
 *    created: Wed, 25 Aug 2021 15:50:39 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  cout << a[0] << " " << a[n - 1] << " ";
  for (int i = 1; i < n; i++) {
    if (a[i] - a[i - 1] != 1) {
      cout << "no" << '\n';
      return 0;
    }
  }
  cout << "yes" << '\n';
  return 0;
}
