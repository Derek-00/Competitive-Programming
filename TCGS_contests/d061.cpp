/**
 *    author:  willy
 *    created: Sat, 06 Nov 2021 07:36:33 GMT
**/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_palin(string s) {
  string ns = s;
  reverse(s.begin(), s.end());
  return (ns == s);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  int Case = 0;
  while (tt--) {
    string s;
    cin >> s;
    vector<string> ans;
    int mx = 0;
    for (int i = 0; i < (int) s.size(); i++) {
      for (int len = mx; i + len - 1 < (int) s.size(); len++) {
        string res = s.substr(i, len);
        if (is_palin(res)) {
          if (mx < len) {
            mx = len;
            ans.clear();
            ans.push_back(res);
          } else {
            if (mx == len) {
              ans.push_back(res);
            }
          }
        }
      }
    }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    cout << "第" << ++Case << "組測試資料的最長迴文子字串長度為:" << mx << '\n';
    cout << "第" << Case << "組測試資料的最長迴文子字串內容為:";
    for (int i = 0; i < (int) ans.size(); i++) {
      cout << ans[i] << " ";
    }
    cout << "\n\n";
  }
  return 0;
}
