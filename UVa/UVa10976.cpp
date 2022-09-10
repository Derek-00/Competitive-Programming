/**
 *    author:  willy
 *    created: Tue, 17 Aug 2021 02:40:09 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k;
  while (cin >> k) {
    vector<int> X;
    vector<int> Y;
    for (int y = k + 1; y <= k * 2; y++) {
      if (k * y % (y - k) == 0) {
        X.push_back(k * y / (y - k));
        Y.push_back(y);
      }
    }
    assert(X.size() == Y.size());
    int sz = (int) X.size();
    cout << sz << '\n';
    for (int i = 0; i < sz; i++) {
      cout << "1/" << k << " = 1/" << X[i] << " + 1/" << Y[i] << '\n';
    }
  }
  return 0;
}
