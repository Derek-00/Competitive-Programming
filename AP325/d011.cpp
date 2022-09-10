#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> S;
    for (int i = 0; i < n; i++) {
        S[a[i]] = 0;
    }
    int cnt = 0;
    for (auto it = S.begin(); it != S.end(); it++) {
        it -> second = cnt++;
    }
    for (int i = 0; i < n; i++) {
        cout << S.find(a[i]) -> second << " ";
    }
    return 0;
}
