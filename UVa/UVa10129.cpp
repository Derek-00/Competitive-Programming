#include <bits/stdc++.h>

using namespace std;

const int maxn = 26;

class dsu {
 public:
   vector<int> p;
   int n;

   dsu(int _n) : n(_n) {
     p = vector<int>(n);
     iota(p.begin(), p.end(), 0);
   }

   inline int get(int x) {
     return (x == p[x] ? x : (p[x] = get(p[x])));
   }

   inline bool unite(int x, int y) {
     x = get(x);
     y = get(y);
     if (x != y) {
       p[x] = y;
       return true;
     }
     return false;
   }
};

inline int conv(char ch) {
  return ch - 'a';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int cc = maxn;
    dsu euler(maxn);
    vector<int> deg(maxn);
    vector<bool> exit(maxn);
    for (int i = 0; i < n; i++) {
      string word;
      cin >> word;
      int left = conv(*word.begin());
      int right = conv(word.back());
      exit[left] = exit[right] = true;
      deg[left]++; deg[right]--;
      if (euler.unite(left, right)) {
        --cc;
      }
    }
    vector<int> d;
    for (int i = 0; i < maxn; i++) {
      if (!exit[i]) {
        --cc;
      } else {
        if (deg[i]) {
          d.push_back(deg[i]);
        }
      }
    }
    bool ok = false;
    if (cc == 1 && (d.empty() || ((int) d.size() == 2 && (*d.begin() == 1 || *d.begin() == -1)))) {
      ok = true;
    }
    cout << (ok ? "Ordering is possible.\n" : "The door cannot be opened.\n");
  }
  return 0;
}
