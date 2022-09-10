#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    set<int> S;
    for (int i = 0, q; i < n; i++) {
        cin >> q;
        S.insert(q);
    }
    cout << S.size() << '\n';
    for (auto i : S) {
        cout << i << " ";
    }
    return 0;
}
