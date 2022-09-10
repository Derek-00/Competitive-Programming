/**
 *    author:  willy
 *    created: Wed, 29 Dec 2021 16:03:00 GMT
**/
#include <bits/stdc++.h>

using namespace std;

/*
  proof:  for each value i between 1 and N consider the numbers consisting of exactly i digits equal to K
  *** Pigeonhole principle:
  example: a pair {2222, 22} are both equal to 2 modulo 4 => the difference of them -2200- is divisible by N,
           and contains only digits equal to K or 0.
*/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> pa(n, -1);
  vector<int> digit(n, -1);
  pa[k % n] = 0;
  digit[k % n] = k;
  vector<int> que(1, k % n);
  for (int b = 0; b < (int) que.size(); b++) {
    if (pa[0] != -1) {
      break;
    }
    for (auto& d : {0, k}) {
      int nxt = (que[b] * 10 + d) % n;
      if (pa[nxt] == -1) {
        digit[nxt] = d;
        pa[nxt] = que[b];
        que.push_back(nxt);
      }
    }
  }
  string ans = "";
  int ptr = 0;
  do {
    ans += (char) ('0' + digit[ptr]);
    ptr = pa[ptr];
  } while (ptr != 0);
  cout << string(ans.rbegin(), ans.rend()) << '\n';
  return 0;
}
