/**
 *    author:  willy
 *    created: Thu, 05 Aug 2021 14:06:32 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  a[0] = (int) 1e9;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> st(1, 0);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    while (a[st.back()] <= a[i]) {
      st.pop_back();
    }
    ans += i - st.back();
    st.push_back(i);
  }
  cout << ans << '\n';
  return 0;
}
