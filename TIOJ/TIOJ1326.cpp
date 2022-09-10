/**
 *    author:  willy
 *    created: Wed, 25 Aug 2021 16:28:12 GMT
**/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// https://omeletwithoutegg.github.io/2019/12/06/Fast-IO/
inline char readchar() {
	const int S = 1<<20; // buffer size
	static char buf[S], *p = buf, *q = buf;
	if(p == q && (q = (p=buf)+fread(buf,1,S,stdin)) == buf) return EOF;
	return *p++;
}

inline int nextint() {
	int x = 0, c = getchar(), neg = false;
	while(('0' > c || c > '9') && c!='-' && c!=EOF) c = getchar();
	if(c == '-') neg = true, c = getchar();
	while('0' <= c && c <= '9') x = x*10 + (c^'0'), c = getchar();
	if(neg) x = -x;
	return x; // returns 0 if EOF
}

class dsu {
 public:
  vector<int> p;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
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

inline int dist(int xa, int ya, int xb, int yb) {
  return abs(xb - xa) + abs(yb - ya);
}

struct edge {
  int from;
  int to;
  int cost;

  inline bool operator < (const edge &other) const {
    return cost < other.cost;
  }
};

int main() {
  int tt = nextint();
  while (tt--) {
    int n = nextint();
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
      a[i].first = nextint();
      a[i].second = nextint();
    }
    vector<edge> edges;
    dsu d(n);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (a[i].first == a[j].first || a[i].second == a[j].second) {
          edges.push_back({i, j, dist(a[i].first, a[i].second, a[j].first, a[j].second)});
        }
      }
    }
    sort(edges.begin(), edges.end());
    int ans = 0;
    for (const auto &e : edges) {
      if (d.unite(e.from, e.to)) {
        ans += e.cost;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
