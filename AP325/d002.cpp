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
    char n[5];
    cin >> n;
    if (n[0] == 'f') {
        int x = eval();
        return 2 * x - 3;
    } else if (n[0] == 'g') {
        int x = eval();
        int y = eval();
        return 2 * x + y - 7;
    } else if (n[0] == 'h') {
        int x = eval();
        int y = eval();
        int z = eval();
        return 3 * x - 2 * y + z;
    } else {
        return atoi(n);
    }
}
