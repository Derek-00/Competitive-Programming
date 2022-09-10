/**
 *    author:  willy
 *    created: Wed, 10 Nov 2021 06:09:41 GMT
**/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

inline bool isoper(char a) {
  return (a == '+' || a == '-' || a == '*' || a == '/');
}

int main() {
  map<char, int> pri;
  pri['*'] = pri['/'] = pri['%'] = 1;
  pri['+'] = pri['-'] = 2;
  pri['('] = pri[')'] = 3;
  string s;
  cin >> s;
  vector<char> stk;
  string res = "";
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == '(') {
      stk.push_back(s[i]);
    }
    if (isalpha(s[i])) {
      res += s[i];
    }
    if (isoper(s[i])) {
      while (!stk.empty() && stk.back() != '(' && pri[stk.back()] <= pri[s[i]]) {
        res += stk.back();
        stk.pop_back();
      }
      stk.push_back(s[i]);
    }
    if (s[i] == ')') {
      while (!stk.empty() && stk.back() != '(') {
        res += stk.back();
        stk.pop_back();
      }
      stk.pop_back();
    }
  }
  while (!stk.empty()) {
    res += stk.back();
    stk.pop_back();
  }
  cout << res << endl;
  return 0;
}
