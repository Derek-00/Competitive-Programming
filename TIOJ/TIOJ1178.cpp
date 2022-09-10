#include <bits/stdc++.h>

using namespace std;

struct point {
	long long x;
	long long y;

	point() : x(0), y(0) {
	}

	point(long long _x, long long _y) : x(_x), y(_y) {
	}

	inline bool operator < (const point& rhs) const {
		return make_pair(x, y) < make_pair(rhs.x, rhs.y);
	}

	inline point operator - (const point& rhs) const {
		return point(x - rhs.x, y - rhs.y);
	}
};

int sign(long long x) {
	return (x == 0 ? 0 : (x < 0 ? -1 : 1));
}

long long cross(point a, point b) {
	return (long long) a.x * b.y - a.y * b.x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
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
	cout << (int) hs.size() << '\n';
	return 0;
}
