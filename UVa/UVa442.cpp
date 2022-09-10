#include <bits/stdc++.h>

using namespace std;

struct matrix {
  int a, b;
  
  matrix(int a = 0, int b = 0) : a(a), b(b) {
  }
} m[26];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  stack<matrix> s;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string name;
    cin >> name;
    int k = name[0] - 'A';
    cin >> m[k].a >> m[k].b;
  }
  string expr;
  while (cin >> expr) {
    int len = (int) expr.length();
    bool error = false;
    int ans = 0;
    for (int i = 0; i < len; i++) {
      if (isalpha(expr[i])) {
        s.push(m[expr[i] - 'A']);
      } else if (expr[i] == ')') {
        matrix m2 = s.top(); s.pop();
        matrix m1 = s.top(); s.pop();
        if (m1.b != m2.a) {
          error = true;
          break;
        }
        ans += m1.a * m1.b * m2.b;
        s.push(matrix(m1.a, m2.b));
      }
    }
    if (error) {
      cout << "error\n";
    } else {
      cout << ans << '\n';
    }
  }
  return 0;
}
