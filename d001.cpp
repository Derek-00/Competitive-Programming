#include <bits/stdc++.h>

using namespace std;

int eval();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << eval();
    return 0;
}

int eval() {
    char n[7];
    cin >> n;
    if (n[0] == 'f') {
        int x = eval();
        return 2 * x - 1;
    } else if (n[0] == 'g') {
        int x = eval();
        int y = eval();
        return x + 2 * y - 3;
    } else {
        return atoi(n);
    }
}
