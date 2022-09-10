/**
 *    author:  willy
 *    created: Sat, 01 Jan 2022 12:50:27 GMT
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long x, k;
  cin >> n >> x >> k;
  vector<array<long long, 2>> pos;
  vector<array<long long, 2>> neg;
  pos.push_back({0, 0});
  neg.push_back({0, 0});
  for (int i = 0; i < n; i++) {
    long long cx, w;
    cin >> cx >> w;
    if (cx > x) {
      pos.push_back({cx - x, w});
    } else {
      neg.push_back({x - cx, w});
    }
  }
  sort(pos.begin(), pos.end());
  sort(neg.begin(), neg.end());
  for (int i = 1; i < (int) pos.size(); i++) {
    pos[i][1] += pos[i - 1][1];
  }
  for (int i = 1; i < (int) neg.size(); i++) {
    neg[i][1] += neg[i - 1][1];
  }
  auto Dist = [&](int l, int r) -> long long {
    return min(pos[r][0] * 2 + neg[l][0], pos[r][0] + neg[l][0] * 2);
  };
  int L = 0, R = 0;
  long long ans = 0;
  for (int i = (int) pos.size() - 1; i >= 0; i--) {
    if (Dist(0, i) <= k) {
      R = i;
      ans += pos[i][1];
      break;
    }
  }
  for (int i = 1; i < (int) neg.size(); i++) {
    if (Dist(i, R) <= k) {
      L = i;
      ans += neg[i][1];
      break;
    }
  }
  while (L + 1 < (int) neg.size() && R >= 0) {
    L += 1;
    while (R > 0 && Dist(L, R) > k) {
      R -= 1;
    }
    if (Dist(L, R) > k) {
      break;
    }
    ans = max(ans, pos[R][1] + neg[L][1]);
  }
  cout << ans << '\n';
  return 0;
}
