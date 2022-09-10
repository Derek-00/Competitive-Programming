/**
 *    author:  willy
 *    created: Fri, 05 Nov 2021 15:16:49 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ptr = 0;
  while (m--) {
    int b;
    cin >> b;
    while (ptr < n && a[ptr] < b) {
      ptr++;
    }
    cout << ptr<< " ";
  }
  return 0;
}
