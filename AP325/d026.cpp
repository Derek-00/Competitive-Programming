#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  map<char, char> oper = {
    {'(', ')'},
    {'[', ']'},
    {'{', '}'}
  };
  string s;
  while (cin >> s) {
    vector<char> st;
    bool ok = true;
    for (int i = 0; i < (int) s.length(); i++) {
      char ch = s[i];
      if (ch == '(' || ch == '[' || ch == '{') {
        st.push_back(ch);
      } else {
        if (oper[st.back()] == ch) {
          st.pop_back();
        } else {
          ok = false;
          break;
        }
      }
    }
    cout << (ok && st.empty() ? "yes" : "no") << '\n';
  }
  return 0;
}
