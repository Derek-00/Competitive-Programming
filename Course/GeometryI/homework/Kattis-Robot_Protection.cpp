#include <bits/stdc++.h>

using namespace std;

struct point {
	int x;
	int y;

	point() : x(0), y(0) {
	}

	point(int _x, int _y) : x(_x), y(_y) {
	}

	inline bool operator < (const point& rhs) const {
		return make_pair(x, y) < make_pair(rhs.x, rhs.y);
	}

	inline point operator - (const point& rhs) const {
		return point(x - rhs.x, y - rhs.y);
	}
};

inline int sign(int x) {
	return (x == 0 ? 0 : (x < 0 ? -1 : 1));
}

inline int cross(point a, point b) {
	return a.x * b.y - a.y * b.x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while (cin >> n && n) {
		vector<point> p(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i].x >> p[i].y;
		}
		sort(p.begin(), p.end());
		vector<point> hs;
		for (int rot = 0; rot < 2; rot++) {
			int base = (int) hs.size();
			for (auto& v : p) {
				while ((int) hs.size() - base >= 2 && sign(cross(hs.back() - hs[hs.size() - 2], v - hs[hs.size() - 2])) < 0) {
					hs.pop_back();
				}
				hs.push_back(v);
			}
			hs.pop_back();
			reverse(p.begin(), p.end());
		}
		int area = 0;
		for (int i = 0; i < (int) hs.size(); i++) {
			area += cross(hs[i], hs[(i + 1) % (int) hs.size()]);
		}
		cout << fixed << setprecision(5) << (double) abs(area) / 2 << '\n';
	}
	return 0;
}
