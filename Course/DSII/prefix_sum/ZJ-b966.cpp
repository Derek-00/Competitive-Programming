/**
 *    author:  willy
 *    created: Thu, 21 Oct 2021 11:32:38 GMT
**/
#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e7 + 5;

array<int, N> tag;
array<int, N> pref;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    tag[a]++;
    tag[b]--;
  }
  int ans = 0;
  pref[0] = tag[0];
  ans += (pref[0] > 0);
  for (int i = 1; i < N; i++) {
    pref[i] = pref[i - 1] + tag[i];
    ans += (pref[i] > 0);
  }
  cout << ans << '\n';
  return 0;
}
