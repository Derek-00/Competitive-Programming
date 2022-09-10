/**
 *    author:  willy
 *    created: Sat, 30 Oct 2021 09:39:40 GMT
**/
#include <bits/stdc++.h>

using namespace std;

const int N = (int) 5e6;

array<int, N> phi;
array<long long, N> S;
map<long long, long long> new_S;

void init() {
  phi[1] = 1;
  for (int i = 2; i < N; i++) {
    if (phi[i] == 0) {
      for (int j = i; j < N; j += i) {
        if (phi[j] == 0) {
          phi[j] = j;
        }
        phi[j] -= phi[j] / i;
      }
    }
  }
  for (int i = 1; i < N; i++) {
    S[i] = (long long) (S[i - 1] + phi[i]);
  }
}

long long Phi(long long n) {
  if (n == 0) {
    return 0;
  }
  if (n < N) {
    return S[n];
  }
  if (new_S[n] != 0) {
    return new_S[n];
  }
  long long c = 0;
  long long j = 2;
  long long k = n / j;
  while (k > 1) {
    long long nj = n / k + 1;
    c += (nj - j) * (2 * Phi(k) - 1);
    j = nj;
    k = n / nj;
  }
  return new_S[n] = (n * (n - 1) - c + j) / 2;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  init();
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    cout << Phi(1LL * n) << '\n';
  }
  return 0;
}
