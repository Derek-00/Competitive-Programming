/**
 *    author:  willy
 *    created: Thu, 11 Nov 2021 13:00:06 GMT
**/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> ans;

int days(int month, bool is_leaf) {
  if (month == 2) {
    if (is_leaf) return 29;
    return 28;
  }
  if (month == 7 || month == 8) {
    return 31;
  }
  if (month < 7) {
    if (month & 1) return 31;
    return 30;
  }
  if (month & 1) return 30;
  return 31;
}

inline int string_to_int(string s) {
  int res = 0;
  for (int i = 0; i < (int) s.size(); i++) {
    res = res * 10 + (int) (s[i] - '0');
  }
  return res;
}

void Solve(string year, string s, bool is_leaf) {
  reverse(s.begin(), s.end());
  string after = year + s;
  for (int rot = 1; rot <= 2; rot++) {
    if ((int) s.size() == 4 && rot == 1) continue;
    int month = string_to_int(s.substr(0, rot));
    int date = string_to_int(s.substr(rot));
    if (month <= 0 || month > 12) continue;
    if (date <= 0 || date > 31) continue;
    int can = days(month, is_leaf);
    if (can >= date) {
      ans.push_back(after);
    }
  }
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int year = string_to_int(s);
    bool is_leaf = ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0));
    if (s[s.size() - 1] == s[s.size() - 2]) Solve(s, s.substr(0, 2), is_leaf);
    Solve(s, s.substr(0, 3), is_leaf);
    Solve(s, s, is_leaf);
    cout << (int) ans.size();
    for (int i = 0; i < (int) ans.size(); i++) {
      cout << " " << ans[i];
    }
    cout << endl;
    ans.clear();
  }
  return 0;
}
