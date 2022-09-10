#include <bits/stdc++.h>

using namespace std;

const int P = 10009;
long long n, ans = 0;
vector<long long> a;

void rec(int i, int total, int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    rec(0, 1, n);
    cout << ans - 1;
    return 0;
}

void rec(int i, int total, int n) {
    if (i >= n) {
        if (total == 1) {
            ans++;
        }
        return;
    }
    rec(i + 1, total, n);
    rec(i + 1, (total * a[i]) % P, n);
    return;
}
