#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string a, b;
  while (cin >> a >> b) {
    vector<int> cnt1(26);
    vector<int> cnt2(26);
    for (int i = 0; i < (int) a.length(); i++) {
      cnt1[a[i] - 'A']++;
      cnt2[b[i] - 'A']++;
    }
    sort(cnt1.begin(), cnt1.end());
    sort(cnt2.begin(), cnt2.end());
    bool is_same = true;
    for (int i = 0; i < 26; i++) {
      if (cnt1[i] != cnt2[i]) {
        is_same = false;
        break;
      }
    }
    cout << (is_same ? "YES\n" : "NO\n");
  }
  return 0;
}
