/**
 *    author:  willy
 *    created: Wed, 10 Nov 2021 11:24:24 GMT
**/
#include <bits/stdc++.h>

using namespace std;

inline bool isoper(char s) {
  return (s == '+' || s == '-' || s == '*' || s == '/' || s == '%');
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  map<char, int> pri = {{'*', 3}, {'/', 3}, {'%', 3}, {'+', 2}, {'-', 2}, {'(', 1}, {')', 1}};
  string s;
  while (getline(cin, s)) {
    stringstream ss;
    ss << "( " << s << " )";
    vector<char> stk;
    vector<long long> digit;
    auto eval = [&]() {
      long long b = digit.back(); digit.pop_back();
      long long a = digit.back(); digit.pop_back();
      char op = stk.back(); stk.pop_back();
      if (op == '+') digit.push_back(a + b);
      if (op == '-') digit.push_back(a - b);
      if (op == '*') digit.push_back(a * b);
      if (op == '/') digit.push_back(a / b);
      if (op == '%') digit.push_back(a % b);
    };
    while (ss >> s) {
      if (isdigit(s[0])) {
        digit.push_back(stoi(s));
      }
      if (s[0] == '(') {
        stk.push_back(s[0]);
      }
      if (isoper(s[0])) {
        while (pri[stk.back()] >= pri[s[0]]) {
          eval();
        }
        stk.push_back(s[0]);
      }
      if (s[0] == ')') {
        while (stk.back() != '(') {
          eval();
        }
        stk.pop_back();
      }
    }
    cout << digit.back() << endl;
  }
  return 0;
}
