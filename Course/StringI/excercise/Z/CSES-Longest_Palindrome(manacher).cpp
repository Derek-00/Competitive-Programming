/**
 *    author:  willy
 *    created: Wed, 01 Dec 2021 12:08:03 GMT
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
vector<int> manacher(int n, const T &s) {
  if (n == 0) {
    return vector<int>();
  }
  vector<int> res(2 * n - 1, 0);
  int l = -1, r = -1;
  for (int z = 0; z < 2 * n - 1; z++) {
    int i = (z + 1) >> 1;
    int j = z >> 1;
    int p = (i >= r ? 0 : min(r - i, res[2 * (l + r) - z]));
    while (j + p + 1 < n && i - p - 1 >= 0) {
      if (!(s[j + p + 1] == s[i - p - 1])) {
        break;
      }
      p++;
    }
    if (j + p > r) {
      l = i - p;
      r = j + p;
    }
    res[z] = p;
  }
  return res;
  // res[2 * i] = odd radius in position i
  // res[2 * i + 1] = even radius between positions i and i + 1
  // s = "abaa" -> res = {0, 0, 1, 0, 0, 1, 0}
  // in other words, for every z from 0 to 2 * n - 2:
  // calculate i = (z + 1) >> 1 and j = z >> 1
  // now there is a palindrome from i - res[z] to j + res[z]
  // (watch out for i > j and res[z] = 0)
}

template <typename T>
vector<int> manacher(const T &s) {
  return manacher((int) s.size(), s);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  auto m = manacher(s);
  int len = -1;
  int id = -1;
  for (int i = 0; i < (int) m.size(); i++) {
    int cur = m[i] + m[i] + (i & 1 ? 0 : 1);
    if (cur > len) {
      len = cur;
      id = i;
    }
  }
  len >>= 1;
  int at = (id >> 1) - len + (id & 1 ? 1 : 0);
  len += m[id] + (id & 1 ? 0 : 1);
  while (len--) {
    cout << s[at++];
  }
  cout << '\n';
  return 0;
}
