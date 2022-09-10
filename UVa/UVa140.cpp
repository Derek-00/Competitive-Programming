/**
 *    author:  willy
 *    created: Sat, 21 Aug 2021 10:19:19 GMT
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 10;
const int ALPHA = 256;

int id[ALPHA];
int letter[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  while (cin >> s && s[0] != '#') {
    int n = 0;
    for (char ch = 'A'; ch <= 'Z'; ch++) {
      if (find(s.begin(), s.end(), ch) != s.end()) {
        id[ch] = n++;
        letter[id[ch]] = ch;
      }
    }
    int len = (int) s.size();
    int p = 0, q = 0;
    vector<int> u;
    vector<int> v;
    while (true) {
      while (p < len && s[p] != ':') {
        p++;
      }
      if (p == len) {
        break;
      }
      while (q < len && s[q] != ';') {
        q++;
      }
      for (int i = p + 1; i < q; i++) {
        u.push_back(id[s[p - 1]]);
        v.push_back(id[s[i]]);
      }
      ++p; ++q;
    }
    vector<int> P(n);
    vector<int> best_P;
    vector<int> pos(n);
    iota(P.begin(), P.end(), 0);
    best_P.reserve(n);
    int ans = n;
    do {
      for (int i = 0; i < n; i++) {
        pos[P[i]] = i;
      }
      int bandwidth = 0;
      for (int i = 0; i < (int) u.size(); i++) {
        bandwidth = max(bandwidth, abs(pos[u[i]] - pos[v[i]]));
      }
      if (bandwidth < ans) {
        ans = bandwidth;
        best_P = P;
      }
    } while (next_permutation(P.begin(), P.end()));
    for (int i = 0; i < n; i++) {
      cout << (char) letter[best_P[i]] << " ";
    }
    cout << "-> " << ans << '\n';
  }
  return 0;
}
