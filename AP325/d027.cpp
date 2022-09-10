/**
 *    author:  wy
 *    created: Thu, 07 Jul 2022 07:30:05 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\wy\C++\solve\_debug\debug.h"
#else
#define debug(...) 42
#endif

inline int Eval(int x, char op, int y) {
  if (op == '+') return x + y;
  if (op == '-') return x - y;
  if (op == '*') return x * y;
  if (op == '/') return x / y;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  vector<int> num(1, (int) (s[0] - '0'));
  vector<char> stk;
  auto Do = [&]() {
    int b = num.back();
    num.pop_back();
    int a = num.back();
    num.pop_back();
    char p = stk.back();
    stk.pop_back();
    num.push_back(Eval(a, p, b));
  };
  for (int i = 1; i < (int) s.size(); i += 2) {
    char op = s[i];
    int y = (int) (s[i + 1] - '0');
    if (op == '*' || op == '/') {
      int x = num.back();
      num.pop_back();
      num.push_back(Eval(x, op, y));
    } else {
      while (!stk.empty()) {
        Do();
      }
      stk.push_back(op);
      num.push_back(y);
    }
  }
  if (!stk.empty()) {
    Do();
  }
  cout << num.back() << '\n';
  return 0;
}
