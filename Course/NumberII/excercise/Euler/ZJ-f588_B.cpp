/**
 *    author:  willy
 *    created: Sat, 30 Oct 2021 12:29:19 GMT
**/
#include <bits/stdc++.h>

using namespace std;

const int N = (int) 5e6;

int cur = 0;
array<bool, N> vis;
array<long long, N> mu;
array<long long, N> pri;
array<long long, N> pref;
map<long long, long long> big_pref;

void init() {
  mu[1] = 1;
  for (int i = 2; i < N; i++) {
    if (!vis[i]) {
      pri[++cur] = i;
      mu[i] = -1;
    }
    for (int j = 1; j <= cur && i * pri[j] < N; j++) {
      vis[i * pri[j]] = true;
      if (i % pri[j] != 0) {
        mu[i * pri[j]] = -mu[i];
      } else {
        mu[i * pri[j]] = 0;
        break;
      }
    }
  }
  for (int i = 1; i < N; i++) {
    pref[i] = pref[i - 1] + mu[i];
  }
}

long long Mu(long long x) {
  if (x < N) {
    return pref[x];
  }
  if (big_pref[x] != 0) {
    return big_pref[x];
  }
  long long ret = 1LL;
  long long j = 0;
  for (long long i = 2; i <= x; i = j + 1) {
    j = x / (x / i);
    ret -= Mu(x / i) * (j - i + 1);
  }
  return big_pref[x] = ret;
}

long long Phi(long long n) {
  long long ret = 0LL;
  long long j = 1;
  for (long long i = 1; i <= n; i = j + 1) {
    j = n / (n / i);
    ret += (Mu(j) - Mu(i - 1)) * (n / i) * (n / i);
  }
  return (ret - 1) / 2 + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  init();
  int tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    cout << Phi(n) << endl;
  }
  return 0;
}
