#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  set<string> S;
  while (getline(cin, s)) {
    for (int i = 0; i < (int) s.length(); i++) {
      if (isalpha(s[i])) {
        s[i] = tolower(s[i]);
      } else {
        s[i] = ' ';
      }
    }
    string tmp;
    stringstream ss(s);
    while (ss >> tmp) {
      S.insert(tmp);
    }
  }
  for (auto it = S.begin(); it != S.end(); it++) {
    cout << *it << '\n';
  }
  return 0;
}
