#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  while (cin >> s >> t) {
    vector<bool> chosen((int) s.length(), false);
    int s_counter = 0;
    for (int i = 0; i < (int) t.length(); i++) {
      if (t[i] == s[s_counter]) {
        chosen[s_counter++] = true;
      }
    }
    cout << (s_counter == (int) s.length() ? "Yes" : "No") << '\n';
  }
  return 0;
}
