#include <bits/stdc++.h>

using namespace std;

struct building {
  int id;
  double x, y, w, d, h;

  bool operator < (const building &rhs) const {
    return (x < rhs.x || (x == rhs.x && y < rhs.y));
  }
};

int n;
vector<double> x;
vector<building> b;

inline bool cover(int i, double mx) {
  return (b[i].x <= mx && mx <= b[i].x + b[i].w);
}

bool visible(int i, double mx) {
  if (!cover(i, mx)) return false;
  for (int k = 0; k < n; k++) {
    if (b[k].y < b[i].y && b[k].h >= b[i].h && cover(k, mx)) {
      return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int kase = 0;
  while (cin >> n && n) {
    b.resize(n);
    x.resize(2 * n);
    for (int i = 0; i < n; i++) {
      cin >> b[i].x >> b[i].y >> b[i].w >> b[i].d >> b[i].h;
      x[i * 2] = b[i].x;
      x[i * 2 + 1] = b[i].x + b[i].w;
      b[i].id = i + 1;
    }
    sort(b.begin(), b.end());
    sort(x.begin(), x.end());
    x.resize(unique(x.begin(), x.end()) - x.begin());
    if (kase++) cout << '\n';
    cout << "For map #" << kase << ", the visible buildings are numbered as follows:\n" << b[0].id;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < (int) x.size() - 1; j++) {
        if (visible(i, (x[j] + x[j + 1]) / 2)) {
          cout << ' ' << b[i].id;
          break;
        }
      }
    }
    cout << '\n';
    x.clear();
    b.clear();
  }
  return 0;
}
