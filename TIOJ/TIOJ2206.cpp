/**
 *    author:  willy
 *    created: Sat, 18 Sep 2021 13:57:47 GMT
**/
#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 10;

int f[N];

int Solve(int a, int b) {
  if (b == 0) {
    return a;
  }
  return Solve(f[a], b - 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> f[i];
  }
  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << Solve(a, b) << '\n';
  }
  return 0;
}
