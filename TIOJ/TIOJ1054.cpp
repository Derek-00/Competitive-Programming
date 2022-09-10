/**
 *    author:  willy
 *    created: Sun, 08 Aug 2021 12:52:37 GMT
**/
#include <bits/stdc++.h>

using namespace std;

const string day[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n;
  cin >> n;
  int pos = -1;
  for (int i = 0; i < 7; i++) {
    if (s == day[i]) {
      pos = i;
    }
  }
  pos = (pos + n) % 7;
  cout << day[pos] << '\n';
  return 0;
}
