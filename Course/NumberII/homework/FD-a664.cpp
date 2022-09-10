/**
 *    author:  willy
 *    created: Sun, 31 Oct 2021 10:56:00 GMT
**/
#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> Get(long long a) {
  vector<pair<int, int>> fact;
  for (int i = 2; i * i <= a; i++) {
    if (a % i == 0) {
      fact.emplace_back(i, 0);
      while (a % i == 0) {
        fact.back().second++;
        a /= i;
      }
    }
  }
  if (a != 1) {
    fact.emplace_back(a, 1);
  }
  return fact;
}

long long power(pair<int, int> f) {
  int x = f.first;
  int k = f.second;
  long long res = 1;
  while (k > 0) {
    if (k & 1) {
      res *= x;
    }
    x *= x;
    k >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long a, b;
  cin >> a >> b;
  long long res = a * b;
  auto fa = Get(a);
  auto fb = Get(b);
  if ((int) fa.size() < (int) fb.size()) { // let size of fa == size of fb (fill 1)
    vector<int> ls;
    int r = 0;
    for (int i = 0; i < (int) fa.size(); i++) {
      while (r < (int) fb.size() && fa[i].first != fb[r].first) {
        ls.push_back(fb[r++].first);
      }
      r++;
    }
    for (int i = r; i < (int) fb.size(); i++) {
      ls.push_back(fb[i].first);
    }
    for (auto& l : ls) {
      fa.emplace_back(l, 0);
    }
    sort(fa.begin(), fa.end());
  }
  assert((int) fa.size() == (int) fb.size());
  int fn = (int) fa.size();
  long long d = (long long) 1e18;
  function<void(int, int)> Dfs = [&](int id, long long prod) {
    if (id == fn) {
      assert(res % prod == 0);
      d = min(d, abs(prod - res / prod));
      return;
    }
    Dfs(id + 1, prod * power(fa[id]));
    Dfs(id + 1, prod * power(fb[id]));
  };
  Dfs(0, 1LL);
  cout << d << '\n';
  return 0;
}
