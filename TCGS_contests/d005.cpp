/**
 *    author:  willy
 *    created: Fri, 12 Nov 2021 07:55:42 GMT
**/
#include <iostream>
#include <string.h>

using namespace std;

const string words[] = {"一", "二", "三", "四", "五", "六", "七", "八", "九", "十"};

int ptr, mx;
string s;

void Solve(int len) {
  while (true) {
    if (ptr >= (int) s.size()) {
      return;
    }
    if (s[ptr] == ')') {
      mx = max(mx, len);
      return;
    }
    if (s[ptr] == '(') {
      ptr += 1;
      Solve(len);
    } else {
      bool neg = false;
      if (s[ptr] == '-') {
        ptr++;
        neg = true;
      }
      int res = 0;
      while (isdigit(s[ptr + 1])) {
        res = res * 10 + (int) (s[ptr++] - '0');
      }
      res = res * 10 + (int) (s[ptr] - '0');
      if (neg) res *= -1;
      len += res;
    }
    ptr++;
  }
}

int main() {
  int Case = 0;
  int tt;
  cin >> tt;
  while (tt--) {
    s = "";
    int cnt = 0;
    char ch;
    while (cin >> ch) {
      if (ch == '(') {
        cnt++;
      }
      s += ch;
      if (ch == ')') {
        if (--cnt == 0) {
          break;
        }
      }
    }
    mx = 0;
    ptr = 1;
    Solve(0);
    cout << "第" << words[Case++] << "棵二元樹最長路徑長度：" << mx << '\n';
  }
  return 0;
}
