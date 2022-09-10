#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int maxn = 1e5 + 5;
  int last, cur, next[maxn]; // next[] == prointer of listnode.
  char s[maxn];
  while (cin >> s + 1) {
    int n = strlen(s + 1);
    last = cur = 0;
    next[0] = 0;
    for (int i = 1; i <= n; i++) {
      char ch = s[i];
      if (ch == '[') {
        cur = 0;
      } else if (ch == ']') {
        cur = last;
      } else {
        next[i] = next[cur]; // newnode -> next = cur.
        next[cur] = i; // cur = newnode;
        if (cur == last) last = i; // if cur == last, cur will plus 1, so last have to plus 1.
        cur = i; 
      }
    }
    for (int i = next[0]; i != 0; i = next[i]) {
      cout << s[i];
    }
    cout << '\n';
  }
  return 0;
}
