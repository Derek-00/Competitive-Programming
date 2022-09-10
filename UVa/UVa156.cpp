#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  map<string, int> cnt;
  vector<string> words;
  auto repr = [&](string s) {
    for (int i = 0; i < (int) s.length(); i++) {
      s[i] = tolower(s[i]);
    }
    sort(s.begin(), s.end());
    return s;
  };
  while (cin >> s) {
    if (s[0] == '#') break;
    words.push_back(s);
    string r = repr(s);
    if (!cnt.count(r)) cnt[r] = 0;
    cnt[r]++;
  }
  vector<string> ans;
  for (int i = 0; i < (int) words.size(); i++) {
    if (cnt[repr(words[i])] == 1) {
      ans.push_back(words[i]);
    }
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}
