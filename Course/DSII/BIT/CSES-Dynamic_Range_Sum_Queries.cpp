#include <bits/stdc++.h>

using namespace std;

#define int long long

template<typename T>
class fenwick {
 public:
 	vector<T> fenw;
 	int n;

 	fenwick(int _n) : n(_n) {
 		fenw.resize(n);
	}

	void modify(int x, T v) {
		while (x < n) {
			fenw[x] += v;
			x |= x + 1;
		}
	}

	int get(int x) {
		T v{};
		while (x >= 0) {
			v += fenw[x];
			x = (x & (x + 1)) - 1;
		}
		return v;
	}
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<long long> a(n);
	fenwick<long long> fenw(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		fenw.modify(i, a[i]);
	}
	while (q--) {
		int t;
		long long u, v;
		cin >> t >> u >> v;
		if (t == 1) {
			--u;
			fenw.modify(u, v - a[u]);
			a[u] = v;
		} else {
			--u; --v;
			if (u == 0) {
				cout << fenw.get(v) << '\n';
			} else {
				cout << fenw.get(v) - fenw.get(u - 1) << '\n';
			}
		}
	}
	return 0;
}
